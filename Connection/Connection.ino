#include "ESP8266.h"
//#include <NewPing.h>
#include <string.h>
#include "Connection.h"
#include "Infos.h"

//#define CH_PD 44
//#define RST 46
//#define GPIO0 48

#define MAX_DISTANCE 200

#define trigPin A0
#define echoPin A1

ESP8266 wifi(Serial1);

Connection *conn = new Connection(&wifi, 0, "dlink-4", "abcd1234", true, 8090);
  Infos *inf = new Infos(&wifi);

void setup(void)
{

	Serial.begin(9600);
	Serial1.begin(9600);

	Serial.println("Iniciando Setup.");
	  conn->start();
  inf->intensidade("dlink-4");
  //Serial.println(inf->getInfoRedes());
	Serial.println("Setup finalizado!");
}

void loop(void) {
  if(Serial.read()=='P'){
    inf->intensidade("dlink-4");
  }
  // put your main code here, to run repeatedly:
	//uint8_t buffer[128] = {0};
	//static uint8_t mux_id = 0;

  //if(wifi.createTCP(HOST_NAME, HOST_PORT)) {
  //   Serial.println("create TCP ok");
  // } else {
  //   Serial.println("create TCP err");
  //  }

  //  uint32_t len = wifi.recv(buffer, sizeof(buffer), 1000);
  //E esta variavel len serve para armazenar o comprimento de dados recebidos por meio da rotina wifi.recv(), que tambem
  //associa ao buffer os dados recebidos e ao mux_id a id responsavel pela transmissao

	//long distance = getDistance();
	//char str[10];
	//itoa(distance, str, 10);

  // char *request;
  //  strcpy(request, str);
  //  request = request + '\0';
  //  char *request = "Hello computer, here is arduino!\n";
  //   Serial.print(request);
  //   Serial.print("\n");

  // envia a distancia do arduino para o PC
  //   wifi.send(mux_id, (const uint8_t*) request, strlen(request));


  // char buf[50];

  // unsigned long testID = 1716526225;
  //// sprintf(buf, "olalallaal", testID);
  //Serial.println( buf );

  //delay( 1000 );




	/*char *request = (char*) "Hello computer, here is arduino!\n";
	Serial.print(request);
	wifi.send(mux_id, (const uint8_t*) request, strlen(request));

  // recebe do pc

	uint32_t len = wifi.recv(mux_id, buffer, sizeof(buffer), 1000);
  //  uint32_t len = wifi.recv(buffer, sizeof(buffer), 100);

	if (len > 0) {
		Serial.print(len);

		Serial.print("Received: [");
		for (uint32_t i = 0; i < len; i++) {
			Serial.print((char) buffer[i]);
		}
    //Serial.println("");
		Serial.print("]\n");
	}

	//delay (100);


  //  wifi.send((const uint8_t*)request, strlen(request));
  // wifi.send(request, strlen(request));
	//delay (100);*/
}



void setupUltrasonic() {
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

long getDistance() {

  /* The following trigPin/echoPin cycle is used to determine the
    distance of the nearest object by bouncing soundwaves off of it. */
	long duration, distance;
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);

  // Calculate the distance (in cm) based on the speed of sound.
	distance = (duration / 2) / 29.1;
	return (distance);
}



