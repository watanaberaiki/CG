#pragma once
#include <Windows.h>
#include<cassert>
#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>
#include <wrl.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

//入力
class Input
{
public:
	//namespace省略
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public://メンバ関数

	//初期化
	void Initialize(HINSTANCE hInstance, HWND  hwnd);
	//更新
	void Update();

private://メンバ変数

	ComPtr<IDirectInputDevice8> keyboard=nullptr;

};

