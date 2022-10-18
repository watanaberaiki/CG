#pragma once
#include <Windows.h>
#include<cassert>
#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>
#include <wrl.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

//����
class Input
{
public:
	//namespace�ȗ�
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;

public://�����o�֐�

	//������
	void Initialize(HINSTANCE hInstance, HWND  hwnd);
	//�X�V
	void Update();

private://�����o�ϐ�

	ComPtr<IDirectInputDevice8> keyboard=nullptr;

};

