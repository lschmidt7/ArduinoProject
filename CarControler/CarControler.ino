#include "Motor.h"

//motor do carro
Motor *motor = new Motor(6,7,9,8,10,11);

void setup() {
	Serial.begin(9600);
	motor->setup();
}

void loop() {
	motor->forward();
	motor->func();
	motor->setSpeed(180);

	if(followleft->alert(ValorCorte) && followright->alert(ValorCorte)){
		m->stop();
	}else if(followright->alert(ValorCorte)){
		motor->left();
	}else if(followleft->alert(ValorCorte)){
		motor->right();
	}
	delay(15);
}
