String readSerial;

#include <Adafruit_NeoPixel.h>

#define PIN            6
#define NUMPIXELS      60
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pixels.begin();
}

void loop(){

  if (Serial.available()){
    
      readSerial = Serial.readString();

      String qb = readSerial.substring(0,2);
      String rb1 = readSerial.substring(2,4);
      String rb2 = readSerial.substring(4,6);
      String wr1 = readSerial.substring(6,8);
      String wr2 = readSerial.substring(8,10);
      String te = readSerial.substring(10,12);
      String flex = readSerial.substring(12,14);
      String k = readSerial.substring(14,16);
      String de = readSerial.substring(16,18);

      Serial.print(readSerial);

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


}
