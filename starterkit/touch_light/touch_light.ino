const int sensorPin = A5;
const int lightPin = 8;
int sensorVal = 0;
int lastSensorVal = 0;
int maxSensorVal = 0;
bool switchOn = false;
int lastTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(lightPin, OUTPUT);  
}

void loop() {
  sensorVal = analogRead(sensorPin);
  
  if(switchOn){
    digitalWrite(lightPin, HIGH);
  }else{
    digitalWrite(lightPin, LOW);
  }
  
  if(sensorVal >= lastSensorVal + 4) {
    switchOn = !switchOn;
  }
   
  lastSensorVal = sensorVal;
  Serial.print("sensorVal: ");
  Serial.println(sensorVal);
  
  // ADC takes 1 ms to read
  delay(1);
}
