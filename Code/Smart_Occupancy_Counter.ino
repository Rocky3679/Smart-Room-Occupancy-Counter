/**
 * @file Smart_Occupancy_Counter.ino
 * @brief Industrial Energy Management System: Non-Blocking State-Driven Occupancy Counter
 * @author Janaki Raman K
 * * DESIGN SPECIFICATIONS:
 * - Target Controller: Arduino UNO / Nano Architecture
 * - I/O Bus: 2x Discrete Inputs (Optical/IR Sensors), 1x Digital Output (Relay Interlock)
 * - Communication: I2C Bus Standard-Mode (100kHz) for SSD1306 HMI Display
 * - Architecture: Asynchronous Finite State Machine (FSM) with Integrated Digital Filters
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// HMI Display Configuration Constants
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// =============================================================================
// HARDWARE I/O REGISTER MAPPING
// =============================================================================
const uint8_t PIN_SENSOR_A   = 2;  /**< Field Sensor A: Entry Boundary Threshold */
const uint8_t PIN_SENSOR_B   = 3;  /**< Field Sensor B: Exit Boundary Threshold */
const uint8_t PIN_LOAD_RELAY = 8;  /**< Discrete Output: Lighting Circuit Control */

// =============================================================================
// SYSTEM PARAMETERS & TIMING REGISTERS
// =============================================================================
const uint32_t T_DEBOUNCE_MS        = 30;   /**< Digital filter integration window */
const uint32_t T_FSM_TIMEOUT_MS     = 3000; /**< Watchdog timeout to flush stale/incomplete transactions */
const uint32_t T_HMI_REFRESH_MS     = 200;  /**< Non-blocking HMI refresh cycle interval */

// =============================================================================
// STATE ENGINE SCHEDULER SYMBOLS
// =============================================================================
enum DeviceState {
    SYS_IDLE,
    SYS_ENTRY_SEQUENCE,
    SYS_EXIT_SEQUENCE,
    SYS_SEQUENCE_LOCK
};

DeviceState systemStateEngine = SYS_IDLE;
uint32_t fsmWatchdogTimer = 0;
volatile int16_t globalOccupancyRegister = 0;

struct DigitalInput {
    uint8_t pin;
    bool rawSignal;
    bool debouncedState;
    bool previousState;
    uint32_t lastDebounceTime;
};

DigitalInput fieldSensorA = { PIN_SENSOR_A, true, true, true, 0 };
DigitalInput fieldSensorB = { PIN_SENSOR_B, true, true, true, 0 };

// =============================================================================
// FIELD SIGNAL INTEGRATION FILTER (Software Debouncing Engine)
// =============================================================================
void filterInputChannel(DigitalInput &sensor) {
    bool physicalSample = digitalRead(sensor.pin);
    
    if (physicalSample != sensor.rawSignal) {
        sensor.lastDebounceTime = millis();
        sensor.rawSignal = physicalSample;
    }
    
    if ((millis() - sensor.lastDebounceTime) > T_DEBOUNCE_MS) {
        if (physicalSample != sensor.debouncedState) {
            sensor.debouncedState = physicalSample;
        }
    }
}

// =============================================================================
// CORE CONTROL LOGIC: SEQUENTIAL FINITE STATE MACHINE
// =============================================================================
void processOccupancyFSM() {
    // Watchdog implementation to prevent channel locks from partial or stale beam breaks
    if (systemStateEngine != SYS_IDLE && (millis() - fsmWatchdogTimer > T_FSM_TIMEOUT_MS)) {
        systemStateEngine = SYS_IDLE;
        Serial.println(F("[WARN] Sequencer Watchdog Tripped. Flushing Register."));
    }

    switch (systemStateEngine) {
        case SYS_IDLE:
            // Detect active-low edge transitions on input boundaries
            if (fieldSensorA.debouncedState == LOW && fieldSensorA.previousState == HIGH) {
                fsmWatchdogTimer = millis();
                systemStateEngine = SYS_ENTRY_SEQUENCE;
            } else if (fieldSensorB.debouncedState == LOW && fieldSensorB.previousState == HIGH) {
                fsmWatchdogTimer = millis();
                systemStateEngine = SYS_EXIT_SEQUENCE;
            }
            break;

        case SYS_ENTRY_SEQUENCE:
            // Sensor A was tripped first. Confirm entry when Sensor B trips next.
            if (fieldSensorB.debouncedState == LOW && fieldSensorB.previousState == HIGH) {
                globalOccupancyRegister++;
                systemStateEngine = SYS_SEQUENCE_LOCK;
                Serial.println(F("[EVENT] Target Entry Transaction Verified."));
            }
            break;

        case SYS_EXIT_SEQUENCE:
            // Sensor B was tripped first. Confirm exit when Sensor A trips next.
            if (fieldSensorA.debouncedState == LOW && fieldSensorA.previousState == HIGH) {
                globalOccupancyRegister--;
                if (globalOccupancyRegister < 0) globalOccupancyRegister = 0; // Mathematical boundary limit
                systemStateEngine = SYS_SEQUENCE_LOCK;
                Serial.println(F("[EVENT] Target Exit Transaction Verified."));
            }
            break;

        case SYS_SEQUENCE_LOCK:
            // Wait for both boundary lines to clear completely before returning to IDLE state
            if (fieldSensorA.debouncedState == HIGH && fieldSensorB.debouncedState == HIGH) {
                systemStateEngine = SYS_IDLE;
            }
            break;
    }

    // Keep state registers updated for the next loop execution
    fieldSensorA.previousState = fieldSensorA.debouncedState;
    fieldSensorB.previousState = fieldSensorB.debouncedState;
}

// =============================================================================
// ELECTRICAL LOAD INVENTORY CONTROL (Relay Interlocking)
// =============================================================================
void processLoadControl() {
    if (globalOccupancyRegister > 0) {
        digitalWrite(PIN_LOAD_RELAY, HIGH); // Close relay poles to energize lights
    } else {
        digitalWrite(PIN_LOAD_RELAY, LOW);  // Open relay poles to isolate load circuits
    }
}

// =============================================================================
// HUMAN-MACHINE INTERFACE (HMI) MANAGEMENT LAYER
// =============================================================================
void executeHMIRender() {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    
    // System Status Frame Banner
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print(F("SYS MODE: AUTOMATIC"));
    
    // Process Variable (PV) Real-time Tracking Output
    display.setCursor(0, 18);
    display.setTextSize(2);
    display.print(F("COUNT: "));
    display.print(globalOccupancyRegister);
    
    // Output Loop Relay Diagnostics Line
    display.setTextSize(1);
    display.setCursor(0, 52);
    display.print(F("LOAD LINE STATUS: "));
    display.print((digitalWrite(PIN_LOAD_RELAY) == HIGH) ? F("ON") : F("OFF"));
    
    display.display();
}

// =============================================================================
// SYSTEM SUBSYSTEM INITIALIZATION
// =============================================================================
void setup() {
    Serial.begin(115200);
    
    pinMode(fieldSensorA.pin, INPUT_PULLUP);
    pinMode(fieldSensorB.pin, INPUT_PULLUP);
    pinMode(PIN_LOAD_RELAY, OUTPUT);
    digitalWrite(PIN_LOAD_RELAY, LOW);
    
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("[FATAL] HMI Allocation Failed. Interruption Loop Active."));
        for (;;); // Force system lockup if critical visual bus is missing
    }
    
    display.clearDisplay();
    display.display();
    Serial.println(F("[INFO] System Architecture Initialization Complete. Engine Active."));
}

// =============================================================================
// DETERMINISTIC ASYNCHRONOUS SYSTEM LOOP
// =============================================================================
void loop() {
    // 1. Physical Signal Acquisition Layer
    filterInputChannel(fieldSensorA);
    filterInputChannel(fieldSensorB);
    
    // 2. State Process Control Engine Layer
    processOccupancyFSM();
    processLoadControl();
    
    // 3. Isolated HMI Execution Scheduler Window
    static uint32_t lastHMITaskExecution = 0;
    if (millis() - lastHMITaskExecution >= T_HMI_REFRESH_MS) {
        executeHMIRender();
        lastHMITaskExecution = millis();
    }
}