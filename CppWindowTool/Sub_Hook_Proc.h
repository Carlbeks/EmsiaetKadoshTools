#pragma once


#include "PreSub_Global_Def.h"


// PreDef Global HookFunc
LRESULT CALLBACK	callbackHook(int, WPARAM, LPARAM);
void				sethook();


// Def callbackHook()
LRESULT CALLBACK callbackHook(int nCode, WPARAM w, LPARAM l) {
	callbackKeyEvent(MainhWnd, nCode, w, l);
	return 1;
}
LRESULT CALLBACK callbackHoom(int nCode, WPARAM w, LPARAM l) {
	//PostMessage(MainhWnd, nCode, w, l);
	return 1;
}
// Def sethook() [new thread]
void sethook() {
	while (true) {
		hook = SetWindowsHookEx(WH_KEYBOARD_LL, callbackHook, 0, 0);
		Sleep(50);
		UnhookWindowsHookEx(hook);
	}
	return;
}
