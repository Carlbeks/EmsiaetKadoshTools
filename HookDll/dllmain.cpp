// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <iostream>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) LRESULT CALLBACK HookProc(int n_, WPARAM w_, LPARAM l_) {
    std::cout << "Got." << std::endl;
    return 1;
}
extern "C" __declspec(dllexport) HHOOK SetHookLocal(int idHook, HOOKPROC lpfn, HINSTANCE hmod, DWORD dwThreadId) {
    return SetWindowsHookEx(idHook, lpfn, hmod, dwThreadId);
}
extern "C" __declspec(dllexport) bool UnHookLocal(HHOOK hhk) {
    return UnhookWindowsHookEx(hhk);
}
extern "C" __declspec(dllexport) void call() {
    std::cout << "Successfully loaded." << std::endl;
    return;
}
extern "C" __declspec(dllexport) void HookLoop(bool* Lct, int time, int idHook, HOOKPROC lpfn, HINSTANCE hmod, DWORD dwThreadId) {
    while (*Lct) {
        HHOOK hook = SetWindowsHookEx(idHook, lpfn, hmod, dwThreadId);
        Sleep(time);
        UnhookWindowsHookEx(hook);
    }
    return;
}
HHOOK hook = 0;
extern "C" __declspec(dllexport) bool SetHook(int idHook, HOOKPROC lpfn, HINSTANCE hmod, DWORD dwThreadId) {
    hook = SetWindowsHookEx(idHook, lpfn, hmod, dwThreadId);
    return hook ? true : false;
}
extern "C" __declspec(dllexport) bool UnHook(HHOOK hhk) {
    return hook ? UnhookWindowsHookEx(hhk) : false;
}