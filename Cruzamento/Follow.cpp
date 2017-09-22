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

bool Follow::alertMax(int treshold){
	if(read()>treshold){
		return true;
	}
	return false;
}

bool Follow::alertMin(int treshold){
  Serial.println(read());
  if(read()<treshold){
    return true;
  }
  return false;
}
