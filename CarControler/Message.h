#ifndef MESSAGE_H
#define MESSAGE_H

/*
* Autor: Leonardo de Abreu Schmidt
*/

#include "ESP8266.h"

class Message {
	private:
		ESP8266 *wifi;
		uint8_t buffer[128] = {0};
		uint32_t len = 0;
  	uint8_t mux_id = 0;
	public:
		Message(ESP8266 *wifi);
		void sendMsg(char* msg);
		void receiveMsg();
		void showMsg();
    char* getMessage();
};

#endif
