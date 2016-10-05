/*
 * Example designed by Erick Sanchez Perez, CEO of App Builders
 * AIB(Android Interface Builder) it´s a library that pretend make easy the connection between Android and PC´s, Android, iPhone, Raspberry
 * The only porpouse of this example, it´s show how to initialize the Library, and make calls beetween devices
 * 
 * Methos of Library:
 * 
 *  - setSerialSpeed(int) // This method provides to user the posibilite to save Serial Speed-
 *    -- The method wait for int value, don´t return anything.
 *  
 *  - prepareConnection() // This method only prepare a bridge between device and Arduino
 *    -- The method don´t wait anythind, and return a integer, this integer it´s the value of profile
 *      --- 1: Production; 2: Testing
 *      
 *  - setAPIDelimiter(char) // This method set de delimiter, for API calls and Responses
 *    -- The method wait for a char value, for default the function set a '|' (pipe)
 *    
 *  - getDelimiter() // This method it´s a getter of delimiter
 *    -- The method don´t wait anythig, and return a char, that is the delimiter
 *    
 *  - start(void) // This method it´s uused to test the connection, automatically send a letter 'a'
 *    -- The method dont´t wit anything, and don´t return nothing
 *    
 *  - startWithInt(int);
 *  - startWithChar(char);
 *  - startWithString(String);
 *    -- Those methods are the same, everyone send a specific character (int, char, String9, to initialize the connection, anyone return nothing
 *    
 *  - void sendInt(int, bool);
 *  - void sendChar(char, bool);
 *  - void send(String, bool);
 *    -- Those methods send a value (int, char, String) to the device, all of them have a second parameter, that it´s optional (by default it´s false), this secodnd parameter add '\n'(break line), anyone return nothing
 */

#include <AIB.h> // Inclusion de Arduino Interface Builder Library

bool interfaceConnection; // Bandera de conexion => Por ahora se maneja aqui
AIB_ interface(2, Serial); // Objeto de la libreria /=/ 1 =>Production /=/ 2 => Testing /=/

void setup() {
    Serial.begin(9600); // Ponemos la velocidad del serial // Importante recordar ese valor
    interface.setAPIDelimiter('|'); // Damos el delimitador para API RESPONSES Y CALLS
    interfaceConnection = false; // Ponemos la bandera en apagada
}

void loop() {

    if ( interfaceConnection == false ) { // Solo entrara la primera ves, cuando aun no se conecta

          int con = interface.prepareConnection(); // Preparamos la conexion
          if ( con == 0 ) { // solo llegara aqui cuando iniciemos el objeto con 1, si se inicia con 2, entrara automaticamente

            interface.start(); // Mandamos un caracter 'a' al interfaz, para esperar respuesta de conexion // Podemos usar los otros metodos para mandar inicializacions personalizdas
            delay(2500); // Delay 2.5 seg

             if (Serial.available() > 0) { // Checamos si hay buffer de entrada para leer datos
                String la = Serial.readString(); // Guardamos este buffer en un String (no importa si nos manda int, char)
                Serial.println(la); // Imprimimos este buffer //
                interfaceConnection = true; // Prendemos la bandera
             }
          } else {
            interfaceConnection = true; // Hacemos esto, pro si hacemos pruebas de la logica misma del aurduino y no se necesita esperar una accion para emepzar
          }


    } else {

          // Here Arduino Logic || Despues de ese ELSE ponemos todo el programa (Obviamente acoplando variables,etc), este codigo solo se ejecutara cuando se haya establecido conexion con la PC, Android, Raspberry
          // No recomiendo usar el println, mejor usar el print normal y al final agregar el salto de linea manualmente
          Serial.print("Hola mundo\n");
          delay(1500); // Delay 1.5 seg
          char delimiter = interface.getDelimiter(); // Le pido el delimitador a la libreria
          Serial.print((String)delimiter + " ==> Delimiter\n"); // Casteo el delimiter para ser String, uso el '+' para concatenar ese String
          delay(1500); // Delay 1.5 seg

    }

}
