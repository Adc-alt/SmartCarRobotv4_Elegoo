# 🤖 Smart Robot Car V4 - Elegoo

![Elegoo Smart Robot Car V4](https://eu.elegoo.com/cdn/shop/products/SmartRobotCarV4_1_2048x2048.jpg?v=1669965874)

This repository contains three different projects for the [Elegoo Smart Robot Car V4.0](https://eu.elegoo.com/es-es/products/elegoo-smart-robot-car-kit-v-4-0), each demonstrating different functionalities of the robot car. The projects use a custom library developed specifically for this kit, with pin definitions based on the official schematic.

## 🚗 Projects Available

1. **Basic Movement** 🎮
   - Simple demonstration of basic car movements
   - Forward/backward movement
   - Left/right turns
   - Speed control
   - Perfect for getting started and testing the car's basic functions

2. **Obstacle Avoidance** 🚧
   - Autonomous navigation
   - Uses ultrasonic sensor to detect obstacles
   - Automatically changes direction when obstacles are detected
   - Demonstrates more advanced control logic

3. **Line Follower** ➰
   - Follows a black line on a white surface
   - Uses infrared sensors for line detection
   - Demonstrates sensor integration and precise movement control

## 🛠️ Custom Library

The projects use a custom-made library (`SmartRobotCarKitV4`) that simplifies the control of the robot car. The library includes:

- Pre-defined pin configurations based on the official schematic
- Easy-to-use movement functions
- Sensor integration helpers
- Motor control abstractions

### Pin Configuration
```cpp
// Motor control pins
#define MOTOR_A1 5  // Left Motor
#define MOTOR_A2 6
#define MOTOR_B1 9  // Right Motor
#define MOTOR_B2 10

// Ultrasonic sensor pins
#define ECHO_PIN 12
#define TRIG_PIN 13

// Line tracking sensor pins
#define LEFT_TRACKING_PIN A0
#define CENTER_TRACKING_PIN A1
#define RIGHT_TRACKING_PIN A2

// Servo motor pin
#define SERVO_PIN 3
```

## 🚀 Getting Started

### Prerequisites
- VS Code with PlatformIO extension installed
- Arduino Uno
- [Elegoo Smart Robot Car V4 Kit](https://eu.elegoo.com/es-es/products/elegoo-smart-robot-car-kit-v-4-0) fully assembled
- USB cable for programming

### Hardware Specifications 📋
- Input: Infrared photoelectric sensor, ultrasonic sensor, buttons
- Output: Motors, servo gimbal, LED
- Voltage: 7.2~8.4V (7.4V lithium battery pack)
- Battery life: 2 hours (line following mode)
- Distance measurement: Ultrasonic range sensor
- Motor driven: Dual channel TB6612 driver chip
- Tracking method: Infrared tracking
- Motor ratio: 1:48
- Communication: UART/WiFi
- Size: 263*145*80 mm
- Weight: 1140g

### Setup Instructions 📝

1. Clone this repository:
   ```bash
   git clone https://github.com/Adc-alt/SmartCarRobotv4_Elegoo.git
   ```

2. Open the project in VS Code with PlatformIO

3. Choose which project to run by editing `platformio.ini`:
   - Locate the environment section you want to run
   - Uncomment the desired project (remove the semicolons)
   - Make sure other projects are commented out
   - Example to run the basic movement project:
     ```ini
     [env:basic_movement]
     build_src_filter = +<projects/basic_movement/src/*>
     
     ; [env:obstacle_avoidance]
     ; build_src_filter = +<projects/obstacle_avoidance/src/*>
     
     ; [env:line_follower]
     ; build_src_filter = +<projects/line_follower/src/*>
     ```

4. Build and upload:
   - Connect your Arduino Uno to your computer
   - Click the PlatformIO Upload button or use `pio run -t upload`

## 📁 Project Structure

```
src/
├── projects/
│   ├── basic_movement/      🎮
│   │   └── src/
│   │       └── main.cpp
│   ├── obstacle_avoidance/  🚧
│   │   └── src/
│   │       └── main.cpp
│   └── line_follower/       ➰
│       └── src/
│           └── main.cpp
```

## 🔧 Components Used

![Components](https://eu.elegoo.com/cdn/shop/products/SmartRobotCarV4_4_2048x2048.jpg?v=1669965874)

- Arduino Uno
- Elegoo Smart Robot Car V4 Kit including:
  - Ultrasonic sensor for distance measurement
  - Line tracking sensors (3x IR sensors)
  - SG90 Servo motor for scanning
  - DC motors with 1:48 gear ratio
  - TB6612 motor driver board
  - 7.4V lithium battery pack

## 🤝 Contributing

Feel free to submit issues and enhancement requests! Your contributions are welcome to make this project even better.

## 🌐 Languages

### Español
[Ver instrucciones en español](#español)

### English
[View instructions in English](#english)

---

## Español
Este proyecto implementa el control de un Smart Robot Car V4 de Elegoo utilizando Arduino. El coche robot puede:
- Moverse hacia adelante de forma autónoma
- Detectar y evitar obstáculos
- Escanear el entorno utilizando un servo motor
- Tomar decisiones de navegación basadas en las lecturas del sensor ultrasónico

### Componentes
- Arduino Uno
- Kit Smart Robot Car V4 de Elegoo
- Servo Motor
- Sensor Ultrasónico
- Motores DC

### Configuración
1. Instalar PlatformIO en VS Code
2. Clonar este repositorio
3. Abrir el proyecto en PlatformIO
4. Compilar y cargar el código al Arduino

## English
This project implements the control of an Elegoo Smart Robot Car V4 using Arduino. The robot car can:
- Move forward autonomously
- Detect and avoid obstacles
- Scan the environment using a servo motor
- Make navigation decisions based on ultrasonic sensor readings

### Components
- Arduino Uno
- Elegoo Smart Robot Car V4 Kit
- Servo Motor
- Ultrasonic Sensor
- DC Motors

### Setup
1. Install PlatformIO in VS Code
2. Clone this repository
3. Open the project in PlatformIO
4. Compile and upload the code to Arduino
