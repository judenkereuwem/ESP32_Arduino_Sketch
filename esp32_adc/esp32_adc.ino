#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads(0x48);
float Intensity = 0.0;

void setup(void) {
Serial.begin(115200); 
ads.begin();
}

void loop(void){
int16_t adc0, adc1, adc2, adc3;

adc0 = ads.readADC_SingleEnded(0);
adc1 = ads.readADC_SingleEnded(1);

Serial.print("AIN0: "); 
Serial.print(adc0);
Serial.print("     AIN1: "); 
Serial.print(adc1);
Serial.println("");

delay(100);
}
