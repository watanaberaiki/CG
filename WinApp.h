#pragma once
#include<Windows.h>

class WinApp
{
public://�ÓI�����o�֐�
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public://�����o�֐�
	//������
	void Initialize();
	//�X�V
	void Update();
};
