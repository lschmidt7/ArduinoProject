/*
  Autor: Leonardo de Abreu Schmidt
*/

#include "Infos.h"
#include <string.h>

char buffer1[4];

Infos::Infos(ESP8266 *wifi) {
  this->wifi = wifi;
}

String Infos::getInfoRedes() {
  return this->wifi->getAPList();
}

char* Infos::intensidade(String ssid) {
  int j = 0;
  int t=0;
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
        buffer1[t]=infs[i + 3];
        t++;
    }
    if(habw && infs[i+3]==','){
      habw=false;
      Serial.println();
      }
  }
  buffer1[3]='\0';
  return buffer1;
}
