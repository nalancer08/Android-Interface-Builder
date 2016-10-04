#include <AIB.h>

int banderita  = 0;

AIB_ interface(2, Serial);
bool conection;
int band = 0;
int con = 0;

void setup() {
    Serial.begin(9600);
    conection = false;
}

void loop() {

    if ( banderita == 0 ) {
          //Serial.print("Testing profile\n");
          Serial.write("start\n");
          con = interface.establishConnection();
          delay(5000);
           if (Serial.available() > 0) {
              String la = Serial.readString();
              Serial.print("I received: ");
              Serial.println(la);
              banderita = 1;
           }
    } else {
          delay(3000);
          Serial.print("hola erick\n");
          delay(5000);
    }
    //banderita = 1;
    
    //interface.prettySerial();
}
