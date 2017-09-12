#ifndef ULTRASSONIC_H
#define ULTRASSONIC_H

#include "Arduino.h"

class Ultrassonic{
	private:
		int trigPin = A0;
		int echoPin = A1;
	public:
		Ultrassonic();
		Ultrassonic(int trigPin, int echoPin);
		void setup();
		long getDistance();
};

#endif
