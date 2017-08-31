/*
* Autor: Leonardo de Abreu Schmidt
*/

#include "Message.h"

Message::Message(ESP8266 *wifi){
	this->wifi = wifi;
}

void Message::sendMsg(char* msg){
	this->wifi->send(this->mux_id, (const uint8_t*) msg, strlen(msg));
}

void Message::receiveMsg(){
	this->len = this->wifi->recv(this->mux_id, this->buffer, sizeof(this->buffer), 1000);
}

void Message::showMsg(){
	for(uint32_t i = 0; i < len; i++) {
        Serial.print((char) buffer[i]);
    }
}
