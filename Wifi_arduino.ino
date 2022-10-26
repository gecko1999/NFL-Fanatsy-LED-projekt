String readSerial;


#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <WiFiNINA.h>
#include <WiFiUdp.h>
#include "arduino_secrets.h"

int status = WL_IDLE_STATUS;
#include "arduino_secrets.h" 
///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key index number (needed only for WEP)

unsigned int localPort = 2390;      // local port to listen on

char packetBuffer[256]; //buffer to hold incoming packet
char  ReplyBuffer[] = "acknowledged";       // a string to send back

WiFiUDP Udp;


#define PIN            6
#define NUMPIXELS      60
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  //Serial.begin(9600);
  pixels.begin();
  //while (!Serial) {
  //  ; // wait for serial port to connect. Needed for native USB port only
  //}

  //check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
   Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.println(status);
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(5000);
  }
  Serial.println("Connected to WiFi");
  printWifiStatus();

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  Udp.begin(localPort);
}


void loop(){

int packetSize = Udp.parsePacket();
  if (packetSize) {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remoteIp = Udp.remoteIP();
    Serial.print(remoteIp);
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // read the packet into packetBufffer
    int len = Udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    //Serial.println("Contents:");
    //Serial.println(packetBuffer);

    // send a reply, to the IP address and port that sent us the packet we received
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(ReplyBuffer);
    Udp.endPacket();
  }
      
      String packetBufferS = String(packetBuffer);
      String qb = packetBufferS.substring(0,2);
      String rb1 = packetBufferS.substring(2,4);
      String rb2 = packetBufferS.substring(4,6);
      String wr1 = packetBufferS.substring(6,8);
      String wr2 = packetBufferS.substring(8,10);
      String te = packetBufferS.substring(10,12);
      String flex = packetBufferS.substring(12,14);
      String k = packetBufferS.substring(14,16);
      String de = packetBufferS.substring(16,18);



      if (qb.equals("10")){
        pixels.setPixelColor(59, pixels.Color(255, 0, 255));
        pixels.setPixelColor(58, pixels.Color(255, 0, 255));
        pixels.setPixelColor(57, pixels.Color(255, 0, 255));
        pixels.show();
      }
      else if(qb.equals("11")){
        pixels.setPixelColor(59, pixels.Color(255, 0, 0));
        pixels.setPixelColor(58, pixels.Color(255, 0, 0));
        pixels.setPixelColor(57, pixels.Color(255, 0, 0));
        pixels.show();
      }
      else if(qb.equals("12")){
        pixels.setPixelColor(59, pixels.Color(0, 255, 0));
        pixels.setPixelColor(58, pixels.Color(0, 255, 0));
        pixels.setPixelColor(57, pixels.Color(0, 255, 0));
        pixels.show();
      }

      if (rb1.equals("20")){
        pixels.setPixelColor(56, pixels.Color(255, 0, 255));
        pixels.setPixelColor(55, pixels.Color(255, 0, 255));
        pixels.setPixelColor(54, pixels.Color(255, 0, 255));
        pixels.show();
      }
      else if(rb1.equals("21")){
        pixels.setPixelColor(56, pixels.Color(255, 0, 0));
        pixels.setPixelColor(55, pixels.Color(255, 0, 0));
        pixels.setPixelColor(54, pixels.Color(255, 0, 0));
        pixels.show();
      }
      else if(rb1.equals("22")){
        pixels.setPixelColor(56, pixels.Color(0, 255, 0));
        pixels.setPixelColor(55, pixels.Color(0, 255, 0));
        pixels.setPixelColor(54, pixels.Color(0, 255, 0));
        pixels.show();
      }

      if (rb2.equals("30")){
        pixels.setPixelColor(53, pixels.Color(255, 0, 255));
        pixels.setPixelColor(52, pixels.Color(255, 0, 255));
        pixels.setPixelColor(51, pixels.Color(255, 0, 255));
        pixels.show();
      }
      else if(rb2.equals("31")){
        pixels.setPixelColor(53, pixels.Color(255, 0, 0));
        pixels.setPixelColor(52, pixels.Color(255, 0, 0));
        pixels.setPixelColor(51, pixels.Color(255, 0, 0));
        pixels.show();
      }
      else if(rb2.equals("32")){
        pixels.setPixelColor(53, pixels.Color(0, 255, 0));
        pixels.setPixelColor(52, pixels.Color(0, 255, 0));
        pixels.setPixelColor(51, pixels.Color(0, 255, 0));
        pixels.show();
      }

      if (wr1.equals("40")){
        pixels.setPixelColor(50, pixels.Color(255, 0, 255));
        pixels.setPixelColor(49, pixels.Color(255, 0, 255));
        pixels.setPixelColor(48, pixels.Color(255, 0, 255));
        pixels.show();
      }
      else if(wr1.equals("41")){
        pixels.setPixelColor(50, pixels.Color(255, 0, 0));
        pixels.setPixelColor(49, pixels.Color(255, 0, 0));
        pixels.setPixelColor(48, pixels.Color(255, 0, 0));
        pixels.show();
      }
      else if(wr1.equals("42")){
        pixels.setPixelColor(50, pixels.Color(0, 255, 0));
        pixels.setPixelColor(49, pixels.Color(0, 255, 0));
        pixels.setPixelColor(48, pixels.Color(0, 255, 0));
        pixels.show();
      }

      if (wr2.equals("50")){
        pixels.setPixelColor(47, pixels.Color(255, 0, 255));
        pixels.setPixelColor(46, pixels.Color(255, 0, 255));
        pixels.setPixelColor(45, pixels.Color(255, 0, 255));
        pixels.show();
      }
      else if(wr2.equals("51")){
        pixels.setPixelColor(47, pixels.Color(255, 0, 0));
        pixels.setPixelColor(46, pixels.Color(255, 0, 0));
        pixels.setPixelColor(45, pixels.Color(255, 0, 0));
        pixels.show();
      }
      else if(wr2.equals("52")){
        pixels.setPixelColor(47, pixels.Color(0, 255, 0));
        pixels.setPixelColor(46, pixels.Color(0, 255, 0));
        pixels.setPixelColor(45, pixels.Color(0, 255, 0));
        pixels.show();
      }

      if (te.equals("60")){
        pixels.setPixelColor(44, pixels.Color(255, 0, 255));
        pixels.setPixelColor(43, pixels.Color(255, 0, 255));
        pixels.setPixelColor(42, pixels.Color(255, 0, 255));
        pixels.show();
      }
      else if(te.equals("61")){
        pixels.setPixelColor(44, pixels.Color(255, 0, 0));
        pixels.setPixelColor(43, pixels.Color(255, 0, 0));
        pixels.setPixelColor(42, pixels.Color(255, 0, 0));
        pixels.show();
      }
      else if(te.equals("62")){
        pixels.setPixelColor(44, pixels.Color(0, 255, 0));
        pixels.setPixelColor(43, pixels.Color(0, 255, 0));
        pixels.setPixelColor(42, pixels.Color(0, 255, 0));
        pixels.show();
      }

      if (flex.equals("70")){
        pixels.setPixelColor(41, pixels.Color(255, 0, 255));
        pixels.setPixelColor(40, pixels.Color(255, 0, 255));
        pixels.setPixelColor(39, pixels.Color(255, 0, 255));
        pixels.show();
      }
      else if(flex.equals("71")){
        pixels.setPixelColor(41, pixels.Color(255, 0, 0));
        pixels.setPixelColor(40, pixels.Color(255, 0, 0));
        pixels.setPixelColor(39, pixels.Color(255, 0, 0));
        pixels.show();
      }
      else if(flex.equals("72")){
        pixels.setPixelColor(41, pixels.Color(0, 255, 0));
        pixels.setPixelColor(40, pixels.Color(0, 255, 0));
        pixels.setPixelColor(39, pixels.Color(0, 255, 0));
        pixels.show();
      }

      if (k.equals("80")){
        pixels.setPixelColor(38, pixels.Color(255, 0, 255));
        pixels.setPixelColor(37, pixels.Color(255, 0, 255));
        pixels.setPixelColor(36, pixels.Color(255, 0, 255));
        pixels.show();
      }
      else if(k.equals("81")){
        pixels.setPixelColor(38, pixels.Color(255, 0, 0));
        pixels.setPixelColor(37, pixels.Color(255, 0, 0));
        pixels.setPixelColor(36, pixels.Color(255, 0, 0));
        pixels.show();
      }
      else if(k.equals("82")){
        pixels.setPixelColor(38, pixels.Color(0, 255, 0));
        pixels.setPixelColor(37, pixels.Color(0, 255, 0));
        pixels.setPixelColor(36, pixels.Color(0, 255, 0));
        pixels.show();
      }

      if (de.equals("90")){
        pixels.setPixelColor(35, pixels.Color(255, 0, 255));
        pixels.setPixelColor(34, pixels.Color(255, 0, 255));
        pixels.setPixelColor(33, pixels.Color(255, 0, 255));
        pixels.show();
      }
      else if(de.equals("91")){
        pixels.setPixelColor(35, pixels.Color(255, 0, 0));
        pixels.setPixelColor(34, pixels.Color(255, 0, 0));
        pixels.setPixelColor(33, pixels.Color(255, 0, 0));
        pixels.show();
      }
      else if(de.equals("92")){
        pixels.setPixelColor(35, pixels.Color(0, 255, 0));
        pixels.setPixelColor(34, pixels.Color(0, 255, 0));
        pixels.setPixelColor(33, pixels.Color(0, 255, 0));
        pixels.show();
      }

}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
