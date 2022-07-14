void setup() {
  pinMode(51, OUTPUT);
  pinMode(50, OUTPUT);
  Serial.begin(115200);
    digitalWrite(51, HIGH);
    Serial.print("atmega esp connection");
}
void loop() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '1') {
      digitalWrite(51, HIGH);
    }
    else if (inChar == '0') {
      digitalWrite(51, LOW);
    }
    if (inChar == '3') {
      digitalWrite(51, HIGH); 
    }
    else if (inChar == '2') {
      digitalWrite(51, LOW);
    }
    if (inChar == '9') {
      digitalWrite(51, LOW);
      digitalWrite(51, LOW);
    }
  }
}
