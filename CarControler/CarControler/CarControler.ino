#include "Motor.h"
#include "Follow.h"
#include "Ultrassonic.h"

// valor de trashold dos sensores de linha
int ValorCorte = 850;

//motor do carro
Motor *motor = new Motor(6,7,9,8,10,11);

//sensor ultrassonico
Ultrassonic *ultrassonic = new Ultrassonic(A0,A1);

//sensores seguidores de linha
Follow *followleft = new Follow(A4);
Follow *followright = new Follow(A5);

void setup() {
	Serial.begin(9600);
	setupUltrasonic();
	motor->setup();
	followright->setup();
	followleft->setup();
	ultrassonic->setup();
}

void loop() {
	motor->forward();
	m->func();
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
