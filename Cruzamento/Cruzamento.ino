#include "ESP8266.h"
#include "Motor.h"
#include "Connection.h"
#include "Message.h"
#include "Follow.h"

bool waiting = false;
bool started = false;
bool crossing = false;

char* command;

ESP8266 wifi(Serial1);

Connection *conn = new Connection(&wifi, 0, "dlink-4", "abcd1234", true, 8090);
Message *m = new Message(&wifi);

// valor de trashold dos sensores de linha
int ValorCorte = 850;
int ValorMin = 165;

//motor do carro
Motor *motor = new Motor(6,7,9,8,10,11);

//sensor ultrassonico
//Ultrassonic *ultrassonic = new Ultrassonic(A0,A1);

//sensores seguidores de linha
Follow *followmiddle = new Follow(A3);
Follow *followleft = new Follow(A4);
Follow *followright = new Follow(A5);

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  motor->setup();
  followright->setup();
  followleft->setup();
  followmiddle->setup();
  conn->start();
  delay(2000);
  Serial.println("Iniciando");
  //ultrassonic->setup();
}

void loop() {
  if(!started){
      m->receiveMsg();
      //m->showMsg();
      command = m->getMessage();
      if(command[0]=='s'){
        started = true;
      }
  }else{
    if(followright->alertMax(ValorCorte) and followmiddle->alertMax(ValorCorte) and followleft->alertMax(ValorCorte) and !waiting and !crossing){
      motor->stop();
      m->sendMsg("P\n");
      waiting = true;
    }
  
    if(waiting){
        m->receiveMsg();
        //m->showMsg();
        command = m->getMessage();
        if(command[0]=='L'){
          waiting=false;
          crossing = true;
        }
    }else{
      motor->forward();
      motor->func();
      motor->setSpeed(180);
        if(followright->alertMax(ValorCorte)){
          crossing=false;
          motor->left();
        }else if(followleft->alertMax(ValorCorte)){
          crossing=false;
          motor->right();
        }
    }
  }
  delay(15);
}
