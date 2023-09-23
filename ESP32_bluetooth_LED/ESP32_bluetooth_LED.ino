
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

char blueVal;

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  //signal from mobile
  if (SerialBT.available()) {
    blueVal = SerialBT.read();
    Serial.write(blueVal);
  }

  if (blueVal == '1') {
    digitalWrite(2, HIGH);
    Serial.println("LED on");
  } 
  if (blueVal == '0') {
    digitalWrite(2, LOW);
    Serial.println("LED off");
  }

  //signal from Serial monitor
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
}
