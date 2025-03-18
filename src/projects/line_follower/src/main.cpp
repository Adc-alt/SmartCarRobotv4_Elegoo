#include <Arduino.h>
#include <SmartRobotCar.h>

SmartRobotCar MyCar;

// Pines para los sensores IR / IR sensor pins
const int PIN_IR_LEFT = A0;    // Sensor IR izquierdo / Left IR sensor
const int PIN_IR_RIGHT = A1;   // Sensor IR derecho / Right IR sensor

void setup()
{
  Serial.begin(115200);
  MyCar.begin();
  MyCar.setSpeed(60);  // Velocidad más baja para seguimiento de línea / Lower speed for line following
  
  // Configurar pines de sensores IR / Setup IR sensor pins
  pinMode(PIN_IR_LEFT, INPUT);
  pinMode(PIN_IR_RIGHT, INPUT);
}
 
void loop() 
{
  // Leer sensores IR / Read IR sensors
  int leftValue = analogRead(PIN_IR_LEFT);
  int rightValue = analogRead(PIN_IR_RIGHT);

  // Imprimir valores de sensores / Print sensor values
  Serial.print("📊 IR Izquierdo / Left IR: ");
  Serial.print(leftValue);
  Serial.print(" | IR Derecho / Right IR: ");
  Serial.println(rightValue);

  // Lógica de seguimiento de línea / Line following logic
  if (leftValue > 500 && rightValue > 500) {
    // Ambos sensores detectan línea / Both sensors detect line
    MyCar.moveForward();
    Serial.println("🚗 Adelante / Forward");
  }
  else if (leftValue > 500) {
    // Solo sensor izquierdo detecta línea / Only left sensor detects line
    MyCar.TurnLeft();
    Serial.println("↪️ Izquierda / Left");
  }
  else if (rightValue > 500) {
    // Solo sensor derecho detecta línea / Only right sensor detects line
    MyCar.TurnRight();
    Serial.println("↩️ Derecha / Right");
  }
  else {
    // Ningún sensor detecta línea / No sensor detects line
    MyCar.stop();
    Serial.println("⏹️ Detenido / Stopped");
  }

  delay(100);  // Pequeña pausa / Small pause
} 