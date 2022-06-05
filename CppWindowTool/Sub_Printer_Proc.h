#pragma once


#include "PreSub_Global_Def.h"



// PreDef windowPrinter
int			windowPrinter();
int			fullscreenPrinter();


/*
* Def windowPrinter()
* 每当窗口大小发生更新时，该函数需要执行一遍。
*/
int windowPrinter() {
	windowNotPrintingBool_judge = false;
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(MainhWnd, &ps);
	RECT temp_rect;
	//按钮定义
	HWND Button;
	Button = CreateWindow(
		L"button",
		L"1",
		WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE | BS_OWNERDRAW,
		(int)(windowWidthInt_tempstore / 40),
		(int)(windowHeightInt_tempstore / 4),
		(int)(windowWidthInt_tempstore / 4),
		(int)(windowHeightInt_tempstore * 1 / 2),
		MainhWnd,
		(HMENU)1,
		NULL,
		NULL);
	ShowWindow(Button, SW_NORMAL);
	while (true) {
		Sleep(100);
		GetWindowRect(MainhWnd, &temp_rect);
		if (windowWidthInt_tempstore == temp_rect.right - temp_rect.left and windowHeightInt_tempstore == temp_rect.bottom - temp_rect.top) {}
		else {
			windowWidthInt_tempstore = temp_rect.right - temp_rect.left;
			windowHeightInt_tempstore = temp_rect.bottom - temp_rect.top;
			if (windowGUIStatus_tempstore == EK_GUI_STARTER) {
				UpdateWindow(Button);
				/*
				HPEN pen = CreatePen(PS_SOLID, 0, RGB(255, 255, 255));
				HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
				HRGN rgn = CreateRoundRectRgn(
					(int)(windowWidthInt_tempstore / 40),
					(int)(windowHeightInt_tempstore / 4),
					(int)(windowWidthInt_tempstore / 4),
					(int)(windowHeightInt_tempstore * 1 / 2),
					(int)(min(windowWidthInt_tempstore, windowHeightInt_tempstore) / 20),
					(int)(min(windowWidthInt_tempstore, windowHeightInt_tempstore) / 20));
				SelectObject(hdc, pen);
				SelectObject(hdc, brush);
				FillRgn(hdc, rgn, brush);
				DeleteObject(pen);
				DeleteObject(brush);
				*/
			}
			else if (windowGUIStatus_tempstore == EK_GUI_WINDOW) {

			}
			else {

			}
		}
	}
	EndPaint(MainhWnd, &ps);
	return 0;
}

/*
* Def fullscreemPrinter()
*/
int fullscreenPrinter() {
	RECT temp_rect;
	GetWindowRect(MainhWnd, &temp_rect);
	windowWidthInt_tempstore = temp_rect.right - temp_rect.left;
	windowHeightInt_tempstore = temp_rect.bottom - temp_rect.top;
	
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(MainhWnd, &ps);
	if (windowGUIStatusLast_tempstore != windowGUIStatus_tempstore) {
		switch (windowGUIStatusLast_tempstore)
		{
		case EK_GUI_BLACK:
			break;
		case EK_GUI_STARTER:
			DestroyWindow(guiButtons.__STARTER.Home);
			DestroyWindow(guiButtons.__STARTER.Normal);
			windowGUIStatusLast_tempstore = windowGUIStatus_tempstore;
			break;
		case EK_GUI_WINDOW:
			DestroyWindow(guiButtons.__WINDOW.BACKtoSTART);
			windowGUIStatusLast_tempstore = windowGUIStatus_tempstore;
			break;
		default:
			break;
		}
	}
	if (windowGUIStatus_tempstore == EK_GUI_STARTER /*开始界面*/) {
		HRGN rgn11 = CreateRoundRectRgn(
			(int)(windowWidthInt_tempstore * 2 / 30),
			(int)(windowHeightInt_tempstore / 2),
			(int)(windowWidthInt_tempstore * 10 / 30),
			(int)(windowHeightInt_tempstore * 3 / 4),
			(int)(min(windowWidthInt_tempstore, windowHeightInt_tempstore) / 20),
			(int)(min(windowWidthInt_tempstore, windowHeightInt_tempstore) / 20));
		HRGN rgn12 = CreateRoundRectRgn(
			(int)(windowWidthInt_tempstore * 11 / 30),
			(int)(windowHeightInt_tempstore / 2),
			(int)(windowWidthInt_tempstore * 19 / 30),
			(int)(windowHeightInt_tempstore * 3 / 4),
			(int)(min(windowWidthInt_tempstore, windowHeightInt_tempstore) / 20),
			(int)(min(windowWidthInt_tempstore, windowHeightInt_tempstore) / 20));
		HRGN rgn13 = CreateRoundRectRgn(
			(int)(windowWidthInt_tempstore * 20 / 30),
			(int)(windowHeightInt_tempstore / 2),
			(int)(windowWidthInt_tempstore * 28 / 30),
			(int)(windowHeightInt_tempstore * 3 / 4),
			(int)(min(windowWidthInt_tempstore, windowHeightInt_tempstore) / 20),
			(int)(min(windowWidthInt_tempstore, windowHeightInt_tempstore) / 20));
		HPEN pen = CreatePen(PS_SOLID, 0, RGB(255, 255, 255));
		HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, brush);
		FillRgn(hdc, rgn11, brush);
		FillRgn(hdc, rgn12, brush);
		FillRgn(hdc, rgn13, brush);
		DeleteObject(pen);
		DeleteObject(brush);
		EndPaint(MainhWnd, &ps);
		//按钮定义
		DestroyWindow(guiButtons.__STARTER.Home);
		guiButtons.__STARTER.Home = CreateWindow(
			L"button",
			L"Home",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE | BS_FLAT | BS_NOTIFY | BS_MULTILINE,
			(int)(windowWidthInt_tempstore * 11 / 30),
			(int)(windowHeightInt_tempstore / 2),
			(int)(windowWidthInt_tempstore * 8 / 30),
			(int)(windowHeightInt_tempstore * 1 / 4),
			MainhWnd,
			NULL,
			NULL,
			NULL);
		DestroyWindow(guiButtons.__STARTER.Normal);
		guiButtons.__STARTER.Normal = CreateWindow(
			L"button",
			L"Normal",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE | BS_FLAT | BS_NOTIFY | BS_MULTILINE,
			(int)(windowWidthInt_tempstore * 2 / 30),
			(int)(windowHeightInt_tempstore / 2),
			(int)(windowWidthInt_tempstore * 8 / 30),
			(int)(windowHeightInt_tempstore * 1 / 4),
			MainhWnd,
			NULL,
			NULL,
			NULL);
		ShowWindow(guiButtons.__STARTER.Home, SW_NORMAL);
		UpdateWindow(guiButtons.__STARTER.Home);
		ShowWindow(guiButtons.__STARTER.Normal, SW_NORMAL);
		UpdateWindow(guiButtons.__STARTER.Normal);
		//
	}
	else if (windowGUIStatus_tempstore == EK_GUI_BLACK /*黑屏界面*/) {
		HRGN rgnBLACK = CreateRectRgn(
			0,0,
			(int)(windowWidthInt_tempstore),
			(int)(windowHeightInt_tempstore));
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		SelectObject(hdc, brush);
		FillRgn(hdc, rgnBLACK, brush);
		DeleteObject(brush);
		EndPaint(MainhWnd, &ps);
	}
	else if (windowGUIStatus_tempstore == EK_GUI_WINDOW /*窗口集合界面*/) {
		DestroyWindow(guiButtons.__WINDOW.BACKtoSTART);
		guiButtons.__WINDOW.BACKtoSTART = CreateWindow(
			L"button",
			L"Back To Starter",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE | BS_FLAT | BS_NOTIFY | BS_MULTILINE,
			0,
			0,
			(int)(windowWidthInt_tempstore * 1 / 10),
			(int)(windowHeightInt_tempstore * 1 / 20),
			MainhWnd,
			NULL,
			NULL,
			NULL);
		ShowWindow(guiButtons.__WINDOW.BACKtoSTART, SW_NORMAL);
		UpdateWindow(guiButtons.__WINDOW.BACKtoSTART);
	}
	else {
	}
	
	return 0;
}


