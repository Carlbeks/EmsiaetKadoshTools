#pragma once


#include "Pre_Global_Def.h"


// Def callbackHook()
LRESULT CALLBACK callbackHook(int nCode, WPARAM w, LPARAM l) {
	callbackKeyEvent(MainhWnd, (int)w, (((KBDLLHOOKSTRUCT*)l)->vkCode), 0);
	return 1;
}
LRESULT CALLBACK callbackHoom(int nCode, WPARAM w, LPARAM l) {
	if (w == WM_MOUSEMOVE) {
	}
	return CallNextHookEx(hoom, nCode, w, l);
}
