#ifndef FOLLOW_H
#define FOLLOW_H

#include "Arduino.h"

class Follow{
	private:
		int sensor;
	public:
		Follow(int sensor);
		void setup();
		int read();
		int alert(int treshold);
};

#endif
