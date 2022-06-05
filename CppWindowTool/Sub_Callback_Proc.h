#pragma once


#include "PreSub_Global_Def.h"
/*
#define VK_LBUTTON        0x01
#define VK_RBUTTON        0x02
#define VK_CANCEL         0x03
#define VK_MBUTTON        0x04    // NOT contiguous with L & RBUTTON

#define VK_BACK           0x08
#define VK_TAB            0x09

#define VK_CLEAR          0x0C
#define VK_RETURN         0x0D

#define VK_SHIFT          0x10
#define VK_CONTROL        0x11
#define VK_MENU           0x12
#define VK_PAUSE          0x13
#define VK_CAPITAL        0x14
#define VK_KANA           0x15
//#define VK_HANGEUL        0x15  old name - should be here for compatibility 
#define VK_HANGUL         0x15
#define VK_JUNJA          0x17
#define VK_FINAL          0x18
#define VK_HANJA          0x19
#define VK_KANJI          0x19

#define VK_ESCAPE         0x1B
#define VK_CONVERT        0x1C
#define VK_NONCONVERT     0x1D
#define VK_ACCEPT         0x1E
#define VK_MODECHANGE     0x1F
#define VK_SPACE          0x20
#define VK_PRIOR          0x21
#define VK_NEXT           0x22
#define VK_END            0x23
#define VK_HOME           0x24
#define VK_LEFT           0x25
#define VK_UP             0x26
#define VK_RIGHT          0x27
#define VK_DOWN           0x28
#define VK_SELECT         0x29
#define VK_PRINT          0x2A
#define VK_EXECUTE        0x2B
#define VK_SNAPSHOT       0x2C
#define VK_INSERT         0x2D
#define VK_DELETE         0x2E
#define VK_HELP           0x2F
 // VK_0 thru VK_9 are the same as ASCII '0' thru '9' (0x30 - 0x39) 
 // VK_A thru VK_Z are the same as ASCII 'A' thru 'Z' (0x41 - 0x5A) 
#define VK_LWIN           0x5B
#define VK_RWIN           0x5C
#define VK_APPS           0x5D

#define VK_NUMPAD0        0x60
#define VK_NUMPAD1        0x61
#define VK_NUMPAD2        0x62
#define VK_NUMPAD3        0x63
#define VK_NUMPAD4        0x64
#define VK_NUMPAD5        0x65
#define VK_NUMPAD6        0x66
#define VK_NUMPAD7        0x67
#define VK_NUMPAD8        0x68
#define VK_NUMPAD9        0x69
#define VK_MULTIPLY       0x6A
#define VK_ADD            0x6B
#define VK_SEPARATOR      0x6C
#define VK_SUBTRACT       0x6D
#define VK_DECIMAL        0x6E
#define VK_DIVIDE         0x6F
#define VK_F1             0x70
#define VK_F2             0x71
#define VK_F3             0x72
#define VK_F4             0x73
#define VK_F5             0x74
#define VK_F6             0x75
#define VK_F7             0x76
#define VK_F8             0x77
#define VK_F9             0x78
#define VK_F10            0x79
#define VK_F11            0x7A
#define VK_F12            0x7B
#define VK_F13            0x7C
#define VK_F14            0x7D
#define VK_F15            0x7E
#define VK_F16            0x7F
#define VK_F17            0x80
#define VK_F18            0x81
#define VK_F19            0x82
#define VK_F20            0x83
#define VK_F21            0x84
#define VK_F22            0x85
#define VK_F23            0x86
#define VK_F24            0x87

#define VK_NUMLOCK        0x90
#define VK_SCROLL         0x91
 *
 * VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
 * Used only as parameters to GetAsyncKeyState() and GetKeyState().
 * No other API or message will distinguish left and right keys in this way.
 *
#define VK_LSHIFT         0xA0
#define VK_RSHIFT         0xA1
#define VK_LCONTROL       0xA2
#define VK_RCONTROL       0xA3
#define VK_LMENU          0xA4
#define VK_RMENU          0xA5

#if(WINVER >= 0x0400)
#define VK_PROCESSKEY     0xE5
#endif // WINVER >= 0x0400 

#define VK_ATTN           0xF6
#define VK_CRSEL          0xF7
#define VK_EXSEL          0xF8
#define VK_EREOF          0xF9
#define VK_PLAY           0xFA
#define VK_ZOOM           0xFB
#define VK_NONAME         0xFC
#define VK_PA1            0xFD
#define VK_OEM_CLEAR      0xFE
*/

// PreDef Global WindowCallback
void callbackKeyEvent(HWND, UINT, WPARAM, LPARAM);

// 
// 【分层】
// 当窗口线程接收到消息时，执行该callback函数。
// 本函数只为分层而创建，由于switch和judge&execute代码太长。
//
void callbackKeyEvent(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	if (msg != WM_KEYDOWN && msg != WM_KEYUP) {
		return;
	}
	switch (wParam)
	{
	case VK_BACK:
		if (msg == WM_KEYDOWN) {
			kd.def.backspace = 1;
		}
		else {
			kd.def.backspace = 0;
		}
		break;
	case VK_TAB:
		if (msg == WM_KEYDOWN) {
			kd.def.tab = 1;
		}
		else {
			kd.def.tab = 0;
		}
		break;
	case VK_CLEAR:
		if (msg == WM_KEYDOWN) {
			kd.def.clear = 1;
		}
		else {
			kd.def.clear = 0;
		}
		break;
	case VK_RETURN:
		if (msg == WM_KEYDOWN) {
			kd.def.returnk = 1;
		}
		else {
			kd.def.returnk = 0;
		}
		break;
	case VK_SHIFT:
		if (msg == WM_KEYDOWN) {
			kd.def.shift = 1;
		}
		else {
			kd.def.shift = 0;
		}
		break;
	case VK_CONTROL:
		if (msg == WM_KEYDOWN) {
			kd.def.ctrl = 1;
		}
		else
		{
			kd.def.ctrl = 0;
		}
		break;
	case VK_MENU:
		if (msg == WM_KEYDOWN) {
			kd.def.menu = 1;
		}
		else {
			kd.def.menu = 0;
		}
		break;
	case VK_CAPITAL:
		if (msg == WM_KEYDOWN) {
			kd.def.capital = 1;
		}
		else {
			kd.def.capital = 0;
		}
		break;
	case VK_ESCAPE:
		if (msg == WM_KEYDOWN) {
			kd.def.escape = 1;
		}
		else {
			kd.def.escape = 0;
		}
		break;
	case VK_SPACE:
		if (msg == WM_KEYDOWN) {
			kd.def.space = 1;
		}
		else {
			kd.def.space = 0;
		}
		break;
	case VK_PRIOR:
		if (msg == WM_KEYDOWN) {
			kd.def.pageUp = 1;
		}
		else {
			kd.def.pageUp = 0;
		}
		break;
	case VK_NEXT:
		if (msg == WM_KEYDOWN) {
			kd.def.pageDown = 1;
		}
		else {
			kd.def.pageDown = 0;
		}
		break;
	case VK_END:
		if (msg == WM_KEYDOWN) {
			kd.def.end = 1;
		}
		else {
			kd.def.end = 0;
		}
		break;
	case VK_HOME:
		if (msg == WM_KEYDOWN) {
			kd.def.home = 1;
		}
		else {
			kd.def.home = 0;
		}
		break;
	case VK_LEFT:
		if (msg == WM_KEYDOWN) {
			kd.def.left = 1;
		}
		else {
			kd.def.left = 0;
		}
		break;
	case VK_UP:
		if (msg == WM_KEYDOWN) {
			kd.def.up = 1;
		}
		else {
			kd.def.up = 0;
		}
		break;
	case VK_RIGHT:
		if (msg == WM_KEYDOWN) {
			kd.def.right = 1;
		}
		else {
			kd.def.right = 0;
		}
		break;
	case VK_DOWN:
		if (msg == WM_KEYDOWN) {
			kd.def.down = 1;
		}
		else {
			kd.def.down = 0;
		}
		break;
	case VK_PRINT:
		if (msg == WM_KEYDOWN) {
			kd.def.print = 1;
		}
		else {
			kd.def.print = 0;
		}
		break;
	case VK_INSERT:
		if (msg == WM_KEYDOWN) {
			kd.def.insert = 1;
		}
		else {
			kd.def.insert = 0;
		}
		break;
	case VK_DELETE:
		if (msg == WM_KEYDOWN) {
			kd.def.deletek = 1;
		}
		else {
			kd.def.deletek = 0;
		}
		break;
	case VK_HELP:
		if (msg == WM_KEYDOWN) {
			kd.def.help = 1;
		}
		else {
			kd.def.help = 0;
		}
		break;
	case 48:
		if (msg == WM_KEYDOWN) {
			kd.num._0 = 1;
		}
		else {
			kd.num._0 = 0;
		}
		break;
	case 49:
		if (msg == WM_KEYDOWN) {
			kd.num._1 = 1;
		}
		else {
			kd.num._1 = 0;
		}
		break;
	case 50:
		if (msg == WM_KEYDOWN) {
			kd.num._2 = 1;
		}
		else {
			kd.num._2 = 0;
		}
		break;
	case 51:
		if (msg == WM_KEYDOWN) {
			kd.num._3 = 1;
		}
		else {
			kd.num._4 = 0;
		}
		break;
	case 52:
		if (msg == WM_KEYDOWN) {
			kd.num._5 = 1;
		}
		else {
			kd.num._5 = 0;
		}
		break;
	case 53:
		if (msg == WM_KEYDOWN) {
			kd.num._6 = 1;
		}
		else {
			kd.num._6 = 0;
		}
		break;
	case 54:
		if (msg == WM_KEYDOWN) {
			kd.num._7 = 1;
		}
		else {
			kd.num._7 = 0;
		}
		break;
	case 55:
		if (msg == WM_KEYDOWN) {
			kd.num._8 = 1;
		}
		else {
			kd.num._8 = 0;
		}
		break;
	case 56:
		if (msg == WM_KEYDOWN) {
			kd.num._9 = 1;
		}
		else {
			kd.num._9 = 0;
		}
		break;
	case 65:
		if (msg == WM_KEYDOWN) {
			kd.chr.a = 1;
		}
		else {
			kd.chr.a = 0;
		}
		break;
	case 66:
		if (msg == WM_KEYDOWN) {
			kd.chr.b = 1;
		}
		else {
			kd.chr.b = 0;
		}
		break;
	case 67:
		if (msg == WM_KEYDOWN) {
			kd.chr.c = 1;
		}
		else {
			kd.chr.c = 0;
		}
		break;
	case 68:
		if (msg == WM_KEYDOWN) {
			kd.chr.d = 1;
		}
		else {
			kd.chr.d = 0;
		}
		break;
	case 69:
		if (msg == WM_KEYDOWN) {
			kd.chr.e = 1;
		}
		else {
			kd.chr.e = 0;
		}
		break;
	case 70:
		if (msg == WM_KEYDOWN) {
			kd.chr.f = 1;
		}
		else {
			kd.chr.f = 0;
		}
		break;
	case 71:
		if (msg == WM_KEYDOWN) {
			kd.chr.g = 1;
		}
		else {
			kd.chr.g = 0;
		}
		break;
	case 72:
		if (msg == WM_KEYDOWN) {
			kd.chr.h = 1;
		}
		else {
			kd.chr.h = 0;
		}
		break;
	case 73:
		if (msg == WM_KEYDOWN) {
			kd.chr.i = 1;
		}
		else {
			kd.chr.i = 0;
		}
		break;
	case 74:
		if (msg == WM_KEYDOWN) {
			kd.chr.j = 1;
		}
		else {
			kd.chr.j = 0;
		}
		break;
	case 75:
		if (msg == WM_KEYDOWN) {
			kd.chr.k = 1;
		}
		else {
			kd.chr.k = 0;
		}
		break;
	case 76:
		if (msg == WM_KEYDOWN) {
			kd.chr.l = 1;
		}
		else {
			kd.chr.l = 0;
		}
		break;
	case 77:
		if (msg == WM_KEYDOWN) {
			kd.chr.m = 1;
		}
		else {
			kd.chr.m = 0;
		}
		break;
	case 78:
		if (msg == WM_KEYDOWN) {
			kd.chr.n = 1;
		}
		else {
			kd.chr.n = 0;
		}
		break;
	case 79:
		if (msg == WM_KEYDOWN) {
			kd.chr.o = 1;
		}
		else {
			kd.chr.o = 0;
		}
		break;
	case 80:
		if (msg == WM_KEYDOWN) {
			kd.chr.p = 1;
		}
		else {
			kd.chr.p = 0;
		}
		break;
	case 81:
		if (msg == WM_KEYDOWN) {
			kd.chr.q = 1;
		}
		else {
			kd.chr.q = 0;
		}
		break;
	case 82:
		if (msg == WM_KEYDOWN) {
			kd.chr.r = 1;
		}
		else {
			kd.chr.r = 0;
		}
		break;
	case 83:
		if (msg == WM_KEYDOWN) {
			kd.chr.s = 1;
		}
		else {
			kd.chr.s = 0;
		}
		break;
	case 84:
		if (msg == WM_KEYDOWN) {
			kd.chr.t = 1;
		}
		else {
			kd.chr.t = 0;
		}
		break;
	case 85:
		if (msg == WM_KEYDOWN) {
			kd.chr.u = 1;
		}
		else {
			kd.chr.u = 0;
		}
		break;
	case 86:
		if (msg == WM_KEYDOWN) {
			kd.chr.v = 1;
		}
		else {
			kd.chr.v = 0;
		}
		break;
	case 87:
		if (msg == WM_KEYDOWN) {
			kd.chr.w = 1;
		}
		else {
			kd.chr.w = 0;
		}
		break;
	case 88:
		if (msg == WM_KEYDOWN) {
			kd.chr.x = 1;
		}
		else {
			kd.chr.x = 0;
		}
		break;
	case 89:
		if (msg == WM_KEYDOWN) {
			kd.chr.y = 1;
		}
		else {
			kd.chr.y = 0;
		}
		break;
	case 90:
		if (msg == WM_KEYDOWN) {
			kd.chr.z = 1;
		}
		else {
			kd.chr.z = 0;
		}
		break;
	case VK_LWIN:
		if (msg == WM_KEYDOWN) {
			kd.def.lwin = 1;
		}
		else {
			kd.def.lwin = 0;
		}
		break;
	case VK_RWIN:
		if (msg == WM_KEYDOWN) {
			kd.def.rwin = 1;
		}
		else {
			kd.def.rwin = 0;
		}
		break;

	default:
		break;
	}
	/*
	* 以上是侦测所有需要的按键状态
	*            {侦测区
	* 键盘消息处理{
	*            {功能区
	* 以下是对特定按键状态组合的反馈
	*/

	/*
	* Ctrl + F + S + C : 切换全屏
	*/
	if (kd.def.ctrl == 1 and kd.chr.f == 1 and kd.chr.c == 1 and kd.chr.s == 1) {
		if (fullscreenBool_judge) {
			SetWindowLongPtr(hWnd, GWL_STYLE, windowStyleLastDword_tempstore);
			SetWindowPos(hWnd, HWND_NOTOPMOST,
				windowRectangleLastRect_tempstore.left,
				windowRectangleLastRect_tempstore.top,
				windowRectangleLastRect_tempstore.right - windowRectangleLastRect_tempstore.left,
				windowRectangleLastRect_tempstore.bottom - windowRectangleLastRect_tempstore.top,
				NULL);
			fullscreenBool_judge = false;
		}
		else {
			windowStyleLastDword_tempstore = GetWindowLong(hWnd, GWL_STYLE);
			GetWindowRect(hWnd, &windowRectangleLastRect_tempstore);
			SetWindowLongPtr(hWnd, GWL_STYLE, WS_VISIBLE | WS_POPUP);
			SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, fullscreenMaxWidthInt_store, fullscreenMaxHeightInt_store, SWP_FRAMECHANGED);
			fullscreenBool_judge = true;
		}
		PostMessage(MainhWnd, WM_PAINT, 0, 0);
	}
	/*
	* Ctrl + A + E + X : 退出
	*/
	else if (kd.def.ctrl == 1 and kd.chr.a == 1 and kd.chr.e == 1 and kd.chr.x == 1) {
		PostMessage(MainhWnd, WM_DESTROY, 0, 0);
	}
	/*
	* Ctrl + S + C + B : 黑屏
	*/
	else if (kd.def.ctrl == 1 and kd.chr.s == 1 and kd.chr.c == 1 and kd.chr.b == 1) {
		if (windowGUIStatus_tempstore != EK_GUI_BLACK) {
			windowGUIStatus_tempstore = EK_GUI_BLACK;
			windowGUIAntiBlack_tempstore = windowGUIStatusLast_tempstore;
			PostMessage(MainhWnd, WM_PAINT, 0, 0);
		}
		else {
			windowGUIStatus_tempstore = windowGUIAntiBlack_tempstore;
			PostMessage(MainhWnd, WM_PAINT, 0, 0);
		}
	}
	else {

	}
}

