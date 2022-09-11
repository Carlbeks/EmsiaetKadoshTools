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
		d3dDevicePointer->CreateVertexBuffer(4 * sizeof(vertex2D), 0, D3DFVF_VERTEX, D3DPOOL_DEFAULT, &d3dVertexPointer, NULL);//创建顶点缓冲区
		d3dDevicePointer->CreateIndexBuffer(6 * sizeof(WORD), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &d3dIndexPointer, NULL);//创建索引缓存
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
				0, // 当前窗口
				EKString_temp, // 显示的字符串
				charCount_temp, // 字符数
				&rect_temp, // 显示的目标矩形
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
	// 函数 d3dInit()
	// 掌管所有的屏幕绘制工作。主要由WM_PAINT驱动。
	//
	HRESULT Init(HWND hWnd) {
		LPDIRECT3D9 d3dcomPointer = NULL;// 创建接口对象
		if (NULL == (d3dcomPointer = Direct3DCreate9(D3D_SDK_VERSION))) { return E_FAIL; }// 初始化接口对象，进行版本协商
		D3DCAPS9 d3dcaps;
		int vp = 0;
		if (FAILED(d3dcomPointer->GetDeviceCaps(
		D3DADAPTER_DEFAULT, // 显卡序号，默认当前
		D3DDEVTYPE_HAL,  // 硬件设备类型，软件后缀是REF
		&d3dcaps))) {
			MessageBox(NULL, L"启动失败：获取设备信息失败", L"EmsiaetKadosh's Desktop Tool Caution", MB_OK); return E_FAIL; }
		if (d3dcaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) {
			vp = D3DCREATE_HARDWARE_VERTEXPROCESSING; // 硬件定点运算
		}
		else {
			vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING; // 软件顶点运算
		}
		D3DPRESENT_PARAMETERS d3dParams;
		ZeroMemory(&d3dParams, sizeof(d3dParams));
		GetClientRect(hWnd, &GuiRectangle_Present);
		d3dParams.BackBufferWidth				= GuiRectangle_Present.right;		// 后台缓冲区宽
		d3dParams.BackBufferHeight				= GuiRectangle_Present.bottom;		// 后台缓冲区高
		d3dParams.BackBufferFormat				= D3DFMT_A8R8G8B8;					// 缓冲区像素格式
		d3dParams.BackBufferCount				= 2;								// 后台缓冲区宽度？个数
		d3dParams.MultiSampleType				= D3DMULTISAMPLE_NONE;				// 多重采样类型
		d3dParams.MultiSampleQuality			= 0;								// 多重采样格式
		d3dParams.SwapEffect					= D3DSWAPEFFECT_DISCARD;			// 缓冲如何复制到前台
		d3dParams.hDeviceWindow					= hWnd;								// 窗口句柄
		d3dParams.Windowed						= true;								// 是否窗口
		d3dParams.EnableAutoDepthStencil		= true;								// 管理深度缓存
		d3dParams.AutoDepthStencilFormat		= D3DFMT_D24S8;						// 深度缓冲像素格式
		d3dParams.Flags							= 0;								// 附加属性
		d3dParams.FullScreen_RefreshRateInHz	= 0;								// 全屏刷新率，非全屏不要给
		d3dParams.PresentationInterval			= D3DPRESENT_INTERVAL_IMMEDIATE;	// 前后台最大交换频率
		if (FAILED(d3dcomPointer->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, vp, &d3dParams, &d3dDevicePointer))) {
			MessageBox(NULL, L"启动失败：创建设备接口失败", L"EmsiaetKadosh's Desktop Tool Caution", MB_OK);
			return E_FAIL;
		}
		SAFE_RELEASE(d3dcomPointer);// 安全释放
		if (!(S_OK == ObjectsInit(hWnd))) {
			MessageBox(NULL, L"启动失败：对象初始化失败", L"EmsiaetKadosh's Desktop Tool Caution", MB_OK);
			return E_FAIL;
		}
		return S_OK;
	}

	//
	// 函数 ObjectsInit()
	// 初始化所有渲染对象
	//
	HRESULT ObjectsInit(HWND hWnd) {
		if (FAILED(
			D3DXCreateFont(
				d3dDevicePointer, // D3D设备指针
				min(GuiRectangle_Present.right / 24, GuiRectangle_Present.bottom / 4), // INT 字体高 需要更改为变量
				0, // UINT 字体宽
				0, // UINT 字体权重
				1, // UINT 字体过滤属性
				false, // BOOL 是否斜体
				DEFAULT_CHARSET, // DWORD 字符集，默认
				OUT_DEFAULT_PRECIS, // DWORD 文本精度，默认
				DEFAULT_QUALITY, // DWORD 文本质量，默认
				0, // DWORD 字体索引号，常0
				_T("微软雅黑"), // LPCTSTR 字体名称
				&d3dFontPointer_XiaoWeiRuanYaHei // LPD3DXFONT 存储字体的指针
			)) or FAILED(
			D3DXCreateFont(
				d3dDevicePointer, // D3D设备指针
				min(GuiRectangle_Present.right / 12, GuiRectangle_Present.bottom / 2), // INT 字体高 需要更改为变量
				0, // UINT 字体宽
				0, // UINT 字体权重
				1, // UINT 字体过滤属性
				false, // BOOL 是否斜体
				DEFAULT_CHARSET, // DWORD 字符集，默认
				OUT_DEFAULT_PRECIS, // DWORD 文本精度，默认
				DEFAULT_QUALITY, // DWORD 文本质量，默认
				0, // DWORD 字体索引号，常0
				_T("微软雅黑"), // LPCTSTR 字体名称
				&d3dFontPointer_DaWeiRuanYaHei // LPD3DXFONT 存储字体的指针
		))) {
			return E_FAIL;
		}
		return S_OK;
	}

	//
	// 函数 GuiPrinter()
	// 掌管所有的屏幕绘制工作。主要由WM_PAINT驱动。
	//
	void GuiPrinter() {
		if (!d3dDevicePointer) {
			return;
		}
		// 第一步：清空屏幕
		d3dDevicePointer->Clear(
			0, // DWORD 指定接下来一个参数指向的矩形数组中矩形的数量。如果下一项为NULL，则这一项必须为0
			NULL, // const D3DRECT* 指向一个D3DRECT结构体的数组指针，表明要清空的目标矩形区域
			D3DCLEAR_TARGET, // DWORD 指定我们需要清空的缓冲区。它为D3DCLEAR_+STENCIL | TARGET | ZBUFFER 的自由组合，分别表示模板缓冲区、颜色缓冲区、深度缓冲区
			D3DCOLOR_XRGB(10, 20, 50), // D3DCOLOR 设置清空后的颜色，对应TARGET
			1.0f, // float 指定清空深度缓冲区后每个像素对应深度值，对应ZBUFFER
			0 // DWORD 指定清空模板缓冲区之后每个模板缓冲区每个像素对应模板值，对应STENCIL
		);
		// 第二步：开始绘制
		d3dDevicePointer->BeginScene();
		// 第三步：正式绘制
		Pages(); // 按钮框架
		d3dDevicePointer->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
		d3dDevicePointer->SetStreamSource(0, d3dVertexPointer, 0, sizeof(vertex2D));
		d3dDevicePointer->SetFVF(D3DFVF_VERTEX);
		d3dDevicePointer->SetIndices(d3dIndexPointer);
		//d3dDevicePointer->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
		d3dDevicePointer->DrawIndexedPrimitive(
			D3DPT_TRIANGLELIST,
			0, // 索引起点位置对应顶点位置
			0, // 索引最小值，常0
			96,//4 * guipages::buttons.buttonsCount, // 顶点数目
			0, // 从第几个索引开始绘制图元
			32//2 * guipages::buttons.buttonsCount  // 图元个数
		);
		PagesText();

		int charCount_temp = swprintf_s(fpsString, 20, _T("FPS:%0.2f"), GetFPS());
		d3dFontPointer_XiaoWeiRuanYaHei->DrawText(
			0, // 当前窗口
			fpsString, // 显示的字符串
			charCount_temp, // 字符数
			&GuiRectangle_Present, // 显示的目标矩形
			DT_TOP | DT_RIGHT,
			fps > 50 ? D3DCOLOR_XRGB(39, 255, 136) : (fps > 35 ? D3DCOLOR_XRGB(255, 64, 255) : D3DCOLOR_XRGB(255, 39, 136))
		);
		// 第四步：结束绘制
		d3dDevicePointer->EndScene();
		// 第五步：翻转显示
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
		//定义静态变量
		static int    frameCount = 0;//帧数
		static float  currentTime = 0.0f;//当前时间
		static float  lastTime = 0.0f;//持续时间

		frameCount++;//每调用一次Get_FPS()函数，帧数自增1
		currentTime = timeGetTime() * 0.001f;//获取系统时间，其中timeGetTime函数返回的是以毫秒为单位的系统时间，所以需要乘以0.001，得到单位为秒的时间

		//如果当前时间减去持续时间大于了1秒钟，就进行一次FPS的计算和持续时间的更新，并将帧数值清零
		if (currentTime - lastTime > 1.0f) //将时间控制在1秒钟
		{
			fps = (float)frameCount / (currentTime - lastTime);//计算这1秒钟的FPS值
			lastTime = currentTime; //将当前时间currentTime赋给持续时间lastTime，作为下一秒的基准时间
			frameCount = 0;//将本次帧数frameCount值清零
		}

		return fps;
		//摘抄自筑梦旅程
	}
	//
	// 函数 GuiPrinterStart()
	// 掌管所有的屏幕绘制工作。主要由WM_PAINT驱动。
	//
	void GuiPrinterStartInit() {
		SAFE_RELEASE(d3dVertexPointer);
		SAFE_RELEASE(d3dIndexPointer);
		// 顶点绘制区

		d3dDevicePointer->CreateVertexBuffer(4 * sizeof(vertex2D), 0, D3DFVF_VERTEX, D3DPOOL_DEFAULT, &d3dVertexPointer, NULL);//创建顶点缓冲区
		d3dDevicePointer->CreateIndexBuffer(6 * sizeof(WORD), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &d3dIndexPointer, NULL);//创建索引缓存

		vertex2D vertices_temp[] = {
			// 顺时针
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
			MessageBox(NULL, L"渲染失败：顶点初始化失败", L"EmsiaetKadosh's Desktop Tool Caution", MB_OK);
			return;
		}
		memcpy(IndicesPointer_temp, Indices_temp, sizeof(Indices_temp));
		d3dIndexPointer->Unlock();
		return;
	}
	void GuiPrinterStart() {
		

		// 第一步：清空屏幕
		d3dDevicePointer->Clear(
			0, // DWORD 指定接下来一个参数指向的矩形数组中矩形的数量。如果下一项为NULL，则这一项必须为0
			NULL, // const D3DRECT* 指向一个D3DRECT结构体的数组指针，表明要清空的目标矩形区域
			D3DCLEAR_TARGET, // DWORD 指定我们需要清空的缓冲区。它为D3DCLEAR_+STENCIL | TARGET | ZBUFFER 的自由组合，分别表示模板缓冲区、颜色缓冲区、深度冲区
			D3DCOLOR_XRGB(10, 20, 50), // D3DCOLOR 设置清空后的颜色，对应TARGET
			1.0f, // float 指定清空深度缓冲区后每个像素对应深度值，对应ZBUFFER
			0 // DWORD 指定清空模板缓冲区之后每个模板缓冲区每个像素对应模板值，对应STENCIL
		);
		// 第二步：开始绘制
		d3dDevicePointer->BeginScene();
		// 第三步：正式绘制

		d3dDevicePointer->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
		d3dDevicePointer->SetStreamSource(0, d3dVertexPointer, 0, sizeof(vertex2D));
		d3dDevicePointer->SetFVF(D3DFVF_VERTEX);
		d3dDevicePointer->SetIndices(d3dIndexPointer);
		//d3dDevicePointer->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
		d3dDevicePointer->DrawIndexedPrimitive(
			D3DPT_TRIANGLELIST, 
			0, // 索引起点位置对应顶点位置
			0, // 索引最小值，常0
			4, // 顶点数目
			0, // 从第几个索引开始绘制图元
			2  // 图元个数
		);

		// 字幕
		wchar_t EKString_temp[50];
		int charCount_temp = swprintf_s(EKString_temp, 20, _T("EmsiaetKadosh"));
		d3dFontPointer_DaWeiRuanYaHei->DrawText(
			0, // 当前窗口
			EKString_temp, // 显示的字符串
			charCount_temp, // 字符数
			&GuiRectangle_Present, // 显示的目标矩形
			DT_CENTER | DT_VCENTER,
			D3DCOLOR_XRGB(255, 255, 255)
		);

		
		// 第四步：结束绘制
		d3dDevicePointer->EndScene();
		// 第五步：翻转显示
		d3dDevicePointer->Present(NULL, NULL, NULL, NULL);
		return;
	}
}

