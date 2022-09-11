#pragma once

#include "PaintProgress.h"
#include "WindowIns.h"

n MainInit() {
	POINT temp;
	GetCursorPos(&temp);
	ScreenToClient(MainhWnd, &temp);
	EkmsgCursorPosition = temp;
	GetClientRect(MainhWnd, &GuiRectangle_Present);
	MainPrintInit(MainhWnd);
	MainObjectsInit(MainhWnd, 0, 0, L"NULL", 0, L"NULL");
	er0
}

n MainPreDefine(v(**defines)(ekThreadBlocker*, ekWindow*), v(**executes)(ekThreadBlocker*, ekWindow*), ekWindow* ekwindow) {
	defines[0] = [](ekThreadBlocker* ekthreadblocker, ekWindow* ekwindow)->v {
		ekButton ekbuttons[6];
		ekTextBox ektextbox[1];

		ekbuttons[0].position = { 0.0f, 0.34f, 0.0f };
		ekbuttons[0].size = { 0.3f, 0.08f, 0.0f };
		ekbuttons[0].bgcolor = D3DCOLOR_RGBA(128, 180, 255, 128);
		ekbuttons[0].bgfocus = D3DCOLOR_RGBA(255, 255, 180, 128);
		ekbuttons[0].txcolor = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[0].txfocus = D3DCOLOR_XRGB(255, 128, 128);
		ekbuttons[0].ReactionvkCode = VK_Q;
		ekbuttons[0].charcount = swprintf_s(&ekbuttons[0].textSwprintf_s[0], 32, L"Start");
		ekbuttons[0].Exe = [](n* Windows, n* Window)->v { *Window += 1; Windows[*Window] = 1; er a };

		ekbuttons[1].position = { 0.0f, 0.46f, 0.0f };
		ekbuttons[1].size = { 0.3f, 0.08f, 0.0f };
		ekbuttons[1].bgcolor = D3DCOLOR_RGBA(128, 180, 255, 128);
		ekbuttons[1].bgfocus = D3DCOLOR_RGBA(255, 255, 180, 128);
		ekbuttons[1].txcolor = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[1].txfocus = D3DCOLOR_XRGB(255, 128, 128);
		ekbuttons[1].ReactionvkCode = VK_A;
		ekbuttons[1].charcount = swprintf_s(&ekbuttons[1].textSwprintf_s[0], 32, L"Settings");
		ekbuttons[1].Exe = [](n* Windows, n* Window)->v { *Window += 1; Windows[*Window] = 2; er a };

		ekbuttons[2].position = { 0.0f, 0.58f, 0.0f };
		ekbuttons[2].size = { 0.3f, 0.08f, 0.0f };
		ekbuttons[2].bgcolor = D3DCOLOR_RGBA(128, 180, 255, 128);
		ekbuttons[2].bgfocus = D3DCOLOR_RGBA(255, 255, 180, 128);
		ekbuttons[2].txcolor = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[2].txfocus = D3DCOLOR_XRGB(255, 128, 128);
		ekbuttons[2].ReactionvkCode = VK_Z;
		ekbuttons[2].charcount = swprintf_s(&ekbuttons[2].textSwprintf_s[0], 32, L"2");
		ekbuttons[2].Exe = [](n* Windows, n* Window)->v { er a };

		ekbuttons[3].position = { 0.7f, 0.34f, 0.0f };
		ekbuttons[3].size = { 0.3f, 0.08f, 0.0f };
		ekbuttons[3].bgcolor = D3DCOLOR_RGBA(128, 180, 255, 128);
		ekbuttons[3].bgfocus = D3DCOLOR_RGBA(255, 255, 180, 128);
		ekbuttons[3].txcolor = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[3].txfocus = D3DCOLOR_XRGB(255, 128, 128);
		ekbuttons[3].ReactionvkCode = VK_E;
		ekbuttons[3].charcount = swprintf_s(&ekbuttons[3].textSwprintf_s[0], 32, L"Command");
		ekbuttons[3].Exe = [](n* Windows, n* Window)->v { *Window += 1; Windows[*Window] = 3; er; };

		ekbuttons[4].position = { 0.7f, 0.46f, 0.0f };
		ekbuttons[4].size = { 0.3f, 0.08f, 0.0f };
		ekbuttons[4].bgcolor = D3DCOLOR_RGBA(128, 180, 255, 128);
		ekbuttons[4].bgfocus = D3DCOLOR_RGBA(255, 255, 180, 128);
		ekbuttons[4].txcolor = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[4].txfocus = D3DCOLOR_XRGB(255, 128, 128);
		ekbuttons[4].ReactionvkCode = VK_D;
		ekbuttons[4].charcount = swprintf_s(&ekbuttons[4].textSwprintf_s[0], 32, L"4");
		ekbuttons[4].Exe = [](n* Windows, n* Window)->v { er a };

		ekbuttons[5].position = { 0.7f, 0.58f, 0.0f };
		ekbuttons[5].size = { 0.3f, 0.08f, 0.0f };
		ekbuttons[5].bgcolor = D3DCOLOR_RGBA(128, 180, 255, 128);
		ekbuttons[5].bgfocus = D3DCOLOR_RGBA(255, 255, 180, 128);
		ekbuttons[5].txcolor = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[5].txfocus = D3DCOLOR_XRGB(255, 128, 128);
		ekbuttons[5].ReactionvkCode = VK_C;
		ekbuttons[5].charcount = swprintf_s(&ekbuttons[5].textSwprintf_s[0], 32, L"Exit");
		ekbuttons[5].Exe = [](n* Windows, n* Window)->v { PostQuitMessage(0); er a };

		ekwindow->ekbuttons = ekbuttons;
		ekwindow->ekbuttonsCount = 6;
		ekthreadblocker->block();
		er a
	};
	executes[0] = [](ekThreadBlocker* ekthreadblocker, ekWindow* ekwindow)->v {
		vertex2D vertextemp[24] = { 0 };
		WORD Indextemp[36] = { 0 };
		ekwindow->ekbuttonsInit(vertextemp, Indextemp);
		VOID* VerticesPointer_temp = NULL;
		if (FAILED(d3dVertexPointer->Lock(0, sizeof(vertextemp), (void**)&VerticesPointer_temp, 0))) {
			er a;
		}
		memcpy(VerticesPointer_temp, vertextemp, sizeof(vertextemp));
		d3dVertexPointer->Unlock();
		// Index
		WORD* IndicesPointer_temp = NULL;
		d3dIndexPointer->Lock(0, sizeof(vertextemp), (void**)&IndicesPointer_temp, 0);
		memcpy(IndicesPointer_temp, Indextemp, sizeof(Indextemp));
		d3dIndexPointer->Unlock();
		PrintShape(24, 12);
		ekwindow->ekbuttonsChar();
		er a
	};
	defines[1] = [](Lambda_def)->v {
		ekButton ekbuttons[2];

		ekbuttons[0].position = { 0.02f,0.03f,0.0f};
		ekbuttons[0].size = { 0.04f,0.06f,0.0f };
		ekbuttons[0].bgcolor = D3DCOLOR_XRGB(200, 0, 0);
		ekbuttons[0].bgfocus = D3DCOLOR_XRGB(200, 150, 150);
		ekbuttons[0].txcolor = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[0].txfocus = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[0].ReactionvkCode = VK_NUMPAD1;
		ekbuttons[0].charcount = swprintf_s(&ekbuttons[0].textSwprintf_s[0], 32, L"¡û");
		ekbuttons[0].Exe = [](n* Windows, n* Window)->v { *Window -= 1; er a };

		ekbuttons[1].position = { 0.07f,0.03f,0.0f };
		ekbuttons[1].size = { 0.04f,0.06f,0.0f };
		ekbuttons[1].bgcolor = D3DCOLOR_XRGB(0, 200, 0);
		ekbuttons[1].bgfocus = D3DCOLOR_XRGB(150, 200, 150);
		ekbuttons[1].txcolor = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[1].txfocus = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[1].ReactionvkCode = VK_NUMPAD2;
		ekbuttons[1].charcount = swprintf_s(&ekbuttons[1].textSwprintf_s[0], 32, L"¡ú");
		ekbuttons[1].Exe = [](n* Windows, n* Window)->v { *Window += 1; er a };
		ekbuttons[1].available = ekwindow->Windows[ekwindow->Window + 1] ? true : false;

		ekwindow->ekbuttons = ekbuttons;
		ekwindow->ekbuttonsCount = 2;
		ekthreadblocker->block();
		er a
	};
	executes[1] = [](Lambda_def)->v {
		vertex2D vertextemp[8] = { 0 };
		WORD Indextemp[12] = { 0 };
		ekwindow->ekbuttonsInit(vertextemp, Indextemp);
		VOID* VerticesPointer_temp = NULL;
		if (FAILED(d3dVertexPointer->Lock(0, sizeof(vertextemp), (void**)&VerticesPointer_temp, 0))) {
			er a;
		}
		memcpy(VerticesPointer_temp, vertextemp, sizeof(vertextemp));
		d3dVertexPointer->Unlock();
		// Index
		WORD* IndicesPointer_temp = NULL;
		d3dIndexPointer->Lock(0, sizeof(vertextemp), (void**)&IndicesPointer_temp, 0);
		memcpy(IndicesPointer_temp, Indextemp, sizeof(Indextemp));
		d3dIndexPointer->Unlock();
		PrintShape(8, 4);
		ekwindow->ekbuttonsChar();
		er a
	};
	defines[3] = [](Lambda_def)->v {
		ekButton ekbuttons[2];

		ekbuttons[0].position = { 0.02f,0.03f,0.0f };
		ekbuttons[0].size = { 0.04f,0.06f,0.0f };
		ekbuttons[0].bgcolor = D3DCOLOR_XRGB(200, 0, 0);
		ekbuttons[0].bgfocus = D3DCOLOR_XRGB(200, 150, 150);
		ekbuttons[0].txcolor = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[0].txfocus = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[0].ReactionvkCode = VK_NUMPAD1;
		ekbuttons[0].charcount = swprintf_s(&ekbuttons[0].textSwprintf_s[0], 32, L"¡û");
		ekbuttons[0].Exe = [](n* Windows, n* Window)->v { *Window -= 1; er a };

		ekbuttons[1].position = { 0.07f,0.03f,0.0f };
		ekbuttons[1].size = { 0.04f,0.06f,0.0f };
		ekbuttons[1].bgcolor = D3DCOLOR_XRGB(0, 200, 0);
		ekbuttons[1].bgfocus = D3DCOLOR_XRGB(150, 200, 150);
		ekbuttons[1].txcolor = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[1].txfocus = D3DCOLOR_XRGB(255, 255, 255);
		ekbuttons[1].ReactionvkCode = VK_NUMPAD2;
		ekbuttons[1].charcount = swprintf_s(&ekbuttons[1].textSwprintf_s[0], 32, L"¡ú");
		ekbuttons[1].Exe = [](n* Windows, n* Window)->v { *Window += 1; er a };
		ekbuttons[1].available = ekwindow->Windows[ekwindow->Window + 1] ? true : false;

		ekTextBox ektextbox;
		ektextbox.position = { 0.0f,0.8f,0.0f };
		ektextbox.size = { 1.0f, 0.12f, 0.0f };
		ektextbox.bgcolor = D3DCOLOR_RGBA(0, 0, 0, 0);
		ektextbox.bgfocus = D3DCOLOR_RGBA(64, 0, 0, 255);
		ektextbox.bgactive = D3DCOLOR_RGBA(128, 0, 0, 255);
		ektextbox.txcolor = D3DCOLOR_XRGB(255, 255, 255);
		ektextbox.ReactionvkCode = VK_RETURN;
		ektextbox.charcount = swprintf_s(&ektextbox.textSwprintf_s[0], 32, L"TestText(Return)");
		ektextbox.Exe = [](n* Windows, n* Window)->v { er a };

		ekwindow->ekbuttons = ekbuttons;
		ekwindow->ekbuttonsCount = 2;
		ekwindow->ektextboxs = &ektextbox;
		ekwindow->ektextboxsCount = 1;
		ekthreadblocker->block();
	};
	executes[3] = [](Lambda_def)->v {
		vertex2D vertextemp[12] = { 0 };
		WORD Indextemp[18] = { 0 };
		ekwindow->Init(vertextemp, Indextemp);
		VOID* VerticesPointer_temp = NULL;
		if (FAILED(d3dVertexPointer->Lock(0, sizeof(vertextemp), (void**)&VerticesPointer_temp, 0))) {
			er a;
		}
		memcpy(VerticesPointer_temp, vertextemp, sizeof(vertextemp));
		d3dVertexPointer->Unlock();
		// Index
		WORD* IndicesPointer_temp = NULL;
		d3dIndexPointer->Lock(0, sizeof(vertextemp), (void**)&IndicesPointer_temp, 0);
		memcpy(IndicesPointer_temp, Indextemp, sizeof(Indextemp));
		d3dIndexPointer->Unlock();
		PrintShape(12, 6);
		ekwindow->Char();
		er a
	};
	er0
}

v MainDefine(ekThreadBlocker* targetekthreadblocker, ekWindow* targetekwindow, b* ifloop, v(**defines)(ekThreadBlocker*, ekWindow*)) {
	while (*ifloop) {
		defines[targetekwindow->Windows[targetekwindow->Window]](targetekthreadblocker, targetekwindow);
	}
	er a
}

n TestProgress() {
	er0
}