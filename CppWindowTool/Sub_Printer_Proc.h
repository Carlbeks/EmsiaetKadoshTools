#pragma once


#include "Pre_Global_Def.h"


class button {
public:
	vector size = { 0.0f, 0.0f, 0.0f };
	wchar_t text[16] = { 0 };
	ID3DXFont* fontPointer = nullptr;
	D3DCOLOR bgndColor = NULL;
	D3DCOLOR textColor = NULL;
	bool available = false;
	int focusStyle = 0;
	D3DCOLOR focusBgndClr = 0;
	D3DCOLOR focusTextClr = 0;
	int focusStyleValue3 = 0;
	int clickStyle = 0;
	D3DCOLOR clickBgndClr = 0;
	D3DCOLOR clickTextClr = 0;
	int clickStyleValue3 = 0;
	bool focusing = false;
	bool clicking = false;
};
class buttons16 {
private:
	button* buttonsPointer[16] = { 0 };
	vertex2D vertices_temp[64] = { 0 };
public:
	int buttonsCount = 0;
	vector startPos = { 0.0f ,0.0f ,0.0f };
	float distance = 0;
	bool movable = false;
	void AddButton(button* buttonPointer) {
		buttonsPointer[buttonsCount] = { 0 };
		buttonsPointer[buttonsCount] = buttonPointer;
		buttonsCount++;
		return;
	}
	void Clear() {
		*buttonsPointer = { 0 };
		buttonsCount = 0;
		startPos = { 0 };
		for (int i = 0; i < 16; i++) {
			vertices_temp[i] = { 0 };
		}
		return;
	}
	void Update() {
		for (int i = 0; i < 16; i++) {
			vertices_temp[i] = { 0 };
		}
		SAFE_RELEASE(d3dVertexPointer);
		SAFE_RELEASE(d3dIndexPointer);
		d3dDevicePointer->CreateVertexBuffer(4 * sizeof(vertex2D), 0, D3DFVF_VERTEX, D3DPOOL_DEFAULT, &d3dVertexPointer, NULL);//�������㻺����
		d3dDevicePointer->CreateIndexBuffer(6 * sizeof(WORD), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &d3dIndexPointer, NULL);//������������
		for (int i = 0; i < buttonsCount; i++) {
			D3DCOLOR bgndColor;
			if (buttonsPointer[i]->available) {
				if (buttonsPointer[i]->focusing) {
					if (buttonsPointer[i]->focusStyle = EK_BUTTONSTYLE_FOCUS_CLRCHANGE) {
						bgndColor = buttonsPointer[i]->focusBgndClr;
					}
				}
			}
			vertices_temp[4 * i] = {
				GuiRectangle_Present.right * (startPos.x),
				GuiRectangle_Present.bottom * (startPos.y + i * (buttonsPointer[i]->size.y + distance)),
				0.0f,
				1.0f, buttonsPointer[i]->bgndColor };
			vertices_temp[4 * i + 1] = {
				GuiRectangle_Present.right * (startPos.x + buttonsPointer[i]->size.x),
				GuiRectangle_Present.bottom * (startPos.y + i * (buttonsPointer[i]->size.y + distance)),
				0.0f,
				1.0f, buttonsPointer[i]->bgndColor };
			vertices_temp[4 * i + 2] = {
				GuiRectangle_Present.right * (startPos.x + buttonsPointer[i]->size.x),
				GuiRectangle_Present.bottom * (startPos.y + i * (buttonsPointer[i]->size.y + distance) + buttonsPointer[i]->size.y),
				0.0f,
				1.0f, buttonsPointer[i]->bgndColor };
			vertices_temp[4 * i + 3] = {
				GuiRectangle_Present.right * (startPos.x),
				GuiRectangle_Present.bottom * (startPos.y + i * (buttonsPointer[i]->size.y + distance) + buttonsPointer[i]->size.y),
				0.0f,
				1.0f, buttonsPointer[i]->bgndColor };
		}


		VOID* VerticesPointer_temp = NULL;
		if (FAILED(d3dVertexPointer->Lock(0, sizeof(vertices_temp), (void**)&VerticesPointer_temp, 0))) {
			return;
		}
		memcpy(VerticesPointer_temp, vertices_temp, sizeof(vertices_temp));
		d3dVertexPointer->Unlock();
		// Index
		WORD Indices_temp[96] = { 0,1,2, 0,2,3, 4,5,6, 4,6,7, 8,9,10, 8,10,11, 12,13,14, 12,14,15, 16,17,18, 16,18,19, 20,21,22, 20,22,23, 24,25,26, 24,26,27, 28,29,30, 28,30,31, 32,33,34, 32,34,35, 36,37,38, 36,38,39, 40,41,42, 40,42,43, 44,45,46, 44,46,47, 48,49,50, 48,50,51, 52,53,54, 52,54,55, 56,57,58, 56,58,59, 60,61,62, 60,62,63 };
		WORD* IndicesPointer_temp = NULL;
		d3dIndexPointer->Lock(0, sizeof(vertices_temp), (void**)&IndicesPointer_temp, 0);
		memcpy(IndicesPointer_temp, Indices_temp, sizeof(Indices_temp));
		d3dIndexPointer->Unlock();
		return;
	}
	void UpdateText() {
		for (int i = 0; i < buttonsCount; i++) {
			wchar_t EKString_temp[16] = { 0 };
			int charCount_temp = swprintf_s(EKString_temp, 16, (const wchar_t *const)&(buttonsPointer[i]->text));
			RECT rect_temp = { (LONG)vertices_temp[4 * i].x, (LONG)vertices_temp[4 * i].y, (LONG)vertices_temp[4 * i + 2].x, (LONG)vertices_temp[4 * i + 2].y };
			buttonsPointer[i]->fontPointer->DrawText(
				0, // ��ǰ����
				EKString_temp, // ��ʾ���ַ���
				charCount_temp, // �ַ���
				&rect_temp, // ��ʾ��Ŀ�����
				DT_CENTER | DT_VCENTER,
				D3DCOLOR_XRGB(255, 255, 255)
			);
		}
		return;
	}
};
buttons16 buttons;


void ButtonStart() {
	buttons.Update();
}


namespace d3d9 {
	HRESULT Init(HWND);
	HRESULT ObjectsInit(HWND);
	void Pages();
	void PagesText();
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
		GetClientRect(hWnd, &GuiRectangle_Present);
		d3dParams.BackBufferWidth				= GuiRectangle_Present.right;		// ��̨��������
		d3dParams.BackBufferHeight				= GuiRectangle_Present.bottom;		// ��̨��������
		d3dParams.BackBufferFormat				= D3DFMT_A8R8G8B8;					// ���������ظ�ʽ
		d3dParams.BackBufferCount				= 2;								// ��̨��������ȣ�����
		d3dParams.MultiSampleType				= D3DMULTISAMPLE_NONE;				// ���ز�������
		d3dParams.MultiSampleQuality			= 0;								// ���ز�����ʽ
		d3dParams.SwapEffect					= D3DSWAPEFFECT_DISCARD;			// ������θ��Ƶ�ǰ̨
		d3dParams.hDeviceWindow					= hWnd;								// ���ھ��
		d3dParams.Windowed						= true;								// �Ƿ񴰿�
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
		if (FAILED(
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
				&d3dFontPointer_XiaoWeiRuanYaHei // LPD3DXFONT �洢�����ָ��
			)) or FAILED(
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
				&d3dFontPointer_DaWeiRuanYaHei // LPD3DXFONT �洢�����ָ��
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
		if (!d3dDevicePointer) {
			return;
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
		// ����������ʽ����
		Pages(); // ��ť���
		d3dDevicePointer->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
		d3dDevicePointer->SetStreamSource(0, d3dVertexPointer, 0, sizeof(vertex2D));
		d3dDevicePointer->SetFVF(D3DFVF_VERTEX);
		d3dDevicePointer->SetIndices(d3dIndexPointer);
		//d3dDevicePointer->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
		d3dDevicePointer->DrawIndexedPrimitive(
			D3DPT_TRIANGLELIST,
			0, // �������λ�ö�Ӧ����λ��
			0, // ������Сֵ����0
			96,//4 * guipages::buttons.buttonsCount, // ������Ŀ
			0, // �ӵڼ���������ʼ����ͼԪ
			32//2 * guipages::buttons.buttonsCount  // ͼԪ����
		);
		PagesText();

		int charCount_temp = swprintf_s(fpsString, 20, _T("FPS:%0.2f"), GetFPS());
		d3dFontPointer_XiaoWeiRuanYaHei->DrawText(
			0, // ��ǰ����
			fpsString, // ��ʾ���ַ���
			charCount_temp, // �ַ���
			&GuiRectangle_Present, // ��ʾ��Ŀ�����
			DT_TOP | DT_RIGHT,
			fps > 50 ? D3DCOLOR_XRGB(39, 255, 136) : (fps > 35 ? D3DCOLOR_XRGB(255, 64, 255) : D3DCOLOR_XRGB(255, 39, 136))
		);
		// ���Ĳ�����������
		d3dDevicePointer->EndScene();
		// ���岽����ת��ʾ
		d3dDevicePointer->Present(NULL, NULL, NULL, NULL);
		return;
	}

	void Pages() {
		//switch (GuiDisplay_Present) {
		//case EK_GUI_START:
			buttons.Clear();
			button head;
			head.size = { 0.0f, 0.0f, 0.0f };
			head.bgndColor = D3DCOLOR_XRGB(0, 0, 0);
			head.available = false;
			button common;
			common.size = { 0.5f,0.1f,0.0f };
			common.bgndColor = D3DCOLOR_XRGB(128, 192, 255);
			swprintf_s(common.text, 16, L"Common");
			common.textColor = D3DCOLOR_XRGB(255, 255, 255);
			common.fontPointer = d3dFontPointer_XiaoWeiRuanYaHei;
			common.available = true;
			common.focusStyle = EK_BUTTONSTYLE_FOCUS_CLRCHANGE;
			common.focusBgndClr = D3DCOLOR_XRGB(255, 255, 128);

			button home;
			home.size = { 0.5f,0.1f,0.0f };
			home.bgndColor = D3DCOLOR_XRGB(128, 192, 255);
			swprintf_s(home.text, 16, L"Home");
			home.textColor = D3DCOLOR_XRGB(255, 255, 255);
			home.fontPointer = d3dFontPointer_XiaoWeiRuanYaHei;
			home.available = true;
			buttons.AddButton(&home);
			buttons.AddButton(&common);
			buttons.distance = 0.04f;
			buttons.startPos = { 0.25f,0.5f,0 };
			buttons.movable = false;

			ButtonStart();
		//	break;
		//default:
		//	break;
		//}
		//return;
	}
	void PagesText() {
		button head;
		head.size = { 0.0f, 0.0f, 0.0f };
		head.bgndColor = D3DCOLOR_XRGB(0, 0, 0);
		head.available = false;
		button common;
		common.size = { 0.5f,0.1f,0.0f };
		common.bgndColor = D3DCOLOR_XRGB(128, 192, 255);
		swprintf_s(common.text, 16, L"Common");
		common.textColor = D3DCOLOR_XRGB(255, 255, 255);
		common.fontPointer = d3dFontPointer_XiaoWeiRuanYaHei;
		common.available = true;
		common.focusStyle = EK_BUTTONSTYLE_FOCUS_CLRCHANGE;
		common.focusBgndClr = D3DCOLOR_XRGB(255, 255, 128);

		button home;
		home.size = { 0.5f,0.1f,0.0f };
		home.bgndColor = D3DCOLOR_XRGB(128, 192, 255);
		swprintf_s(home.text, 16, L"Home");
		home.textColor = D3DCOLOR_XRGB(255, 255, 255);
		home.fontPointer = d3dFontPointer_XiaoWeiRuanYaHei;
		home.available = true;
		buttons.AddButton(&home);
		buttons.AddButton(&common);
		buttons.distance = 0.04f;
		buttons.startPos = { 0.25f,0.5f,0 };
		buttons.movable = false;
		
		buttons.UpdateText();
		return;
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
	//
	// ���� GuiPrinterStart()
	// �ƹ����е���Ļ���ƹ�������Ҫ��WM_PAINT������
	//
	void GuiPrinterStartInit() {
		SAFE_RELEASE(d3dVertexPointer);
		SAFE_RELEASE(d3dIndexPointer);
		// ���������

		d3dDevicePointer->CreateVertexBuffer(4 * sizeof(vertex2D), 0, D3DFVF_VERTEX, D3DPOOL_DEFAULT, &d3dVertexPointer, NULL);//�������㻺����
		d3dDevicePointer->CreateIndexBuffer(6 * sizeof(WORD), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &d3dIndexPointer, NULL);//������������

		vertex2D vertices_temp[] = {
			// ˳ʱ��
			{(float)(-min(GuiRectangle_Present.right / 12, GuiRectangle_Present.bottom / 2) + GuiRectangle_Present.right / 2), (float)(GuiRectangle_Present.bottom / 2), 0.0f, 1.0f, D3DCOLOR_XRGB(96, 160, 200)},// x-
			{(float)(min(GuiRectangle_Present.right / 12, GuiRectangle_Present.bottom / 2) + GuiRectangle_Present.right / 2), (float)(GuiRectangle_Present.bottom / 2), 0.0f, 1.0f, D3DCOLOR_XRGB(96, 160, 200)},// x+
			{(float)(GuiRectangle_Present.right / 2), (float)(-min(GuiRectangle_Present.right / 12, GuiRectangle_Present.bottom / 2) + GuiRectangle_Present.bottom / 2), 0.0f, 1.0f, D3DCOLOR_XRGB(200, 160, 96)},// y-
			{(float)(GuiRectangle_Present.right / 2), (float)(min(GuiRectangle_Present.right / 12, GuiRectangle_Present.bottom / 2) + GuiRectangle_Present.bottom / 2), 0.0f, 1.0f, D3DCOLOR_XRGB(200, 160, 96)},// y+
		};
		VOID* VerticesPointer_temp = NULL;
		if (FAILED(d3dVertexPointer->Lock(0, sizeof(vertices_temp), (void**)&VerticesPointer_temp, 0))) {
			return;
		}
		memcpy(VerticesPointer_temp, vertices_temp, sizeof(vertices_temp));
		d3dVertexPointer->Unlock();

		// Index
		WORD Indices_temp[] = { 0,2,1, 0,1,3 };

		WORD* IndicesPointer_temp = NULL;
		if (FAILED(d3dIndexPointer->Lock(0, sizeof(vertices_temp), (void**)&IndicesPointer_temp, 0))) {
			MessageBox(NULL, L"��Ⱦʧ�ܣ������ʼ��ʧ��", L"EmsiaetKadosh's Desktop Tool Caution", MB_OK);
			return;
		}
		memcpy(IndicesPointer_temp, Indices_temp, sizeof(Indices_temp));
		d3dIndexPointer->Unlock();
		return;
	}
	void GuiPrinterStart() {
		

		// ��һ���������Ļ
		d3dDevicePointer->Clear(
			0, // DWORD ָ��������һ������ָ��ľ��������о��ε������������һ��ΪNULL������һ�����Ϊ0
			NULL, // const D3DRECT* ָ��һ��D3DRECT�ṹ�������ָ�룬����Ҫ��յ�Ŀ���������
			D3DCLEAR_TARGET, // DWORD ָ��������Ҫ��յĻ���������ΪD3DCLEAR_+STENCIL | TARGET | ZBUFFER ��������ϣ��ֱ��ʾģ�建��������ɫ����������ȳ���
			D3DCOLOR_XRGB(10, 20, 50), // D3DCOLOR ������պ����ɫ����ӦTARGET
			1.0f, // float ָ�������Ȼ�������ÿ�����ض�Ӧ���ֵ����ӦZBUFFER
			0 // DWORD ָ�����ģ�建����֮��ÿ��ģ�建����ÿ�����ض�Ӧģ��ֵ����ӦSTENCIL
		);
		// �ڶ�������ʼ����
		d3dDevicePointer->BeginScene();
		// ����������ʽ����

		d3dDevicePointer->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
		d3dDevicePointer->SetStreamSource(0, d3dVertexPointer, 0, sizeof(vertex2D));
		d3dDevicePointer->SetFVF(D3DFVF_VERTEX);
		d3dDevicePointer->SetIndices(d3dIndexPointer);
		//d3dDevicePointer->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
		d3dDevicePointer->DrawIndexedPrimitive(
			D3DPT_TRIANGLELIST, 
			0, // �������λ�ö�Ӧ����λ��
			0, // ������Сֵ����0
			4, // ������Ŀ
			0, // �ӵڼ���������ʼ����ͼԪ
			2  // ͼԪ����
		);

		// ��Ļ
		wchar_t EKString_temp[50];
		int charCount_temp = swprintf_s(EKString_temp, 20, _T("EmsiaetKadosh"));
		d3dFontPointer_DaWeiRuanYaHei->DrawText(
			0, // ��ǰ����
			EKString_temp, // ��ʾ���ַ���
			charCount_temp, // �ַ���
			&GuiRectangle_Present, // ��ʾ��Ŀ�����
			DT_CENTER | DT_VCENTER,
			D3DCOLOR_XRGB(255, 255, 255)
		);

		
		// ���Ĳ�����������
		d3dDevicePointer->EndScene();
		// ���岽����ת��ʾ
		d3dDevicePointer->Present(NULL, NULL, NULL, NULL);
		return;
	}
}

