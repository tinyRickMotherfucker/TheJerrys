/*
	Library for initializing Jerry bot
	Needs two motors before bot can be contstructed
	First 4 pins are motor 1 and next 4 pins are motor 2
	---------------------------------------------------------
	Care has to be taken with the speed
	Motors use approximately 1A each at 100 rpm and .5A at 200 rpm
	150rpm is a good balance of speed and torque



*/
#include "Arduino.h"
#include "Stepper.h"
#ifndef Jerry_h
#define Jerry_h



class Jerry {
	public:
		//Constructors
		Jerry(int steps_revolution, int motor1_1, int motor1_2, int motor1_3, int motor1_4, int motor2_1, int motor2_2, int motor2_3, int motor2_4);
		//void setSensors(int sensor_echo1, int sensor_trigger1, int sensor_echo2, int sensor_trigger2, int sensor_echo3, int sensor_trigger3);
		//void setSwitches(int switches[4]);
		void moveForward(int number_of_steps);
		void turnRight();
		void turnLeft();
		void turnAround();
		//set speed
		void setSpeed(int speed);
		//turn angle
		void setTurnAngle(int angle_in_steps);
		void setDebug(bool choice);
		void setTurnSpeed(int turn_speed);
		void initializeSwitches(int switch1, int switch2, int switch3, int switch4);
		int readSwitches();



	private:
		Stepper _motorLeft;
		Stepper _motorRight;
		int _speed;
		int _turnAngle;
		int _motor1_1;
		int _motor1_2;
		int _motor1_3;
		int _motor1_4;
		int _motor2_1;
		int _motor2_2;
		int _motor2_3;
		int _motor2_4;
		int _turnSpeed;
		int _switches[4];
		int _switch_value;
		void motorsOff();
		void leftMotorOff();
		void rightMotorOff();
		bool _debug;
		int _steps_per_revolution;
};



#endif