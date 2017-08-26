#include "ESP8266.h"
//#include <NewPing.h>
#include <string.h>

//#define CH_PD 44
//#define RST 46
//#define GPIO0 48

//Coloque nos campos indicados o nome e senha da sua rede WiFi
#define SSID        "dlink-4"
#define PASSWORD    "abcd1234"


#define MAX_DISTANCE 200

#define trigPin A0
#define echoPin A1


//#define HOST_NAME   "192.168.0.105"
#define HOST_PORT   (8090)

//Cria objeto de conexão wifi com o módulo, usando a Serial1 do Mega.
ESP8266 wifi(Serial1);


void setup(void)
{
  //////   pinMode(CH_PD,OUTPUT);
  //  pinMode(RST,OUTPUT);
  // pinMode(GPIO0,OUTPUT);
  //   digitalWrite(CH_PD,HIGH); //setado em ALTO - operacao normal
  // digitalWrite(RST,HIGH);
  //  digitalWrite(GPIO0,HIGH); //setado em ALTO - operacao normal

  Serial.begin(9600);
  Serial1.begin(9600);

  //  setupUltrasonic();
  // setupWifi();
  //}


  //void setupWifi() {

  Serial.println("Iniciando Setup.");

  Serial.print("Versao de Firmware ESP8266: ");
  //A funcao wifi.getVersion() retorna a versao de firmware informada pelo modulo no inicio da comunicacao
  Serial.println(wifi.getVersion().c_str());

  //Vamos setar o modulo para operar em modo Station (conecta em WiFi) e modo AP (é um ponto de WiFi tambem)
  if (wifi.setOprToStationSoftAP()) {
    Serial.println("Station e AP OK.");
  } else {
    Serial.println("Erro em setar Station e AP.");
  }

  //Agora vamos conectar no ponto de WiFi informado no inicio do codigo, e ver se corre tudo certo
  if (wifi.joinAP(SSID, PASSWORD)) {
    Serial.println("Conectado com Sucesso.");
    Serial.println("IP: ");
    // rotina wifi.getLocalIP() retorna o IP usado na conexao com AP conectada.
    Serial.println(wifi.getLocalIP().c_str());
  } else {
    Serial.println("Falha na conexao AP.");
  }



  //Agora vamos habiliar a funcionalidade MUX, que permite a realizacao de varias conexoes TCP/UDP
  if (wifi.enableMUX()) {
    Serial.println("Multiplas conexoes OK.");
  } else {
    Serial.println("Erro ao setar multiplas conexoes.");
  }

  //Inicia servidor TCP na porta 8090 (veja depois a funcao "startServer(numero_porta)", que serve para UDP!
  if (wifi.startTCPServer(HOST_PORT)) {
    // if (wifi.startServer(HOST_PORT)) {
    Serial.println("Servidor iniciado com sucesso.");
  } else {
    Serial.println("Erro ao iniciar servidor.");
  }
  Serial.println("Setup finalizado!");
}





void loop(void) {
  // put your main code here, to run repeatedly:
  uint8_t buffer[128] = {0};
  static uint8_t mux_id = 0;

  //if(wifi.createTCP(HOST_NAME, HOST_PORT)) {
  //   Serial.println("create TCP ok");
  // } else {
  //   Serial.println("create TCP err");
  //  }

  //  uint32_t len = wifi.recv(buffer, sizeof(buffer), 1000);
  //E esta variavel len serve para armazenar o comprimento de dados recebidos por meio da rotina wifi.recv(), que tambem
  //associa ao buffer os dados recebidos e ao mux_id a id responsavel pela transmissao

  long distance = getDistance();
  char str[10];
  itoa(distance, str, 10);

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




  char *request = (char*) "Hello computer, here is arduino!\n";
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

  delay (100);


  //  wifi.send((const uint8_t*)request, strlen(request));
  // wifi.send(request, strlen(request));
  delay (100);
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



