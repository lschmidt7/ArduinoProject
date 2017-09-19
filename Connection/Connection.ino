#include "ESP8266.h"
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
long value;
char buffer2[4];
void setup()
{
	Serial.begin(9600);
	Serial1.begin(9600);

	Serial.println("Iniciando Setup.");
	conn->start();
  //inf->intensidade("dlink-4");
	Serial.println("Setup finalizado!");
}

void loop(void) {
  value = Serial.parseInt();
  if(value>0){
    Serial.print("Distancia: ");
    Serial.println(value);
    for(int i=0;i<10;i++){
      //strcpy(buffer2,inf->intensidade("dlink-4"));
      //Serial.println(buffer2);
      //strcat(buffer4,buffer2);
      //strcat(buffer4,"Olá\n");
      //Serial.println(buffer4);
      m->sendMsg("Olá\n");
      Serial.println("fadsfa");
    }
  }
}
