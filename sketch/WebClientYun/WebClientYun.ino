#include <Bridge.h>
#include <YunClient.h>

char server[] = "www.arduino.cc"; //address (DNS)

YunClient yclient;

Client * client = &yclient;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  Bridge.begin(); //open bridge

  delay(2000); //aspetta 2 secondi
  
  Serial.println("connecting...");
  
  if (client->connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    client->println("GET /asciilogo.txt HTTP/1.1");
    client->println("Host: www.arduino.cc");
    client->println("Connection: close");
    client->println();
  }
  else {
    // kf you didn't get a connection to the server:
    Serial.println("connection failed");
  }
  
  
}

void loop()
{
  // if there are incoming bytes available
  // from the server, read them and print them:
  if (client->available()) {
    char c = client->read();
    Serial.print(c);
  
  } else if (!client->connected()) { // if the server's disconnected, stop the client:
    Serial.println();
    Serial.println("disconnecting.");
    client->stop();

    // do nothing forevermore:
    while (true)
      ;
  }
  
}

