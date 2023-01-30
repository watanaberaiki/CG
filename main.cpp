//#include <d3dcompiler.h>

//#include <d3d12.h>
//#include <dxgi1_6.h>
//#include <cassert>
//#include <vector>
//#include <string>
//#include <DirectXMath.h>
//#include<math.h>
//#include <wrl.h>

#include "Input.h"
#include"WinApp.h"
#include"DirectXCommon.h"
#include "SpriteCommon.h"
#include "Sprite.h"
#include"Object3d.h"
#include <DirectXMath.h>
#include<math.h>
#include <d3dcompiler.h>
#include <DirectXTex.h>

#pragma comment (lib,"d3dcompiler.lib")

using namespace Microsoft::WRL;
using namespace DirectX;

//using namespace Microsoft::WRL;
//using namespace DirectX;
//#pragma comment (lib,"d3dcompiler.lib")
//#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
//#include <dinput.h>
//
//#pragma comment(lib, "dinput8.lib")
//#pragma comment(lib, "dxguid.lib")
//
//#pragma comment(lib,"d3d12.lib")
//#pragma comment(lib,"dxgi.lib")
//
//const float PI = 3.141592f;
//
////�萔�o�b�t�@�p�f�[�^�\����(�}�e���A��)
//struct ConstBufferDataMaterial {
//	XMFLOAT4 color;		//�F(RGBA)
//};
//
////�萔�o�b�t�@�p�f�[�^�\����(3D�ϊ��s��)
//struct ConstBufferDataTransform {
//	XMMATRIX mat;		//3D�ϊ��s��
//};
//
////3D�I�u�W�F�N�g�^
//struct Object3d
//{
//	//�萔�o�b�t�@(�s��p)
//	ComPtr<ID3D12Resource> constBuffTransform;
//	//�萔�o�b�t�@�}�b�v(�s��p)
//	ConstBufferDataTransform* constMapTransform = 0;
//	//�A�t�B���ϊ����
//	XMFLOAT3 scale = { 1,1,1 };
//	XMFLOAT3 rotation = { 0,0,0 };
//	XMFLOAT3 position = { 0,0,0 };
//	//���[���h�ϊ��s��
//	XMMATRIX matWorld = {};
//	//�e�I�u�W�F�N�g�ւ̃|�C���^
//	Object3d* parent = nullptr;
//};
//
//
////3D�I�u�W�F�N�g�̏�����
//void InitializeObject3d(Object3d* object, ID3D12Device* device) {
//	HRESULT result;
//
//	//�萔�o�b�t�@�̃q�[�v�ݒ�
//	D3D12_HEAP_PROPERTIES heapProp{};
//	heapProp.Type = D3D12_HEAP_TYPE_UPLOAD;
//	// �萔�o�b�t�@�̃��\�[�X�ݒ�
//	D3D12_RESOURCE_DESC resdesc{};
//	resdesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
//	resdesc.Width = (sizeof(ConstBufferDataTransform) + 0xff) & ~0xff;
//	resdesc.Height = 1;
//	resdesc.DepthOrArraySize = 1;
//	resdesc.MipLevels = 1;
//	resdesc.SampleDesc.Count = 1;
//	resdesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
//
//	// �萔�o�b�t�@�̐���
//	result = device->CreateCommittedResource(
//		&heapProp, // �q�[�v�ݒ�
//		D3D12_HEAP_FLAG_NONE,
//		&resdesc, // ���\�[�X�ݒ�
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&object->constBuffTransform));
//	assert(SUCCEEDED(result));
//
//	// �萔�o�b�t�@�̃}�b�s���O
//	result = object->constBuffTransform->Map(0, nullptr, (void**)&object->constMapTransform); // �}�b�s���O
//	assert(SUCCEEDED(result));
//
//}
//
//void UpdateObject3d(Object3d* object, XMMATRIX& matView, XMMATRIX& matProjection) {
//
//	XMMATRIX matScale, matRot, matTrans;
//
//	//�X�P�[���A��]�A���s�ړ��s��̌v�Z
//	matScale = XMMatrixScaling(object->scale.x, object->scale.y, object->scale.z);
//
//	matRot = XMMatrixIdentity();
//	matRot *= XMMatrixRotationZ(object->rotation.z);
//	matRot *= XMMatrixRotationX(object->rotation.x);
//	matRot *= XMMatrixRotationY(object->rotation.y);
//
//	matTrans = XMMatrixTranslation(object->position.x, object->position.y, object->position.z);
//
//	//���[���h�s��̍���
//	object->matWorld = XMMatrixIdentity();
//	object->matWorld *= matScale;
//	object->matWorld *= matRot;
//	object->matWorld *= matTrans;
//
//	//�e�I�u�W�F�N�g�������
//	if (object->parent != nullptr)
//	{
//		//�e�I�u�W�F�N�g�̃��[���h�s���������
//		object->matWorld *= object->parent->matWorld;
//	}
//
//	//�萔�o�b�t�@�փf�[�^�]��
//	object->constMapTransform->mat = object->matWorld * matView * matProjection;
//
//}
//
//void DrawObject3d(Object3d* object, ID3D12GraphicsCommandList* commandList, D3D12_VERTEX_BUFFER_VIEW& vbView,
//	D3D12_INDEX_BUFFER_VIEW& ibView, UINT numIndices)
//{
//	//���_�o�b�t�@�̐ݒ�
//	commandList->IASetVertexBuffers(0, 1, &vbView);
//	//�C���f�b�N�X�o�b�t�@�̐ݒ�
//	commandList->IASetIndexBuffer(&ibView);
//	//�萔�o�b�t�@�r���[
//	commandList->SetGraphicsRootConstantBufferView(2, object->constBuffTransform->GetGPUVirtualAddress());
//
//	//�`��R�}���h
//	commandList->DrawIndexedInstanced(numIndices, 1, 0, 0, 0);
//}

////�E�B���h�E�v���[�W��
//LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
//	//���b�Z�[�W�ɉ����ăQ�[���ŗL�̏������s��
//	switch (msg) {
//		//�E�B���h�E���j�����ꂽ
//	case WM_DESTROY:
//		//OS���΂��āA�A�v���̏I����`����
//		PostQuitMessage(0);
//		return 0;
//	}
//	//�W���̃��b�Z�[�W�������s��
//	return DefWindowProc(hwnd, msg, wparam, lparam);
//}

enum Scene {
	title,
	game,
	clear,
	gameover
};

bool CheakCollision(XMFLOAT3 posA, XMFLOAT3 posB, XMFLOAT3 sclA, XMFLOAT3 sclB, XMFLOAT3 minModelA, XMFLOAT3 minModelB, XMFLOAT3 maxModelA, XMFLOAT3 maxModelB) {

	XMFLOAT3 minposA = { sclA.x * minModelA.x,sclA.y * minModelA.y,sclA.z * minModelA.z };
	XMFLOAT3 minposB = { sclB.x * minModelB.x,sclB.y * minModelB.y,sclB.z * minModelB.z };
	XMFLOAT3 maxposA = { sclA.x * maxModelA.x,sclA.y * maxModelA.y,sclA.z * maxModelA.z };
	XMFLOAT3 maxposB = { sclB.x * maxModelB.x,sclB.y * maxModelB.y,sclB.z * maxModelB.z };

	minposA = { fabsf(minposA.x),fabsf(minposA.y),fabsf(minposA.z) };
	minposB = { fabsf(minposB.x),fabsf(minposB.y),fabsf(minposB.z) };
	maxposA = { fabsf(maxposA.x),fabsf(maxposA.y),fabsf(maxposA.z) };
	maxposB = { fabsf(maxposB.x),fabsf(maxposB.y),fabsf(maxposB.z) };

	/*sclA = { sclA.x * a,sclA.y * a ,sclA.z * a };
	sclB = { sclB.x * a,sclB.y * a ,sclB.z * a };*/

	if (posA.x - minposA.x < posB.x + maxposB.x && posA.x + maxposA.x > posB.x - minposB.x &&
		posA.y - minposA.y < posB.y + maxposB.y && posA.y + maxposA.y > posB.y - minposB.y &&
		posA.z - minposA.z < posB.z + maxposB.z && posA.z + maxposA.z > posB.z - minposB.z)
	{
		return true;
	}

	return false;
}

//Windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	//�@��ՃV�X�e���̏�����
		//�|�C���^
	Input* input = nullptr;
	WinApp* winApp = nullptr;
	DirectXCommon* dxCommon = nullptr;
	/*SpriteCommon* spriteCommon = nullptr;*/


	//WindowsAPI�̏�����
	winApp = new WinApp();
	winApp->Initialize();

	//DirectX�̏�����
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(winApp);


	//���͂̏�����
	input = new Input();
	input->Initialize(winApp);

	//3D�I�u�W�F�N�g�ÓI������
	Object3d::StaticInitialize(dxCommon->GetDevice(), winApp->window_width, winApp->window_height);


	SpriteCommon* spriteCommon = nullptr;
	//�X�v���C�g���ʕ����̏�����
	spriteCommon = new SpriteCommon;
	spriteCommon->Initialize(dxCommon);

//��ՃV�X�e���̏�����

//�ŏ��̃V�[���̏�����
	//�e�L�X�g
	Sprite* sprite = new Sprite();
	sprite->Initialize(spriteCommon);
	XMFLOAT2 position = sprite->GetPosition();
	position.x = 400.0f;
	position.y = 0.0f;
	sprite->SetPozition(position);
	XMFLOAT4 color = { 1,1,1,1 };
	sprite->SetColor(color);
	sprite->SetSize(XMFLOAT2{ 500.0f,281.0f });


	Sprite* sprite1 = new Sprite();
	sprite1->Initialize(spriteCommon);
	XMFLOAT2 position1 = sprite1->GetPosition();
	position1.x = 30.0f;
	position1.y = 30.0f;
	sprite1->SetPozition(position1);
	XMFLOAT4 color1 = { 1,1,1,1 };
	sprite1->SetColor(color1);
	sprite1->SetSize(XMFLOAT2{ 200.0f,112.0f });

	spriteCommon->LoadTexture(0, "Resources/mario.png");
	sprite->SetTextureIndex(0);

	spriteCommon->LoadTexture(1, "Resources/reimu.png");
	sprite1->SetTextureIndex(1);


	/*OBJ���烂�f���f�[�^��ǂݍ���*/
	//�~��
	XMFLOAT3 minModel = {}, maxModel = {};
	Model* model = Model::LoadFromObj("cylinder", minModel, maxModel);
	minModel = model->GetminModel();
	maxModel = model->GetmaxModel();
	//�v���C���[
	XMFLOAT3 minModel2 = {}, maxModel2 = {};
	Model* model2 = Model::LoadFromObj("cube", minModel2, maxModel2);
	minModel2 = model2->GetminModel();
	maxModel2 = model2->GetmaxModel();

	//�V��(�~��)
	Object3d* skyCylinder = Object3d::Create();
	skyCylinder->SetModel(model);
	skyCylinder->SetScale({ 50,50,500 });
	skyCylinder->SetRotation({ 90,0,0 });

	//�v���C���[
	Object3d* Player = Object3d::Create();
	//�I�u�W�F�N�g�Ƀ��f����R�Â���
	Player->SetModel(model2);
	//�v���C���[���W�ۑ��p
	DirectX::XMFLOAT3 playerPosition;
	//���񂾔���
	bool isDead = false;
	Player->SetScale({ 1.0f,1.0f,1.0f });
	float upSpeed = 0.0f;
	bool isStart = false;
	bool isGoal = false;


	//�r���[�ϊ��s��
	XMMATRIX matView;
	XMFLOAT3 eye(0, 5, -30);	//���_���W
	XMFLOAT3 target(0, 0, 0);	//�����_���W
	XMFLOAT3 up(0, 1, 0);		//������x�N�g��
	matView = DirectX::XMMatrixLookAtLH(XMLoadFloat3(&eye), XMLoadFloat3(&target), XMLoadFloat3(&up));
	float angle = 0.0f;//�J�����̉�]�p

	//�V�[��
	Scene scene = Scene::title;

	//�ŏ��̃V�[���̏�����

#ifdef _DEBUG

#endif
	//�Q�[�����[�v
	while (true) {
		//�@��ՃV�X�e���̍X�V


		//���b�Z�[�W������H
		if (winApp->ProcessMesseage()) {
			//�Q�[�����[�v�𔲂���
			break;
		}

		//DirectX���t���[������ ��������

		//���͂̍X�V
		input->Update();
		skyCylinder->Update(matView);
		Player->Update(matView);


		//// 4.�`��R�}���h��������

		dxCommon->PreDraw();
		Object3d::PreDraw(dxCommon->GetCommandlist());
		//�ŏ��̃V�[���̕`��

		skyCylinder->Draw();
		Player->Draw();

		Object3d::PostDraw();

		sprite->Draw();
		sprite1->Draw();

	//�ŏ��̃V�[���̕`��

		dxCommon->PostDraw();


		// 4.�`��R�}���h�����܂�


		////DirectX���t���[������ �����܂�
	}

	//�@��ՃV�X�e���̏I��


	//���͊J��
	delete input;
	//WindowsAPI�̏I������
	winApp->Finalize();
	//WindowsAPI�̉��
	delete winApp;
	//DirectX���
	delete dxCommon;
	////3d�I�u�W�F�N�g���
	//delete Player;
	//////�V�����
	////delete skyCylinder;
	//////3D���f�����
	////delete model;

	//delete model2;
	//delete model3;
	//delete model4;
	////�ǉ��
	//for (int i = 0; i < wallnum; i++) {
	//	delete wall[i];
	//}
	////���ړ��ǉ��
	//for (int i = 0; i < besideWallnum; i++) {
	//	delete besideWall[i];
	//}
	////�c�ړ����
	//for (int i = 0; i < verticalWallnum; i++) {
	//	delete verticalWall[i];
	//}
	////���J��
	//delete floor;

	//delete spriteCommon;

	//��ՃV�X�e���̏I��

	return 0;
}

