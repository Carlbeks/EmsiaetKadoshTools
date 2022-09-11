// Main

#include "MainProgress.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, MainWindowTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CPPWINDOWTOOLPRE2, MainWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance(hInstance, nCmdShow)) {
        return FALSE;
    }/*
    if (GuiPrintInit(MainhWnd) == E_FAIL) {
        return FALSE;
    }*/
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CPPWINDOWTOOLPRE2));
    GetClientRect(MainhWnd, &GuiRectangle_Present);
    ShowWindow(MainhWnd, nCmdShow);
    UpdateWindow(MainhWnd);

    ekThreadBlocker MainEkThreadBlocker;
    ekWindow MainEkwindow;
    pf(v, Defines[128], (ekThreadBlocker*, ekWindow*));
    pf(v, Executes[128], (ekThreadBlocker*, ekWindow*));
    MainPreDefine(Defines, Executes, &MainEkwindow);
    b MainDefineThreadIfLoop = true;
    std::thread MainDefineThread(MainDefine, &MainEkThreadBlocker, &MainEkwindow, &MainDefineThreadIfLoop, Defines);
    MainDefineThread.detach();

    if (MainInit()) {
        WINDOWOUT_WRONG(L"启动失败：程序初始化失败");
        er FALSE;
    }
    if (TestProgress()) {
        WINDOWOUT_WRONG(L"启动失败：测试脚本错误");
        return FALSE;
    }


    // 主消息循环:
    MSG MainMsg;
    while (GetMessage(&MainMsg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(MainMsg.hwnd, hAccelTable, &MainMsg))
        {
            TranslateMessage(&MainMsg);
            DispatchMessage(&MainMsg);
        }
        if (MainEkwindow.repaint) {
            MainEkThreadBlocker.release();
            MainEkwindow.repaint = false;
        }
        PrintStart();
        MainEkwindow.reset();
        Executes[MainEkwindow.Windows[MainEkwindow.Window]](&MainEkThreadBlocker, &MainEkwindow);
        PrintEnd();
        //if () { WINDOWOUT_WRONG(L"启动失败：主循环错误"); }
    }

    // 内存清理与收尾
    MainDefineThreadIfLoop = false;
    MainEkThreadBlocker.release();
    d3drelease();
    return (int) MainMsg.wParam;
}

//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW /*宽变重绘*/ | CS_VREDRAW /*高变重绘*/;// | CS_NOCLOSE /*禁用关闭按钮 | CS_DBLCLKS 双击识别*/;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CPPWINDOWTOOLPRE2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CPPWINDOWTOOLPRE2);
    wcex.lpszClassName  = MainWindowClass;
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
   MainhInstance = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(MainWindowClass, MainWindowTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)   
   {
      return FALSE;
   }
   MainhWnd = hWnd;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

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
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(MainhInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
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
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            d3drelease();
            MainInit();
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        if (wParam < 128) {
            EkmsgKeyStatus[wParam] = 1;
        }
        break;
    case WM_KEYUP:
        if (wParam < 128) {
            EkmsgKeyStatus[wParam] = 0;
        }
        break;
    case WM_SYSKEYDOWN:
        if (wParam < 128) {
            EkmsgKeyStatus[wParam] = 1;
        }
        break;
    case WM_SYSKEYUP:
        if (wParam < 128) {
            EkmsgKeyStatus[wParam] = 0;
        }
        break;
    case WM_MOUSEMOVE:
        POINT temp;
        GetCursorPos(&temp);
        ScreenToClient(MainhWnd, &temp);
        EkmsgCursorPosition = temp;
        break;
    case WM_LBUTTONDOWN:
        EkmsgMouseClicked = 1;
        break;
    case WM_LBUTTONUP:
        EkmsgMouseClicked = 0;
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
