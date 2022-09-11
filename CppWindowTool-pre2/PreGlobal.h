#pragma once

#include <ios>
#include <thread>
#include <fstream>
#include <time.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <stdio.h>
#include <windowsx.h>
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"comctl32.lib")
#pragma comment(lib,"C:\\Program Files (x86)\\DirectX9\\Lib\\x64\\d3dx9.lib")
#include "framework.h"
#include "CppWindowTool-pre2.h"
#include "EmsiaetKadosh.h"

#ifndef EMSIAETKADOSHTOOLS_GRAND
#define EMSIAETKADOSHTOOLS_GRAND 1
#define MAX_LOADSTRING 100

#define TYPE_WINDOWIN 1
#define TYPE_INTERFACEIN 2

#define WINDOWOUT_WRONG(pIn) {MessageBox(NULL, pIn, L"EKDT错误", MB_OK);er0}

#define SAFE_RELEASE(pointer) {if(pointer){(pointer)->Release();(pointer)=NULL;}}
#define D3DFVF_VERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)/*经过顶点变换、漫反射*/

#define Lambda_def ekThreadBlocker* ekthreadblocker, ekWindow* ekwindow

// Global values:
WCHAR MainWindowTitle[MAX_LOADSTRING];
WCHAR MainWindowClass[MAX_LOADSTRING];
HWND MainhWnd;
HINSTANCE MainhInstance;
LPDIRECT3DDEVICE9 d3dDevicePointer;
LPDIRECT3DVERTEXBUFFER9 d3dVertexPointer;
n d3dVertexCount;
LPDIRECT3DINDEXBUFFER9 d3dIndexPointer;
n d3dIndexCount;
ID3DXFont* d3dFontPointerArray[4];
RECT GuiRectangle_Present;
POINT EkmsgCursorPosition;
n EkmsgMouseClicked = 0;
b EkmsgKeyStatus[128] = { 0 };
n* UserSettings[16];
f fps = 0.0f;
n fps_count = 0.0f;
f fps_pretime = 0.0f;
f fps_curtime = 0.0f;
wct fpsString = 0.0f;
S vertex2D{
	FLOAT x = 0.0f;
	FLOAT y = 0.0f;
	FLOAT z = 0.0f;
	FLOAT rhw = 1.0f;
	DWORD color = D3DCOLOR_RGBA(0, 0, 0, 0);
};
S vector{
	float x;
	float y;
	float z;
};
n ER0() {er0}
v d3drelease() {
	SAFE_RELEASE(d3dFontPointerArray[0]);
	SAFE_RELEASE(d3dFontPointerArray[1]);
	SAFE_RELEASE(d3dFontPointerArray[2]);
	SAFE_RELEASE(d3dFontPointerArray[3]);
	SAFE_RELEASE(d3dVertexPointer);
	SAFE_RELEASE(d3dIndexPointer);
	SAFE_RELEASE(d3dDevicePointer);
	er a
}

// complex api
namespace ekfiles {
	inline b IsFileExist(const std::string& name) {
		std::ifstream the_file(name.c_str());
		return the_file.good();
	}
};
C ekButton{ // position, size, bgcolor, bgfocus, textSwprintf_s, charcount, txcolor, txfocus, ReactionvkCode, Exe()
cpi:
	b preclicked = false;
	b focused = false;
	b clicked = false;
	b init = false;
	RECT rect = { 0 };
cpo:
	vector position;
	vector size;
	D3DCOLOR bgcolor;
	D3DCOLOR bgfocus;
	D3DCOLOR bgunavailable = D3DCOLOR_XRGB(160, 160, 160);
	wchar_t textSwprintf_s[32];
	b available = true;
	n charcount;
	D3DCOLOR txcolor;
	D3DCOLOR txfocus;
	D3DCOLOR txunavailable = D3DCOLOR_XRGB(64, 64, 64);
	n VertexCount = 4;
	n IndexCount = 6;
	n ReactionvkCode;
	pf(v, Exe, (n*, n*)) = [](n* Windows, n* Window)->v {er a};

	n Init(vertex2D* vertextemp, n* vc, WORD* indextemp, n* ic, n* Windows, n* Window) {
		f x = (f)EkmsgCursorPosition.x;
		f y = (f)EkmsgCursorPosition.y;
		f px = position.x * GuiRectangle_Present.right;
		f py = position.y * GuiRectangle_Present.bottom;
		f sx = size.x * GuiRectangle_Present.right + px;
		f sy = size.y * GuiRectangle_Present.bottom + py;
		rect.left = px;
		rect.right = sx;
		rect.top = py;
		rect.bottom = sy;
		if (available) {
			if (preclicked) {
				focused = false;
				clicked = false;
				if (!EkmsgMouseClicked) {
					preclicked = false;
				}
			}
			else {
				if ((px < x) && (x < sx) && (py < y) && (y < sy)) {
					focused = true;
					if (EkmsgMouseClicked) {
						clicked = true;
					}
				}
				else {
					focused = false;
					clicked = false;
					if (EkmsgMouseClicked) {
						preclicked = true;
					}
					else {
						preclicked = false;
					}
				}
			}
		}
		if (available) {
			if (focused) {
				vertextemp[*vc] = { px,py,position.z,1.0f,bgfocus };
				vertextemp[*vc + 1] = { sx,py,position.z,1.0f,bgfocus };
				vertextemp[*vc + 2] = { sx,sy,position.z,1.0f,bgfocus };
				vertextemp[*vc + 3] = { px,sy,position.z,1.0f,bgfocus };
			}
			else {
				vertextemp[*vc] = { px,py,position.z,1.0f,bgcolor };
				vertextemp[*vc + 1] = { sx,py,position.z,1.0f,bgcolor };
				vertextemp[*vc + 2] = { sx,sy,position.z,1.0f,bgcolor };
				vertextemp[*vc + 3] = { px,sy,position.z,1.0f,bgcolor };
			}
		}
		else{
			vertextemp[*vc] = { px,py,position.z,1.0f,bgunavailable };
			vertextemp[*vc + 1] = { sx,py,position.z,1.0f,bgunavailable };
			vertextemp[*vc + 2] = { sx,sy,position.z,1.0f,bgunavailable };
			vertextemp[*vc + 3] = { px,sy,position.z,1.0f,bgunavailable };
		}
		n s = *ic * 3;
		indextemp[s] = *vc;
		indextemp[s + 1] = *vc + 1;
		indextemp[s + 2] = *vc + 2;
		indextemp[s + 3] = *vc;
		indextemp[s + 4] = *vc + 2;
		indextemp[s + 5] = *vc + 3;
		*vc += 4;
		*ic += 2;
		init = 1;
		if (EkmsgKeyStatus[ReactionvkCode]) {
			b preclicked = false;
			b focused = false;
			b clicked = false;
			EkmsgKeyStatus[ReactionvkCode] = 0;
			Exe(Windows, Window);er1
		}
		if (clicked) {
			if (!EkmsgMouseClicked) {
				clicked = false;
				Exe(Windows, Window);er1
			}
		}
		er0
	}
	v Char() {
		if (init) {
			if (focused) {
				d3dFontPointerArray[0]->DrawText(
					0, // 当前窗口
					textSwprintf_s, // 显示的字符串
					charcount, // 字符数
					&rect, // 显示的目标矩形
					DT_CENTER | DT_VCENTER,
					txfocus
				);
			}
			else {
				d3dFontPointerArray[0]->DrawText(
					0, // 当前窗口
					textSwprintf_s, // 显示的字符串
					charcount, // 字符数
					&rect, // 显示的目标矩形
					DT_CENTER | DT_VCENTER,
					txcolor
				);
			}
		}
		else {
			f x = (f)EkmsgCursorPosition.x;
			f y = (f)EkmsgCursorPosition.y;
			f px = position.x * GuiRectangle_Present.right;
			f py = position.y * GuiRectangle_Present.bottom;
			f sx = size.x * GuiRectangle_Present.right + px;
			f sy = size.y * GuiRectangle_Present.bottom + py;
			rect.left = px;
			rect.right = sx;
			rect.top = py;
			rect.bottom = sy;
			if ((px < x) && (x < sx) && (py < y) && (y < sy)) {
				d3dFontPointerArray[0]->DrawText(
					0, // 当前窗口
					textSwprintf_s, // 显示的字符串
					charcount, // 字符数
					&rect, // 显示的目标矩形
					DT_CENTER,
					txfocus
				);
				focused = 1;
			}
			else {
				d3dFontPointerArray[0]->DrawText(
					0, // 当前窗口
					textSwprintf_s, // 显示的字符串
					charcount, // 字符数
					&rect, // 显示的目标矩形
					DT_CENTER,
					txcolor
				);
				focused = 0;
			}
		}
		er a
	}
};
C ekTextBox{ // position, size, bgcolor, bgfocus, textSwprintf_s, charcount, txcolor, txfocus, ReactionvkCode, Exe()
cpi:
	b preclicked = false;
	b focused = false;
	b clicked = false;
	b activated = false; // means can input
	b init = false;
	RECT rect = { 0 };
cpo:
	b ifinputbox = false;
	vector position;
	vector size;
	D3DCOLOR bgcolor;
	D3DCOLOR bgfocus;
	D3DCOLOR bgactive;
	wchar_t textSwprintf_s[512];
	n charcount;
	D3DCOLOR txcolor;
	n VertexCount = 4;
	n IndexCount = 6;
	n ReactionvkCode;
	pf(v, Exe, (n*, n*)) = [](n* Windows, n* Window)->v {er a};
	n Init(vertex2D* vertextemp, n* vc, WORD* indextemp, n* ic, n* Windows, n* Window) {
		f x = (f)EkmsgCursorPosition.x;
		f y = (f)EkmsgCursorPosition.y;
		f px = position.x * GuiRectangle_Present.right;
		f py = position.y * GuiRectangle_Present.bottom;
		f sx = size.x * GuiRectangle_Present.right + px;
		f sy = size.y * GuiRectangle_Present.bottom + py;
		rect.left = px;
		rect.right = sx;
		rect.top = py;
		rect.bottom = sy;

		if (preclicked) {
			focused = false;
			clicked = false;
			activated = false;
			if (!EkmsgMouseClicked) {
				preclicked = false;
			}
		}
		else {
			if ((px < x) && (x < sx) && (py < y) && (y < sy)) {
				focused = true;
				if (EkmsgMouseClicked) {
					clicked = true;
					activated = true;
				}
			}
			else {
				focused = false;
				clicked = false;
				if (EkmsgMouseClicked) {
					preclicked = true;
					activated = false;
				}
			}
		}
		if (EkmsgKeyStatus[ReactionvkCode]) {
			preclicked = false;
			focused = false;
			clicked = false;
			activated = true;
			EkmsgKeyStatus[ReactionvkCode] = 0;
		}
		if (activated) {
		vertextemp[*vc] = { px,py,position.z,1.0f,bgactive };
		vertextemp[*vc + 1] = { sx,py,position.z,1.0f,bgfocus };
		vertextemp[*vc + 2] = { sx,sy,position.z,1.0f,bgfocus };
		vertextemp[*vc + 3] = { px,sy,position.z,1.0f,bgactive };
		}
		else if (focused) {
			vertextemp[*vc] = { px,py,position.z,1.0f,bgfocus };
			vertextemp[*vc + 1] = { sx,py,position.z,1.0f,bgfocus };
			vertextemp[*vc + 2] = { sx,sy,position.z,1.0f,bgfocus };
			vertextemp[*vc + 3] = { px,sy,position.z,1.0f,bgfocus };
		}
		else {
			vertextemp[*vc] = { px,py,position.z,1.0f,bgcolor };
			vertextemp[*vc + 1] = { sx,py,position.z,1.0f,bgcolor };
			vertextemp[*vc + 2] = { sx,sy,position.z,1.0f,bgcolor };
			vertextemp[*vc + 3] = { px,sy,position.z,1.0f,bgcolor };
		}
		
		n s = *ic * 3;
		indextemp[s] = *vc;
		indextemp[s + 1] = *vc + 1;
		indextemp[s + 2] = *vc + 2;
		indextemp[s + 3] = *vc;
		indextemp[s + 4] = *vc + 2;
		indextemp[s + 5] = *vc + 3;
		*vc += 4;
		*ic += 2;
		init = 1;
		er0
	}
	v Char() {
		d3dFontPointerArray[0]->DrawText(
			0, // 当前窗口
			textSwprintf_s, // 显示的字符串
			charcount, // 字符数
			&rect, // 显示的目标矩形
			DT_CENTER | DT_VCENTER,
			txcolor
		);
		er a
	}
};
C ekWindow{
cpo:
	n vertexCount = 0;
	n triangleCount = 0;
	n Windows[32] = { 0 };
	n Window = 0;
	ekButton* ekbuttons;
	n ekbuttonsCount;
	ekTextBox* ektextboxs;
	n ektextboxsCount;
	b repaint = false;
	v ekbuttonsInit(vertex2D* vertextemp, WORD* indextemp) {
		for (n i = 0; i < ekbuttonsCount; i++) {
			if (ekbuttons[i].Init(vertextemp, &vertexCount, indextemp, &triangleCount, Windows, &Window)) {
				repaint = true;
			}
		}
	}
	v ekbuttonsChar() {
		for (n i = 0; i < ekbuttonsCount; i++) {
			ekbuttons[i].Char();
		}
	}
	v ektextboxsInit(vertex2D* vertextemp, WORD* indextemp) {
		for (n i = 0; i < ektextboxsCount; i++) {
			if (ektextboxs[i].Init(vertextemp, &vertexCount, indextemp, &triangleCount, Windows, &Window)) {
				repaint = true;
			}
		}
	}
	v ektextboxsChar() {
		for (n i = 0; i < ektextboxsCount; i++) {
			ektextboxs[i].Char();
		}
	}

	v reset() {
		vertexCount = 0;
		triangleCount = 0;
		er;
	}
	v Init(vertex2D* vertextemp, WORD* indextemp) {
		ekbuttonsInit(vertextemp, indextemp);
		ektextboxsInit(vertextemp, indextemp);
		er a
	}
	v Char() {
		ekbuttonsChar();
		ektextboxsChar();
		er a
	}
};


// Global functions:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
n MainInit();
n MainPreDefine(v(**)(ekThreadBlocker*, ekWindow*), v(**)(ekThreadBlocker*, ekWindow*));
n TestProgress();
HRESULT MainObjectsInit(HWND, n, n, LPCTSTR, n, LPCTSTR);
HRESULT MainPrintInit(HWND);
n PrintStart();
n PrintShape(n, n);
n PrintEnd();
f GetFPS();
f GetFPSEk();

#endif // !EMSIAETKADOSHTOOLS_GRAND