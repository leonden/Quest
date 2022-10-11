int ignitionSwitch = 12;
int ledRed = 10;
int ledGreen = 8;
int readIgnitionSwitch = 0;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ignitionSwitch, INPUT_PULLUP);
}

void loop() {

  digitalWrite(ledGreen, HIGH);
  readIgnitionSwitch = digitalRead(ignitionSwitch);

  if (readIgnitionSwitch == LOW && count == 0) {
    for (int i = 1; i <= 10; i++) {
      digitalWrite(ledRed, HIGH);
      delay(500);
      digitalWrite(ledRed, LOW);
      delay(500);
      readIgnitionSwitch = digitalRead(ignitionSwitch);
      if (readIgnitionSwitch == HIGH) {
        digitalWrite(ledRed, LOW);
        break;
      }
    }
    count++;
  } else if (readIgnitionSwitch == HIGH) {
    count = 0;
  }
}