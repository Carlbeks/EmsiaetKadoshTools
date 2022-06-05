#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <WinUser.h>
#include <time.h>
#include <thread>
#pragma warning(disable:4309)
#pragma warning(disable:4311)

std::string string;
bool r_command_bool=true;
bool r1_command_bool=false;
std::string dec2hex(int i, int width)
{
	std::stringstream ioss;     //定义字符串流
	std::string s_temp;         //存放转化后字符
	ioss << std::hex << i;      //以十六制形式输出
	ioss >> s_temp;
	if (width > s_temp.size())
	{
		std::string s_0(width - s_temp.size(), '0');      //位数不够则补0
		s_temp = s_0 + s_temp;                            //合并
	}
	std::string s = s_temp.substr(s_temp.length() - width, s_temp.length());    //取右width位
	return s;
}
void recognize(int c, WPARAM w) {
	if (w == WM_KEYDOWN) {
		std::string strTemp = dec2hex(c, 2);
		printf(" <KeyCode> ");
		std::cout << c << " >> 0x" << strTemp << std::endl << " <KeyName> ";
		//putchar(x);
		switch (c) {
		case 8:
			std::cout << "BackSpace";
			string = string.substr(0, string.length() - 1);
			break;
		case 9:
			std::cout << "Tab";
			string += " ";
			break;
		case 12:
			std::cout << "Clear";
			break;
		case 13:
			std::cout << "Enter";
			r1_command_bool = true;
			break;
		case 16:
			std::cout << "Shift";
			break;
		case 17:
			std::cout << "Ctrl";
			break;
		case 18:
			std::cout << "Alt";
			break;
		case 19:
			std::cout << "Pause";
			break;
		case 20:
			std::cout << "Caps Lock";
			break;
		case 27:
			std::cout << "Esc";
			string = "";
			break;
		case 32:
			std::cout << "SpaceBar";
			break;
		case 33:
			std::cout << "PageUp";
			break;
		case 34:
			std::cout << "PageDown";
			break;
		case 35:
			std::cout << "End";
			break;
		case 36:
			std::cout << "Home";
			break;
		case 37:
			std::cout << "Left";
			break;
		case 38:
			std::cout << "Up";
			break;
		case 39:
			std::cout << "Right";
			break;
		case 40:
			std::cout << "Down";
			break;
		case 41:
			std::cout << "Select";
			break;
		case 42:
			std::cout << "Print";
			break;
		case 43:
			std::cout << "Execute";
			break;
		case 44:
			std::cout << "PrintScreen";
			break;
		case 45:
			std::cout << "Insert";
			break;
		case 46:
			std::cout << "Delete";
			break;
		case 47:
			std::cout << "Help";
			break;
		case 48:
			std::cout << "0";
			string += "0";
			break;
		case 49:
			std::cout << "1";
			string += "1";
			break;
		case 50:
			std::cout << "2";
			string += "2";
			break;
		case 51:
			std::cout << "3";
			string += "3";
			break;
		case 52:
			std::cout << "4";
			string += "4";
			break;
		case 53:
			std::cout << "5";
			string += "5";
			break;
		case 54:
			std::cout << "6";
			string += "6";
			break;
		case 55:
			std::cout << "7";
			string += "7";
			break;
		case 56:
			std::cout << "8";
			string += "8";
			break;
		case 57:
			std::cout << "9";
			string += "9";
			break;
		case 65:
			std::cout << "A";
			string += "a";
			break;
		case 66:
			std::cout << "B";
			string += "b";
			break;
		case 67:
			std::cout << "C";
			string += "c";
			break;
		case 68:
			std::cout << "D";
			string += "d";
			break;
		case 69:
			std::cout << "E";
			string += "e";
			break;
		case 70:
			std::cout << "F";
			string += "f";
			break;
		case 71:
			std::cout << "G";
			string += "g";
			break;
		case 72:
			std::cout << "H";
			string += "h";
			break;
		case 73:
			std::cout << "I";
			string += "i";
			break;
		case 74:
			std::cout << "J";
			string += "j";
			break;
		case 75:
			std::cout << "K";
			string += "k";
			break;
		case 76:
			std::cout << "L";
			string += "l";
			break;
		case 77:
			std::cout << "M";
			string += "m";
			break;
		case 78:
			std::cout << "N";
			string += "n";
			break;
		case 79:
			std::cout << "O";
			string += "o";
			break;
		case 80:
			std::cout << "P";
			string += "p";
			break;
		case 81:
			std::cout << "Q";
			string += "q";
			break;
		case 82:
			std::cout << "R";
			string += "r";
			break;
		case 83:
			std::cout << "S";
			string += "s";
			break;
		case 84:
			std::cout << "T";
			string += "t";
			break;
		case 85:
			std::cout << "U";
			string += "u";
			break;
		case 86:
			std::cout << "V";
			string += "v";
			break;
		case 87 :
			std::cout << "W";
			string += "w";
			break;
		case 88:
			std::cout << "X";
			string += "x";
			break;
		case 89:
			std::cout << "Y";
			string += "y";
			break;
		case 90:
			std::cout << "Z";
			string += "z";
			break;
		default:
			std::cout << "<UnknownKey>";
			break;
		}
	std::cout << std::endl;
	std::cout << " <commander> " << string << std::endl;
	}
}
LRESULT CALLBACK callback(int nCode, WPARAM w, LPARAM l) {
	//KBDLLHOOKSTRUCT* T = (KBDLLHOOKSTRUCT*)l;
	//DWORD x = T->vkCode;
	//int c = (int)x;
	//recognize(c, w);
	PostMessage(HWND_TOPMOST, nCode, w, l);
	return 1;
}
/*
class rtd {
public:
	int r = 0;
	int t = -1;
};
rtd rtdata;
void loopGetMessage() {
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		std::cout << "get?" << std::endl;
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		break;
	}
}
void inputer() {
	float T = -1.0;
	std::cout << " <Require> << \'挂钩频率（0 ms为系统最大速度）\'" << std::endl;
	while (T < 0){
		std::cout << " << 每 ____ ms\b\b\b\b\b\b\b";
		std::cin >> T;
	}
	int t = (int)T;
	int r = 0;
	std::cout << " <Require> << \'输出按键信息（输入1）或 传递给系统处理（输入2）\'" << std::endl;
	while (r != 1 and r != 2) {
		std::cout << " << 方式[_]\b\b";
		std::cin >> r;
	}
	rtdata.r = r;
	rtdata.t = t;
	return;
}
void r1() {
	MSG msg;
	while (r_command_bool) {
		HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, EmsiaetKadoshHooks, GetModuleHandle(NULL), 0);
		// GetModuleHandle(NULL) 将返回创建调用进程（.exe文件）的文件的句柄；0似乎是当前进程的意思。
		//loopGetMessage();
		while (PeekMessage(&msg, NULL, WM_KEYFIRST, WM_KEYLAST, PM_NOREMOVE)) {
			std::cout << "get?" << std::endl;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			break;
		}
		//Sleep(rtdata.t);
		UnhookWindowsHookEx(hook);
	}
	return;
}
void r2() {
	while (r_command_bool) {
		HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, EmsiaetKadoshHooks, GetModuleHandle(NULL), 0);
		// GetModuleHandle(NULL) 将返回创建调用进程（.exe文件）的文件的句柄。　
		Sleep(rtdata.t);
		UnhookWindowsHookEx(hook);
	}
	return;
}
void starthook() {
	r_command_bool = true;
	if (rtdata.r == 1) {
		r1_command_bool = false;
		string = "";
		r1();
	}
	else if (rtdata.r == 2) {
		r2();
	}
	return;
}
void stophook() {
	r_command_bool = false;
	string = "";
}
bool commander(std::string ipt) {
	if (ipt == "stop") {
		return false;
	}
	else if (ipt == "reset") {
		stophook();
		inputer();
		starthook();
		return true;
	}
	else if (ipt == "pause") {
		stophook();
		return true;
	}
	else if (ipt == "continue") {
		starthook();
		return true;
	}
}
void EKHOOK() {
	inputer();
	starthook();
	bool C = true;
	while (C) {
		if (rtdata.r == 1) {
			if (r1_command_bool) {
				C = commander(string);
				string = "";
			}
		}
		else if (rtdata.r == 2) {
			std::string str;
			std::cout << " <Commander> ";
			std::cin >> str;
			C = commander(str);
		}
	}
}
int main() {
	EKHOOK();

	HHOOK hook = ::SetWindowsHookEx(WH_KEYBOARD_LL, EmsiaetKadoshHooks, 0, 0);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
*/
int main() {
	while (true) {
		HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, callback, 0, 0);
		Sleep(10);
		UnhookWindowsHookEx(hook);
	}
	return 0;
}