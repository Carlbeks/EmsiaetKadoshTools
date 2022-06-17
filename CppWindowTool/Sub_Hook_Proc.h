#pragma once


#include "Pre_Global_Def.h"


// Def callbackHook()
LRESULT CALLBACK callbackHook(int nCode, WPARAM w, LPARAM l) {
	callbackKeyEvent(MainhWnd, (int)w, (((KBDLLHOOKSTRUCT*)l)->vkCode), 0);
	return 1;
}
LRESULT CALLBACK callbackHoom(int nCode, WPARAM w, LPARAM l) {
	if (w == WM_MOUSEMOVE) {
		PostMessage(NULL, (int)w, NULL, (LPARAM) & (((MSLLHOOKSTRUCT*)l)->pt));
	}
	else
	{
		callbackMouseEvent(MainhWnd, (int)w, NULL, (LPARAM) & (((MSLLHOOKSTRUCT*)l)->pt));
	}
	return 1;
}

// Def sethook()
void sethook() {
	hook = SetWindowsHookEx(WH_KEYBOARD_LL, callbackHook, 0, 0);
	while (true) {
		if (PeekMessage(&(hookmsg.msg), NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&(hookmsg.msg));
			DispatchMessage(&(hookmsg.msg));
		}
	}
	return;
}

// Def sethookEx() [new thread]
void sethookEx() {
	while (true) {
		hook = SetWindowsHookEx(WH_KEYBOARD_LL, callbackHook, 0, 0);
		while (true) {
			if (PeekMessage(&(hookmsg.msg), NULL, 0, 0, PM_REMOVE)) {
				TranslateMessage(&(hookmsg.msg));
				DispatchMessage(&(hookmsg.msg));
			}
			UnhookWindowsHookEx(hook);
		}
		return;
	}
}

void sethoom() {
	hoom = SetWindowsHookEx(WH_MOUSE_LL, callbackHoom, 0, 0);
	while (true) {
		if (PeekMessage(&(hoommsg.msg), NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&(hoommsg.msg));
			DispatchMessage(&(hoommsg.msg));
		}
	}
	return;
}