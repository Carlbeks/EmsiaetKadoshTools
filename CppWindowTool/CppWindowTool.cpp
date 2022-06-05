// CppWindowTool.cpp : 定义应用程序的入口点。
//

#include "PreSub_Global_Def.h"
#include "Sub_Callback_Proc.h"
#include "Sub_Hook_Proc.h"
#include "Sub_Catcher_Proc.h"
#include "Sub_Printer_Proc.h"
#include "Sub_Controll_Proc.h"


// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void                setTop(HWND); //添加的前向声明


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
    //LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    //LoadStringW(hInstance, IDC_CPPWINDOWTOOL, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        MessageBox(NULL, L"启动失败：未分配句柄", L"EmsiaetKadosh's Desktop Tool Caution", MB_OK | MB_ICONSTOP);
        return FALSE;
    }


    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CPPWINDOWTOOL));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

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

    wcex.style          = CS_HREDRAW /*宽变重绘*/ | CS_VREDRAW /*高变重绘*/ | CS_NOCLOSE /*禁用关闭按钮*/ | CS_DBLCLKS /*双击识别*/;
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
    MainhWnd = CreateWindowW(L"EmsiaetKadosh's Desktop Tool", L"EmsiaetKadosh's Desktop Tool",/*szWindowClass, szTitle,*/ WS_SYSMENU | WS_OVERLAPPED | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!MainhWnd)
    {
        return FALSE;
    }

    //全屏化
    windowStyleLastDword_tempstore = GetWindowLong(MainhWnd, GWL_STYLE);
    GetWindowRect(MainhWnd, &windowRectangleLastRect_tempstore);
    SetWindowLongPtr(MainhWnd, GWL_STYLE, WS_VISIBLE | WS_POPUP);
    SetWindowPos(MainhWnd, NULL, 0, 0, fullscreenMaxWidthInt_store, fullscreenMaxHeightInt_store, SWP_FRAMECHANGED);
    fullscreenBool_judge = true;
    ShowWindow(MainhWnd, nCmdShow);
    UpdateWindow(MainhWnd);
    //置顶
    if (MessageBox(NULL, L"启动成功！", L"EmsiaetKadosh's Desktop Tool Presentation", MB_OK)){}
    std::thread setWindowTop(setTop, MainhWnd);
    setWindowTop.detach();
    // 添加自定义动作
    //std::thread setWindowHook(sethook);
    //setWindowHook.detach();
    // 添加自定义动作
 

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
                //按键功能
                if ((HWND)lParam == guiButtons.__STARTER.Home) {
                    windowGUIStatus_tempstore = EK_GUI_STARTER;
                    PostMessage(MainhWnd, WM_PAINT, wParam, lParam);
                }
                else if ((HWND)lParam == guiButtons.__STARTER.Normal) {
                    windowGUIStatus_tempstore = EK_GUI_WINDOW;
                    PostMessage(MainhWnd, WM_PAINT, wParam, lParam);
                }
                else if ((HWND)lParam == guiButtons.__WINDOW.BACKtoSTART) {
                    windowGUIStatus_tempstore = EK_GUI_STARTER;
                    PostMessage(MainhWnd, WM_PAINT, wParam, lParam);
                }
                else {
                    return DefWindowProc(hWnd, message, wParam, lParam);
                }
            }
        }
        break;
    case WM_PAINT:
        fullscreenPrinter();
        break;
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        callbackKeyEvent(hWnd, message, wParam, lParam);
        break;
    case WM_KEYUP:
        callbackKeyEvent(hWnd, message, wParam, lParam);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 1;
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

void setTop(HWND hWnd) {
    int set = 0;
    while (true) {
        if (fullscreenBool_judge and !popupBool_judge) {
            SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, fullscreenMaxWidthInt_store, fullscreenMaxHeightInt_store, SWP_FRAMECHANGED);
            set = 0;
        }
        else {
            if (set) {}
            else {
                SetWindowPos(hWnd, HWND_NOTOPMOST,
                    windowRectangleLastRect_tempstore.left,
                    windowRectangleLastRect_tempstore.top,
                    windowRectangleLastRect_tempstore.right - windowRectangleLastRect_tempstore.left,
                    windowRectangleLastRect_tempstore.bottom - windowRectangleLastRect_tempstore.top,
                    NULL);
                set = 1;
            }
        }
        Sleep(1);
    }
}


