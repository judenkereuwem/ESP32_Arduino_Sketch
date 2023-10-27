#include <IRremoteESP8266.h>
#include <IRrecv.h>

IRrecv irrecv(19);
decode_results results;

const int led = 2;

void setup(){
  Serial.begin(115200);
  irrecv.enableIRIn();
  pinMode(led, OUTPUT);
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);

        if(results.value == 0xFF6897){
          digitalWrite(led, HIGH);
        }else if(results.value == 0xFFB04F){
          digitalWrite(led, LOW);
        }
        
        delay(1000);
        irrecv.resume();
  }
}
