const int redSensorPin = A3;
const int greenSensorPin = A4;
const int blueSensorPin = A5;

const int redLightPin = 9;
const int greenLightPin = 11;
const int blueLightPin = 10;

int redSensorVal = 0;
int greenSensorVal = 0;
int blueSensorVal = 0;

int redVal = 0;
int greenVal = 0;
int blueVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(redLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  pinMode(blueLightPin, OUTPUT);
}

void loop() {
  // ADC takes 1 ms to read*
  redSensorVal = analogRead(redSensorPin);
  delay(5);
  greenSensorVal = analogRead(greenSensorVal);
  delay(5);
  blueSensorVal = analogRead(blueSensorPin);

  Serial.print("redSensorVal: ");
  Serial.print(redSensorVal);
  Serial.print(" greenSensorVal: ");
  Serial.print(greenSensorVal);
  Serial.print(" blueSensorVal: ");
  Serial.println(blueSensorVal);
  
  // Map RGB value to 0 - 255
  redVal = redSensorVal/4;
  greenVal = greenSensorVal/4;
  blueVal = blueSensorVal/4;  

  analogWrite(redLightPin, redVal);
  analogWrite(greenLightPin, greenVal);
  analogWrite(blueLightPin, blueVal);

  Serial.print("red: ");
  Serial.print(redVal);
  Serial.print(" green: ");
  Serial.print(greenVal);
  Serial.print(" blue: ");
  Serial.println(blueVal);
}
