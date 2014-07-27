#ifndef KEYBOARD_H
#include <string>
#include <map>
#include <windows.h>

class Keyboard{
	public:
		Keyboard();
		~Keyboard();
		void pressButton(std::string button);
		void releaseButton(std::string button);
		void tapButton(std::string button);
		void releaseALL();

	private:
		INPUT ip;
		std::map<std::string, unsigned int> keys;
};

#endif