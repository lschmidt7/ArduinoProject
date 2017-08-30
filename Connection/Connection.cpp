/*
* Autor: Leonardo de Abreu Schmidt
*/

#include "Connection.h"

Connection::Connection(ESP8266 *wifi, int mode, String SSID, String PASSWORD, bool MUX, int HOST_PORT){
	this->wifi = wifi;
	this->mode = mode;
	this->SSID = SSID;
	this->PASSWORD = PASSWORD;
	this->MUX = MUX;
	this->HOST_PORT=(HOST_PORT);
}

String Connection::getFirmwareVersion(){
	return this->wifi->getVersion().c_str();
}

void Connection::setMode(int mode){
	if(mode == 0){
		if (this->wifi->setOprToStationSoftAP()) {
		    Serial.println("Station e AP: OK");
		} else {
		    Serial.println("Erro em setar Station e AP.");
		}
	}
}

void Connection::join(){
	if (this->wifi->joinAP(this->SSID, this->PASSWORD)) {
	    Serial.println("Conexão: OK");
	    Serial.print("IP: ");
	    // rotina wifi.getLocalIP() retorna o IP usado na conexao com AP conectada.
	    Serial.println(this->wifi->getLocalIP().c_str());
	} else {
		Serial.println("Falha na conexao AP.");
	}
}

void Connection::enableMux(){
	if (this->wifi->enableMUX()) {
	    Serial.println("Multiplas conexoes: OK.");
	} else {
	    Serial.println("Erro ao setar multiplas conexoes.");
	}
}

void Connection::startServerTCP(){
	if (this->wifi->startTCPServer(this->HOST_PORT)) {
	    // if (wifi.startServer(HOST_PORT)) {
	    Serial.println("Servidor: OK");
	} else {
	    Serial.println("Erro ao iniciar servidor.");
	}
}
