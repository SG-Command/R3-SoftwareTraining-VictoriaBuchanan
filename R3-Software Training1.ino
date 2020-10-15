// Variables for motor1 - assumes motor 1 is for the left wheel
const int speed1 = 9; // Pin to control speed
const int in1 = 8; // Pin to control direction
const int in2 = 7;// Pin to control direction
// Variables for motor2 - assumes motor 2 is for the right wheel
const int speed2 = 3; // Pin to control speed
const int in3 = 5; // Pin to control direction
const int in4 = 4; // Pin to control direction
// Variables for the potentiometer
const int potentiometer = A0;
int motorPWM = 0;
// Variables for the dip switch
const int dip1 = 6; //When activated turns the car left
const int dip2 = 12; //When activated moves the car forwards
const int dip3 = 11; // When activated moves the car backwards
const int dip4 = 10; // When activated turns the car right

void setup()
{
	// Initializes the serial port
	Serial.begin(9600);
  	// Sets up all the control pins motor1
  	pinMode(speed1, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    // Sets up all the control pins motor2
    pinMode(speed2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
  	// Sets up all the pins for the dip switch
  	pinMode(dip1, INPUT_PULLUP);
  	pinMode(dip2, INPUT_PULLUP);
  	pinMode(dip3, INPUT_PULLUP);
  	pinMode(dip4, INPUT_PULLUP);
 	
  	// Ensures the motor is stopped in the initial state
  	stopMotor();


}

void loop()
{
  	// Reads the value from the potentiometer
  	int pot = analogRead(potentiometer);
  	motorPWM = map(pot,1023,0,1,255);
  	// Reads the values from the dip switch
  	int dip1State = digitalRead(dip1);
  	int dip2State = digitalRead(dip2);
  	int dip3State = digitalRead(dip3);
  	int dip4State = digitalRead(dip4);
  	// The dip switch determines whether the rover turns left (dip1), forwards (dip2), backwards (dip3) and turns right (dip4)
  	// Because of the way I structured the if statement the dip switch farthest to the left will take precedence over the others
  	// (i.e if both dip1 and dip4 are active the car will turn left even if dip4 was activated later).
  	if (dip1State ==1 && dip2State ==1 && dip3State ==1 && dip4State ==1){
		stopMotor();
    } else if(dip1State == 0){
		turnLeft(motorPWM);
    }else if(dip4State ==0){
    	turnRight(motorPWM);
    }else if(dip2State == 0) {
    	moveForward(motorPWM);
    } else if(dip3State ==0){
    	moveBackward(motorPWM);
    }
}

// FUNCTIONS TO MOVE THE ROVER
void moveForward(int motorPWM)
{
  	// Sets motors to a speed based on the potentiometer value
  	analogWrite(speed1, motorPWM);
  	analogWrite(speed2, motorPWM);
  
  	//Moves motors 1 and 2 forwards
  	digitalWrite(in1, HIGH);
  	digitalWrite(in2, LOW);
  	digitalWrite(in3, HIGH);
  	digitalWrite(in4, LOW);
}

void moveBackward(int motorPWM)
{
  	// Sets motors to a speed based on the potentiometer value
  	analogWrite(speed1, motorPWM);
  	analogWrite(speed2, motorPWM);
  
  	//Turn on motors 1 and 2 backwards
  	digitalWrite(in1, LOW);
  	digitalWrite(in2, HIGH);
  	digitalWrite(in3, LOW);
  	digitalWrite(in4, HIGH);
}

void stopMotor()
{
	// Turns off motors
  	digitalWrite(in1, LOW);
  	digitalWrite(in2, LOW);
  	digitalWrite(in3, LOW);
  	digitalWrite(in4, LOW);
}

void turnLeft(int motorPWM)
{
  	// Sets motor speed based on the potentiometer value
  	analogWrite(speed1, motorPWM);
  	analogWrite(speed2, motorPWM);
  	//To turn left we want the right wheels moving forward and the left wheels moving backwards at the same speed
  	// Motor 2 (right wheel) - moving forward
  	digitalWrite(in3, HIGH);
  	digitalWrite(in4, LOW);	
  	// Motor 1 (left wheel) - moving backwards
  	digitalWrite(in1, LOW);
  	digitalWrite(in2, HIGH);

}

void turnRight(int motorPWM)
{
  	// Sets motor speed based on the potentiometer value
  	analogWrite(speed1, motorPWM);
  	analogWrite(speed2, motorPWM);
  	//To turn right we want the left wheels moving forward and the right wheels moving backwards at the same speed
  	// Motor 2 (right wheel) - moving backwards
  	digitalWrite(in3, LOW);
  	digitalWrite(in4, HIGH);		
  	// Motor 1 (left wheel) - moving forwards
  	digitalWrite(in1, HIGH);
  	digitalWrite(in2, LOW);
}