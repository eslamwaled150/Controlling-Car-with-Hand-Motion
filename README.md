# Controlling Car with Hand Motion

## Project Overview
This project aims to control a car's direction and speed using hand or finger motions. It involves two main modules: the Hand Module and the Car Module.

## System Description
- The Hand Module detects finger postures and sends updates to the controller.
- The Car Module interprets finger postures to control the car's movement.
- Thumb posture determines the speed of the motors.

## Car Module
![Car Module](https://github.com/eslamwaled150/Controlling-Car-with-Hand-Mtion/assets/92927283/7e673388-79cd-4c2b-a465-1c7d3b0d845f)

## Hand Module
![Hand Module](https://github.com/eslamwaled150/Controlling-Car-with-Hand-Mtion/assets/92927283/af657817-adb5-4b69-9959-e4bdcee19e34)

## Specifications
### Flexible Sensor & BT Module
- Each finger has an individual sensor.
- Motion of fingers is detected and used to control the car's motors.

### L293D, BT Module, LCD
- BT Module receives finger postures and activates motor direction via L293D.
- LCD displays the current direction of the car.

## Software
- Proteus Simulator
- Microchip Studio

## Hardware
1. **ATMEGAxx or ATTINYxx** for hand module.
2. 5x **Flexible Sensors**.
3. **Gloves & Wires**.
4. 2x **Battery 3.7 V**.
5. **LM7805 voltage regulator, 2x 22uf capacitor**.
6. 2x **HC-05**.
7. **L293D**.
8. **Motors**.
9. **Caster Wheel**.
10. **Chassis**

![Chassis](https://github.com/eslamwaled150/Controlling-Car-with-Hand-Mtion/assets/92927283/aaf7de2a-a806-45e7-8e4a-baa1c20b60d7)

## How to Use
1. Assemble the hardware components according to the provided diagram.
2. Install the necessary software tools.
3. Upload the appropriate code to the microcontrollers.
4. Wear the gloves with the attached sensors.
5. Use hand motions to control the car's direction and speed.

## Notes
- Ensure proper wiring and connections to avoid malfunctions.
- Adjust sensitivity and responsiveness settings as needed for optimal performance.
