/*
 * Question 4: Embedded Systems
 * Application: Automated Temperature Monitoring & Fan Control System
 *
 * COMPONENTS:
 *   Sensor     : DHT11 Temperature & Humidity Sensor (Pin A0 / D2)
 *   Controller : Arduino Uno (ATmega328P microcontroller)
 *   Actuator   : DC Brushless Fan via NPN transistor (Pin D9, PWM)
 *
 * DATA FLOW:
 *   DHT11 Sensor --> Arduino (reads analog voltage, converts to Celsius)
 *                --> Evaluates temperature thresholds
 *                --> Sends PWM signal to transistor base
 *                --> Transistor switches fan motor ON/OFF/speed
 *                --> Serial Monitor displays live readings
 *
 * CIRCUIT CONNECTIONS:
 *   DHT11 VCC  -> Arduino 5V
 *   DHT11 GND  -> Arduino GND
 *   DHT11 DATA -> Arduino Pin D2 (with 10kΩ pull-up resistor to 5V)
 *
 *   Fan +12V   -> External 12V supply positive
 *   Fan GND    -> NPN Collector (e.g., TIP120 or 2N2222)
 *   NPN Base   -> Arduino Pin D9 (via 1kΩ resistor)
 *   NPN Emitter-> GND (common ground with Arduino)
 *   Flyback diode (1N4007) across fan terminals (cathode to +12V)
 *
 * LIBRARIES REQUIRED:
 *   DHT sensor library by Adafruit (v1.4.x)
 *   Install via: Sketch > Include Library > Manage Libraries > "DHT sensor library"
 */

#include <DHT.h>

/* -------------------------------------------------------
 * PIN DEFINITIONS
 * ------------------------------------------------------- */
#define DHT_PIN       2       /* Digital pin connected to DHT11 DATA */
#define DHT_TYPE      DHT11   /* Sensor model */
#define FAN_PIN       9       /* PWM-capable pin for fan speed control */

/* -------------------------------------------------------
 * TEMPERATURE THRESHOLDS (degrees Celsius)
 * ------------------------------------------------------- */
#define TEMP_OFF      25.0    /* Below this -> fan stays OFF */
#define TEMP_LOW      28.0    /* 25-28°C    -> fan at LOW speed */
#define TEMP_MED      32.0    /* 28-32°C    -> fan at MEDIUM speed */
/* Above TEMP_MED               -> fan at FULL speed              */

/* -------------------------------------------------------
 * FAN PWM SPEED LEVELS (0-255, mapped to 0-100% duty cycle)
 * ------------------------------------------------------- */
#define FAN_SPEED_OFF    0
#define FAN_SPEED_LOW    80    /* ~31% duty cycle */
#define FAN_SPEED_MED   160    /* ~63% duty cycle */
#define FAN_SPEED_HIGH  255    /* 100% duty cycle */

/* -------------------------------------------------------
 * TIMING
 * ------------------------------------------------------- */
#define READ_INTERVAL_MS  2000   /* DHT11 minimum sampling interval is 1s */

/* -------------------------------------------------------
 * GLOBAL OBJECTS & STATE
 * ------------------------------------------------------- */
DHT dht(DHT_PIN, DHT_TYPE);   /* Instantiate sensor driver */

float currentTemp = 0.0;
float currentHumidity = 0.0;
int   currentFanSpeed = FAN_SPEED_OFF;

/* -------------------------------------------------------
 * FUNCTION PROTOTYPES
 * ------------------------------------------------------- */
bool  readSensor(float *temperature, float *humidity);
int   determineFanSpeed(float temperature);
void  setFanSpeed(int pwmValue);
void  logStatus(float temp, float humidity, int fanSpeed);

/* -------------------------------------------------------
 * SETUP — runs once on power-on or reset
 * ------------------------------------------------------- */
void setup() {
    Serial.begin(9600);           /* Open serial port at 9600 baud */
    dht.begin();                  /* Initialize DHT11 sensor */
    pinMode(FAN_PIN, OUTPUT);     /* Configure fan pin as output */
    analogWrite(FAN_PIN, FAN_SPEED_OFF);  /* Fan starts OFF */

    Serial.println("===========================================");
    Serial.println("  Temperature-Controlled Fan System");
    Serial.println("  Sensor: DHT11 | Controller: Arduino Uno");
    Serial.println("===========================================");
    Serial.println("Temp(C)  Humidity(%)  Fan Speed  Mode");
    Serial.println("-------  -----------  ---------  ----");
}

/* -------------------------------------------------------
 * LOOP — runs continuously after setup()
 * ------------------------------------------------------- */
void loop() {
    /* 1. READ SENSOR DATA */
    if (!readSensor(&currentTemp, &currentHumidity)) {
        Serial.println("[ERROR] Failed to read DHT11. Check wiring.");
        delay(READ_INTERVAL_MS);
        return;   /* Skip processing if sensor read failed */
    }

    /* 2. PROCESS: Determine required fan speed from temperature */
    currentFanSpeed = determineFanSpeed(currentTemp);

    /* 3. ACTUATE: Apply PWM signal to fan driver transistor */
    setFanSpeed(currentFanSpeed);

    /* 4. REPORT: Log status to Serial Monitor */
    logStatus(currentTemp, currentHumidity, currentFanSpeed);

    /* 5. WAIT before next reading (DHT11 requires >= 1s between reads) */
    delay(READ_INTERVAL_MS);
}

/* -------------------------------------------------------
 * readSensor()
 *   Reads temperature and humidity from DHT11.
 *   Returns: true  = valid reading
 *            false = sensor error (NaN returned by library)
 * ------------------------------------------------------- */
bool readSensor(float *temperature, float *humidity) {
    float t = dht.readTemperature();   /* Celsius by default */
    float h = dht.readHumidity();

    /* DHT library returns NaN on failure */
    if (isnan(t) || isnan(h)) {
        return false;
    }

    *temperature = t;
    *humidity    = h;
    return true;
}

/* -------------------------------------------------------
 * determineFanSpeed()
 *   Maps temperature reading to a PWM fan speed level.
 *   Uses cascading if-else for clear threshold logic.
 * ------------------------------------------------------- */
int determineFanSpeed(float temperature) {
    if (temperature < TEMP_OFF) {
        return FAN_SPEED_OFF;     /* Comfortable — fan not needed */
    } else if (temperature < TEMP_LOW) {
        return FAN_SPEED_LOW;     /* Slightly warm — low cooling */
    } else if (temperature < TEMP_MED) {
        return FAN_SPEED_MED;     /* Warm — moderate cooling */
    } else {
        return FAN_SPEED_HIGH;    /* Hot — maximum cooling */
    }
}

/* -------------------------------------------------------
 * setFanSpeed()
 *   Sends a PWM duty-cycle value (0-255) to the fan pin.
 *   The NPN transistor amplifies this signal to drive the
 *   12V fan motor at the corresponding speed.
 * ------------------------------------------------------- */
void setFanSpeed(int pwmValue) {
    analogWrite(FAN_PIN, pwmValue);
}

/* -------------------------------------------------------
 * logStatus()
 *   Prints formatted sensor and actuator status to Serial.
 * ------------------------------------------------------- */
void logStatus(float temp, float humidity, int fanSpeed) {
    /* Convert PWM value to human-readable mode label */
    const char *mode;
    if      (fanSpeed == FAN_SPEED_OFF)  mode = "OFF";
    else if (fanSpeed == FAN_SPEED_LOW)  mode = "LOW";
    else if (fanSpeed == FAN_SPEED_MED)  mode = "MEDIUM";
    else                                 mode = "HIGH";

    Serial.print(temp,    1);   Serial.print("       ");
    Serial.print(humidity,1);   Serial.print("        ");
    Serial.print(fanSpeed);     Serial.print("         ");
    Serial.println(mode);
}
