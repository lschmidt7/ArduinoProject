void setup() {

    // Setup computer to Arduino serial
    Serial.begin(9600);

    // Setup Arduino to ESP8266 serial
    // Use baud rate 115200 during firmware update
   Serial1.begin(9600);
 // Serial1.begin(9600);
  
  
// Set my mode to “AT+CWMODE=3” to allow for both client and server mode (at least that is what I think it is).
// Scan for access points with AT+CWLAP command.
// Join the AP by sending AT+CWJAP=”[YourNetwork]”,”[YourPassword]”
// Check that you get IP assignment from the router with AT+CIFSR
// I got to IP’s, 192.168.4.1 and 192.168.0.128.
// The first one (192.168.4.1) is the IP of the AP that the ESP8266 when operating as an AP (remember I set to CWMODE=3 in step one).  Not sure how to use it yet.
// The second one (192.168.0.128) is the one my Dlink AP assigned to the ESP8266.  This is the one I know how to use for now.
  
  

}

void loop() {

    // Send bytes from ESP8266 to computer
    if ( Serial1.available() ) {
        Serial.write( Serial1.read() );
    }

    // Send bytes from computer back to ESP8266
    if ( Serial.available() ) {
        Serial1.write( Serial.read() );
    }

}
