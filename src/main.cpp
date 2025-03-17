

#include <Arduino.h>
#include <SmartRobotCar.h>

SmartRobotCar MyCar;

void setup()
{
  Serial.begin(115200);
  MyCar.begin();
  MyCar.setSpeed(75);  // Velocidad inicial / Initial speed
}
 
void loop() 
{
  MyCar.updateState();
  delay(100);
}