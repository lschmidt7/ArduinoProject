#include "ESP8266.h"
#include "Motor.h"
#include "Connection.h"
#include "Message.h"

char* command;

//motor do carro
Motor *motor = new Motor(6,7,9,8,10,11);

ESP8266 wifi(Serial1);

Connection *conn = new Connection(&wifi, 0, "arduino", "arduino", true, 8090);
Message *m = new Message(&wifi);

void setup() {
	Serial.begin(9600);
	Serial1.begin(9600);
	motor->setup();
	conn->start();
}

void loop() {
	m->receiveMsg();
	motor->setSpeed(180);
	command = m->getMessage();
	if(command[0]=='a'){
		motor->forward();
	}else if(command[0]=='d'){
		motor->right();
	}else if(command[0]=='e'){
		motor->left();
	}else{
	  motor->stop();
	}

	motor->func();
	delay(15);
}
