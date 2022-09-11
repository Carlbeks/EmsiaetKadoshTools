// CppWindowTool.cpp : 定义应用程序的入口点。
//

#include "Pre_Global_Def.h"
#include "Sub_Callback_Proc.h"
#include "Sub_Hook_Proc.h"
#include "Sub_Catcher_Proc.h"
#include "Sub_Printer_Proc.h"


// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void                setTopEx(HWND); //添加的前向声明

// Def WinMain()
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。


    // 初始化全局字符串
    MyRegisterClass(hInstance);


    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        MessageBox(NULL, L"启动失败：未分配句柄", L"EmsiaetKadosh's Desktop Tool Caution", MB_OK);
        return FALSE;
    }
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CPPWINDOWTOOL));

    if (d3d9::Init(MainhWnd) == E_FAIL) {
        MessageBox(NULL, L"启动失败：初始化DX失败", L"EmsiaetKadosh's Desktop Tool Caution", MB_OK);
        return FALSE;
    }


    GetWindowRect(MainhWnd, &WindowRectangle_PrevFsc);
    GetWindowRect(MainhWnd, &WindowRectangle_Present);
    GetClientRect(MainhWnd, &GuiRectangle_Present);
    GetClientRect(MainhWnd, &GuiRectangle_Previous);
    FullscreenStatus = false;
    ShowWindow(MainhWnd, nCmdShow);
    UpdateWindow(MainhWnd);

    std::thread setWindowTop(setTopEx, MainhWnd);
    setWindowTop.detach();
    //std::thread setGlobalHook(sethookEx);
    //setGlobalHook.detach();


    MSG msg = { 0 };
    //hook = SetWindowsHookEx(WH_KEYBOARD_LL, callbackHook, 0, 0);
    //hoom = SetWindowsHookEx(WH_MOUSE_LL, callbackHoom, 0, 0);
    ULONGLONG Systime_Prev_temp = GetTickCount64();
    Systime_Prev = GetTickCount64();
    d3d9::GuiPrinterStartInit();
    while (msg.message != WM_QUIT) {
        //
        // 开始循环
        // 消息循环:
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        // 程序循环:
        Systime = GetTickCount64();
        if (Systime - Systime_Prev >= 15) {
            if (GuiRectangle_Present.right != GuiRectangle_Previous.right or GuiRectangle_Present.bottom != GuiRectangle_Previous.bottom) {
                SAFE_RELEASE(d3dFontPointer_DaWeiRuanYaHei);
                SAFE_RELEASE(d3dFontPointer_XiaoWeiRuanYaHei);
                SAFE_RELEASE(d3dDevicePointer);
                d3d9::Init(MainhWnd);
                d3d9::GuiPrinterStartInit();
                GetClientRect(MainhWnd, &GuiRectangle_Previous);
            }
            d3d9::GuiPrinterStart();
            //UnhookWindowsHookEx(hook);
            //UnhookWindowsHookEx(hoom);
            //hook = SetWindowsHookEx(WH_KEYBOARD_LL, callbackHook, 0, 0);
            //hoom = SetWindowsHookEx(WH_MOUSE_LL, callbackHoom, 0, 0);
            Systime_Prev = GetTickCount64();
        }
        if (Systime - Systime_Prev_temp > 4000) {
            break;
        }
    }
    //UnhookWindowsHookEx(hook);
    //UnhookWindowsHookEx(hoom);
    //hook = SetWindowsHookEx(WH_KEYBOARD_LL, callbackHook, 0, 0);
    //
    // 主循环:
    //
    SAFE_RELEASE(d3dFontPointer_DaWeiRuanYaHei);
    SAFE_RELEASE(d3dFontPointer_XiaoWeiRuanYaHei);
    SAFE_RELEASE(d3dDevicePointer);
    d3d9::Init(MainhWnd);
    Systime_Prev = GetTickCount64();
    while (msg.message != WM_QUIT) {
        // 消息循环:
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        // 程序循环:
        Systime = GetTickCount64();
        if (Systime - Systime_Prev >= 10) {
            if (GuiRectangle_Present.right != GuiRectangle_Previous.right or GuiRectangle_Present.bottom != GuiRectangle_Previous.bottom) {
                SAFE_RELEASE(d3dFontPointer_DaWeiRuanYaHei);
                SAFE_RELEASE(d3dFontPointer_XiaoWeiRuanYaHei);
                SAFE_RELEASE(d3dDevicePointer);
                d3d9::Init(MainhWnd);
                GetClientRect(MainhWnd, &GuiRectangle_Previous);
                PrintInitReq = true;
            }
            d3d9::GuiPrinter();
            //UnhookWindowsHookEx(hook);
            //UnhookWindowsHookEx(hoom);
            //hook = SetWindowsHookEx(WH_KEYBOARD_LL, callbackHook, 0, 0);
            //hoom = SetWindowsHookEx(WH_MOUSE_LL, callbackHoom, 0, 0);
            Systime_Prev = GetTickCount64();
        }
    }
    //
    // 清理资源:
    //
    UnregisterClass(L"EmsiaetKadosh's Desktop Tool", hInstance);
    SAFE_RELEASE(d3dFontPointer_DaWeiRuanYaHei);
    SAFE_RELEASE(d3dFontPointer_XiaoWeiRuanYaHei);
    SAFE_RELEASE(d3dDevicePointer);
    //UnhookWindowsHookEx(hook);
    //UnhookWindowsHookEx(hoom);
    return (int) msg.wParam;
}

//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex = { 0 };

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW /*宽变重绘*/ | CS_VREDRAW /*高变重绘*/;// | CS_NOCLOSE /*禁用关闭按钮 | CS_DBLCLKS 双击识别*/;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CPPWINDOWTOOL));//LoadImage(...);
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(CreateSolidBrush(RGB(0,0,0))/*COLOR_WINDOW+1*/);
    wcex.lpszMenuName   = NULL;//MAKEINTRESOURCEW(IDC_CPPWINDOWTOOL);
    wcex.lpszClassName  = _T("EmsiaetKadosh's Desktop Tool");//szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 将实例句柄存储在全局变量中
    MainhWnd = CreateWindowW(L"EmsiaetKadosh's Desktop Tool", L"EmsiaetKadosh's Desktop Tool", WS_OVERLAPPEDWINDOW, (int)(SCREEN_WIDTH / 6), (int)(SCREEN_HEIGHT / 6), (int)(SCREEN_WIDTH / 1.5), (int)(SCREEN_HEIGHT / 1.5), nullptr, nullptr, hInstance, nullptr);

    if (!MainhWnd)
    {
        return FALSE;
    }

    return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            //wParam 高两个字节 通知码
            //wParam 低两字节 命令ID
            //lParam 发送命令消息的子窗体句柄。
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            // 分析菜单选择:
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        break;
    case WM_CLOSE:
        DestroyWindow(MainhWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_SYSKEYDOWN:
        callbackKeyEvent(MainhWnd, message, wParam, lParam);
        break;
    case WM_KEYDOWN:
        callbackKeyEvent(MainhWnd, message, wParam, lParam);
        break;
    case WM_SYSKEYUP:
        callbackKeyEvent(MainhWnd, message, wParam, lParam);
        break;
    case WM_KEYUP:
        callbackKeyEvent(MainhWnd, message, wParam, lParam);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void setTopEx(HWND hWnd) {
    bool set_temp = false;
    while (true) {
        GetWindowRect(hWnd, &WindowRectangle_Present);
        GetClientRect(hWnd, &GuiRectangle_Present);
        GetCursorPos(&MousePosition);
        if (FullscreenStatus) {
            if (set_temp){
                GetWindowRect(hWnd, &WindowRectangle_PrevFsc);
                GuiRectangle_Present.right = SCREEN_WIDTH;
                GuiRectangle_Present.bottom = SCREEN_HEIGHT;
            }
            SetWindowLongPtr(hWnd, GWL_STYLE, WS_VISIBLE);
            SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SWP_NOREDRAW);
            set_temp = false;
        }
        else {
            GetClientRect(MainhWnd, &GuiRectangle_Present);
            if (set_temp) {}
            else {
                SetWindowLongPtr(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
                SetWindowPos(hWnd, HWND_TOP,
                    WindowRectangle_PrevFsc.left,
                    WindowRectangle_PrevFsc.top,
                    WindowRectangle_PrevFsc.right - WindowRectangle_PrevFsc.left,
                    WindowRectangle_PrevFsc.bottom - WindowRectangle_PrevFsc.top,
                    NULL);
                set_temp = true;
            }
        }
        Sleep(1);
    }
    return;
}
