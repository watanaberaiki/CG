#include "Input.h"
#include<cassert>
#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>
#include <wrl.h>
using namespace Microsoft::WRL;

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
void Input::Initialize(HINSTANCE hInstance,HWND  hwnd) 
{
	HRESULT result;

	// DirectInput�̏�����
	IDirectInput8* directInput = nullptr;
	result = DirectInput8Create(
		hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&directInput, nullptr);
	assert(SUCCEEDED(result));

	// �L�[�{�[�h�f�o�C�X�̐���
	IDirectInputDevice8* keyboard = nullptr;
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	// ���̓f�[�^�`���̃Z�b�g
	result = keyboard->SetDataFormat(&c_dfDIKeyboard); // �W���`��
	assert(SUCCEEDED(result));

	// �r�����䃌�x���̃Z�b�g
	result = keyboard->SetCooperativeLevel(
		hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}

void Input::Update() 
{

}

