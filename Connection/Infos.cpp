/*
  Autor: Leonardo de Abreu Schmidt
*/

#include "Infos.h"
#include <string.h>

Infos::Infos(ESP8266 *wifi) {
  this->wifi = wifi;
}

String Infos::getInfoRedes() {
  return this->wifi->getAPList();
}

void Infos::intensidade(String ssid) {
  int j = 0;
  String infs = getInfoRedes();
  for (int i = 0; i < infs.length(); i++) {
    if (j==6 && habw == false) {
      habw = true;
    }
    if (infs[i] != ssid[j]) {
      j = 0;
    }
    if (infs[i] == ssid[j]) {
      j++;
    }
    if (habw) {
        Serial.print(infs[i + 3]);
    }
    if(habw && infs[i+3]==','){
      habw=false;
      Serial.println();
      }
  }
}
