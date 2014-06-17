#define WINVER 0x0500
#include <windows.h>

INPUT setupKeyboard(){
	INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    return ip;
}

bool pressCTRL(INPUT &ip){
	ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}

bool releaseCTRL(INPUT &ip) {
	ip.ki.wVk = VK_CONTROL;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}

bool pressTab(INPUT &ip){
	ip.ki.wVk = VK_TAB;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}

bool releaseTab(INPUT &ip) {
	ip.ki.wVk = VK_TAB;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}

bool pressAlt(INPUT &ip){
	ip.ki.wVk = VK_MENU;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}

bool releaseAlt(INPUT &ip) {
	ip.ki.wVk = VK_MENU;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}

bool pressSpace(INPUT &ip){
	ip.ki.wVk = VK_SPACE;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}

bool releaseSpace(INPUT &ip) {
	ip.ki.wVk = VK_SPACE;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}

bool pressBrowserBack(INPUT &ip){
	ip.ki.wVk = VK_BROWSER_BACK;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}

bool releaseBrowserBack(INPUT &ip) {
	ip.ki.wVk = VK_BROWSER_BACK;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}

bool pressBrowserForward(INPUT &ip){
	ip.ki.wVk = VK_BROWSER_FORWARD;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}

bool releaseBrowserForward(INPUT &ip) {
	ip.ki.wVk = VK_BROWSER_FORWARD;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}

bool pressKey(INPUT &ip, const char &c){
	ip.ki.wVk = c;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
	return true;

}

bool releaseKey(INPUT &ip, const char &c){
	ip.ki.wVk = c;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
	return true;
}



/*

VK_TAB -> tab
VK_RETURN -> enter
VK_BACK -> backspace
VK_SHIFT -> shift
VK_MENU -> alt
VK_ESCAPE -> escape
VK_SPACE -> space
VK_UP/DOWN/LEFT/RIGHT -> arrow keys
VK_DELETE -> del key
0x30 - 0x39 -> 0-9
VK_SLEEP -> computer sleep key
VK_BROWSER_BACK -> browser back button
VK_BROWSER_FORWARD -> browser forward key
VK_BROWSER_REFRESH -> refresh
VK_VOLUME_/MUTE/DOWN/UP -> control volume
VK_MEDIA_/NEXT_TRACK/PREVIOUS_TRACK/STOP/PLAY_PAUSE -> media controls

*/