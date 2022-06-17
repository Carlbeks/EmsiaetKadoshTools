#pragma once


#include "Pre_Global_Def.h"


namespace d3d9 {
	HRESULT Init(HWND);
	HRESULT ObjectsInit(HWND);
	void GuiPrinter();
	void SetBackgroundPic();
	float GetFPS();

	//
	// ���� d3dInit()
	// �ƹ����е���Ļ���ƹ�������Ҫ��WM_PAINT������
	//
	HRESULT Init(HWND hWnd) {
		LPDIRECT3D9 d3dcomPointer = NULL;// �����ӿڶ���
		if (NULL == (d3dcomPointer = Direct3DCreate9(D3D_SDK_VERSION))) { return E_FAIL; }// ��ʼ���ӿڶ��󣬽��а汾Э��
		D3DCAPS9 d3dcaps;
		int vp = 0;
		if (FAILED(d3dcomPointer->GetDeviceCaps(
		D3DADAPTER_DEFAULT, // �Կ���ţ�Ĭ�ϵ�ǰ
		D3DDEVTYPE_HAL,  // Ӳ���豸���ͣ������׺��REF
		&d3dcaps))) {
			MessageBox(NULL, L"����ʧ�ܣ���ȡ�豸��Ϣʧ��", L"EmsiaetKadosh's Desktop Tool Caution", MB_OK); return E_FAIL; }
		if (d3dcaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) {
			vp = D3DCREATE_HARDWARE_VERTEXPROCESSING; // Ӳ����������
		}
		else {
			vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING; // �����������
		}
		D3DPRESENT_PARAMETERS d3dParams;
		ZeroMemory(&d3dParams, sizeof(d3dParams));
		d3dParams.BackBufferWidth				= GuiRectangle_Present.right;		// ��̨��������
		d3dParams.BackBufferHeight				= GuiRectangle_Present.bottom;		// ��̨��������
		d3dParams.BackBufferFormat				= D3DFMT_A8R8G8B8;					// ���������ظ�ʽ
		d3dParams.BackBufferCount				= 2;								// ��̨��������ȣ�����
		d3dParams.MultiSampleType				= D3DMULTISAMPLE_NONE;				// ���ز�������
		d3dParams.MultiSampleQuality			= 0;								// ���ز�����ʽ
		d3dParams.SwapEffect					= D3DSWAPEFFECT_DISCARD;			// ������θ��Ƶ�ǰ̨
		d3dParams.hDeviceWindow					= hWnd;								// ���ھ��
		d3dParams.Windowed						= !FullscreenStatus;				// �Ƿ񴰿�
		d3dParams.EnableAutoDepthStencil		= true;								// ������Ȼ���
		d3dParams.AutoDepthStencilFormat		= D3DFMT_D24S8;						// ��Ȼ������ظ�ʽ
		d3dParams.Flags							= 0;								// ��������
		d3dParams.FullScreen_RefreshRateInHz	= 0;								// ȫ��ˢ���ʣ���ȫ����Ҫ��
		d3dParams.PresentationInterval			= D3DPRESENT_INTERVAL_IMMEDIATE;	// ǰ��̨��󽻻�Ƶ��
		if (FAILED(d3dcomPointer->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, vp, &d3dParams, &d3dDevicePointer))) {
			MessageBox(NULL, L"����ʧ�ܣ������豸�ӿ�ʧ��", L"EmsiaetKadosh's Desktop Tool Caution", MB_OK);
			return E_FAIL;
		}
		SAFE_RELEASE(d3dcomPointer);// ��ȫ�ͷ�
		if (!(S_OK == ObjectsInit(hWnd))) {
			MessageBox(NULL, L"����ʧ�ܣ������ʼ��ʧ��", L"EmsiaetKadosh's Desktop Tool Caution", MB_OK);
			return E_FAIL;
		}
		return S_OK;
	}

	//
	// ���� ObjectsInit()
	// ��ʼ��������Ⱦ����
	//
	HRESULT ObjectsInit(HWND hWnd) {
		if (FAILED(D3DXCreateFont(
			d3dDevicePointer, // D3D�豸ָ��
			36, // INT ����� ��Ҫ����Ϊ����
			0, // UINT �����
			0, // UINT ����Ȩ��
			1, // UINT �����������
			false, // BOOL �Ƿ�б��
			DEFAULT_CHARSET, // DWORD �ַ�����Ĭ��
			OUT_DEFAULT_PRECIS, // DWORD �ı����ȣ�Ĭ��
			DEFAULT_QUALITY, // DWORD �ı�������Ĭ��
			0, // DWORD ���������ţ���0
			_T("΢���ź�"), // LPCTSTR ��������
			&d3dFontPointer // LPD3DXFONT �洢�����ָ��
		))) {
			return E_FAIL;
		}
		return S_OK;
	}

	//
	// ���� GuiPrinter()
	// �ƹ����е���Ļ���ƹ�������Ҫ��WM_PAINT������
	//
	void GuiPrinter() {
		// ��һ���������Ļ
		d3dDevicePointer->Clear(
			0, // DWORD ָ��������һ������ָ��ľ��������о��ε������������һ��ΪNULL������һ�����Ϊ0
			NULL, // const D3DRECT* ָ��һ��D3DRECT�ṹ�������ָ�룬����Ҫ��յ�Ŀ���������
			D3DCLEAR_TARGET, // DWORD ָ��������Ҫ��յĻ���������ΪD3DCLEAR_+STENCIL | TARGET | ZBUFFER ��������ϣ��ֱ��ʾģ�建��������ɫ����������Ȼ�����
			D3DCOLOR_XRGB(0, 20, 70), // D3DCOLOR ������պ����ɫ����ӦTARGET
			1.0f, // float ָ�������Ȼ�������ÿ�����ض�Ӧ���ֵ����ӦZBUFFER
			0 // DWORD ָ�����ģ�建����֮��ÿ��ģ�建����ÿ�����ض�Ӧģ��ֵ����ӦSTENCIL
		);
		// �ڶ�������ʼ����
		d3dDevicePointer->BeginScene();
		// ����������ʽ����
		int charCount_temp = swprintf_s(fpsString, 20, _T("FPS:%0.3f"), GetFPS());
		RECT fpsRectanglePointer_temp = { 0 };
		fpsRectanglePointer_temp.right = GuiRectangle_Present.right;
		fpsRectanglePointer_temp.bottom = GuiRectangle_Present.bottom / 20;
		d3dFontPointer->DrawText(
			0, // ��ǰ����
			fpsString, // ��ʾ���ַ���
			charCount_temp, // �ַ���
			&fpsRectanglePointer_temp, // ��ʾ��Ŀ�����
			DT_TOP | DT_RIGHT,
			fps > 50 ? D3DCOLOR_XRGB(39, 255, 136) : (fps > 35 ? D3DCOLOR_XRGB(255, 64, 255) : D3DCOLOR_XRGB(255, 39, 136))
		);
		// ���Ĳ�����������
		d3dDevicePointer->EndScene();
		// ���岽����ת��ʾ
		d3dDevicePointer->Present(NULL, NULL, NULL, NULL);
	}

	//
	// ���� SetBackgroundPic()
	// 
	// ��װ�����ñ���ͼƬ��һϵ�в���������
	// ��Ӳ���м���ָ��ͼƬ�������ƣ�
	// ���ص���Ӧ������
	//
	void SetBackgroundPic() {

	}

	float GetFPS() {
		//���徲̬����
		static int    frameCount = 0;//֡��
		static float  currentTime = 0.0f;//��ǰʱ��
		static float  lastTime = 0.0f;//����ʱ��

		frameCount++;//ÿ����һ��Get_FPS()������֡������1
		currentTime = timeGetTime() * 0.001f;//��ȡϵͳʱ�䣬����timeGetTime�������ص����Ժ���Ϊ��λ��ϵͳʱ�䣬������Ҫ����0.001���õ���λΪ���ʱ��

		//�����ǰʱ���ȥ����ʱ�������1���ӣ��ͽ���һ��FPS�ļ���ͳ���ʱ��ĸ��£�����֡��ֵ����
		if (currentTime - lastTime > 1.0f) //��ʱ�������1����
		{
			fps = (float)frameCount / (currentTime - lastTime);//������1���ӵ�FPSֵ
			lastTime = currentTime; //����ǰʱ��currentTime��������ʱ��lastTime����Ϊ��һ��Ļ�׼ʱ��
			frameCount = 0;//������֡��frameCountֵ����
		}

		return fps;
		//ժ���������ó�
	}
}