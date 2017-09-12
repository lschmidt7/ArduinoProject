#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

class Motor{
	private:
		int IN1 = 6; // grey 
		int IN2 = 7; // violet
		int IN3 = 9; // blue 
		int IN4 = 8; // green
		int ENA = 10; // green
		int ENB = 11; // orange
		long speed=180;
	public:
		Motor();
		Motor(int IN1,int IN2,int IN3,int IN4,int ENA,int ENB);
		void setup();
		void forward();
		void stop();
		void right();
		void left();
		void back();
		void func();
};

#endif
