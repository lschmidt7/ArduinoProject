/*
* Autor: Leonardo de Abreu Schmidt
*/

#include "ESP8266.h"
#include <string.h>

class Connection {
	private:
		ESP8266 wifi(Serial1);
		String SSID = "dlink-4"
		String PASSWORD = "abcd1234"
		int HOST_PORT = (8090)
	public:
		Connection(String mode, String SSID, String PASSWORD, bool MUX, String HOST_PORT);
		String getFirmwareVersion();

		
}