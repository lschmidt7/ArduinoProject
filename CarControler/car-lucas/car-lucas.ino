/* ULTRASONIC SENSOR */
#define trigPin A0
#define echoPin A1

/* MOTOR DRIVER BOARD */
#define IN1  6 // grey 
#define IN2  7 // violet
#define IN3  9 // blue 
#define IN4  8 // green
#define ENA 10 // green
#define ENB 11 // orange
#define sensorLinhaEsq A4
#define sensorLinhaDir A5

int ValorLinhaEsq, ValorLinhaDir;
int ValorCorte = 850;

void setupUltrasonic() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void setupMotors() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
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

void startMotors(int mspeed) {
  analogWrite(ENA, mspeed);
  analogWrite(ENB, mspeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN4, HIGH);
}

void setup() {
  Serial.begin(9600);
  setupUltrasonic();
  setupMotors();
}

void loop() {
  startMotors(220);
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

  analogWrite(ENA, mspeed);
  analogWrite(ENB, mspeed);

  ValorLinhaEsq = analogRead(sensorLinhaEsq);
  ValorLinhaDir = analogRead(sensorLinhaDir);
  Serial.println(ValorLinhaEsq);
  Serial.println("..");
  Serial.println( ValorLinhaDir);
  
    if ((ValorLinhaEsq > ValorCorte) && (ValorLinhaDir > ValorCorte)) {
      analogWrite(ENA, mspeed);
      analogWrite(ENB, mspeed);
      digitalWrite(IN1, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN4, LOW);
    }
    
    // Curva para a direita
    if ((ValorLinhaEsq > ValorCorte) && (ValorLinhaDir < ValorCorte)) {
      analogWrite(ENA, mspeed);
      analogWrite(ENB, mspeed);
      digitalWrite(IN2, LOW);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    
    // Curva para a esquerda
    if ((ValorLinhaEsq < ValorCorte) && (ValorLinhaDir > ValorCorte)) {
      analogWrite(ENA, mspeed);
      analogWrite(ENB, mspeed);
      digitalWrite(IN1, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      digitalWrite(IN2, HIGH);
    }
  delay(15);
}
