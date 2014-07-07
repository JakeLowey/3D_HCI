#define WINVER 0x0500
#include <string>
#include <windows.h>
#include <map>
#include "Keyboard.h"

template <typename T, typename U>
class create_map
{
private:
    std::map<T, U> m_map;
public:
    create_map(const T& key, const U& val)
    {
        m_map[key] = val;
    }

    create_map<T, U>& operator()(const T& key, const U& val)
    {
        m_map[key] = val;
        return *this;
    }

    operator std::map<T, U>()
    {
        return m_map;
    }
};

std::map<std::string, unsigned int> setKeys();


//Constructor
Keyboard::Keyboard(){
	ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    keys = setKeys();
}


//Destructor
Keyboard::~Keyboard(){
	keys.clear();
}

//Down presses the key that is given
void Keyboard::pressButton(std::string button){
	ip.ki.wVk = keys.find(button)->second;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
}

//releases key that is given
void Keyboard::releaseButton(std::string button){
	ip.ki.wVk = keys.find(button)->second;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

//Presses and then releases a given key
void Keyboard::tapButton(std::string button){
	ip.ki.wVk = keys.find(button)->second;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(25);
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}



std::map<std::string, unsigned int> setKeys(){
	std::map<std::string,unsigned int> keys = create_map<std::string,unsigned int>("LeftClick",0x01)("RightClick",0x02)("Cancel",0x03)("MiddleClick",0x04)("X1Click",0x05)("X2Click",0x06)("Backspace",0x08)("Tab",0x09)("Clear",0x0c)("Return",0x0d)("Enter",0x0d)("Shift",0x10)("Control",0x11)("Alt",0x12)("Puase",0x13)("CapsLock",0x14)("IMEKana",0x15)("IMEHangul",0x15)("IMEJunja",0x17)("IMEFinal",0x18)("IMEKanji",0x19)("Escape",0x1b)("IMEConvert",0x1c)("IMENonconvert",0x1d)("IMEAccept",0x1e)("IMEModeChange",0x1f)("Space",0x20)("PageUp",0x21)("PageDown",0x22)("End",0x23)("Home",0x24)("LeftArrow",0x25)("UpArrow",0x26)("RightArrow",0x27)("DownArrow",0x28)("Select",0x29)("Print",0x2a)("Execute",0x2b)("PrintScreen",0x2c)("Insert",0x2d)("Delete",0x2e)("Help",0x2f)("0",0x30)("1",0x31)("2",0x32)("3",0x33)("4",0x34)("5",0x35)("6",0x36)("7",0x37)("8",0x38)("9",0x39)("A",0x41)("B",0x42)("C",0x43)("D",0x44)("E",0x45)("F",0x46)("G",0x47)("H",0x48)("I",0x49)("J",0x4a)("K",0x4b)("L",0x4c)("M",0x4d)("N",0x4e)("O",0x4f)("P",0x50)("Q",0x51)("R",0x52)("S",0x53)("T",0x54)("U",0x55)("V",0x56)("W",0x57)("X",0x58)("Y",0x59)("Z",0x5a)("LeftWindows",0x5b)("RightWindows",0x5c)("Applications",0x5d)("Sleep",0x5f)("Numpad0",0x60)("Numpad1",0x61)("Numpad2",0x62)("Numpad3",0x63)("Numpad4",0x64)("Numpad5",0x65)("Numpad6",0x66)("Numpad7",0x67)("Numpad8",0x68)("Numpad9",0x69)("Multiply",0x6a)("Add",0x6b)("Separate",0x6c)("Subtract",0x6d)("Decimal",0x6e)("Divide",0x6f)("F1",0x70)("F2",0x71)("F3",0x72)("F4",0x73)("F5",0x74)("F6",0x75)("F7",0x76)("F8",0x77)("F9",0x78)("F10",0x79)("F11",0x7a)("F12",0x7b)("F13",0x7c)("F14",0x7d)("F15",0x7e)("F16",0x7f)("F17",0x80)("F18",0x81)("F19",0x82)("F20",0x83)("F21",0x84)("F22",0x85)("F23",0x86)("F24",0x87)("NumberLock",0x90)("ScrollLock",0x91)("LeftShift",0xa0)("RightShift",0xa1)("LeftControl",0xa2)("RightControl",0xa3)("LeftAlt",0xa4)("RightAlt",0xa5)("BrowserBack",0xa6)("BrowserForward",0xa7)("BrowserRefresh",0xa8)("BrowserStop",0xa9)("BrowserSearch",0xaa)("BrowserFavorites",0xab)("BrowserHome",0xac)("VolumeMute",0xad)("VolumeDown",0xae)("VolumeUp",0xaf)("NextTrack",0xb0)("PreviousTrack",0xb1)("MediaStop",0xb2)("MediaPlayPause",0xb3)("Mail",0xb4)("MediaSelect",0xb5)("LaunchApp1",0xb6)("LaunchApp2",0xb7)("Colon",0xba)("Plus",0xbb)("Comma",0xbc)("Minus",0xbd)("Period",0xbe)("ForwardSlash",0xbf)("Tilde",0xc0)("OpenBracket",0xdb)("BackSlash",0xdc)("CloseBracket",0xdd)("Quote",0xde)("IMEProcess",0xe5)("Attn",0xf6)("CrSel",0xf7)("ExSel",0xf8)("EraseEOF",0xf9)("Play",0xfa)("Zoom",0xfb)("PA1",0xfd)("Clear",0xfe);
	return keys;
}