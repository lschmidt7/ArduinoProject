#include "Arduino.h"
#include <TimeLib.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

class GPS{

private:
	int RX = 4;
	int TX = 3;
	int UTC_offset = -3;
	TinyGPSPlus gps;
  SoftwareSerial *Serial_GPS;
public:
  
	GPS(SoftwareSerial *ss);
	void SetUTFOffset(int offset);
	void Info();
	void Lat();
	void Long();
};
