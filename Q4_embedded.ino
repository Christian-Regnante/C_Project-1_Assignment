/*
========================================================
  Smart Analog Level LED Indicator System
  -------------------------------------------------------
  Description:
  This system reads an analog input signal (simulated
  using a potentiometer in Tinkercad) and lights up
  different LEDs based on the input range.

  It demonstrates:
  - Sensor input (Analog signal)
  - Control flow (if-else conditions)
  - Output devices (LEDs)
  - Real-time embedded system behavior
========================================================
*/

// ----------------------
// Pin Definitions
// ----------------------
int sensorPin = A0;     // Analog input pin (potentiometer / sound sensor)

int redLED = 8;         // Low level indicator
int yellowLED = 9;      // Medium level indicator
int greenLED = 10;      // High level indicator

int value = 0;          // Stores analog reading

// ----------------------
// Setup function (runs once)
// ----------------------
void setup()
{
  // Set LED pins as OUTPUT
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Start serial communication (for debugging)
  Serial.begin(9600);
}

// ----------------------
// Main loop (runs forever)
// ----------------------
void loop()
{
  // Read analog input from sensor (0 - 1023)
  value = analogRead(sensorPin);

  // Print value to Serial Monitor (for testing)
  Serial.print("Sensor Value: ");
  Serial.println(value);

  // Turn OFF all LEDs before deciding
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  // ----------------------
  // Decision Making Logic
  // ----------------------

  // Low range → Red LED ON
  if (value >= 0 && value <= 340)
  {
    digitalWrite(redLED, HIGH);
  }

  // Medium range → Yellow LED ON
  else if (value > 340 && value <= 680)
  {
    digitalWrite(yellowLED, HIGH);
  }

  // High range → Green LED ON
  else
  {
    digitalWrite(greenLED, HIGH);
  }

  // Small delay for stability
  delay(100);
}