#include "ESP8266.h"
#include "Motor.h"
#include "Connection.h"
#include "Message.h"
#include "Follow.h"

char* command;

bool pass = false;

//motor do carro
Motor *motor = new Motor(6,7,9,8,10,11);

//sensores seguidores de linha
Follow *followmiddle = new Follow(A3);
Follow *followleft = new Follow(A4);
Follow *followright = new Follow(A5);

ESP8266 wifi(Serial1);

int ValorCorte = 850;

Connection *conn = new Connection(&wifi, 0, "dlink-4", "abcd1234", true, 8090);
Message *m = new Message(&wifi);

void setup() {
	Serial.begin(9600);
	Serial1.begin(9600);
	motor->setup();
	conn->start();
  followright->setup();
  followleft->setup();
  followmiddle->setup();
}

void loop() {
	m->receiveMsg();
  m->showMsg();
  m->sendMsg("passar");
  motor->func();
	motor->setSpeed(220);
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
 
	delay(15);
}
