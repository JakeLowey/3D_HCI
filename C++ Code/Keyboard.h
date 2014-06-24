#define WINVER 0x0500
#include <windows.h>
#include <string>
#include <map>

class Keyboard{
	public:
		Keyboard();
		~Keyboard();
		void pressButton(std::string button);
		void releaseButton(std::string button);
		void tapButton(std::string button);

	private:
		INPUT ip;
		std::map<std::string, unsigned int> keys;
};