#include <stdio.h>
// #include <tchar.h>
#include "SerialClass.h"	// Library described above
#include <string>
#include <iostream>

// application reads from the specified serial port and reports the collected data
using namespace std;

int main(int argc, char* argv[])
{
	printf("Welcome to the serial test app!\n\n");
	char* c = "\\\\.\\COM10";
	// char* d = c;
	Serial* SP = new Serial(c);    // adjust as needed

	if (SP->IsConnected())
		printf("We're connected");

	char incomingData[256] = "";			// don't forget to pre-allocate memory
	//printf("%s\n",incomingData);
	int dataLength = 256;
	int readResult = 0;

	while(SP->IsConnected())
	{
		readResult = SP->ReadData(incomingData,dataLength);
		cout << "Bytes read: (-1 means no data available) " + readResult << endl;

		std::string test(incomingData);

		cout << test << endl;
		test = "";

		Sleep(500);
	}
	return 0;
}
