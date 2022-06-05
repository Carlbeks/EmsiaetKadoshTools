#pragma once


#include <time.h>
#include <thread>
#include <dxgi.h>
//#include <amp.h>

#include "CppWindowTool.h"
#include "framework.h"

#define MAX_LOADSTRING 100


struct HOOKMSG {
	int nCode;
	MSG msg;
	UINT uint;
	WPARAM wParam;
	LPARAM lParam;
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
		int separator = 0;
		int subtract = 0;
		int decimal = 0;
		int dicede = 0;
	};
};
struct BUTTON {
	struct STARTER {
		HWND		Home;
		HWND		Normal;
	};
	STARTER __STARTER;
	struct WINDOW {
		HWND		BACKtoSTART;
		
	};
	WINDOW __WINDOW;
};


// PreDef Global Printer   @ Sub_Printer_Proc
#ifndef EK_GUI_STARTER		/*�����������ʼ����*/
#define EK_GUI_STARTER 1
#endif // !EK_GUI_STARTER 
#ifndef EK_GUI_WINDOW		/*������������ڽ���*/
#define EK_GUI_WINDOW 2
#endif // !EH_GUI_WINDOW
#ifndef EK_GUI_BLACK
#define EK_GUI_BLACK 100	/*�����������������*/
#endif // !EK_GUI_BLACK



#ifndef EK_GUIBUTTON_NORMAL	/*��ť��������ʼ�ļ�*/
#define EK_GUIBUTTON_NORMAL 102
#endif // !EK_GUIBUTTON_NORMAL
#ifndef EK_GUIBUTTON_HOME	/*��ť��������ʼ����*/
#define EK_GUIBUTTON_HOME 101
#endif // !EK_GUIBUTTON_HOME

int			windowGUIStatus_tempstore = EK_GUI_STARTER;
int			windowGUIStatusLast_tempstore = EK_GUI_STARTER;
int			windowGUIAntiBlack_tempstore;
bool		windowNotPrintingBool_judge = true;
BUTTON		guiButtons;


// ȫ�ֱ���:
HINSTANCE hInst;                                // ��ǰʵ��
//WCHAR szTitle[MAX_LOADSTRING];                  // �������ı�  "EmsiaetKadosh's Desktop Tool"
//WCHAR szWindowClass[MAX_LOADSTRING];            // ����������  "EmsiaetKadosh's Desktop Tool"
HWND MainhWnd;                                  // ��ǰ���

//Test
LPPAINTSTRUCT TestPs;
HDC Testhdc;

// PreDef Global WindowVar @ Sub_Callback_Proc
bool		fullscreenBool_judge;
bool		popupBool_judge = false;
DWORD		windowStyleLastDword_tempstore;									/* ȫ����������ʱ������				*/
RECT		windowRectangleLastRect_tempstore;								/* ȫ����������ʱ������				*/
int			windowWidthInt_tempstore;										/* ���ڿ�ȣ����Ĵ��ڴ�Сʱ���´��ڿ��	*/
int			windowHeightInt_tempstore;										/* ���ڸ߶ȣ����Ĵ��ڴ�Сʱ���´��ڸ߶�	*/
const int	fullscreenMaxWidthInt_store = GetSystemMetrics(SM_CXSCREEN);	/* ȫ��ʱ���ڵ������				*/
const int	fullscreenMaxHeightInt_store = GetSystemMetrics(SM_CYSCREEN);	/* ȫ��ʱ���ڵ����߶�				*/

// PreDef Global HookVar   @ Sub_Hook_Proc
HOOKMSG		hookmsg;														/* �ص��������������Ϣ���ݣ���δ���ã�	*/
KEYDOWN		kd;																/* �ص������е��õİ���״̬			*/
HHOOK		hook;



//
// 
// 
// 
// ������������ʾ
// 
// 
//
// ����MessageBox(...)
/*
* MessageBox(
*	HWND	hWnd,			��Ϣ�����������NULL��ʾ�������棻
*	LPCTSTR	lpText,			��Ϣ���ݣ�
*	LPCTSTR	lpCation,		��Ϣ����⣻
*	UINT	uType			��Ϣ����ʽ��
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