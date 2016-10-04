/*
  AIB.h - Library for Arduino Interface Builder
  Created by Erick C. Sanchez, October 4, 2016.
  MIT License
*/
#ifndef AIB_h
#define AIB_h

#define interfaceProduction 1
#define interfaceTesting 2

#include "SoftwareSerial.h"
#define SERIAL_BUFFER_SIZE 256

class AIB_ {
	public:
		AIB_(int typeInterface, Print &print);

		void setSerialSpeed(int);
		int establishConnection(void);

		void setAPIDelimiter(char delimiter);
		char getDelimiter(void);

		void start(void);
		void startWithInt(int value);
		void startWithChar(char value);
		void startWithString(String value);

		void sendInt(int value, bool returnLine = false);
		void sendChar(char value, bool returnLine = false);
		void send(String value, bool returnLine = false);

		//bool checkInstance(void);
		void prettySerial(void);
	private:
		int _typeInterface;
		int _serialSpeed;

		char _delimiter;

		Print* _printer;
		//bool _completeSetup;
};

extern AIB_ AIB;


#endif
