# R3-SoftwareTraining-VictoriaBuchanan

### Link to Tinkercad
https://www.tinkercad.com/things/6qIoTWQcuCD

### Software Used

* Arduino 
* TinkerCad 

### Circuit Components

<i>Image 1 - Components used in the circuit</i>

<img src="https://github.com/SG-Command/R3-SoftwareTraining-VictoriaBuchanan/blob/main/photos/Components.JPG" width="607" height="285">

* 9V Battery
* Arduino Uno R3
* Breadboard Small
* Dip Switch SPST x 4
* H-Bridge Motor Driver (L293D Motor Drive)
* Hobby Gearmotors (2)
* Potentiometer

### Wiring

<i>Image 2 - Wiring of the completed circuit</i>

<img src="https://github.com/SG-Command/R3-SoftwareTraining-VictoriaBuchanan/blob/main/photos/Wiring.JPG" width="607" height="285">

All the red wires are positive wires and the black wires are ground. The wires for each component are color coded as follows:
* The blue wire connects the potentiometer to the analog input A0 on the Arduino.
* The green wires connect the L293D to the Arduino to control motor2.  Pin 3 controls the speed and pins 4 and 5 control the direction of the motor.
* The purple wires connect the L293D to the Arduino to control motor1.  Pin 9 controls the speed and pins 7 and 8 control the direction of the motor.
* The turquoise wires connect the dip switch to the digital pins 6, 10, 11 and 12 of the Arduino.
* The yellow wires connect the motors to the L293D. Pins 3 and 7 control motor 1 (the left wheel) and pins 11 and 14 control motor 2 (the right wheel).

### Notes about the Project
The goal of the project was to create a circuit that controlled 2 motors with a dip switch and a potentiometer. The motors should be able to move a set of wheels forwards, backwards, left and right.
