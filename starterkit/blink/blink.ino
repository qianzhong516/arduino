int switchState;
bool blinkState = false;
unsigned long now;
unsigned long lastTime = 0;

void setup() {
  // open the serial port at 9600 bps:
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);
  now = millis();
  
  if(switchState == HIGH) {
    // Ignore extra connecting time when pressing down within 0.5 second
    if(now - lastTime > 500) {
      blinkState = !blinkState;
      lastTime = now;
      Serial.println(blinkState);  
    }
  }

  if(!blinkState) {
    // init state
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }else {
    // blink effect
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    delay(200);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(200);
    digitalWrite(5, LOW);
    delay(200);    
  }
}
