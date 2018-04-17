#include "GPS.hpp"

SoftwareSerial ss(3,4);

GPS *g;

void setup() {
  g = new GPS(&ss);
}

void loop() {
  g->Info();
}
