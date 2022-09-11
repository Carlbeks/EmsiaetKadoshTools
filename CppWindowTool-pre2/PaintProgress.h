#pragma once

#include "PreGlobal.h"

HRESULT MainObjectsInit(HWND hWnd, n req, n height1, LPCTSTR name1, n height2, LPCTSTR name2) {
	if (
		FAILED(
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
				&d3dFontPointerArray[0] // LPD3DXFONT 存储字体的指针
			)
		) or FAILED(
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
				&d3dFontPointerArray[1] // LPD3DXFONT 存储字体的指针
			)
		) or (req?
			FAILED(
				D3DXCreateFont(
					d3dDevicePointer, // D3D设备指针
					height1, // INT 字体高 需要更改为变量
					0, // UINT 字体宽
					0, // UINT 字体权重
					1, // UINT 字体过滤属性
					false, // BOOL 是否斜体
					DEFAULT_CHARSET, // DWORD 字符集，默认
					OUT_DEFAULT_PRECIS, // DWORD 文本精度，默认
					DEFAULT_QUALITY, // DWORD 文本质量，默认
					0, // DWORD 字体索引号，常0
					name1, // LPCTSTR 字体名称
					&d3dFontPointerArray[3] // LPD3DXFONT 存储字体的指针
				)
			) or FAILED(
				D3DXCreateFont(
					d3dDevicePointer, // D3D设备指针
					height2, // INT 字体高 需要更改为变量
					0, // UINT 字体宽
					0, // UINT 字体权重
					1, // UINT 字体过滤属性
					false, // BOOL 是否斜体
					DEFAULT_CHARSET, // DWORD 字符集，默认
					OUT_DEFAULT_PRECIS, // DWORD 文本精度，默认
					DEFAULT_QUALITY, // DWORD 文本质量，默认
					0, // DWORD 字体索引号，常0
					name2, // LPCTSTR 字体名称
					&d3dFontPointerArray[4] // LPD3DXFONT 存储字体的指针
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
	LPDIRECT3D9 d3dcomPointer = NULL;// 创建接口对象
	if (NULL == (d3dcomPointer = Direct3DCreate9(D3D_SDK_VERSION))) { return E_FAIL; }// 初始化接口对象，进行版本协商
	D3DCAPS9 d3dcaps;
	int vp = 0;
	if (FAILED(d3dcomPointer->GetDeviceCaps(
		D3DADAPTER_DEFAULT, // 显卡序号，默认当前
		D3DDEVTYPE_HAL,  // 硬件设备类型，软件后缀是REF
		&d3dcaps))) {
		MessageBox(NULL, L"次级获取设备信息失败", L"EKDT错误", MB_OK); return E_FAIL;
	}
	if (d3dcaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) {
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING; // 硬件定点运算
	}
	else {
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING; // 软件顶点运算
	}
	D3DPRESENT_PARAMETERS d3dParams;
	ZeroMemory(&d3dParams, sizeof(d3dParams));
	d3dParams.BackBufferWidth = GuiRectangle_Present.right;						// 后台缓冲区宽
	d3dParams.BackBufferHeight = GuiRectangle_Present.bottom;					// 后台缓冲区高
	d3dParams.BackBufferFormat = D3DFMT_A8R8G8B8;			// 缓冲区像素格式
	d3dParams.BackBufferCount = 2;							// 后台缓冲区宽度？个数
	d3dParams.MultiSampleType = D3DMULTISAMPLE_NONE;		// 多重采样类型
	d3dParams.MultiSampleQuality = 0;						// 多重采样格式
	d3dParams.SwapEffect = D3DSWAPEFFECT_DISCARD;			// 缓冲如何复制到前台
	d3dParams.hDeviceWindow = hWnd;							// 窗口句柄
	d3dParams.Windowed = true;								// 是否窗口
	d3dParams.EnableAutoDepthStencil = true;				// 管理深度缓存
	d3dParams.AutoDepthStencilFormat = D3DFMT_D24S8;		// 深度缓冲像素格式
	d3dParams.Flags = 0;									// 附加属性
	d3dParams.FullScreen_RefreshRateInHz = 0;				// 全屏刷新率，非全屏不要给
	d3dParams.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;	// 前后台最大交换频率
	if (FAILED(d3dcomPointer->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, vp, &d3dParams, &d3dDevicePointer))) {
		MessageBox(NULL, L"次级创建设备接口失败", L"EKDT错误", MB_OK);
		return E_FAIL;
	}
	return S_OK;
}
n PrintStart(){
	if (!d3dDevicePointer) {
		return 1;
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
	d3dDevicePointer->CreateVertexBuffer(4 * sizeof(vertex2D), 0, D3DFVF_VERTEX, D3DPOOL_DEFAULT, &d3dVertexPointer, NULL);//创建顶点缓冲区
	d3dDevicePointer->CreateIndexBuffer(6 * sizeof(WORD), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &d3dIndexPointer, NULL);//创建索引缓存
	return 0;
	// 第三步：正式绘制
}
n PrintShape(n vertexCount, n triangleCount) {
	d3dDevicePointer->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	d3dDevicePointer->SetStreamSource(0, d3dVertexPointer, 0, sizeof(vertex2D));
	d3dDevicePointer->SetFVF(D3DFVF_VERTEX);
	d3dDevicePointer->SetIndices(d3dIndexPointer);
	//d3dDevicePointer->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
	d3dDevicePointer->DrawIndexedPrimitive(
		D3DPT_TRIANGLELIST,
		0, // 索引起点位置对应顶点位置
		0, // 索引最小值，常0
		vertexCount,//4 * guipages::buttons.buttonsCount, // 顶点数目
		0, // 从第几个索引开始绘制图元
		triangleCount//2 * guipages::buttons.buttonsCount  // 图元个数
	);
	er0
}
n PrintEnd() {
	int charCount_temp = swprintf_s(&fpsString, 20, _T("%0.2f FPS"), GetFPSEk());
	d3dFontPointerArray[0]->DrawText(
		0, // 当前窗口
		&fpsString, // 显示的字符串
		charCount_temp, // 字符数
		&GuiRectangle_Present, // 显示的目标矩形
		DT_TOP | DT_RIGHT,
		fps > 60 ? D3DCOLOR_XRGB(39, 255, 136) : (fps > 40 ? D3DCOLOR_XRGB(255, 255, 64) : D3DCOLOR_XRGB(255, 39, 136))
	);
	// 第四步：结束绘制
	d3dDevicePointer->EndScene();
	// 第五步：翻转显示
	d3dDevicePointer->Present(NULL, NULL, NULL, NULL);
	er0
}

f GetFPS() {
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