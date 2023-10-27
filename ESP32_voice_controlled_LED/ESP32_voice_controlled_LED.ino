

// Define 4 channel relay pins
const int BLUE_LIGHT = 25; 
const int RED_LIGHT  = 27; 
  

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


void setup() {
  
  Serial.begin(115200);
  SerialBT.begin("ESP32_HOME");
  Serial.println("You can pair it with bluetooth!");
  pinMode(BLUE_LIGHT, OUTPUT);
  pinMode(RED_LIGHT, OUTPUT);

  digitalWrite(BLUE_LIGHT, LOW);
  digitalWrite(RED_LIGHT, LOW);
}

void loop() {

  String data="";
  char ch;

  while (SerialBT.available())  
    { ch = SerialBT.read(); 
      data=data+ch;
    }
   Serial.println(data);
   

    // Blue light
    if ((data == "turn on blue light")||(data == "turn on blue lights")){
      digitalWrite(BLUE_LIGHT, HIGH);
      delay(200);
    }

    else if ((data == "turn off blue light")||(data == "turn off blue lights")){
      digitalWrite(BLUE_LIGHT, LOW);
      delay(200);
    }  

    
    // Red light 
    if ((data == "turn on red light")||(data == "turn on red lights")){
      digitalWrite(RED_LIGHT, HIGH);
      delay(200);
    }

    else if ((data == "turn off red light")||(data == "turn off red lights")){
      digitalWrite(RED_LIGHT, LOW);
      delay(200);
    } 


    // All light 
    if ((data == "turn on all light")||(data == "turn on all lights")){
      digitalWrite(BLUE_LIGHT, HIGH);
      digitalWrite(RED_LIGHT, HIGH);
      delay(200);
    }

    else if ((data == "turn off all light")||(data == "turn off all lights")){
      digitalWrite(BLUE_LIGHT, LOW);
      digitalWrite(RED_LIGHT, LOW);
      delay(200);
    }
}
