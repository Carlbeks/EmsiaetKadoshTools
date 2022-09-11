#pragma once

#include <ios>
#include <thread>
#include <fstream>
#include <time.h>
#include <d3d9.h>
#include "C:\Program Files (x86)\DirectX9\Include\d3dx9.h"
#include <windowsx.h>
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"comctl32.lib")
#pragma comment(lib,"C:\\Program Files (x86)\\DirectX9\\Lib\\x64\\d3dx9.lib")
#include "framework.h"
#include "EmsiaetKadoshDesktopTool-pre3.h"

#include "EmsiaetKadosh.h"

#ifndef EMSIAETKADOSHTOOLS_GRAND
#define EMSIAETKADOSHTOOLS_GRAND 1
#define MAX_LOADSTRING 100

#define WINDOWOUT_WRONG(pIn) {MessageBox(NULL, pIn, L"EKDT错误", MB_OK);er0}
#define GetCursorClientPosition(hWnd, lpPoint) {POINT temp; GetCursorPos(&temp); ScreenToClient(hWnd,&temp); *lpPoint = temp;}

#define SAFE_RELEASE(pointer) {if(pointer){(pointer)->Release();(pointer)=NULL;}}
#define D3DFVF_VERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)/*经过顶点变换、漫反射*/

#endif

HWND MainhWnd;
HINSTANCE MainhInstance;
LPDIRECT3DDEVICE9 d3dDevicePointer;
LPDIRECT3DVERTEXBUFFER9 d3dVertexPointer;
LPDIRECT3DINDEXBUFFER9 d3dIndexPointer;
RECT GuiRectangle;
POINT EkmsgCursorPosition;
b EkmsgMouseClicked[3] = { 0 };
b EkmsgKeyStatus[256] = { 0 };
f fps = 0.0f;
n fps_count = 0;
f fps_pretime = 0.0f;
f fps_curtime = 0.0f;
wct fpsString = 0;
static DWORD prev_time = 0;
static DWORD pres_time = 0;
S vertex2D{ FLOAT x = 0.0f; FLOAT y = 0.0f; FLOAT z = 0.0f; FLOAT rhw = 1.0f; DWORD color = D3DCOLOR_RGBA(0, 0, 0, 0); };
v d3drelease() { SAFE_RELEASE(d3dVertexPointer); SAFE_RELEASE(d3dIndexPointer); SAFE_RELEASE(d3dDevicePointer); er; }

v Counter() {
	static n prev;
	static n count;
	static n delta;
	delta = timeGetTime() - prev;
	count++;
	if (delta >= 1000) {
		//itoa((n)(1000 * count / delta), the, 16);
		std::string thes = IntToString_OCT((n)(1000 * count / delta));
		logging.Output(LOG_INFO, JoinString("TIME COUNTER ------------------------------", thes));
		prev = timeGetTime();
		count = 0;
	}
	er;
}