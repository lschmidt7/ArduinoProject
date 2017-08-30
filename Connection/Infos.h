#ifndef INFOS_H
#define INFOS_H

/*
* Autor: Leonardo de Abreu Schmidt
* Retorna informações de uma determinada rede
*/

#include "ESP8266.h"
#include <string.h>

class Infos {
	private:
		ESP8266 *wifi;
    int count=0;
    bool habw=false;
    bool ssidok = false;
	public:
		Infos(ESP8266 *wifi);
		String getInfoRedes();
    void intensidade(String ssid);

};

#endif
