/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "AIB.h"
#include "Arduino.h"

AIB_::AIB_(int typeInterface, Print &print) {
	_typeInterface = typeInterface;
	_printer = &print;
	//Serial.begin(9600);
}

void AIB_::setSerialSpeed(int serialSpeed) {
	_serialSpeed = serialSpeed;
	Serial.begin(_serialSpeed);
}

int AIB_::prepareConnection(void) {

	String type = "";
	int ret = 0;

	switch(_typeInterface) {

		case 1:
			type + "Produc";
			_printer->println("Production profile = Waiting for initializing!");
			ret = 0;
		break;

		case 2:
			type + "Test";
			_printer->print("Testing profile\n");
			ret = 1;

      /*_printer->print("Esperando por data => ");
      if (Serial.available() > 0) {
        char la = Serial.read();
        Serial.print("I received: ");
        Serial.println(la);
			}*/

		break;

		default:
			type + "Error";
			_printer->print("Error || No matching profile\n");
			ret = 0;
		break;
	}

	delay(5000);
	return ret;
}

void setAPIDelimiter(char delimiter) {
	_delimiter = delimiter;
}

void start(void) {
	_printer->write('a');
}

void startWithInt(int value) {
	sendInt( value, true );
}

void startWithChar(char value) {
	sendChar( value, true );
}

void startWithString(String value) {
	send( value, true );
}

void sendInt(int value, bool returnLine = false) {
	String newLine = ( returnLine == false ) ? "" : "\n";
	_printer->write(value + newLine);
}

void sendChar(char value, bool returnLine = false) {
	String newLine = ( returnLine == false ) ? "" : "\n";
	_printer->write(value + newLine);
}

void send(String value, bool returnLine = false) {
	String newLine = ( returnLine == false ) ? "" : "\n";
	_printer->write(value + newLine);
}

char getDelimiter(void) {
	return _delimiter;
}

void AIB_::prettySerial(void) {
	Serial.print("10\n");
}
