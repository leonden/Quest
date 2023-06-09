#include <RCSwitch.h> 

int ignitionSwitch = 12;
int ledRed = 10;
int ledGreen = 8;
int readIgnitionSwitch = 0;
int count = 0;
//int Sender = X Richtigen Wert einführen

RCSwitch Sender = RCSwitch();

void setup() {
  Serial.begin(9600);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ignitionSwitch, INPUT_PULLUP);

  Sender.enableTransmit(6);
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
      count++;
    }

    if (count == 10) {
      Sender.send(6969, 24); 
      Serial.println("Signal sent successfully");
      delay(1500); 
      }
 
  } else if (readIgnitionSwitch == HIGH) {
    count = 0;
  }
}