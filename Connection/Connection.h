#ifndef CONNECTION_H
#define CONNECTION_H

/*
* Autor: Leonardo de Abreu Schmidt
*/

#include "ESP8266.h"
#include <string.h>

class Connection {
	private:
		ESP8266 *wifi;
		String SSID = "dlink-4";
		String PASSWORD = "abcd1234";
		int HOST_PORT = (8090);
		int mode;
		bool MUX;
	public:
		Connection(ESP8266 *wifi, int mode, String SSID, String PASSWORD, bool MUX, int HOST_PORT);
		void start();
		char* getFirmwareVersion();
		void setMode(int mode); // 0 - Station, 1 - AP
		void join();
		void enableMux();
		void startServerTCP();
};

#endif
