#include "GPS.hpp"

GPS::GPS(SoftwareSerial * ss){
  Serial_GPS = ss;
	Serial_GPS->begin(9600);
}

void GPS::SetUTFOffset(int offset){
	UTC_offset = offset;
}

void GPS::Info(){
	if(Serial_GPS->available() > 0){
		if(gps.encode(Serial_GPS->read())){
			if (gps.location.isValid())
			{
				Serial.print(gps.location.lat(), 6); //latitude
				Serial.print(F(","));
				Serial.print(gps.location.lng(), 6); //longitude
			}
			if (gps.date.isValid())
			{
				Serial.print(gps.date.day()); //dia
				Serial.print(F("/"));
				Serial.print(gps.date.month()); //mes
				Serial.print(F("/"));
				Serial.print(gps.date.year()); //ano
			}
			if (gps.time.isValid())
			{
				if (gps.time.hour() < 10) Serial.print(F("0"));
					Serial.print(gps.time.hour()); //hora
					Serial.print(F(":"));
			    if (gps.time.minute() < 10) Serial.print(F("0"));
					Serial.print(gps.time.minute()); //minuto
					Serial.print(F(":"));
				if (gps.time.second() < 10) Serial.print(F("0"));
					Serial.print(gps.time.second()); //segundo
					Serial.print(F("."));
				if (gps.time.centisecond() < 10) Serial.print(F("0"));
					Serial.print(gps.time.centisecond());
			  }
		}
	}
}

void GPS::Lat(){

}

void GPS::Long(){
	
}
