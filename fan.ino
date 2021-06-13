#include <M5StickC.h>
#include "BluetoothSerial.h"


float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32");
  M5.begin();
  M5.IMU.Init();
  
}
 
void loop() {
  M5.update();
  M5.IMU.getAccelData(&accX, &accY, &accZ);
  SerialBT.printf("%5.2f,%5.2f,%5.2f\n", accX, accY, accZ);
  delay(10);
}
