// 
// EmsiaetKadoshDesktopTool-pre3.cpp : 定义应用程序的入口点。
//

#include "PreGlobal.h"
#include "Sub_MainProcess.h"

#define MAX_LOADSTRING 100

// 全局变量:
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int __stdcall wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) {
    ShowCmd(CMD_stdout);
    logging.logrank = LOG_INFO;
    logging.Output(LOG_INFO, "EKDT started!");

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。
    std::thread imThread(f_InnerMessageLoop);
    imThread.detach();
    std::thread mainThread(f_MainLoop);
    mainThread.detach();
    std::thread hookThread(f_HookLoop);
    hookThread.detach();

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EMSIAETKADOSHDESKTOPTOOLPRE3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow)) {
        logging.Output(LOG_OFF, "Failed to init.");
        return FALSE;
    }
    else {
        logging.Output(LOG_INFO, "Init fin.");
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EMSIAETKADOSHDESKTOPTOOLPRE3));

    MSG msg = { 0 };

    // 主消息循环:
    logging.Output(LOG_INFO, "Starting message loop...");
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        Counter();
    }

    // 清理资源

    logging.Output(LOG_OFF, "Got WM_QUIT.");
    logging.Output(LOG_OFF, "Shutting down.");
    ifloopMain_temp = false;
    ifloopHook_temp = false;
    IsMainMessageLoopActive = false;
    logging.SetOutputColor(LOG_INFO);
    StepThreadBlocker.releaseAll();
    if (InnerMessage.isActive()) {
        InnerMessage.PostInnerMessage(IM_QUIT, 0, 0, 0);
    }
    Sleep(1000);
    system("Pause");

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EMSIAETKADOSHDESKTOPTOOLPRE3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = 0;// MAKEINTRESOURCEW(IDC_EMSIAETKADOSHDESKTOPTOOLPRE3);
    wcex.lpszClassName  = szWindowClass;
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

   TARGET_H = SCREEN_H / 2;
   TARGET_W = max(SCREEN_W / 16, TARGET_H / 4);
   POS_H = TARGET_H / 2;
   HWND hWnd = CreateWindowW(szWindowClass, szTitle,
       WS_VISIBLE | WS_BORDER | WS_DLGFRAME
       , 0, 0, 300, 300, nullptr, nullptr, hInstance, nullptr);
   MainhWnd = hWnd;

   if (!hWnd)
   {
      return FALSE;
   }

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
__int64 __stdcall WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    std::string the_msg_str;
    switch (message)
    {
    case WM_SYSKEYDOWN:
        the_msg_str = "GetMsg: WM_SYSKEYDOWN";
        logging.Output(LOG_ALL, the_msg_str);
        EkmsgKeyStatus[wParam] = true;
        break;
    case WM_KEYUP:
        the_msg_str = "GetMsg: WM_KEYUP";
        logging.Output(LOG_ALL, the_msg_str);
        EkmsgKeyStatus[wParam] = false;
        break;
    case WM_SYSKEYUP:
        the_msg_str = "GetMsg: WM_SYSKEYUP";
        logging.Output(LOG_ALL, the_msg_str);
        EkmsgKeyStatus[wParam] = false;
        break;
    case WM_LBUTTONDOWN:
        the_msg_str = "GetMsg: WM_LBUTTONDOWN";
        logging.Output(LOG_ALL, the_msg_str);
        EkmsgMouseClicked[0] = true;
        GetCursorClientPosition(hWnd,&EkmsgCursorPosition);
        break;
    case WM_LBUTTONUP:
        the_msg_str = "GetMsg: WM_LBUTTONUP";
        logging.Output(LOG_ALL, the_msg_str);
        EkmsgMouseClicked[0] = false;
        GetCursorClientPosition(hWnd, &EkmsgCursorPosition);
        InnerMessage.PostInnerMessage(IM_ACT, ACT_MOUSE, MOUSE_L_U, 0);
        break;
    case WM_MBUTTONDOWN:
        the_msg_str = "GetMsg: WM_MBUTTONDOWN";
        logging.Output(LOG_ALL, the_msg_str);
        EkmsgMouseClicked[1] = true;
        GetCursorClientPosition(hWnd, &EkmsgCursorPosition);
        break;
    case WM_MBUTTONUP:
        the_msg_str = "GetMsg: WM_MBUTTONUP";
        logging.Output(LOG_ALL, the_msg_str);
        EkmsgMouseClicked[1] = false;
        GetCursorClientPosition(hWnd, &EkmsgCursorPosition);
        break;
    case WM_RBUTTONDOWN:
        the_msg_str = "GetMsg: WM_RBUTTONDOWN";
        logging.Output(LOG_ALL, the_msg_str);
        EkmsgMouseClicked[2] = true;
        GetCursorClientPosition(hWnd, &EkmsgCursorPosition);
        InnerMessage.PostInnerMessage(IM_ACT, ACT_MOUSE, MOUSE_R_D, 0);
        break;
    case WM_RBUTTONUP:
        the_msg_str = "GetMsg: WM_RBUTTONUP";
        logging.Output(LOG_ALL, the_msg_str);
        EkmsgMouseClicked[2] = false;
        GetCursorClientPosition(hWnd, &EkmsgCursorPosition);
        break;
    case WM_MOUSEMOVE:
        if (IsMouseOut) {
            ZeroMemory(&MouseEvent, sizeof(TRACKMOUSEEVENT));
            MouseEvent.cbSize = sizeof(TRACKMOUSEEVENT);

            MouseEvent.hwndTrack = MainhWnd;
            MouseEvent.dwFlags = TME_LEAVE;
            MouseEvent.dwHoverTime = HOVER_DEFAULT;

            TrackMouseEvent(&MouseEvent);
            IsMouseOut = false;
        }
        the_msg_str = "GetMsg: WM_MOUSEMOVE";
        logging.Output(LOG_ALL, the_msg_str);
        GetCursorClientPosition(hWnd, &EkmsgCursorPosition);
        POS_W = SHOW_W;
        break;
    case WM_MOUSELEAVE:
        POS_W = HIDE_W - TARGET_W;
        IsMouseOut = true;
        the_msg_str = "GetMsg: WM_MOUSELEAVE";
        logging.Output(LOG_ALL, the_msg_str);
        InnerMessage.PostInnerMessage(IM_ACT, ACT_MOUSE, MOUSE_LEAVE, 0);
        break;
    //case WM_COMMAND:
    //    the_msg_str = "GetMsg: WM_COMMAND";
    //    logging.Output(LOG_ALL, the_msg_str);
    //    {
    //        int wmId = LOWORD(wParam);
    //        // 分析菜单选择:
    //        switch (wmId)
    //        {
    //        case IDM_ABOUT:
    //            DialogBox(MainhInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
    //            break;
    //        case IDM_EXIT:
    //            DestroyWindow(hWnd);
    //            break;
    //        default:
    //            return DefWindowProc(hWnd, message, wParam, lParam);
    //        }
    //    }
    //    break;
    case WM_PAINT:
        the_msg_str = "GetMsg: WM_PAINT";
        logging.Output(LOG_ALL, the_msg_str);
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        the_msg_str = "GetMsg: WM_DESTROY";
        logging.Output(LOG_ALL, the_msg_str);
        PostQuitMessage(0);
        break;
    default:
        //char the_msg_char[16];
        //itoa(message, the_msg_char, 16);
        //the_msg_str = the_msg_char;
        //logging.Output(LOG_ALL, JoinString("GetMsg: ", the_msg_str));
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
