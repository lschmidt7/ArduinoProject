#include "Ultrassonic.h"

Ultrassonic::Ultrassonic(){

}

Ultrassonic::Ultrassonic(int trigPin, int echoPin){
	this->trigPin = trigPin;
	this->echoPin = echoPin;
}

void Ultrassonic::setup(){
	pinMode(this->trigPin, OUTPUT);
	pinMode(this->echoPin, INPUT);
}

long Ultrassonic::getDistance(){
	long duration, distance;
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distance = (duration / 2) / 29.1;
	return (distance);
}

