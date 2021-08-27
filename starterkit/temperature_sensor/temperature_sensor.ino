const int SENSOR_PIN = A0;
float baseTemp = 0.0;
float minSensorVal = 1023.0;
float maxSensorVal = 0.0;

void setup() {
  Serial.begin(9600);
  for(int i = 3; i < 6; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int sensorVal = analogRead(SENSOR_PIN);
  Serial.print("sensor value: ");
  Serial.println(sensorVal);
   
  if(millis() < 3000) {
     // set up base temperature 
     maxSensorVal = max(maxSensorVal, sensorVal);    
     minSensorVal = min(minSensorVal, sensorVal);
     baseTemp = ((5.0/1023.0 * ( (maxSensorVal + minSensorVal) / 2) ) - 0.5) * 100;
  }else {
     // sensorVal ranges 0-1023
     float volts = 5.0/1023.0 * sensorVal;
     Serial.print(" volts: ");
     Serial.print(volts);
     
     // scale factor 10C/mV with offset 0.5V to account for negative value
     // E,g. 0C : 0.5V, 1C : 0.51V, etc. 
     float temp = (volts - 0.5) * 100;
     Serial.print(" tempature: ");
     Serial.print(temp);  

     float diff = temp - baseTemp;
     Serial.print(" diff: ");
     Serial.println(diff);
     
     if(diff >= 4) {
        digitalWrite(3, HIGH); 
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH); 
     }else if(diff >= 3 && diff < 4) {
        digitalWrite(3, HIGH); 
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);      
     }else if(diff >= 2 && diff < 3) {
        digitalWrite(3, HIGH); 
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);      
     }else {
        for(int i = 3; i < 6; i++) {
          digitalWrite(i, LOW);
        }
     }
  }

  // small delay in order for ADC to read in properly
  delay(1);
}
