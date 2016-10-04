#include <AIB.h> // Inclusion de Arduino Interface Builder Library

bool connection; // Bandera de conexion => Por ahora se maneja aqui
AIB_ interface(2, Serial); // Objeto de la libreria /=/ 1 =>Production /=/ 2 => Testing /=/

void setup() {
    Serial.begin(9600); // Ponemos la velocidad del serial
    interface.setDelimiter('|'); // Damos el delimitador para APII RESPONSES Y CALLS
    connection = false; // Ponemos la bandera en apagada
}

void loop() {

    if ( connection == false ) { // Solo entrara la primera ves, cuando aun no se conecta

          interface.establishConnection(); // Abrimos la conexion
          interface.start(); // Mandamos un caacter 'a' al interfaz, para eesperar respuesta de coneion
          delay(2500); // Delay

           if (Serial.available() > 0) { // Checamos is hay buffer de entrada para leer
              String la = Serial.readString(); // Guardamos este buffer
              Serial.println(la); // Imprimimos este buffer
              connection = true; // Prendemos la bandera
           }

    } else {

          // Here Arduino logic || Aqui va la logica del arduino o l que se quiera hacer :D
    }

}
