int sensorPin = A0;

int redLED = 8;
int yellowLED = 9;
int greenLED = 10;

int value = 0;

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  value = analogRead(sensorPin);

  Serial.println(value);

  // turn everything off first
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  // map potentiometer (0–1023) to your ranges
  if(value >= 0 && value <= 340)
  {
    digitalWrite(redLED, HIGH);
  }
  else if(value > 340 && value <= 680)
  {
    digitalWrite(yellowLED, HIGH);
  }
  else
  {
    digitalWrite(greenLED, HIGH);
  }

  delay(100);
}