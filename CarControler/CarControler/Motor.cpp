
#include "Motor.h"

Motor::Motor(int IN1,int IN2,int IN3,int IN4,int ENA,int ENB){
	this->IN1 = IN1;
	this->IN2 = IN2;
	this->IN3 = IN3;
	this->IN4 = IN4;
	this->ENA = ENA;
	this->ENB = ENB;
}

void Motor::setup(){
	pinMode(this->IN1, OUTPUT);
	pinMode(this->IN2, OUTPUT);
	pinMode(this->IN3, OUTPUT);
	pinMode(this->IN4, OUTPUT);
	pinMode(this->ENA, OUTPUT);
	pinMode(this->ENB, OUTPUT);
}

void Motor::forward(){
	analogWrite(this->ENA, this->speed);
	analogWrite(this->ENB, this->speed);
	digitalWrite(this->IN1, LOW);
	digitalWrite(this->IN3, LOW);
	digitalWrite(this->IN2, HIGH);
	digitalWrite(this->IN4, HIGH);
}

void Motor::stop(){
	analogWrite(this->ENA, this->speed);
	analogWrite(this->ENB, this->speed);
	digitalWrite(this->IN1, LOW);
	digitalWrite(this->IN3, LOW);
	digitalWrite(this->IN2, LOW);
	digitalWrite(this->IN4, LOW);
}

void Motor::right(){
	analogWrite(this->ENA, this->speed);
	analogWrite(this->ENB, this->speed);
	digitalWrite(this->IN2, LOW);
	digitalWrite(this->IN1, HIGH);
	digitalWrite(this->IN3, LOW);
	digitalWrite(this->IN4, HIGH);
}

void Motor::left(){
	analogWrite(this->ENA, this->speed);
	analogWrite(this->ENB, this->speed);
	digitalWrite(this->IN1, LOW);
	digitalWrite(this->IN3, HIGH);
	digitalWrite(this->IN4, LOW);
	digitalWrite(this->IN2, HIGH);
}

void Motor::back(){

}

void Motor::func(){
	analogWrite(this->ENA, this->speed);
	analogWrite(this->ENB, this->speed);
}

void Motor::setSpeed(long speed){
	this->speed = speed;
	if (speed < 0) {
		this->speed = 0;
	}
	if (speed > 220) {
		this->speed = 220;
	}
}