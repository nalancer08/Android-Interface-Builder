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

          int con = interface.prepareConnection(); // Preparamos la conexion
          if ( con == 0 ) { // solo llegara aqui cuando iniciemos el objeto con 1, si se inicia con 2, entrara automaticamente

            interface.start(); // Mandamos un caacter 'a' al interfaz, para eesperar respuesta de coneion
            delay(2500); // Delay

             if (Serial.available() > 0) { // Checamos is hay buffer de entrada para leer
                String la = Serial.readString(); // Guardamos este buffer
                Serial.println(la); // Imprimimos este buffer
                connection = true; // Prendemos la bandera
             }
          } else {
            connection = true; // Hacemos esto, pro si hacemos pruebas de la logica misma del aurduino y no se necesita esperar una accion para emepzar
          }


    } else {

          // Here Arduino logic || Aqui va la logica del arduino o l que se quiera hacer :D
    }

}
