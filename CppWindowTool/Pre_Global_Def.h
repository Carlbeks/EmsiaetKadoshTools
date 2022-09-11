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
// ȫ�ֳ���
// 
const int	SCREEN_WIDTH = GetSystemMetrics(SM_CXSCREEN);		/* ȫ��ʱ���ڵ������				*/
const int	SCREEN_HEIGHT = GetSystemMetrics(SM_CYSCREEN);		/* ȫ��ʱ���ڵ����߶�				*/
// PreDef Global Printer   @ Sub_Printer_Proc
#ifndef EMSIAETKADOSH_GRAND
#define EMSIAETKADOSH_GRAND 0
#define SAFE_RELEASE(pointer)	{ if(pointer) { (pointer)->Release(); (pointer) = NULL; } }
#define D3DFVF_VERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)/*��������任��������*/

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
// ȫ�ֱ���
//
HINSTANCE				hInst;												// ��ǰʵ��
HWND					MainhWnd;											// ��ǰ���
ULONGLONG				Systime;											// ϵͳʱ��
ULONGLONG				Systime_Prev;										// ��һ�μ�¼��ʱ��
bool					ReqRepaint = true;									// �Ƿ���Ҫ�ظ��ػ�
// Sub_Callback_Proc
bool					FullscreenStatus;
DWORD					WindowStyle_Prev;									/* ȫ����������ʱ�ľ���				*/
RECT					WindowRectangle_PrevFsc;							/* ȫ����������ʱ�ľ���				*/
RECT					WindowRectangle_Present;							/* �κ�ʱ�̴�������Ļ�ϵľ���			*/
RECT					GuiRectangle_Previous;								/* �ͻ����ı��С֮ǰ����Ļ�ϵľ���	*/
RECT					GuiRectangle_Present;								/* �κ�ʱ�̿ͻ����ڿͻ����ϵľ���		*/
// Sub_Hook_Proc
HOOKMSG					hookmsg;											/* �ص��������������Ϣ���ݣ���δ���ã�	*/
KEYDOWN					kd;													/* �ص������е��õİ���״̬			*/
HHOOK					hook;
HHOOK					hoom;
// Sub_Printer_Proc
int						GuiDisplay_Present = EK_GUI_START;
int						GuiDisplay_PrevBlack;
bool					PrintInitReq = true;
float					fps;
wchar_t					fpsString[50];
ID3DXFont*				d3dFontPointer_XiaoWeiRuanYaHei = NULL;				/* D3D����ָ��						*/
ID3DXFont*				d3dFontPointer_DaWeiRuanYaHei = NULL;
LPDIRECT3DDEVICE9		d3dDevicePointer = NULL;							/* D3D�豸ָ��						*/
LPDIRECT3DVERTEXBUFFER9 d3dVertexPointer = NULL;
LPDIRECT3DINDEXBUFFER9	d3dIndexPointer = NULL;
POINT					MousePosition = { 0 };

// Sub_Catcher_Proc
HWND*		AllhWnd;

//
// ȫ�ֺ���
//
LRESULT CALLBACK	callbackHook(int, WPARAM, LPARAM);
LRESULT CALLBACK	callbackHoom(int, WPARAM, LPARAM);
void				callbackKeyEvent(HWND, UINT, WPARAM, LPARAM);





//
// 
// 
// 
// ������������ʾ
// 
// 
//
// ���ڴ�����Ϣ�ص�����
/*
* LRESULT CALLBACK WndProc(
*	HWND			��Ҫ������Ϣ�Ĵ��ڵľ��
*	UINT			��������Ϣ��ID��Ҳ������Ϣ������
*	WPARAM LPARAM	��Ϣ�ĸ�����Ϣ
* )
*/
// ����MessageBox(...)
/*
* MessageBox(
*	HWND	hWnd,			��Ϣ�����������NULL��ʾ�������棻
*	LPCTSTR	lpText,			��Ϣ���ݣ�
*	LPCTSTR	lpCation,		��Ϣ����⣻
*	UINT	uType			��Ϣ����ʽ��
* )
* 
* ������Ϣ����ʽ��
*	MB_ABORTRETRYIGNORE		������ť��abort, retry, ignore
*	MB_OK					һ��OK��ť��Ĭ����ʽ
*	MB_OKCANCEL				������ť��OK, Cancel
*	MB_RETRYCANCEL			������ť��Retry, Cancel
*	MB_YESNO				������ť��Yes, No
*	MB_YESNOCANCEL			������ť��Yes, No, Cancel
* 
* ������
*	MB_APPLMODAL			?
*	MB_CANCELTRYCONTINUE	?
*	MB_COMPOSITE			?
*	MB_CUR_MAX				?
*	MB_DEFAULT_DESKTOP_ONLY	?
*	
* ͼ��
*	MB_ICONWARNING			����
*	MB_ICONASTERISK			����
*	MB_ICONQUESTION			�ʺ�
*	MB_ICONSTOP				ֹͣ
*/
// ����CreateWindow(...)
/*
* CreateWindow(
*	LPCTSTR		����������һ���ÿ�ʼ����Ĵ�������
*	LPCTSTR		������������
*	DWORD		������ʽ��
*	int int		�������Ͻ�����
*	int int		���ڿ��
*	HWND		�����ھ��
*	HMENU		���ڲ˵�����Դ���
*	HINSTANCE	��������Ӧ�ó���������ѡhInst
*	LPVOID		lpParam��ΪWM_CREATE��Ϣ�ĸ��Ӳ���lParam���������ָ�롣
* )
* 
* ���ڴ�����ʽ������������
*	WS_OVERLAPPED         ����һ��������ڣ����б������ͱ߿�
*	WS_CAPTION            ����һ�����б������Ĵ��ڣ�
*	WS_SYSMENU            ����һ������ϵͳ�˵��Ĵ��ڣ�ǰ������WS_CAPTION��
*	WS_THICKFRAME         ����һ���ɵ��߿�Ĵ��ڣ�
*	WS_MINIMAZEBOX        ����һ������С����ť�Ĵ��ڣ�ǰ������WS_SYSTEM���ͣ�
*	WS_MAXIMIZEBOX        ����һ������󻯰�ť�Ĵ��ڣ�ǰ������WS_SYSTEM���ͣ����ԡ������ó̡�����Ϸ��̴��㿪ʼ��
*
*	WS_OVERLAPPEDWINDOW   ������������
*/
// UpdateWindow(HWND);��������WM_PAINT����������Ϣ����
// ����MoveWindow(...)
/*
* MoveWindow(
*	HWND		���ھ��
*	int int		���λ��
*	int int		���
*	BOOL		�Ƿ��ػ�
* )
*/
// ���ڴ��ڰ�ť���
/*
���ڷ��
	WS_CHILD             �Ӵ��ڣ�������
	WS_VISIBLE           ���ڿɼ���һ�㶼��
	WS_DISABLED          ���ô��ڣ�������ʼ״̬Ϊ��ɫ�����õİ�ťʱʹ��
	WS_TABSTOP           ����Tab��ѡ��
	WS_GROUP             ���飬���ڳ���ĵ�ѡ��ť�еĵ�һ����ť
��ť���
	BS_3STATE			�븴ѡ��һ������ʽ��ť�ɱ������䰵���䰵״̬ͨ������ָʾ����ʽ�İ��������ڽ���״̬��
	BS_AUTO3STATE		����״̬�ĸ�ѡ��һ�����û�ѡ��������ť��ʽ״̬��ۻ�ı䡣
	BS_AUTOCHECKBOX		�븴ѡ��һ�����������û���ؼ�������һ��ѡ�б�־�����û�����һ�ε�ѡʱ���ñ�־����ʧ��
	BS_AUTORADIOBUTTON	�뵥ѡ��һ������ͬ���ǣ��û���ѡ��ʱ�������ʾ��ͬʱ�����ͬһ�������ͬ���İ�ť�ĸ���״̬ת�Ƶ��Լ����ϡ�
	BS_BITMAP			ָ����ť��һ��λͼ��ʾ��
	BS_BOTTOM			�Ѱ�ť������õ���ť��������ĵײ���
	BS_CENTER			��ť�����ڰ�ť�ľ�������������ʾ��
	BS_CHECKBOX			�ڰ�ť���ұߴ���һ��С���飨����ʽ������BS_LEFTTEXT���ʹ�á���
	BS_DEFPUSHBUTTON	����һ��ͨ�õ�Ĭ�ϰ�ť�ð�ť��һ�����صĺ�ɫ�߿��û�����ͨ�����س�������ѡ����ť���ð�ť����ʵ���û�ͨ��Ҫʹ�õĹ��ܣ���Ĭ��ִ�ж������ܣ���
	BS_FLAT				ָ����ťΪ2D��ť��������3D�ؼ���ʹ�õ���Ӱ��
	BS_GROUPBOX			����һ������������ؼ����飬���ʹ���˱��⣬����������ڷ��������Ͻ�λ�á�
	BS_ICON				ָ����ť����ʾһ��ͼ�ꡣ
	BS_LEFT				�ڿؼ��ľ����������������⡣�����ť��һ��û��BS_RIGHTBUTTON ��ʽ�ĸ�ѡ���ѡ�� ����ô�ı��ӽ��ڸ�ѡ���ѡ����ұ߾�����루�⻰��Щ���࣬��˼�ı��ڸ�ѡ���ѡ����Ǹ���ѡ��С�����ԲȦ���ұߡ�����
	BS_LEFTTEXT			����ť�ǵ�ѡ���Ǹ�ѡ��ʱ�������ı��������ڵ�ѡ��ѡ��Ŀͻ���������ѡ��ľ��ο򣬵�ѡ���Բ�ο򣩵���ߡ�
	BS_MULTILINE		��������ı�̫�������ڻ��������ڶ��ı��������д���
	BS_NOTIFY			���ť��ʹ֮�ɶԸ����ڷ���BN_DBLCLK, BN_KILLFOCUS,  BN_SETFOCUS ��Ϣ��ע�⣺������û��ʹ�ñ���ʽ����ť����һ�� BN_CLICKED �ɷ�����Ϣ��
	BS_OWNERDRAW		����һ���Ի���İ�ť������ť����۷����ı�ʱ����ܻ����DrawItem��Ա����������ʽ��ʹ��CBitmapButton��ʱ�������á�
	BS_PUSHBUTTON		����һ����ť��������İ�ť�����ð�ť�ڵ��ʱ�����򸸴��ڷ���һ��WM_COMMAND ��Ϣ��
	BS_PUSHLIKE			�ѣ���ѡ����̬��ѡ�򣬵�ѡ���԰�ť����ʽ��ʾ���ð�ť��δѡ��״̬ʱ�Ǹ���ģ�����ѡ��״̬ʱ������״̬�ġ�
	BS_RADIOBUTTON		������ѡ�򣬸ð�ť��һ��Բ�εĿͻ��������ڱ���ʽ����BS_LEFTTEXT   ��ʽ���ʹ�õ�����£������ı������ҷ�����ѡ��ͨ��������������Ķ����ѡ�����棬���໥֮��ֻ����һ��ѡ�������¡�
	BS_RIGHT			�ڰ�ť�Ļ����������Ҷ����ı����������ť��һ��û��BS_RIGHTBUTTON��ʽ�ĵ�ѡ��ѡ�򣬱����ı����ڵ�ѡ��ѡ��ɵ�ѡ�����ұ߾��Ҷ��롣
	BS_RIGHTBUTTON		�趨��ѡ���Բ�ο�ѡ����ѡ��ķ����θ�ѡ�������ڰ�ť�ľ���������ұߡ���BS_LEFTTEXT ��Ч��һ����
	BS_TEXT				ָ����ť����ʾ�ı����⡣
	BS_TOP				�������ı���ʾ�ڰ�ť�Ļ�������Ķ��ߡ�
	//BS_USERBUTTON		�ѷ������ã�ֻ��Ϊ����16λϵͳ�汾��Windows������32λwindowsϵͳ������BS_OWNERDRAW��ʽȡ����
	BS_VCENTER			�趨��ť�ı����ڻ�������Ĵ�ֱ������С�
���Ϸ��ָ���˴����İ�ť���ͣ�����ͬʱʹ�ã�����������һ��
���з��Զ����͵İ�ť��Ҫ�Լ������ʵ��ѡ������״̬�л���
	BS_BITMAP            ��ť�Ͻ���ʾλͼ
	BS_DEFPUSHBUTTON     ����ΪĬ�ϰ�ť��ֻ������ѹʽ��ť��һ���Ի�����ֻ��ָ��һ��Ĭ�ϰ�ť
*/
// ����CreatePen(...)
/*
BOOL CreatePen(
	int			nPenStyle,
	int			nWidth,
	COLORREF	crColor);
�������ʵĺ����У�nPenStyle������ʾ���ʷ�񣬿�����������ֵ֮һ
	PS_SOLID		���ʻ�������ʵ�ߡ�
	PS_DASH			���ʻ�����������(nWidth���벻����1)��
	PS_DOT			���ʻ������ǵ���(nWidth���벻����1)��
	PS_DASHDOT		���ʻ������ǵ㻮��(nWidth���벻����1)��
	PS_DASHDOTDOT	���ʻ������ǵ�-��-����(nWidth���벻����1)��
	PS_NULL			�ջ��ʣ����ʲ��ܻ�ͼ��
	PS_INSIDEFRAME	�ڲ�ʵ�߻���
		����Բ�����Ρ�Բ�Ǿ��Ρ���ͼ�Լ��ҵ����ɵķ�ն����ʱ�����߿��������չ����ָ����׼ȷRGB��ɫ�����ڣ��ͽ��ж�������
�������ʵĺ����У�nWidth��ʾ�����߿���һ���߼�ֵ�����ֵԽС��������ͼ����Խϸ�����ֵԽ�󣬻��Ƶ�ͼ������Խ�֡�
������ɫͨ��RGB����ƣ�������Ҫ����ɫ��ͼ�Σ�RGB��255,0,0����MFC�������������ɫ��RGB�������ܽ���һЩ��������ɫ�ĺ꣬����Ҳο���
*/
// ����CreateHatchPen(...)
/*
* CreateHatchPen(
*	int			��Ӱ��ʽ
*	COLORREF	ǰ����ɫ��������RGB(r,g,b)
* 
* ������Ӱ��ʽ����һ��������
*	HS_BDIAGONAL	45����������
*	HS_CROSS		ˮƽ��ֱ����
*	HS_DIAGCROSS	45�㽻��
*	HS_FDIAGONAL	45����������
*	HS_HORIZONTAL	ˮƽ
*	HS_VERTICAL		��ֱ
* )
*/
// ����CreateRoundRectRgn(...)
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
// ����LineTo(HDC, int, int)������HDC�������յ����ꡣ�ӡ���������λ�á���ʼ����һ��ֱ�ߡ�
// ����MoveToEx(HDC, int, int, LPPOINT)����HDC������Ŀ�����ꡢ��һ�����λ�ã�ָ�룩
// ����TextOut(...)
/*
* TextOut(
*	HDC			HDC
*	int int		��ʼ��дλ��
*	LPCTSTR		�ַ���ָ��
*	int			�ַ����ַ������������strlen����ֽڵ�wcslen�������㣩
* )
*/
// ����SetTextColor(HDC, COLORREF)
// ����SetBkMode(HDC, int)��intָ��������ʽ��һ��ΪTRANSPARENT
// ����HFONT CreateFont(...)
/*
* CreateFont(
*	int int		�߼��߿�
*	int			��ʾ�ĽǶ�
*	int			����ĽǶ�
*	int			����İ���
*	DWORD		б��(0)
*	DWORD		�»���(0)
*	DWORD		ɾ����(0)
*	DWORD		�ַ���(GB2312_CHARSET ? GB312_CHARSET)
*	DWORD		�������(0)
*	DWORD		�ü�����(0)
*	DWORD		�������(0)
*	DWORD		��������ַ���(0)
*	LPCTSTR		��������
* )
*/
// ����PeekMessage(...)
/*
* PeekMessage(
*	LPMSG		����Ŀ�꣬��*MSG
*	HWND		������һ�����ڣ����������Ϣ��NULL��ʾ�������Ե����̵߳���Ϣ
*	UINT UINT	��ȡ��Ϣ����Сֵ�����ֵ������0�����������Ϣ
*	UINT		PM_REMOVE����PM_NOREMOVE������Ϣ��͵�����Ƿ������Ϣ�������Ƴ�
* 
* �ú����������Ϣ������ȡ������Ϣ�򷵻�!0�����û���򷵻�0
*/
// ����Timer���ڶ�ʱ��
/*
* UINT_PTR WINAPI SetTimer(
*	HWND		���ն�ʱ���Ĵ��ھ��
*	UINT_PTR	��ʱ�����ţ�ͬһ��������Ψһ�Ҳ�Ϊ�㣩
*	UINT		ʱ���������룩
*	TIMERPROC	������Ӧ����
* )
* BOOL WINAPI KillTimer(
*	HWND UINT_PTR
* )
* ÿ���̶�ʱ�������Ϣ�����м���WM_TIMER��Ϣ����WM_PAINTһ�����ǵ����ȼ�����Ϣ
*/
// memset����������
/*
* memset(
*	void*		ֱ����Ŀ��
*	int			�滻�ɸ���
*	size_t		��Ŀ���ǰ������滻Ϊ��һ��
* )
*/
// ����swprintf_s(...)
/*
* swprintf_s(
*	wchar_t*		Ҫд���ַ����Ļ�������Ҳ���Ǵ洢λ��
*	size_t			�洢������ַ�����sizeof()���ԣ�
*	const wchar_t	Ҫ������ַ�
*					��ѡ�������κ��������͸�ʽ����������������
* )
*/