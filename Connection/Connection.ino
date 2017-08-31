#include "ESP8266.h"
//#include <NewPing.h>
#include <string.h>
#include "Connection.h"
#include "Infos.h"
#include "Message.h"

//#define CH_PD 44
//#define RST 46
//#define GPIO0 48

ESP8266 wifi(Serial1);

Connection *conn = new Connection(&wifi, 0, "dlink-4", "abcd1234", true, 8090);
Infos *inf = new Infos(&wifi);
Message *m = new Message(&wifi);

void setup(void)
{
	Serial.begin(9600);
	Serial1.begin(9600);

	Serial.println("Iniciando Setup.");
	conn->start();
  inf->intensidade("dlink-4");
	Serial.println("Setup finalizado!");
}

void loop(void) {
  if(Serial.read()=='P'){
    inf->intensidade("dlink-4");
  }
  if(Serial.read()=='L'){
    m->sendMsg("Olá\n");
    delay(100);
  }
}



