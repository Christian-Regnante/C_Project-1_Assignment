/*
====================================================
 Smart Distance Guidance Indicator System
====================================================

 Sensor:
 - Ultrasonic Distance Sensor

 Controller:
 - Arduino Uno

 Actuator:
 - RGB LED

 Function:
 - Green  : Object is close
 - Yellow : Object is medium distance
 - Red    : Object is far
 - White  : Object is out of monitoring range

====================================================
*/

int cm = 0;

// RGB LED pins
const int redPin = 10;
const int greenPin = 8;
const int bluePin = 9;

/*
  Reads distance from ultrasonic sensor
*/
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin, LOW);

  pinMode(echoPin, INPUT);

  return pulseIn(echoPin, HIGH);
}

/*
  Turns off all LED colors
*/
void turnOffLED()
{
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

void setup()
{
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  // Read distance in centimeters
  cm = 0.01723 * readUltrasonicDistance(7, 7);

  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.println(" cm");

  turnOffLED();

  // Close distance
  if(cm >= 0 && cm <= 112)
  {
    digitalWrite(greenPin, HIGH);
  }

  // Medium distance
  else if(cm > 113 && cm <= 224)
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
  }

  // Far distance
  else if(cm > 225 && cm <= 335.9)
  {
    digitalWrite(redPin, HIGH);
  }

  // Out of range
  else
  {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  }

  delay(100);
}