# Controlling Car with Hand Motion

## Project Overview
This project aims to control a car's direction and speed using hand or finger motions. It involves two main modules: the Hand Module and the Car Module.

## System Description
- The Hand Module detects finger postures and sends updates to the controller.
- The Car Module interprets finger postures to control the car's movement.
- Thumb posture determines the speed of the motors.

## Car Module
![image](https://github.com/eslamwaled150/Controlling-Car-with-Hand-Motion/assets/92927283/b4cccb54-d615-4613-82a9-a17d90ad2d39)


## Hand Module
![image](https://github.com/eslamwaled150/Controlling-Car-with-Hand-Motion/assets/92927283/971b451c-b254-4702-b102-e904c3d2acc6)


## Specifications
### Flexible Sensor & BT Module
- Each finger has an individual sensor to control the car's direction and speed.
- Motion of fingers is detected and used to control the car's motors.

### L293D, BT Module, LCD
- BT Module receives finger postures and activates motor direction via L293D.
- LCD displays the current direction of the car & its speed.

## Software
- Proteus Simulator
- Microchip Studio

## Hardware
1. **ATMEGA32** for car module & **ATMEGA32** for hand module.
2. 5x **Flexible Sensors**.
3. **Gloves & Wires**.
4. 2x **Battery 3.7 V**.
5. **LM7805 voltage regulator, 2x 22uf capacitor**.
6. 2x **HC-05**.
7. **L293D**.
8. **Motors**.
9. **Caster Wheel**.
10. **Chassis**

![image](https://github.com/eslamwaled150/Controlling-Car-with-Hand-Motion/assets/92927283/efad24b6-7abf-4ec4-b1ce-3e5fa84eeaf3)

## How to Use
1. Assemble the hardware components according to the provided diagram.
2. Install the necessary software tools.
3. Upload the appropriate code to the microcontrollers.
4. Wear the gloves with the attached sensors.
5. Use hand motions to control the car's direction and speed.

## Notes
- Ensure proper wiring and connections to avoid malfunctions.
- Adjust sensitivity and responsiveness settings as needed for optimal performance.
