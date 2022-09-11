#pragma once

#include "PreGlobal.h"

HRESULT MainObjectsInit(HWND hWnd, n req, n height1, LPCTSTR name1, n height2, LPCTSTR name2) {
	if (
		FAILED(
			D3DXCreateFont(
				d3dDevicePointer, // D3D�豸ָ��
				min(GuiRectangle_Present.right / 24, GuiRectangle_Present.bottom / 4), // INT ����� ��Ҫ����Ϊ����
				0, // UINT �����
				0, // UINT ����Ȩ��
				1, // UINT �����������
				false, // BOOL �Ƿ�б��
				DEFAULT_CHARSET, // DWORD �ַ�����Ĭ��
				OUT_DEFAULT_PRECIS, // DWORD �ı����ȣ�Ĭ��
				DEFAULT_QUALITY, // DWORD �ı�������Ĭ��
				0, // DWORD ���������ţ���0
				_T("΢���ź�"), // LPCTSTR ��������
				&d3dFontPointerArray[0] // LPD3DXFONT �洢�����ָ��
			)
		) or FAILED(
			D3DXCreateFont(
				d3dDevicePointer, // D3D�豸ָ��
				min(GuiRectangle_Present.right / 12, GuiRectangle_Present.bottom / 2), // INT ����� ��Ҫ����Ϊ����
				0, // UINT �����
				0, // UINT ����Ȩ��
				1, // UINT �����������
				false, // BOOL �Ƿ�б��
				DEFAULT_CHARSET, // DWORD �ַ�����Ĭ��
				OUT_DEFAULT_PRECIS, // DWORD �ı����ȣ�Ĭ��
				DEFAULT_QUALITY, // DWORD �ı�������Ĭ��
				0, // DWORD ���������ţ���0
				_T("΢���ź�"), // LPCTSTR ��������
				&d3dFontPointerArray[1] // LPD3DXFONT �洢�����ָ��
			)
		) or (req?
			FAILED(
				D3DXCreateFont(
					d3dDevicePointer, // D3D�豸ָ��
					height1, // INT ����� ��Ҫ����Ϊ����
					0, // UINT �����
					0, // UINT ����Ȩ��
					1, // UINT �����������
					false, // BOOL �Ƿ�б��
					DEFAULT_CHARSET, // DWORD �ַ�����Ĭ��
					OUT_DEFAULT_PRECIS, // DWORD �ı����ȣ�Ĭ��
					DEFAULT_QUALITY, // DWORD �ı�������Ĭ��
					0, // DWORD ���������ţ���0
					name1, // LPCTSTR ��������
					&d3dFontPointerArray[3] // LPD3DXFONT �洢�����ָ��
				)
			) or FAILED(
				D3DXCreateFont(
					d3dDevicePointer, // D3D�豸ָ��
					height2, // INT ����� ��Ҫ����Ϊ����
					0, // UINT �����
					0, // UINT ����Ȩ��
					1, // UINT �����������
					false, // BOOL �Ƿ�б��
					DEFAULT_CHARSET, // DWORD �ַ�����Ĭ��
					OUT_DEFAULT_PRECIS, // DWORD �ı����ȣ�Ĭ��
					DEFAULT_QUALITY, // DWORD �ı�������Ĭ��
					0, // DWORD ���������ţ���0
					name2, // LPCTSTR ��������
					&d3dFontPointerArray[4] // LPD3DXFONT �洢�����ָ��
				)
			):true
		)
	) {
		er E_FAIL;
	}
	else {
		er MB_OK;
	}
}
HRESULT MainPrintInit(HWND hWnd) {
	d3drelease();
	LPDIRECT3D9 d3dcomPointer = NULL;// �����ӿڶ���
	if (NULL == (d3dcomPointer = Direct3DCreate9(D3D_SDK_VERSION))) { return E_FAIL; }// ��ʼ���ӿڶ��󣬽��а汾Э��
	D3DCAPS9 d3dcaps;
	int vp = 0;
	if (FAILED(d3dcomPointer->GetDeviceCaps(
		D3DADAPTER_DEFAULT, // �Կ���ţ�Ĭ�ϵ�ǰ
		D3DDEVTYPE_HAL,  // Ӳ���豸���ͣ������׺��REF
		&d3dcaps))) {
		MessageBox(NULL, L"�μ���ȡ�豸��Ϣʧ��", L"EKDT����", MB_OK); return E_FAIL;
	}
	if (d3dcaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) {
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING; // Ӳ����������
	}
	else {
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING; // �����������
	}
	D3DPRESENT_PARAMETERS d3dParams;
	ZeroMemory(&d3dParams, sizeof(d3dParams));
	d3dParams.BackBufferWidth = GuiRectangle_Present.right;						// ��̨��������
	d3dParams.BackBufferHeight = GuiRectangle_Present.bottom;					// ��̨��������
	d3dParams.BackBufferFormat = D3DFMT_A8R8G8B8;			// ���������ظ�ʽ
	d3dParams.BackBufferCount = 2;							// ��̨��������ȣ�����
	d3dParams.MultiSampleType = D3DMULTISAMPLE_NONE;		// ���ز�������
	d3dParams.MultiSampleQuality = 0;						// ���ز�����ʽ
	d3dParams.SwapEffect = D3DSWAPEFFECT_DISCARD;			// ������θ��Ƶ�ǰ̨
	d3dParams.hDeviceWindow = hWnd;							// ���ھ��
	d3dParams.Windowed = true;								// �Ƿ񴰿�
	d3dParams.EnableAutoDepthStencil = true;				// ������Ȼ���
	d3dParams.AutoDepthStencilFormat = D3DFMT_D24S8;		// ��Ȼ������ظ�ʽ
	d3dParams.Flags = 0;									// ��������
	d3dParams.FullScreen_RefreshRateInHz = 0;				// ȫ��ˢ���ʣ���ȫ����Ҫ��
	d3dParams.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;	// ǰ��̨��󽻻�Ƶ��
	if (FAILED(d3dcomPointer->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, vp, &d3dParams, &d3dDevicePointer))) {
		MessageBox(NULL, L"�μ������豸�ӿ�ʧ��", L"EKDT����", MB_OK);
		return E_FAIL;
	}
	return S_OK;
}
n PrintStart(){
	if (!d3dDevicePointer) {
		return 1;
	}
	// ��һ���������Ļ
	d3dDevicePointer->Clear(
		0, // DWORD ָ��������һ������ָ��ľ��������о��ε������������һ��ΪNULL������һ�����Ϊ0
		NULL, // const D3DRECT* ָ��һ��D3DRECT�ṹ�������ָ�룬����Ҫ��յ�Ŀ���������
		D3DCLEAR_TARGET, // DWORD ָ��������Ҫ��յĻ���������ΪD3DCLEAR_+STENCIL | TARGET | ZBUFFER ��������ϣ��ֱ��ʾģ�建��������ɫ����������Ȼ�����
		D3DCOLOR_XRGB(10, 20, 50), // D3DCOLOR ������պ����ɫ����ӦTARGET
		1.0f, // float ָ�������Ȼ�������ÿ�����ض�Ӧ���ֵ����ӦZBUFFER
		0 // DWORD ָ�����ģ�建����֮��ÿ��ģ�建����ÿ�����ض�Ӧģ��ֵ����ӦSTENCIL
	);
	// �ڶ�������ʼ����
	d3dDevicePointer->BeginScene();
	d3dDevicePointer->CreateVertexBuffer(4 * sizeof(vertex2D), 0, D3DFVF_VERTEX, D3DPOOL_DEFAULT, &d3dVertexPointer, NULL);//�������㻺����
	d3dDevicePointer->CreateIndexBuffer(6 * sizeof(WORD), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &d3dIndexPointer, NULL);//������������
	return 0;
	// ����������ʽ����
}
n PrintShape(n vertexCount, n triangleCount) {
	d3dDevicePointer->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	d3dDevicePointer->SetStreamSource(0, d3dVertexPointer, 0, sizeof(vertex2D));
	d3dDevicePointer->SetFVF(D3DFVF_VERTEX);
	d3dDevicePointer->SetIndices(d3dIndexPointer);
	//d3dDevicePointer->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	d3dDevicePointer->DrawIndexedPrimitive(
		D3DPT_TRIANGLELIST,
		0, // �������λ�ö�Ӧ����λ��
		0, // ������Сֵ����0
		vertexCount,//4 * guipages::buttons.buttonsCount, // ������Ŀ
		0, // �ӵڼ���������ʼ����ͼԪ
		triangleCount//2 * guipages::buttons.buttonsCount  // ͼԪ����
	);
	er0
}
n PrintEnd() {
	int charCount_temp = swprintf_s(&fpsString, 20, _T("%0.2f FPS"), GetFPSEk());
	d3dFontPointerArray[0]->DrawText(
		0, // ��ǰ����
		&fpsString, // ��ʾ���ַ���
		charCount_temp, // �ַ���
		&GuiRectangle_Present, // ��ʾ��Ŀ�����
		DT_TOP | DT_RIGHT,
		fps > 60 ? D3DCOLOR_XRGB(39, 255, 136) : (fps > 40 ? D3DCOLOR_XRGB(255, 255, 64) : D3DCOLOR_XRGB(255, 39, 136))
	);
	// ���Ĳ�����������
	d3dDevicePointer->EndScene();
	// ���岽����ת��ʾ
	d3dDevicePointer->Present(NULL, NULL, NULL, NULL);
	er0
}

f GetFPS() {
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
f GetFPSEk() {
	fps_count++;
	fps_curtime = 0.001 * timeGetTime();
	if (fps_curtime - fps_pretime > 0.2f) {
		fps = (f)(fps_count / (fps_curtime - fps_pretime));
		fps_pretime = fps_curtime;
		fps_count = 0;
	}
	er fps a
}