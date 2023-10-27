
const int buttonPin = 33;
const int LED = 2;
byte LEDState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

}

void loop() {
  int button = digitalRead(buttonPin);
  Serial.print("Button: ");
  Serial.print(button);
  Serial.print("   LED: ");
  Serial.println(LEDState);
  

  if ((button == 0) && (LEDState == LOW)){
    LEDState = HIGH;
    digitalWrite(LED, LEDState);
  }

  else if ((button == 0) && (LEDState == HIGH)){
    LEDState = LOW;
    digitalWrite(LED, LEDState);
  }
  
  delay(1000);
}
