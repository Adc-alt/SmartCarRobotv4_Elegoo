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
  // Demostración de movimientos básicos / Basic movements demonstration 
  Serial.println("🚗 Moviendo hacia adelante / Moving forward");
  MyCar.moveForward();
  delay(2000);

  Serial.println("⏹️ Deteniendo / Stopping");
  MyCar.stop();
  delay(1000);

  Serial.println("↪️ Girando a la izquierda / Turning left");
  MyCar.TurnLeft();
  delay(1000);

  Serial.println("↩️ Girando a la derecha / Turning right");
  MyCar.TurnRight();
  delay(1000);

  Serial.println("⬅️ Moviendo hacia atrás / Moving backward");
  MyCar.moveBackward();
  delay(2000);

  Serial.println("⏹️ Deteniendo / Stopping");
  MyCar.stop();
  delay(2000);
}