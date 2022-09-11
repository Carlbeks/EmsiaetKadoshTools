#pragma once


#include "Pre_Global_Def.h"


// 
// Def callbackKeyEvent
// 函数封装了窗口收到键盘进程的消息。主要由WM_KEYUP和WM_KEYDOWN驱动
//
void callbackKeyEvent(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	if (msg != WM_KEYDOWN && msg != WM_SYSKEYDOWN && msg != WM_SYSKEYUP && msg != WM_KEYUP) { return; }
	if (msg == WM_SYSKEYDOWN) {
		msg = WM_KEYDOWN;
	}
	else if (msg == WM_SYSKEYUP) {
		msg = WM_KEYUP;
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
	case VK_LCONTROL:
	case VK_RCONTROL:
	case VK_CONTROL:
		if (msg == WM_KEYDOWN) {
			kd.def.ctrl = 1;
		}
		else
		{
			kd.def.ctrl = 0;
		}
		break;
	case VK_LMENU:
	case VK_RMENU:
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
	case VK_NUMPAD0:
		if (msg == WM_KEYDOWN) {
			kd.num._0 = 1;
		}
		else {
			kd.num._0 = 0;
		}
		break;
	case 49:
	case VK_NUMPAD1:
		if (msg == WM_KEYDOWN) {
			kd.num._1 = 1;
		}
		else {
			kd.num._1 = 0;
		}
		break;
	case 50:
	case VK_NUMPAD2:
		if (msg == WM_KEYDOWN) {
			kd.num._2 = 1;
		}
		else {
			kd.num._2 = 0;
		}
		break;
	case 51:
	case VK_NUMPAD3:
		if (msg == WM_KEYDOWN) {
			kd.num._3 = 1;
		}
		else {
			kd.num._3 = 0;
		}
		break;
	case 52:
	case VK_NUMPAD4:
		if (msg == WM_KEYDOWN) {
			kd.num._4 = 1;
		}
		else {
			kd.num._4 = 0;
		}
		break;
	case 53:
	case VK_NUMPAD5:
		if (msg == WM_KEYDOWN) {
			kd.num._5 = 1;
		}
		else {
			kd.num._5 = 0;
		}
		break;
	case 54:
	case VK_NUMPAD6:
		if (msg == WM_KEYDOWN) {
			kd.num._6 = 1;
		}
		else {
			kd.num._6 = 0;
		}
		break;
	case 55:
	case VK_NUMPAD7:
		if (msg == WM_KEYDOWN) {
			kd.num._7 = 1;
		}
		else {
			kd.num._7 = 0;
		}
		break;
	case 56:
	case VK_NUMPAD8:
		if (msg == WM_KEYDOWN) {
			kd.num._8 = 1;
		}
		else {
			kd.num._8 = 0;
		}
		break;
	case 57:
	case VK_NUMPAD9:
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
	case VK_MULTIPLY:
		if (msg == WM_KEYDOWN) {
			kd.sig.multiply = 1;
		}
		else {
			kd.sig.multiply = 0;
		}
		break;
	case VK_ADD:
		if (msg == WM_KEYDOWN) {
			kd.sig.add = 1;
		}
		else {
			kd.sig.add = 0;
		}
		break;
	case VK_SEPARATOR:
		if (msg == WM_KEYDOWN) {
			kd.sig.separator = 1;
		}
		else {
			kd.sig.separator = 0;
		}
		break;
	case VK_SUBTRACT:
		if (msg == WM_KEYDOWN) {
			kd.sig.subtract = 1;
		}
		else {
			kd.sig.subtract = 0;
		}
		break;
	case VK_DECIMAL:
		if (msg == WM_KEYDOWN) {
			kd.sig.decimal = 1;
		}
		else {
			kd.sig.decimal = 0;	
		}
		break;
	case VK_DIVIDE:
		if (msg == WM_KEYDOWN) {
			kd.sig.divide = 1;
		}
		else {
			kd.sig.divide = 0;
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

	// Win + F + S + C : 切换全屏
	if (kd.def.lwin == 1 and kd.chr.f == 1 and kd.chr.c == 1 and kd.chr.s == 1) {
		FullscreenStatus = !FullscreenStatus;
	}
	// Win + A + E + X : 退出
	else if (kd.def.lwin == 1 and kd.chr.a == 1 and kd.chr.e == 1 and kd.chr.x == 1) {
		PostMessage(MainhWnd, WM_DESTROY, 0, 0);
		PostQuitMessage(0);
	}
		return;
}