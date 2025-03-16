#include <Arduino.h>
#include <SmartRobotCar.h>
#include <Servo.h>


SmartRobotCar MyCar;
Servo MyServo;

//Declaration state functions
void movingForward();
void scanning();
void turningLeft();
void turningRight();
void reversing();
void stopped();

int distance;

enum CarState
{
  FORWARD,
  SCANNING,
  TURNING_LEFT,
  TURNING_RIGHT,
  REVERSING,
  STOPPED,
};

CarState currentState = FORWARD;


//Array of pointers to functions
typedef void (*StateFunction)();
StateFunction StateFunctions[] = {movingForward,scanning,turningLeft,turningRight,reversing,stopped};

void setup()
{
  Serial.begin(115200);
  MyCar.begin();
  MyCar.setSpeed(75);  // Set an initial speed
  
  distance = MyCar.getDistance();
}

 
void loop() 
{
  //Main loop 
  StateFunctions[currentState]();
  delay(100);
  
}

void movingForward() {
    MyCar.moveForward();  // Llama al método de la clase MyCar
    if (MyCar.detectObstacle()) {
        currentState = SCANNING;
    }
}

void scanning ()
{
  Serial.println("Scanning...");
  MyCar.stop();

  MyServo.write(10);
  delay(500);
  int leftDistance = MyCar.getDistance();

  MyServo.write(150);
  delay(500);  // Dar tiempo al servo para moverse
  int rightDistance = MyCar.getDistance();

  MyServo.write(90);

  currentState = (leftDistance>rightDistance) ? TURNING_LEFT:
                 (rightDistance> leftDistance) ? TURNING_RIGHT:
                 REVERSING;

}


void turningLeft() {
    MyCar.TurnLeft();
    delay(1000);
    currentState = FORWARD;
    Serial.println("⏹️ Car turning left.");
}

void turningRight() {
    MyCar.TurnRight();
    delay(1000);
    currentState = FORWARD;
    Serial.println("⏹️ Car turning right.");
}

void reversing() {
    MyCar.moveBackward();
    delay(1000);  // Dar tiempo para retroceder
    currentState = FORWARD;
    Serial.println("⏹️ Car reversing");
}

void stopped() {
    MyCar.stop();
    Serial.println("⏹️ Car stopped.");
}