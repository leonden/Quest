int pinPowerSwitch = 12;
int statusPowerSwitch = 0;
int pinIndicatorLed = 10;

void setup()
{
    pinMode(pinPowerSwitch, INPUT);
    pinMode(pinIndicatorLed, OUTPUT);
}

void loop()
{
    statusPowerSwitch.digitalRead(pinPowerSwitch);

    if (statusPowerSwitch == HIGH) {
      digitalWrite(pinIndicatorLed, HIGH);
    }
}