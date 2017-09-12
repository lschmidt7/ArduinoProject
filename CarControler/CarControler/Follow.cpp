pinMode(sensorLinhaEsq, INPUT);

#include "Follow.h"

Follow::Follow(int sensor){
	this->sensor = sensor;
}

void Follow::setup(){
	pinMode(this->sensor, INPUT);
}

int Follow::read(){
	return analogRead(this->sensor);
}

bool Follow::alert(int treshold){
	if(read()>treshold){
		return true;
	}
	return false;
}