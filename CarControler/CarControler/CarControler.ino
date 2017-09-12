#include "Motor.h"

/* ULTRASONIC SENSOR */
#define trigPin A0
#define echoPin A1

/* MOTOR DRIVER BOARD */
#define sensorLinhaEsq A4
#define sensorLinhaDir A5

Motor *m = new Motor(6,7,9,8,10,11);

int ValorLinhaEsq, ValorLinhaDir;
int ValorCorte = 850;

void setupUltrasonic() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void setupSensoresLinhas() {
  pinMode(sensorLinhaEsq, INPUT);
  pinMode(sensorLinhaDir, INPUT);
}


// Para começar a medição é necessário alimentar o módulo e colocar o pino
// Trigger em nível alto por mais de 10us. Assim o sensor emitirá uma onda
// sonora que ao encontrar um obstáculo rebaterá de volta em direção ao módulo,
// sendo que o neste tempo de emissão e recebimento do sinal o pino ECHO
// ficará em nivel alto. Logo o calcula da distância pode ser feito de
// acordo com o tempo em que o pino ECHO permaneceu em nível alto após
// o pino Trigger ter sido colocado em nível alto.

// Distância = [Tempo ECHO em nível alto * Velocidade do Som] / 2

// A velocidade do som poder ser considerada idealmente igual a 340 m/s,
// logo o resultado é obtido em metros se considerado o tempo em segundos.

long getDistance() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  return (distance);
}

void setup() {
  Serial.begin(9600);
  setupUltrasonic();
  m->setup();
}

void loop() {
  m->forward();
  long distance = getDistance();
  //long mspeed = 255 / 20 * ( distance - 5 ) - 10;
  long mspeed = 180;
  if (mspeed < 0) {
    mspeed = 0;
  }
  if (mspeed > 220) {
    mspeed = 220;
  }
  // Serial.println(mspeed);

  m->func();

  ValorLinhaEsq = analogRead(sensorLinhaEsq);
  ValorLinhaDir = analogRead(sensorLinhaDir);
  Serial.println(ValorLinhaEsq);
  Serial.println("..");
  Serial.println( ValorLinhaDir);
  
    if ((ValorLinhaEsq > ValorCorte) && (ValorLinhaDir > ValorCorte)) {
      m->stop();
    }
    
    // Curva para a direita
    if ((ValorLinhaEsq > ValorCorte) && (ValorLinhaDir < ValorCorte)) {
		  m->right();
    }
    
    // Curva para a esquerda
    if ((ValorLinhaEsq < ValorCorte) && (ValorLinhaDir > ValorCorte)) {
      m->left();
    }
  delay(15);
}
