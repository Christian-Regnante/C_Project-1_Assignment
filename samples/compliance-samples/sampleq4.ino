/*
 * temp_alert.ino
 * Automatic temperature alert using TMP36 sensor and LED actuator
 * Controller: Arduino Uno
 */

#define TEMP_PIN     A0
#define LED_PIN      13
#define TEMP_THRESH  30   /* degrees Celsius — LED turns on above this */

/**
 * read_temperature - reads raw ADC and converts to Celsius
 *
 * Return: temperature in degrees Celsius as float
 */
float read_temperature()
{
    int   raw      = analogRead(TEMP_PIN);
    float voltage  = (raw / 1023.0) * 5.0;      /* convert ADC to volts   */
    float temp_c   = (voltage - 0.5) * 100.0;   /* TMP36 formula */

    return (temp_c);
}

/**
 * control_led - turns LED on or off based on temperature
 * @temp: current temperature in Celsius
 */
void control_led(float temp)
{
    if (temp >= TEMP_THRESH)
    {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("WARNING: High temperature! LED ON");
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
        Serial.println("Temperature normal. LED OFF");
    }
}

/**
 * display_temp - prints current temperature to serial monitor
 * @temp: current temperature in Celsius
 */
void display_temp(float temp)
{
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" C");
}

/**
 * setup - runs once on power-on
 */
void setup()
{
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

/**
 * loop - runs repeatedly forever until stopped
 * Reads sensor and updates actuator every 1000ms
 */
void loop()
{
    float temp = read_temperature();

    display_temp(temp);
    control_led(temp);

    delay(1000);
}
