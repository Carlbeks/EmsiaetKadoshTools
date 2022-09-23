#pragma once

#include "PreGlobal.h"
#define COUTEDL(___in___) std::cout<<___in___<<std::endl


b ifloopMain_temp = true;
b top_temp = false;	
v f_MainProgress() {
	SetWindowPos(MainhWnd, HWND_TOPMOST, POS_W, POS_H, TARGET_W, TARGET_H, SWP_SHOWWINDOW | SWP_FRAMECHANGED);
	if (IsKill) {
		HWND hWnd = FindWindow(NULL, L"此电脑");
		SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, 500, 500, SWP_NOSENDCHANGING | SWP_HIDEWINDOW);
		HWND hWndMythVirus = FindWindow(NULL, L"屏幕广播");
		SetWindowPos(hWndMythVirus, HWND_BOTTOM, 0, 0, SCREEN_W, SCREEN_H, SWP_NOSENDCHANGING | SWP_HIDEWINDOW);
		if (!top_temp) {
			InnerMessage.PostInnerMessageLogU(LOG_WARN, "!!! TO KILL !!!");
			top_temp = true;
		}
	}
	else {
		if (top_temp) {
			top_temp = false;
			InnerMessage.PostInnerMessageLogU(LOG_WARN, "___ FORGIVE ___");
			HWND hWndMythVirus = FindWindow(NULL, L"屏幕广播");
			SetWindowPos(hWndMythVirus, HWND_TOP, 0, 0, SCREEN_W, SCREEN_H, SWP_NOSENDCHANGING | SWP_SHOWWINDOW);
			HWND hWnd = FindWindow(NULL, L"此电脑");
			SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 500, 500, SWP_NOSENDCHANGING | SWP_SHOWWINDOW);
		}
	}
	Sleep(1);
	er;
}
v f_MainLoop() {
	logging.Output(LOG_INFO, "f_MainLoop start.");
	while (ifloopMain_temp) {
		f_MainProgress();
	}
	logging.Output(LOG_INFO, "f_MainLoop exit.");
	er;
}

n InnerMsgProc(un3 c_, un3 f_, un3 i_, n t_) {
	switch (c_)
	{
	case IM_ACT:
		switch (f_)
		{
		case ACT_MOUSE:
			switch (i_)
			{
			case MOUSE_R_D:
				if (ExitCallCount == 4) {
					logging.Output(LOG_WARN, "5 / 5 to close.");
					InnerMessage.PostInnerMessage(IM_QUIT, 0, 0, 0);
					er0;
				}
				else {
					ExitCallCount++;
					logging.Output(LOG_WARN, JoinString(IntToString_OCT(ExitCallCount)," / 5 to close"));
				}
				break;
			case MOUSE_LEAVE:
				if (ExitCallCount) {
					ExitCallCount = 0;
					logging.Output(LOG_WARN, "0 / 5 to close.");
				}
				break;
			case MOUSE_L_U:
				IsKill = !IsKill;
				er0;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	er1;
}
v f_InnerMessageLoop() {
	logging.Output(LOG_INFO, "f_InnerMessageLoop start.");
	InnerMessage.Init(InnerMsgProc);
	EKMSG* pekmsg_ = new EKMSG;
	while (InnerMessage.GetInnerMessageS(pekmsg_)) {
		InnerMessage.DispatchInnerMessage(pekmsg_);
	}
	logging.Output(LOG_INFO, "f_InnerMessageLoop exit.");
	if (IsMainMessageLoopActive) {
		PostQuitMessage(0);
		PostMessage(MainhWnd, WM_QUIT, 0, 0);
	}
	er;
}

bool ifloopHook_temp = true;
v f_HookLoop() {
	logging.Output(LOG_INFO, "f_HookLoop start.");
	def(__int64, __stdcall proc, (n, WPARAM, LPARAM)) = [](n nc, WPARAM w, LPARAM l)->__int64 {
		PostMessage(HWND_BROADCAST, nc, w, l);
		er1;
	};
	while (ifloopHook_temp) {
		HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, proc, 0, 0);
		Sleep(10);
		UnhookWindowsHookEx(hook);
	}
	logging.Output(LOG_INFO, "f_HookLoop exit.");
	er;

	logging.Output(LOG_INFO, "f_HookLoop start.");
	HMODULE hmd = LoadLibrary(L"D:\\EmsiaetKadosh\\O\\ProjectSaves\\EKTools\\x64\\Release\\HookDll.dll");
	std::cout << hmd << std::endl;
	if (!hmd) {
		logging.Output(LOG_INFO, "f_HookLoop shut.");
		er;
	}
	HOOKPROC HookProc = (HOOKPROC)GetProcAddress(hmd, "HookProc");
	v(*call)() = (v(*)())GetProcAddress(hmd, "call");
	HHOOK(*SetHookLocal)(n, HOOKPROC, HINSTANCE, DWORD) = (HHOOK(*)(n, HOOKPROC, HINSTANCE, DWORD))GetProcAddress(hmd, "SetHookLocal");
	b(*UnHookLocal)(HHOOK) = (b(*)(HHOOK))GetProcAddress(hmd, "UnHookLocal");
	//void(*HookLoop)(bool*, int, int, HOOKPROC, HINSTANCE, DWORD) = (void(*)(bool*, int, int, HOOKPROC, HINSTANCE, DWORD))GetProcAddress(hmd, "HookLoop");
	COUTEDL(HookProc);
	COUTEDL(call);
	COUTEDL(SetHookLocal);
	COUTEDL(UnHookLocal);
	//COUTEDL(HookLoop);
	if (!HookProc || !call || !SetHookLocal || !UnHookLocal) {
		ifloopHook_temp = false;
		er;
	}
	call();
	while (ifloopHook_temp) {
		HHOOK the_ = SetHookLocal(WH_KEYBOARD_LL, HookProc, 0, 0);
		Sleep(1000);
		UnHookLocal(the_);
	}
	//hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookProc, 0, 0);
	//while (ifloopHook_temp) {
	//	std::cout << UnhookWindowsHookEx(hook) << std::endl;
	//	hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookProc, 0, 0);
	//	std::cout << hook << std::endl;
	//	Sleep(1000);
	//}
	//UnhookWindowsHookEx(hook);
	FreeLibrary(hmd);
	logging.Output(LOG_INFO, "f_HookLoop exit.");
	er;
}
