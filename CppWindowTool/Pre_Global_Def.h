#pragma once


#include <time.h>
#include <thread>
#include <ios>
#include <d3d9.h>
#include <d3dx9.h>
#include <stdio.h>
#include <windowsx.h>

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"C:\\Program Files (x86)\\DirectX9\\Lib\\x64\\d3dx9.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"comctl32.lib")

#include "CppWindowTool.h"
#include "framework.h"

#define MAX_LOADSTRING 100


struct HOOKMSG {
	int nCode;
	MSG msg;
};
struct KEYDOWN {
	struct CHAR
	{
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		int e = 0;
		int f = 0;
		int g = 0;
		int h = 0;
		int i = 0;
		int j = 0;
		int k = 0;
		int l = 0;
		int m = 0;
		int n = 0;
		int o = 0;
		int p = 0;
		int q = 0;
		int r = 0;
		int s = 0;
		int t = 0;
		int u = 0;
		int v = 0;
		int w = 0;
		int x = 0;
		int y = 0;
		int z = 0;
	};
	CHAR chr;
	struct NUM {
		int _0 = 0;
		int _1 = 0;
		int _2 = 0;
		int _3 = 0;
		int _4 = 0;
		int _5 = 0;
		int _6 = 0;
		int _7 = 0;
		int _8 = 0;
		int _9 = 0;
	};
	NUM num;
	struct DEF {
		int leftButton = 0;
		int rightButton = 0;
		int backspace = 0;
		int tab = 0;
		int clear = 0;
		int returnk = 0;
		int shift = 0;
		int ctrl = 0;
		int menu = 0;
		//int pause = 0;
		int capital = 0;
		int escape = 0;
		//int convert = 0;
		//int nonconvert = 0;
		//int accept = 0;
		//int modechange = 0;
		int space = 0;
		int pageUp = 0;
		int pageDown = 0;
		int end = 0;
		int home = 0;
		int left = 0;
		int up = 0;
		int right = 0;
		int down = 0;
		//int select = 0;
		int print = 0;
		//int execute = 0;
		//int snapshot = 0;
		int insert = 0;
		int deletek = 0;
		int help = 0;
		int lwin = 0;
		int rwin = 0;
		int numlock = 0;
		int scroll = 0;
		int lshift = 0;
		int rshift = 0;
	};
	DEF def;
	struct F {
		int _01 = 0;
		int _02 = 0;
		int _03 = 0;
		int _04 = 0;
		int _05 = 0;
		int _06 = 0;
		int _07 = 0;
		int _08 = 0;
		int _09 = 0;
		int _10 = 0;
		int _11 = 0;
		int _12 = 0;
		int _13 = 0;
		int _14 = 0;
		int _15 = 0;
		int _16 = 0;
		int _17 = 0;
		int _18 = 0;
		int _19 = 0;
		int _20 = 0;
		int _21 = 0;
		int _22 = 0;
		int _23 = 0;
		int _24 = 0;
	};
	F f;
	struct SIGN {
		int multiply = 0;
		int add = 0;
		int separator = 0;
		int subtract = 0;
		int decimal = 0;
		int divide = 0;
	};
	SIGN sig;
};
struct vertex2D {
	FLOAT x, y, z, rhw;
	DWORD color;
};
struct vector {
	float x;
	float y;
	float z;
};


// 
// 全局常量
// 
const int	SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);		/* 全屏时窗口的最大宽度				*/
const int	SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);		/* 全屏时窗口的最大高度				*/
// PreDef Global Printer   @ Sub_Printer_Proc
#ifndef EMSIAETKADOSH_GRAND
#define EMSIAETKADOSH_GRAND 0
#define SAFE_RELEASE(pointer)	{ if(pointer) { (pointer)->Release(); (pointer) = NULL; } }
#define D3DFVF_VERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)/*经过顶点变换、漫反射*/

#define EK_VECTOR_AD			2
#define EK_VECTOR_XY			1

#define EK_GUI_START 1

#define EK_BUTTONSTYLE_FOCUS_GROW 1
#define EK_BUTTONSTYLE_FOCUS_FRAME 2
#define EK_BUTTONSTYLE_FOCUS_CLRCHANGE 3
#define EK_BUTTONSTYLE_CLICK_DIMINISH 1
#define EK_BUTTONSTYLE_CLICK_FRAME 2
#endif // !EMSIAETKADOSH_GRAND


//
// 全局变量
//
HINSTANCE				hInst;												// 当前实例
HWND					MainhWnd;											// 当前句柄
ULONGLONG				Systime;											// 系统时间
ULONGLONG				Systime_Prev;										// 上一次记录的时间
bool					ReqRepaint = true;									// 是否需要重复重绘
// Sub_Callback_Proc
bool					FullscreenStatus;
DWORD					WindowStyle_Prev;									/* 全屏保留窗口时的矩形				*/
RECT					WindowRectangle_PrevFsc;							/* 全屏保留窗口时的矩形				*/
RECT					WindowRectangle_Present;							/* 任何时刻窗口在屏幕上的矩形			*/
RECT					GuiRectangle_Previous;								/* 客户区改变大小之前在屏幕上的矩形	*/
RECT					GuiRectangle_Present;								/* 任何时刻客户区在客户区上的矩形		*/
// Sub_Hook_Proc
HOOKMSG					hookmsg;											/* 回调函数中输出的消息内容（并未启用）	*/
KEYDOWN					kd;													/* 回调函数中调用的按键状态			*/
HHOOK					hook;
HHOOK					hoom;
// Sub_Printer_Proc
int						GuiDisplay_Present = EK_GUI_START;
int						GuiDisplay_PrevBlack;
bool					PrintInitReq = true;
float					fps;
wchar_t					fpsString[50];
ID3DXFont*				d3dFontPointer_XiaoWeiRuanYaHei = NULL;				/* D3D字体指针						*/
ID3DXFont*				d3dFontPointer_DaWeiRuanYaHei = NULL;
LPDIRECT3DDEVICE9		d3dDevicePointer = NULL;							/* D3D设备指针						*/
LPDIRECT3DVERTEXBUFFER9 d3dVertexPointer = NULL;
LPDIRECT3DINDEXBUFFER9	d3dIndexPointer = NULL;
POINT					MousePosition = { 0 };

// Sub_Catcher_Proc
HWND*		AllhWnd;

//
// 全局函数
//
LRESULT CALLBACK	callbackHook(int, WPARAM, LPARAM);
LRESULT CALLBACK	callbackHoom(int, WPARAM, LPARAM);
void				callbackKeyEvent(HWND, UINT, WPARAM, LPARAM);





//
// 
// 
// 
// 函数及参数提示
// 
// 
//
// 对于窗口消息回调函数
/*
* LRESULT CALLBACK WndProc(
*	HWND			需要处理消息的窗口的句柄
*	UINT			待处理消息的ID，也就是消息的类型
*	WPARAM LPARAM	消息的附加信息
* )
*/
// 对于MessageBox(...)
/*
* MessageBox(
*	HWND	hWnd,			消息框所属句柄，NULL表示属于桌面；
*	LPCTSTR	lpText,			消息内容；
*	LPCTSTR	lpCation,		消息框标题；
*	UINT	uType			消息框样式。
* )
* 
* 对于消息框样式：
*	MB_ABORTRETRYIGNORE		三个按钮：abort, retry, ignore
*	MB_OK					一个OK按钮，默认样式
*	MB_OKCANCEL				两个按钮：OK, Cancel
*	MB_RETRYCANCEL			两个按钮：Retry, Cancel
*	MB_YESNO				两个按钮：Yes, No
*	MB_YESNOCANCEL			三个按钮：Yes, No, Cancel
* 
* 不常用
*	MB_APPLMODAL			?
*	MB_CANCELTRYCONTINUE	?
*	MB_COMPOSITE			?
*	MB_CUR_MAX				?
*	MB_DEFAULT_DESKTOP_ONLY	?
*	
* 图标
*	MB_ICONWARNING			警告
*	MB_ICONASTERISK			风险
*	MB_ICONQUESTION			问号
*	MB_ICONSTOP				停止
*/
// 对于CreateWindow(...)
/*
* CreateWindow(
*	LPCTSTR		窗口类名，一般用开始定义的窗口类名
*	LPCTSTR		窗口名，标题
*	DWORD		窗口样式、
*	int int		窗口左上角坐标
*	int int		窗口宽高
*	HWND		父窗口句柄
*	HMENU		窗口菜单的资源句柄
*	HINSTANCE	窗口所属应用程序句柄，可选hInst
*	LPVOID		lpParam作为WM_CREATE消息的附加参数lParam传入的数据指针。
* )
* 
* 对于窗口样式（第三参数）
*	WS_OVERLAPPED         产生一个层叠窗口，具有标题栏和边框；
*	WS_CAPTION            创建一个具有标题栏的窗口；
*	WS_SYSMENU            创建一个具有系统菜单的窗口，前置条件WS_CAPTION；
*	WS_THICKFRAME         创建一个可调边框的窗口；
*	WS_MINIMAZEBOX        创建一个有最小化按钮的窗口，前置条件WS_SYSTEM类型；
*	WS_MAXIMIZEBOX        创建一个有最大化按钮的窗口，前置条件WS_SYSTEM类型；来自《筑梦旅程——游戏编程从零开始》
*
*	WS_OVERLAPPEDWINDOW   具有以上所有
*/
// UpdateWindow(HWND);就是立刻WM_PAINT而不加入消息队列
// 对于MoveWindow(...)
/*
* MoveWindow(
*	HWND		窗口句柄
*	int int		相对位置
*	int int		宽高
*	BOOL		是否重画
* )
*/
// 对于窗口按钮风格
/*
窗口风格：
	WS_CHILD             子窗口，必须有
	WS_VISIBLE           窗口可见，一般都有
	WS_DISABLED          禁用窗口，创建初始状态为灰色不可用的按钮时使用
	WS_TABSTOP           可用Tab键选择
	WS_GROUP             成组，用于成组的单选按钮中的第一个按钮
按钮风格：
	BS_3STATE			与复选框一样本样式按钮可被单击变暗。变暗状态通常用于指示本样式的按键正处于禁用状态。
	BS_AUTO3STATE		与三状态的复选框一样当用户选中它本按钮样式状态外观会改变。
	BS_AUTOCHECKBOX		与复选框一样，除了在用户点控件后会出现一个选中标志，当用户在下一次点选时，该标志会消失。
	BS_AUTORADIOBUTTON	与单选框一样，不同的是，用户点选它时会高亮显示，同时，会把同一组的其它同样的按钮的高亮状态转移到自己身上。
	BS_BITMAP			指定按钮以一张位图显示。
	BS_BOTTOM			把按钮标题放置到按钮矩形区域的底部。
	BS_CENTER			按钮标题在按钮的矩形区域中央显示。
	BS_CHECKBOX			在按钮的右边创建一个小方块（此样式必须与BS_LEFTTEXT结合使用。）
	BS_DEFPUSHBUTTON	创建一个通用的默认按钮该按钮有一个厚重的黑色边框。用户可以通过按回车键来点选本按钮，该按钮可以实现用户通常要使用的功能（即默认执行动作功能）。
	BS_FLAT				指定按钮为2D按钮，不采用3D控件所使用的阴影。
	BS_GROUPBOX			创建一个分组框来给控件分组，如果使用了标题，则标题会出现在分组框的左上角位置。
	BS_ICON				指定按钮上显示一个图标。
	BS_LEFT				在控件的矩形区域内左对齐标题。如果按钮是一个没有BS_RIGHTBUTTON 样式的复选框或单选框 ，那么文本居将在复选框或单选框的右边居左对齐（这话有些多余，意思文本在复选框或单选框的那个可选被小方框或圆圈的右边。）。
	BS_LEFTTEXT			当按钮是单选或是复选框时，标题文本将出现在单选或复选框的客户区（即复选框的矩形框，单选框的圆形框）的左边。
	BS_MULTILINE		如果标题文本太长，将在绘制区域内对文本进行折行处理。
	BS_NOTIFY			激活按钮，使之可对父窗口发送BN_DBLCLK, BN_KILLFOCUS,  BN_SETFOCUS 消息，注意：不管有没有使用本样式，按钮都有一个 BN_CLICKED 可发送消息。
	BS_OWNERDRAW		创建一个自绘风格的按钮。当按钮的外观发生改变时，框架会调用DrawItem成员函数。本样式在使用CBitmapButton类时必须设置。
	BS_PUSHBUTTON		创建一个按钮（即最常见的按钮），该按钮在点击时，将向父窗口发送一个WM_COMMAND 消息。
	BS_PUSHLIKE			把（多选框，三态多选框，单选框）以按钮的形式显示，该按钮在未选种状态时是浮起的，但在选中状态时是陷入状态的。
	BS_RADIOBUTTON		创建单选框，该按钮有一个圆形的客户区，（在本样式不与BS_LEFTTEXT   样式结合使用的情况下）标题文本在其右方。单选框通常用于有相关联的多个可选项里面，但相互之间只有作一个选择的情况下。
	BS_RIGHT			在按钮的绘制区域内右对齐文本。但如果按钮是一个没有BS_RIGHTBUTTON样式的单选或复选框，标题文本将在单选或复选框可点选区的右边居右对齐。
	BS_RIGHTBUTTON		设定单选框的圆形可选区或复选框的方开形复选区出现在按钮的矩形区域的右边。与BS_LEFTTEXT 的效果一样。
	BS_TEXT				指定按钮将显示文本标题。
	BS_TOP				将标题文本显示在按钮的绘制区域的顶边。
	//BS_USERBUTTON		已废弃不用，只作为兼容16位系统版本的Windows，基于32位windows系统的请用BS_OWNERDRAW样式取代。
	BS_VCENTER			设定按钮的标题在绘制区域的垂直方向居中。
以上风格指定了创建的按钮类型，不能同时使用，但必须有其一；
其中非自动类型的按钮需要自己编程来实现选中与否的状态切换。
	BS_BITMAP            按钮上将显示位图
	BS_DEFPUSHBUTTON     设置为默认按钮，只用于下压式按钮，一个对话框中只能指定一个默认按钮
*/
// 对于CreatePen(...)
/*
BOOL CreatePen(
	int			nPenStyle,
	int			nWidth,
	COLORREF	crColor);
创建画笔的函数中，nPenStyle参数表示画笔风格，可以设置下列值之一
	PS_SOLID		画笔画出的是实线。
	PS_DASH			画笔画出的是虚线(nWidth必须不大于1)。
	PS_DOT			画笔画出的是点线(nWidth必须不大于1)。
	PS_DASHDOT		画笔画出的是点划线(nWidth必须不大于1)。
	PS_DASHDOTDOT	画笔画出的是点-点-划线(nWidth必须不大于1)。
	PS_NULL			空画笔，画笔不能画图。
	PS_INSIDEFRAME	内侧实线画笔
		由椭圆、矩形、圆角矩形、饼图以及弦等生成的封闭对象框时，画线宽度向内扩展。如指定的准确RGB颜色不存在，就进行抖动处理。
创建画笔的函数中，nWidth表示画笔线宽，是一个逻辑值，这个值越小，画出的图形线越细；这个值越大，绘制的图形线条越粗。
画笔颜色通过RGB宏控制，例如需要画红色的图形，RGB（255,0,0）。MFC中有许多引用颜色宏RGB，这里总结了一些常见的颜色的宏，供大家参考。
*/
// 对于CreateHatchPen(...)
/*
* CreateHatchPen(
*	int			阴影样式
*	COLORREF	前景颜色，可以用RGB(r,g,b)
* 
* 对于阴影样式（第一个参数）
*	HS_BDIAGONAL	45°左下右上
*	HS_CROSS		水平竖直交叉
*	HS_DIAGCROSS	45°交叉
*	HS_FDIAGONAL	45°左上右下
*	HS_HORIZONTAL	水平
*	HS_VERTICAL		竖直
* )
*/
// 对于CreateRoundRectRgn(...)
/*
* 
* CreateRoundRectRgn(
*	int toLeft,
*	int toTop,
*	int toLeft,
*	int toTop,
*	int rx,
*	int ry);
*/
// 对于LineTo(HDC, int, int)，定义HDC、画笔终点坐标。从“画笔所在位置”开始绘制一条直线。
// 对于MoveToEx(HDC, int, int, LPPOINT)定义HDC、画笔目标坐标、上一个点的位置（指针）
// 对于TextOut(...)
/*
* TextOut(
*	HDC			HDC
*	int int		开始书写位置
*	LPCTSTR		字符串指针
*	int			字符串字符数（可以配合strlen或宽字节的wcslen当场计算）
* )
*/
// 对于SetTextColor(HDC, COLORREF)
// 对于SetBkMode(HDC, int)，int指定背景形式，一般为TRANSPARENT
// 对于HFONT CreateFont(...)
/*
* CreateFont(
*	int int		逻辑高宽
*	int			显示的角度
*	int			字体的角度
*	int			字体的磅数
*	DWORD		斜体(0)
*	DWORD		下划线(0)
*	DWORD		删除线(0)
*	DWORD		字符集(GB2312_CHARSET ? GB312_CHARSET)
*	DWORD		输出精度(0)
*	DWORD		裁剪精度(0)
*	DWORD		输出质量(0)
*	DWORD		字体间距的字符集(0)
*	LPCTSTR		字体名称
* )
*/
// 对于PeekMessage(...)
/*
* PeekMessage(
*	LPMSG		保存目标，即*MSG
*	HWND		接收哪一个窗口（句柄）的消息，NULL表示所有来自调用线程的消息
*	UINT UINT	获取消息的最小值和最大值，都填0则接收所有消息
*	UINT		PM_REMOVE或者PM_NOREMOVE，当消息被偷看后是否将其从消息队列中移除
* 
* 该函数如果从消息队列中取到了消息则返回!0，如果没有则返回0
*/
// 对于Timer窗口定时器
/*
* UINT_PTR WINAPI SetTimer(
*	HWND		接收定时器的窗口句柄
*	UINT_PTR	定时器代号（同一个窗口内唯一且不为零）
*	UINT		时间间隔（毫秒）
*	TIMERPROC	处理相应函数
* )
* BOOL WINAPI KillTimer(
*	HWND UINT_PTR
* )
* 每隔固定时间会在消息队列中加入WM_TIMER消息，和WM_PAINT一样都是低优先级的消息
*/
// memset：批量操作
/*
* memset(
*	void*		直接填目标
*	int			替换成该项
*	size_t		将目标的前该项个替换为上一项
* )
*/
// 对于swprintf_s(...)
/*
* swprintf_s(
*	wchar_t*		要写入字符串的缓冲区，也就是存储位置
*	size_t			存储的最大字符数（sizeof()可以）
*	const wchar_t	要处理的字符
*					可选参数，任何数据类型格式化到第三个参数中
* )
*/