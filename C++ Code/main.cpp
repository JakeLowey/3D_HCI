//Incudes
#include <stdio.h>
#include "wtypes.h"
#include "SerialClass.h"	// Library described above
#include <string>
#include <iostream>

// application reads from the specified serial port and reports the collected data
using namespace std;

//Function Prototypes
void GetDesktopResolution(int& horizontal, int& vertical);
void SetUpCursor();

//Global variables
POINT* loc = new POINT();

//Main function
int main(int argc, char* argv[])
{
	cout << "Welcome to the serial test app!\n\n";
	// char* c = "\\\\.\\COM10";
	char* c = "COM3";
	Serial* SP = new Serial(c);    // adjust as needed
	SetUpCursor();
	// for (int i = 0; i < 1600; i+=10)
	// {
	// 	SetCursorPos(i,i);
	// 	Sleep(150);
	// }
	if (SP->IsConnected())
		cout << "We're connected" << endl;

	char incomingData[256] = "";			// don't forget to pre-allocate memory
	int dataLength = 256;
	int readResult = 0;

	while(SP->IsConnected())
	{
		readResult = SP->ReadData(incomingData,dataLength);
		cout << "Bytes read: (-1 means no data available) " + readResult << endl;

		std::string test(incomingData);

		cout << test << endl;
		test = "";

		Sleep(250);
	}
	cout << "done";
	return 0;
}

//Gets the screen resolution of the monitor being used
void GetDesktopResolution(int& horizontal, int& vertical)
{
   RECT desktop;
   // Get a handle to the desktop window
   const HWND hDesktop = GetDesktopWindow();
   // Get the size of screen to the variable desktop
   GetWindowRect(hDesktop, &desktop);
   // The top left corner will have coordinates (0,0)
   // and the bottom right corner will have coordinates
   // (horizontal, vertical)
   horizontal = desktop.right;
   vertical = desktop.bottom;
}

bool SetUpCursor(){
	int h,v = 0;
	GetDesktopResolution(h,v);
	RECT* rec = new RECT {0,0,h,v};
	ClipCursor(rec);
	bool  result = GetCursorPos(loc);
	// h = loc->x;
	// v = loc->y;
	// cout << result << endl << h << endl << v << endl;
	return result;
}
