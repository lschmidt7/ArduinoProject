/*
* Autor: Leonardo de Abreu Schmidt
*/

#include "Message.h"

Message::Message(ESP8266 *wifi){
	this->wifi = wifi;
}

void Message::sendMsg(char* msg){
  char *request = "Olá!\n";
	this->wifi->send(this->mux_id, (const uint8_t*) msg, strlen(msg));
}

void Message::receiveMsg(){
	this->len = this->wifi->recv(this->mux_id, this->buffer, sizeof(this->buffer), 1000);
}

void Message::showMsg(){
        Serial.print((char) buffer[0]);
  Serial.println();
}

char* Message::getMessage(){
  return buffer;
}
