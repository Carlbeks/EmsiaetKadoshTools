#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <WinUser.h>
#include <time.h>
#include <thread>
#pragma warning(disable:4309)
#pragma warning(disable:4311)
std::string dec2hex(int i, int width)
{
	std::stringstream ioss;     //�����ַ�����
	std::string s_temp;         //���ת�����ַ�
	ioss << std::hex << i;      //��ʮ������ʽ���
	ioss >> s_temp;
	if (width > s_temp.size())
	{
		std::string s_0(width - s_temp.size(), '0');      //λ��������0
		s_temp = s_0 + s_temp;                            //�ϲ�
	}
	std::string s = s_temp.substr(s_temp.length() - width, s_temp.length());    //ȡ��widthλ
	return s;
}

LRESULT CALLBACK EmsiaetKadoshHooks(
	int nCode,
	WPARAM w,
	LPARAM l
) {
	KBDLLHOOKSTRUCT* T = (KBDLLHOOKSTRUCT*)l;
	DWORD x = T -> vkCode;
	int c = (int)x;
	if (w == WM_KEYDOWN) {
		std::string strTemp = dec2hex(c, 2);
		printf(" >> From ><< Keyboard vkcode >> ");
		std::cout << c << " >> 0x" << strTemp << std::endl << "                            " << " >> recognize >>";
		//putchar(x);
		switch (c) {
		case 8:
			std::cout << " > BackSpace <";
			break;
		case 9:
			std::cout << " > Tab <";
			break;
		case 12:
			std::cout << " > Clear <";
			break;
		case 13:
			std::cout << " > Enter <";
			break;
		case 16:
			std::cout << " > Shift <";
			break;
		case 17:
			std::cout << " > Ctrl <";
			break;
		case 18:
			std::cout << " > Alt <";
			break;
		case 19:
			std::cout << " > Pause <";
			break;
		case 20:
			std::cout << " > Caps Lock <";
			break;
		case 27:
			std::cout << " > Esc <";
			break;
		case 32:
			std::cout << " > SpaceBar <";
			break;
		case 33:
			std::cout << " > PageUp <";
			break;
		case 34:
			std::cout << " > PageDown <";
			break;
		case 35:
			std::cout << " > End <";
			break;
		case 36:
			std::cout << " > Home <";
			break;
		case 37:
			std::cout << " > Left <";
			break;
		case 38:
			std::cout << " > Up <";
			break;
		case 39:
			std::cout << " > Right <";
			break;
		case 40:
			std::cout << " > Down <";
			break;
		case 41:
			std::cout << " > Select <";
			break;
		case 42:
			std::cout << " > Print <";
			break;
		case 43:
			std::cout << " > Execute <";
			break;
		case 44:
			std::cout << " > PrintScreen <";
			break;
		case 45:
			std::cout << " > Insert <";
			break;
		case 46:
			std::cout << " > Delete <";
			break;
		case 47:
			std::cout << " > Help <";
			break;
		case 48:
			std::cout << " > 0 <";
			break;
		case 49:
			std::cout << " > 1 <";
			break;
		case 50:
			std::cout << " > 2 <";
			break;
		case 51:
			std::cout << " > 3 <";
			break;
		case 52:
			std::cout << " > 4 <";
			break;
		case 53:
			std::cout << " > 5 <";
			break;
		case 54:
			std::cout << " > 6 <";
			break;
		case 55:
			std::cout << " > 7 <";
			break;
		case 56:
			std::cout << " > 8 <";
			break;
		case 57:
			std::cout << " > 9 <";
			break;
		case 65:
			std::cout << " > A <";
			break;
		case 66:
			std::cout << " > B <";
			break;
		case 67:
			std::cout << " > C <";
			break;
		case 68:
			std::cout << " > D <";
			break;
		case 69:
			std::cout << " > E <";
			break;
		default:
			std::cout << " > ? <";
			break;
		}
		std::cout << std::endl;
	}
	PostMessage(HWND_BROADCAST, nCode, w, l);
	return 1;
}

void sethook() {
	HHOOK hook = ::SetWindowsHookEx(WH_KEYBOARD_LL, EmsiaetKadoshHooks, 0, 0);
	while (true) {
		HHOOK hook = ::SetWindowsHookEx(WH_KEYBOARD_LL, EmsiaetKadoshHooks, 0, 0);
		MSG msg;
		if (GetMessage(&msg, NULL, 0, 0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			DefWindowProc(HWND_BROADCAST, msg.message, msg.wParam, msg.lParam);
		}
		Sleep(500);
		UnhookWindowsHookEx(hook);
	}
	return;
}

int main() {
	/*
	//window class
	TCHAR name[] = TEXT("EmsiaetKadoshHook Test Window");
	WNDCLASS win{0};
	win.cbClsExtra = 0;
	win.cbWndExtra = 0;
	win.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	win.hCursor = LoadCursor(NULL, 
		//IDC_APPSTARTING ��׼�ļ�ͷ��Сɳ©
		//IDC_ARROW ��׼�ļ�ͷ
		//IDC_CROSS ʮ�ֹ��
		//IDC_HELP ��׼�ļ�ͷ���ʺ�
		//IDC_IBEAM ���ֹ��
		//IDC_NO ��ֹȦ
		//IDC_SIZEALL �����ͷָ�򶫡������ϡ���
		//IDC_SIZENESW ˫��ͷָ�򶫱�������
		//IDC_SIZENS ˫��ͷָ���ϱ�
		//IDC_SIZENWSE ˫��ͷָ�������Ͷ���
		//IDC_SIZEWE ˫��ͷָ����
		//IDC_UPARROW ��ֱ��ͷ
		//IDC_WAIT ɳ©����ֵ������ɹ�������ֵ��������Ĺ��ľ�������ʧ�ܣ�����ֵ��NULL�������ø��������Ϣ�������GetLastError������
		IDC_ARROW);
	win.hIcon = NULL;
	win.hInstance = hInstance;
	win.lpfnWndProc = windowproc;
	*/
	std::thread thr(sethook);
	thr.join();
	return 0;
}