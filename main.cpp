//#include <d3dcompiler.h>
//#include <DirectXTex.h>
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
#include"Sprite.h"
#include"SpriteCommon.h"
#include"Object3d.h"


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


	////�X�v���C�g���ʕ��̏�����
	//spriteCommon = new SpriteCommon();
	//spriteCommon->Initialize(dxCommon);

//��ՃV�X�e���̏�����
	
//�@�ŏ��̃V�[���̏�����
	Object3d* object3d = Object3d::Create();

//�ŏ��̃V�[���̏�����

#ifdef _DEBUG
	
#endif

//	//�`�揉�������� ��������
//	//�X�P�[�����O�{��
//	XMFLOAT3 scale;
//	//��]�p
//	XMFLOAT3 rotation;
//	//���W
//	XMFLOAT3 position;
//
//	//�X�P�[�����O�{��
//	scale = { 1.0f,1.0f,1.0f };
//	//��]�p
//	rotation = { 0.0f,0.0f,0.0f };
//	//���W
//	position = { 0.0f,0.0f,0.0f };
//
//	float angle = 0.0f;//�J�����̉�]�p
//
//	// ���_�f�[�^�\����
//	struct Vertex
//	{
//		XMFLOAT3 pos;	// xyz���W
//		XMFLOAT3 normal;//�@���x�N�g��
//		XMFLOAT2 uv;	// uv���W
//	};
//	// ���_�f�[�^
//	Vertex vertices[] = {
//		// x      y     z       u     v
//		//�O
//		{{-5.0f, -5.0f, -5.0f},{}, {0.0f, 1.0f}}, // ����
//		{{-5.0f, 5.0f, -5.0f}, {}, {0.0f, 0.0f}}, // ����
//		{{5.0f, -5.0f, -5.0f},{}, {1.0f, 1.0f}}, // �E��
//		{{5.0f, 5.0f, -5.0f}, {},{1.0f, 0.0f}}, // �E��
//		//��(�O�ʂ�Z���W�̕������t)
//		{{-5.0f, -5.0f, 5.0f},{}, {0.0f, 1.0f}}, // ����
//		{{-5.0f, 5.0f, 5.0f},{}, {0.0f, 0.0f}}, // ����
//		{{5.0f, -5.0f, 5.0f},{}, {1.0f, 1.0f}}, // �E��
//		{{5.0f, 5.0f, 5.0f},{}, {1.0f, 0.0f}}, // �E��
//		//��
//		{{-5.0f, -5.0f, -5.0f},{}, {0.0f, 1.0f}}, // ����
//		{{-5.0f, -5.0f, 5.0f},{}, {0.0f, 0.0f}}, // ����
//		{{-5.0f, 5.0f, -5.0f},{}, {1.0f, 1.0f}}, // �E��
//		{{-5.0f, 5.0f, 5.0f},{}, {1.0f, 0.0f}}, // �E��
//		//�E(���ʂ�X���W�̕������t)
//		{{5.0f, -5.0f, -5.0f}, {},{0.0f, 1.0f}}, // ����
//		{{5.0f, -5.0f, 5.0f},{}, {0.0f, 0.0f}}, // ����
//		{{5.0f, 5.0f, -5.0f},{}, {1.0f, 1.0f}}, // �E��
//		{{5.0f, 5.0f, 5.0f},{}, {1.0f, 0.0f}}, // �E��
//		//��
//		{{-5.0f, -5.0f, -5.0f},{}, {0.0f, 1.0f}}, // ����
//		{{-5.0f, -5.0f, 5.0f},{}, {0.0f, 0.0f}}, // ����
//		{{5.0f, -5.0f, -5.0f} ,{}, {1.0f, 1.0f}}, // �E��
//		{{5.0f, -5.0f, 5.0f}, {},{1.0f, 0.0f}}, // �E��
//		//��(���ʂ�Y���W�̕������t)
//		//��
//		{{-5.0f, 5.0f, -5.0f},{}, {0.0f, 1.0f}}, // ����
//		{{-5.0f, 5.0f, 5.0f}, {},{0.0f, 0.0f}}, // ����
//		{{5.0f, 5.0f, -5.0f},{}, {1.0f, 1.0f}}, // �E��
//		{{5.0f, 5.0f, 5.0f},{}, {1.0f, 0.0f}}, // �E��
//
//	};
//
//
//
//	// �C���f�b�N�X�f�[�^
//	unsigned short indices[] = {
//		//�O
//		0, 1, 2, // �O�p�`1��
//		2, 1, 3, // �O�p�`2��
//		//��
//		5,4,7,	//�O�p�`3��
//		7,4,6,	//�O�p�`4��
//		//��
//		8,9,10,
//		10,9,11,
//		//�E
//		13,12,15,
//		15,12,14,
//		//��
//		17,16,19,
//		19,16,18,
//		//��
//		20,21,22,
//		22,21,23,
//
//	};
//
//	// ���_�f�[�^�S�̂̃T�C�Y = ���_�f�[�^����̃T�C�Y * ���_�f�[�^�̗v�f��
//	UINT sizeVB = static_cast<UINT>(sizeof(vertices[0]) * _countof(vertices));
//
//	// ���_�o�b�t�@�̐ݒ�
//	D3D12_HEAP_PROPERTIES heapProp{}; // �q�[�v�ݒ�
//	heapProp.Type = D3D12_HEAP_TYPE_UPLOAD; // GPU�ւ̓]���p
//	// ���\�[�X�ݒ�
//	D3D12_RESOURCE_DESC resDesc{};
//	resDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
//	resDesc.Width = sizeVB; // ���_�f�[�^�S�̂̃T�C�Y
//	resDesc.Height = 1;
//	resDesc.DepthOrArraySize = 1;
//	resDesc.MipLevels = 1;
//	resDesc.SampleDesc.Count = 1;
//	resDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
//
//	// ���_�o�b�t�@�̐���
//	ComPtr<ID3D12Resource> vertBuff = nullptr;
//	result = dxCommon->GetDevice()->CreateCommittedResource(
//		&heapProp, // �q�[�v�ݒ�
//		D3D12_HEAP_FLAG_NONE,
//		&resDesc, // ���\�[�X�ݒ�
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&vertBuff));
//	assert(SUCCEEDED(result));
//
//
//
//	// GPU��̃o�b�t�@�ɑΉ��������z������(���C����������)���擾
//	Vertex* vertMap = nullptr;
//	result = vertBuff->Map(0, nullptr, (void**)&vertMap);
//
//	// �q���������
//	vertBuff->Unmap(0, nullptr);
//
//	// ���_�o�b�t�@�r���[�̍쐬
//	D3D12_VERTEX_BUFFER_VIEW vbView{};
//	// GPU���z�A�h���X
//	vbView.BufferLocation = vertBuff->GetGPUVirtualAddress();
//	// ���_�o�b�t�@�̃T�C�Y
//	vbView.SizeInBytes = sizeVB;
//	// ���_�f�[�^1���̃T�C�Y
//	vbView.StrideInBytes = sizeof(vertices[0]);
//
//	ID3DBlob* vsBlob = nullptr; // ���_�V�F�[�_�I�u�W�F�N�g
//	ID3DBlob* psBlob = nullptr; // �s�N�Z���V�F�[�_�I�u�W�F�N�g
//	ID3DBlob* errorBlob = nullptr; // �G���[�I�u�W�F�N�g
//
//	// ���_�V�F�[�_�̓ǂݍ��݂ƃR���p�C��
//	result = D3DCompileFromFile(
//		L"Resources/shaders/BasicVS.hlsl",  // �V�F�[�_�t�@�C����
//		nullptr,
//		D3D_COMPILE_STANDARD_FILE_INCLUDE, // �C���N���[�h�\�ɂ���
//		"main", "vs_5_0", // �G���g���[�|�C���g���A�V�F�[�_�[���f���w��
//		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // �f�o�b�O�p�ݒ�
//		0,
//		&vsBlob, &errorBlob);
//
//	// �G���[�Ȃ�
//	if (FAILED(result)) {
//		// errorBlob����G���[���e��string�^�ɃR�s�[
//		std::string error;
//		error.resize(errorBlob->GetBufferSize());
//
//		std::copy_n((char*)errorBlob->GetBufferPointer(),
//			errorBlob->GetBufferSize(),
//			error.begin());
//		error += "\n";
//		// �G���[���e���o�̓E�B���h�E�ɕ\��
//		OutputDebugStringA(error.c_str());
//		assert(0);
//	}
//
//	// �s�N�Z���V�F�[�_�̓ǂݍ��݂ƃR���p�C��
//	result = D3DCompileFromFile(
//		L"Resources/shaders/BasicPS.hlsl",   // �V�F�[�_�t�@�C����
//		nullptr,
//		D3D_COMPILE_STANDARD_FILE_INCLUDE, // �C���N���[�h�\�ɂ���
//		"main", "ps_5_0", // �G���g���[�|�C���g���A�V�F�[�_�[���f���w��
//		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // �f�o�b�O�p�ݒ�
//		0,
//		&psBlob, &errorBlob);
//
//	// �G���[�Ȃ�
//	if (FAILED(result)) {
//		// errorBlob����G���[���e��string�^�ɃR�s�[
//		std::string error;
//		error.resize(errorBlob->GetBufferSize());
//
//		std::copy_n((char*)errorBlob->GetBufferPointer(),
//			errorBlob->GetBufferSize(),
//			error.begin());
//		error += "\n";
//		// �G���[���e���o�̓E�B���h�E�ɕ\��
//		OutputDebugStringA(error.c_str());
//		assert(0);
//	}
//
//	// ���_���C�A�E�g
//	D3D12_INPUT_ELEMENT_DESC inputLayout[] = {
//		{ // xyz���W(1�s�ŏ������ق������₷��)
//			"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
//		},
//
//		{//�@���x�N�g��(1�s�����������ق������₷��)
//			"NORMAL",0,DXGI_FORMAT_R32G32B32_FLOAT,0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0
//		},
//
//		{ // uv���W(1�s�ŏ������ق������₷��)
//			"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
//		},
//	};
//
//
//	// �O���t�B�b�N�X�p�C�v���C���ݒ�
//	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc{};
//
//	// �V�F�[�_�[�̐ݒ�
//	pipelineDesc.VS.pShaderBytecode = vsBlob->GetBufferPointer();
//	pipelineDesc.VS.BytecodeLength = vsBlob->GetBufferSize();
//	pipelineDesc.PS.pShaderBytecode = psBlob->GetBufferPointer();
//	pipelineDesc.PS.BytecodeLength = psBlob->GetBufferSize();
//
//	// �T���v���}�X�N�̐ݒ�
//	pipelineDesc.SampleMask = D3D12_DEFAULT_SAMPLE_MASK; // �W���ݒ�
//
//	// ���X�^���C�U�̐ݒ�
//	pipelineDesc.RasterizerState.CullMode = D3D12_CULL_MODE_BACK;  // �J�����O���Ȃ�
//	pipelineDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID; // �|���S�����h��Ԃ�
//	pipelineDesc.RasterizerState.DepthClipEnable = true; // �[�x�N���b�s���O��L����
//
//	// �u�����h�X�e�[�g
//	//pipelineDesc.BlendState.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;  // RBGA�S�Ẵ`�����l����`��
//	D3D12_RENDER_TARGET_BLEND_DESC& blenddesc = pipelineDesc.BlendState.RenderTarget[0];
//	blenddesc.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
//	blenddesc.BlendEnable = true;
//	blenddesc.BlendOpAlpha = D3D12_BLEND_OP_ADD;
//	blenddesc.SrcBlendAlpha = D3D12_BLEND_ONE;
//	blenddesc.DestBlendAlpha = D3D12_BLEND_ZERO;
//
//	////���Z����
//	//blenddesc.BlendOp = D3D12_BLEND_OP_ADD;			//���Z
//	//blenddesc.SrcBlend = D3D12_BLEND_ONE;			//�\�[�X�̒l��100%�g��
//	//blenddesc.DestBlend = D3D12_BLEND_ONE;			//�f�X�g�̒l��100%�g��
//
//	////���Z����
//	//blenddesc.BlendOp = D3D12_BLEND_OP_REV_SUBTRACT;	//�f�X�g����\�[�X�����Z
//	//blenddesc.SrcBlend = D3D12_BLEND_ONE;				//�\�[�X�̒l��100%�g��
//	//blenddesc.DestBlend = D3D12_BLEND_ONE;				//�f�X�g�̒l��100%�g��
//	//
//	////�F���]
//	//blenddesc.BlendOp = D3D12_BLEND_OP_ADD;				//���Z
//	//blenddesc.SrcBlend = D3D12_BLEND_INV_DEST_COLOR;	//1.0f-�f�X�g�J���[�̒l
//	//blenddesc.DestBlend = D3D12_BLEND_ZERO;				//�g��Ȃ�
//
//	//����������
//	blenddesc.BlendOp = D3D12_BLEND_OP_ADD;				//���Z
//	blenddesc.SrcBlend = D3D12_BLEND_SRC_ALPHA;			//�\�[�X�̃A���t�@�l
//	blenddesc.DestBlend = D3D12_BLEND_INV_SRC_ALPHA;	//1.0f-�\�[�X�̃A���t�@�l
//
//
//	// ���_���C�A�E�g�̐ݒ�
//	pipelineDesc.InputLayout.pInputElementDescs = inputLayout;
//	pipelineDesc.InputLayout.NumElements = _countof(inputLayout);
//
//	// �}�`�̌`��ݒ�
//	pipelineDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
//
//	// ���̑��̐ݒ�
//	pipelineDesc.NumRenderTargets = 1; // �`��Ώۂ�1��
//	pipelineDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB; // 0�`255�w���RGBA
//	pipelineDesc.SampleDesc.Count = 1; // 1�s�N�Z���ɂ�1��T���v�����O
//
//	// �f�X�N���v�^�����W�̐ݒ�
//	D3D12_DESCRIPTOR_RANGE descriptorRange{};
//	descriptorRange.NumDescriptors = 1;         //��x�̕`��Ɏg���e�N�X�`����1���Ȃ̂�1
//	descriptorRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
//	descriptorRange.BaseShaderRegister = 0;     //�e�N�X�`�����W�X�^0��
//	descriptorRange.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
//
//	// �e�N�X�`���T���v���[�̐ݒ�
//	D3D12_STATIC_SAMPLER_DESC samplerDesc{};
//	samplerDesc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //���J��Ԃ��i�^�C�����O�j
//	samplerDesc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //�c�J��Ԃ��i�^�C�����O�j
//	samplerDesc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //���s�J��Ԃ��i�^�C�����O�j
//	samplerDesc.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;  //�{�[�_�[�̎��͍�
//	samplerDesc.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;                   //�S�ă��j�A���
//	samplerDesc.MaxLOD = D3D12_FLOAT32_MAX;                                 //�~�b�v�}�b�v�ő�l
//	samplerDesc.MinLOD = 0.0f;                                              //�~�b�v�}�b�v�ŏ��l
//	samplerDesc.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
//	samplerDesc.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;           //�s�N�Z���V�F�[�_����̂ݎg�p�\
//
//	// ���[�g�p�����[�^�̐ݒ�
//	D3D12_ROOT_PARAMETER rootParams[3] = {};
//	rootParams[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;    // �萔�o�b�t�@�r���[
//	rootParams[0].Descriptor.ShaderRegister = 0;                    // �萔�o�b�t�@�ԍ�
//	rootParams[0].Descriptor.RegisterSpace = 0;                     // �f�t�H���g�l
//	rootParams[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;   //�S�ẴV�F�[�_���猩����
//	// �e�N�X�`�����W�X�^0��
//	rootParams[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;   //���
//	rootParams[1].DescriptorTable.pDescriptorRanges = &descriptorRange;		  //�f�X�N���v�^�����W
//	rootParams[1].DescriptorTable.NumDescriptorRanges = 1;              		  //�f�X�N���v�^�����W��
//	rootParams[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;               //�S�ẴV�F�[�_���猩����
//	//�萔�o�b�t�@1��
//	rootParams[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;    // �萔�o�b�t�@�r���[
//	rootParams[2].Descriptor.ShaderRegister = 1;                    // �萔�o�b�t�@�ԍ�
//	rootParams[2].Descriptor.RegisterSpace = 0;                     // �f�t�H���g�l
//	rootParams[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;   //�S�ẴV�F�[�_���猩����
//	// ���[�g�V�O�l�`��
//	ComPtr<ID3D12RootSignature> rootSignature;
//	// ���[�g�V�O�l�`���̐ݒ�
//	D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc{};
//	rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
//	rootSignatureDesc.pParameters = rootParams; //���[�g�p�����[�^�̐擪�A�h���X
//	rootSignatureDesc.NumParameters = _countof(rootParams);        //���[�g�p�����[�^��
//	rootSignatureDesc.pStaticSamplers = &samplerDesc;
//	rootSignatureDesc.NumStaticSamplers = 1;
//
//
//
//
//	// ���[�g�V�O�l�`���̃V���A���C�Y
//	ComPtr<ID3DBlob> rootSigBlob = nullptr;
//	result = D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1_0, &rootSigBlob, &errorBlob);
//	assert(SUCCEEDED(result));
//	result = dxCommon->GetDevice()->CreateRootSignature(0, rootSigBlob->GetBufferPointer(), rootSigBlob->GetBufferSize(), IID_PPV_ARGS(&rootSignature));
//	assert(SUCCEEDED(result));
//
//
//	// �p�C�v���C���Ƀ��[�g�V�O�l�`�����Z�b�g
//	pipelineDesc.pRootSignature = rootSignature.Get();
//
//	//�f�X�X�e���V���X�e�[�g�̐ݒ�
//	pipelineDesc.DepthStencilState.DepthEnable = true;//�[�x�e�X�g���s��
//	pipelineDesc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;//�������݋���
//	pipelineDesc.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_LESS;//��������΍��i
//	pipelineDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;//�[�x�l�t�H�[�}�b�g
//
//	// �p�C�v�����X�e�[�g�̐���
//	ComPtr<ID3D12PipelineState> pipelineState = nullptr;
//	result = dxCommon->GetDevice()->CreateGraphicsPipelineState(&pipelineDesc, IID_PPV_ARGS(&pipelineState));
//	assert(SUCCEEDED(result));
//
//
//
//
//	// �q�[�v�ݒ�
//	D3D12_HEAP_PROPERTIES cbHeapProp{};
//	cbHeapProp.Type = D3D12_HEAP_TYPE_UPLOAD;                   // GPU�ւ̓]���p
//	// ���\�[�X�ݒ�
//	D3D12_RESOURCE_DESC cbResourceDesc{};
//	cbResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
//	cbResourceDesc.Width = (sizeof(ConstBufferDataMaterial) + 0xff) & ~0xff;   // 256�o�C�g�A���C�������g
//	cbResourceDesc.Height = 1;
//	cbResourceDesc.DepthOrArraySize = 1;
//	cbResourceDesc.MipLevels = 1;
//	cbResourceDesc.SampleDesc.Count = 1;
//	cbResourceDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
//
//	ComPtr<ID3D12Resource> constBuffMaterial = nullptr;
//	// �萔�o�b�t�@�̐���
//	result = dxCommon->GetDevice()->CreateCommittedResource(
//		&cbHeapProp, // �q�[�v�ݒ�
//		D3D12_HEAP_FLAG_NONE,
//		&cbResourceDesc, // ���\�[�X�ݒ�
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&constBuffMaterial));
//	assert(SUCCEEDED(result));
//
//	// �萔�o�b�t�@�̃}�b�s���O
//	ConstBufferDataMaterial* constMapMaterial = nullptr;
//	result = constBuffMaterial->Map(0, nullptr, (void**)&constMapMaterial); // �}�b�s���O
//	assert(SUCCEEDED(result));
//
//	// �l���������ނƎ����I�ɓ]�������
//	constMapMaterial->color = XMFLOAT4(1, 1, 1, 1.0f);              // RGBA�Ŕ������̐�
//
//
//	//3D�I�u�W�F�N�g�̐�
//	const size_t kObjectCount = 50;
//	//3D�I�u�W�F�N�g�̔z��
//	Object3d object3ds[kObjectCount];
//
//	for (int i = 0; i < _countof(object3ds); i++) {
//		//������
//		InitializeObject3d(&object3ds[i], dxCommon->GetDevice());
//
//		//�������火�͐e�q�\���̃T���v��
//		//�擪�ȊO�Ȃ�
//		if (i > 0) {
//			//��O�̃I�u�W�F�N�g��e�I�u�W�F�N�g�Ƃ���
//			object3ds[i].parent = &object3ds[i - 1];
//			//�e�I�u�W�F�N�g��9���̑傫��
//			object3ds[i].scale = { 0.9f,0.9f,0.9f };
//			//�e�I�u�W�F�N�g�ɑ΂���Z�������30�x��]
//			object3ds[i].rotation = { 0.0f,0.0f,XMConvertToRadians(30.0f) };
//
//			//�e�I�u�W�F�N�g�ɑ΂���Z����-8.0���炷
//			object3ds[i].position = { 0.0f,0.0f,-8.0f };
//		}
//	}
//
//
//	////���s���e�s��̌v�Z
//	//constMapTransform->mat = XMMatrixOrthographicOffCenterLH(
//	//0.0f,window_width,
//	//window_height,0.0f ,
//	//0.0f,1.0f
//	//);
//
//	//�������e�ϊ��s��̌v�Z
//	XMMATRIX matProjection = XMMatrixPerspectiveFovLH(
//		XMConvertToRadians(45.0f),
//		(float)WinApp::window_width / WinApp::window_height,
//		0.1f, 1000.0f
//	);
//
//	//�r���[�ϊ��s��
//	XMMATRIX matView;
//	XMFLOAT3 eye(0, 0, -100);	//���_���W
//	XMFLOAT3 target(0, 0, 0);	//�����_���W
//	XMFLOAT3 up(0, 1, 0);		//������x�N�g��
//	matView = XMMatrixLookAtLH(XMLoadFloat3(&eye), XMLoadFloat3(&target), XMLoadFloat3(&up));
//
//	//���[���h�ϊ��s��
//	XMMATRIX matWorld;
//	matWorld = XMMatrixIdentity();
//
//	//matScale = XMMatrixScaling(1.0f, 0.5f, 1.0f);
//	//matWorld *= matScale;//���[���h�s��ɃX�P�[�����O
//
//	//matWorld *= matRot;
//	//matTrans = XMMatrixTranslation(-50.0f, 0, 0);
//	//matWorld *= matTrans;
//
//	////�萔�o�b�t�@�ɓ]��
//	//constMapTransform->mat = matWorld*matView * matProjection;
//
//
//
////// �������s�N�Z����
////const size_t textureWidth = 256;
////// �c�����s�N�Z����
////const size_t textureHeight = 256;
////// �z��̗v�f��
////const size_t imageDataCount = textureWidth * textureHeight;
////// �摜�C���[�W�f�[�^�z��
////XMFLOAT4* imageData = new XMFLOAT4[imageDataCount]; // ���K����ŉ������
//
////// �S�s�N�Z���̐F��������
////for (size_t i = 0; i < imageDataCount; i++) {
////		imageData[i].x = 1.0f;    // R
////		imageData[i].y = 0.0f;    // G
////		imageData[i].z = 0.0f;    // B
////		imageData[i].w = 1.0f;    // A
////}
//
//
//	//�摜1����
//	TexMetadata metadata{};
//	ScratchImage scratchImg{};
//	// WIC�e�N�X�`���̃��[�h
//	result = LoadFromWICFile(
//		L"Resources/mario.jpg",   //�uResources�v�t�H���_�́ulavender.jpg�v
//		WIC_FLAGS_NONE,
//		&metadata, scratchImg);
//
//	ScratchImage mipChain{};
//	// �~�b�v�}�b�v����
//	result = GenerateMipMaps(
//		scratchImg.GetImages(), scratchImg.GetImageCount(), scratchImg.GetMetadata(),
//		TEX_FILTER_DEFAULT, 0, mipChain);
//	if (SUCCEEDED(result)) {
//		scratchImg = std::move(mipChain);
//		metadata = scratchImg.GetMetadata();
//	}
//
//	// �ǂݍ��񂾃f�B�t���[�Y�e�N�X�`����SRGB�Ƃ��Ĉ���
//	metadata.format = MakeSRGB(metadata.format);
//
//	// �q�[�v�ݒ�
//	D3D12_HEAP_PROPERTIES textureHeapProp{};
//	textureHeapProp.Type = D3D12_HEAP_TYPE_CUSTOM;
//	textureHeapProp.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_WRITE_BACK;
//	textureHeapProp.MemoryPoolPreference = D3D12_MEMORY_POOL_L0;
//	// ���\�[�X�ݒ�
//	D3D12_RESOURCE_DESC textureResourceDesc{};
//	textureResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
//	textureResourceDesc.Format = metadata.format;
//	textureResourceDesc.Width = metadata.width;
//	textureResourceDesc.Height = (UINT)metadata.height;
//	textureResourceDesc.DepthOrArraySize = (UINT16)metadata.arraySize;
//	textureResourceDesc.MipLevels = (UINT16)metadata.mipLevels;
//	textureResourceDesc.SampleDesc.Count = 1;
//
//
//	// �e�N�X�`���o�b�t�@�̐���
//	ComPtr<ID3D12Resource> texBuff = nullptr;
//	result = dxCommon->GetDevice()->CreateCommittedResource(
//		&textureHeapProp,
//		D3D12_HEAP_FLAG_NONE,
//		&textureResourceDesc,
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&texBuff));
//	// �S�~�b�v�}�b�v�ɂ���
//	for (size_t i = 0; i < metadata.mipLevels; i++) {
//		// �~�b�v�}�b�v���x�����w�肵�ăC���[�W���擾
//		const Image* img = scratchImg.GetImage(i, 0, 0);
//		// �e�N�X�`���o�b�t�@�Ƀf�[�^�]��
//		result = texBuff->WriteToSubresource(
//			(UINT)i,
//			nullptr,              // �S�̈�փR�s�[
//			img->pixels,          // ���f�[�^�A�h���X
//			(UINT)img->rowPitch,  // 1���C���T�C�Y
//			(UINT)img->slicePitch // 1���T�C�Y
//		);
//		assert(SUCCEEDED(result));
//	}
//
//	//�摜2����
//	TexMetadata metadata2{};
//	ScratchImage scratchImg2{};
//
//	// WIC�e�N�X�`���̃��[�h
//	result = LoadFromWICFile(
//		L"Resources/reimu.png",   //�uResources�v�t�H���_�́ureimu.jpg�v
//		WIC_FLAGS_NONE,
//		&metadata2, scratchImg2);
//	ScratchImage mipChain2{};
//	// �~�b�v�}�b�v����
//	result = GenerateMipMaps(
//		scratchImg2.GetImages(), scratchImg2.GetImageCount(), scratchImg2.GetMetadata(),
//		TEX_FILTER_DEFAULT, 0, mipChain2);
//	if (SUCCEEDED(result)) {
//		scratchImg2 = std::move(mipChain2);
//		metadata2 = scratchImg2.GetMetadata();
//	}
//
//	// �ǂݍ��񂾃f�B�t���[�Y�e�N�X�`����SRGB�Ƃ��Ĉ���
//	metadata2.format = MakeSRGB(metadata2.format);
//
//	// ���\�[�X�ݒ�
//	D3D12_RESOURCE_DESC textureResourceDesc2{};
//	textureResourceDesc2.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
//	textureResourceDesc2.Format = metadata2.format;
//	textureResourceDesc2.Width = metadata2.width;
//	textureResourceDesc2.Height = (UINT)metadata2.height;
//	textureResourceDesc2.DepthOrArraySize = (UINT16)metadata2.arraySize;
//	textureResourceDesc2.MipLevels = (UINT16)metadata2.mipLevels;
//	textureResourceDesc2.SampleDesc.Count = 1;
//
//	// �e�N�X�`���o�b�t�@�̐���
//	ComPtr<ID3D12Resource> texBuff2 = nullptr;
//	result = dxCommon->GetDevice()->CreateCommittedResource(
//		&textureHeapProp,
//		D3D12_HEAP_FLAG_NONE,
//		&textureResourceDesc2,
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&texBuff2));
//
//
//	// �S�~�b�v�}�b�v�ɂ���
//	for (size_t i = 0; i < metadata2.mipLevels; i++) {
//		// �~�b�v�}�b�v���x�����w�肵�ăC���[�W���擾
//		const Image* img2 = scratchImg2.GetImage(i, 0, 0);
//		// �e�N�X�`���o�b�t�@�Ƀf�[�^�]��
//		result = texBuff2->WriteToSubresource(
//			(UINT)i,
//			nullptr,              // �S�̈�փR�s�[
//			img2->pixels,          // ���f�[�^�A�h���X
//			(UINT)img2->rowPitch,  // 1���C���T�C�Y
//			(UINT)img2->slicePitch // 1���T�C�Y
//		);
//		assert(SUCCEEDED(result));
//	}
//
//
//	//// ���f�[�^���
//	//delete[] imageData;
//
//	// SRV�̍ő��
//	const size_t kMaxSRVCount = 2056;
//
//	// �f�X�N���v�^�q�[�v�̐ݒ�
//	D3D12_DESCRIPTOR_HEAP_DESC srvHeapDesc = {};
//	srvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
//	srvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;//�V�F�[�_���猩����悤��
//	srvHeapDesc.NumDescriptors = kMaxSRVCount;
//
//	// �ݒ������SRV�p�f�X�N���v�^�q�[�v�𐶐�
//	ComPtr<ID3D12DescriptorHeap> srvHeap = nullptr;
//	result = dxCommon->GetDevice()->CreateDescriptorHeap(&srvHeapDesc, IID_PPV_ARGS(&srvHeap));
//	assert(SUCCEEDED(result));
//
//	//SRV�q�[�v�̐擪�n���h�����擾
//	D3D12_CPU_DESCRIPTOR_HANDLE srvHandle = srvHeap->GetCPUDescriptorHandleForHeapStart();
//
//	// �V�F�[�_���\�[�X�r���[�ݒ�
//	D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc{};
//	srvDesc.Format = textureResourceDesc.Format;
//	srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
//	srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
//	srvDesc.Texture2D.MipLevels = textureResourceDesc.MipLevels;
//
//	// �n���h���̎w���ʒu�ɃV�F�[�_�[���\�[�X�r���[�쐬
//	dxCommon->GetDevice()->CreateShaderResourceView(texBuff.Get(), &srvDesc, srvHandle);
//
//
//	//�񖇖ڂ̉摜�p
//	//��n���h����i�߂�
//	UINT incrementSize = dxCommon->GetDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
//	srvHandle.ptr += incrementSize;
//
//	// �V�F�[�_���\�[�X�r���[�ݒ�
//	D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc2{};
//	srvDesc2.Format = textureResourceDesc2.Format;
//	srvDesc2.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
//	srvDesc2.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
//	srvDesc2.Texture2D.MipLevels = textureResourceDesc2.MipLevels;
//
//	// �n���h���̎w���ʒu�ɃV�F�[�_�[���\�[�X�r���[�쐬
//	dxCommon->GetDevice()->CreateShaderResourceView(texBuff2.Get(), &srvDesc2, srvHandle);
//
//
//
//	// �C���f�b�N�X�f�[�^�S�̂̃T�C�Y
//	UINT sizeIB = static_cast<UINT>(sizeof(uint16_t) * _countof(indices));
//
//	// ���\�[�X�ݒ�
//	resDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
//	resDesc.Width = sizeIB; // �C���f�b�N�X��񂪓��镪�̃T�C�Y
//	resDesc.Height = 1;
//	resDesc.DepthOrArraySize = 1;
//	resDesc.MipLevels = 1;
//	resDesc.SampleDesc.Count = 1;
//	resDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
//
//	// �C���f�b�N�X�o�b�t�@�̐���
//	ComPtr<ID3D12Resource> indexBuff = nullptr;
//
//	result = dxCommon->GetDevice()->CreateCommittedResource(
//		&heapProp, // �q�[�v�ݒ�
//		D3D12_HEAP_FLAG_NONE,
//		&resDesc, // ���\�[�X�ݒ�
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&indexBuff));
//
//	// �C���f�b�N�X�o�b�t�@���}�b�s���O
//	uint16_t* indexMap = nullptr;
//	result = indexBuff->Map(0, nullptr, (void**)&indexMap);
//	// �S�C���f�b�N�X�ɑ΂���
//	for (int i = 0; i < _countof(indices); i++)
//	{
//		indexMap[i] = indices[i];   // �C���f�b�N�X���R�s�[
//	}
//	// �}�b�s���O����
//	indexBuff->Unmap(0, nullptr);
//
//	// �C���f�b�N�X�o�b�t�@�r���[�̍쐬
//	D3D12_INDEX_BUFFER_VIEW ibView{};
//	ibView.BufferLocation = indexBuff->GetGPUVirtualAddress();
//	ibView.Format = DXGI_FORMAT_R16_UINT;
//	ibView.SizeInBytes = sizeIB;





	//�`�揉�������� �����܂�

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

		// �I�u�W�F�N�g�ړ�
		if (input->PushKey(DIK_UP) || input->PushKey(DIK_DOWN) || input->PushKey(DIK_RIGHT) || input->PushKey(DIK_LEFT)|| input->PushKey(DIK_W)|| input->PushKey(DIK_S))
		{
			// ���݂̍��W���擾
			DirectX::XMFLOAT3 position = object3d->GetPosition();

			// �ړ���̍��W���v�Z
			if (input->PushKey(DIK_UP)) { position.y += 1.0f; }
			else if (input->PushKey(DIK_DOWN)) { position.y -= 1.0f; }
			if (input->PushKey(DIK_RIGHT)) { position.x += 1.0f; }
			else if (input->PushKey(DIK_LEFT)) { position.x -= 1.0f; }
			if (input->PushKey(DIK_W)) { position.z += 1.0f; }
			else if (input->PushKey(DIK_S)) { position.z -= 1.0f; }

			// ���W�̕ύX�𔽉f
			object3d->SetPosition(position);
		}
		//��ՃV�X�e���̍X�V
		object3d->Update();


		/*sprite->Update();*/

		//for (int i = 0; i < _countof(indices) / 3; i++)
		//{//�O�p�`1���ƂɌv�Z���Ă���
		//	//�O�p�`�̃C���f�b�N�X�����o���āA�ꎞ�I�ȕϐ��ɓ����
		//	unsigned short indices0 = indices[i * 3 + 0];
		//	unsigned short indices1 = indices[i * 3 + 1];
		//	unsigned short indices2 = indices[i * 3 + 2];
		//	//�O�p�`���\�����钸�_���W���x�N�g���ɑ��
		//	XMVECTOR p0 = XMLoadFloat3(&vertices[indices0].pos);
		//	XMVECTOR p1 = XMLoadFloat3(&vertices[indices1].pos);
		//	XMVECTOR p2 = XMLoadFloat3(&vertices[indices2].pos);
		//	//p0��p1�x�N�g���Ap0��p2�x�N�g�����v�Z(�x�N�g���̌��Z)
		//	XMVECTOR v1 = XMVectorSubtract(p1, p0);
		//	XMVECTOR v2 = XMVectorSubtract(p2, p0);
		//	//�O�ς͗������琂���ȃx�N�g��
		//	XMVECTOR normal = XMVector3Cross(v1, v2);
		//	//���K��(������1�ɂ���)
		//	normal = XMVector3Normalize(normal);
		//	//���߂��@���𒸓_�f�[�^�ɑ��
		//	XMStoreFloat3(&vertices[indices0].normal, normal);
		//	XMStoreFloat3(&vertices[indices1].normal, normal);
		//	XMStoreFloat3(&vertices[indices2].normal, normal);
		//}

		////�S���_�ɑ΂���
		//for (int i = 0; i < _countof(vertices); i++) {
		//	vertMap[i] = vertices[i]; // ���W���R�s�[
		//}



		////�J����
		//if (input->TriggerKey(DIK_D) || input->TriggerKey(DIK_A)) {
		//	if (input->TriggerKey(DIK_D)) {
		//		angle += XMConvertToRadians(1.0f);
		//	}
		//	else if (input->TriggerKey(DIK_A)) {
		//		angle -= XMConvertToRadians(1.0f);
		//	}
		//	//	angle���W�A������Y������ɉ�]�B���a��-100
		//	eye.x = -100 * sinf(angle);
		//	eye.z = -100 * cosf(angle);
		//	//�r���[�ϊ��s��
		//	matView = XMMatrixLookAtLH(XMLoadFloat3(&eye), XMLoadFloat3(&target), XMLoadFloat3(&up));
		//}



		////���W����

		//if (input->PushKey(DIK_UP) || input->PushKey(DIK_DOWN) || input->PushKey(DIK_RIGHT) || input->PushKey(DIK_LEFT))
		//{
		//	if (input->PushKey(DIK_UP)) { object3ds[0].position.y += 1.0f; }
		//	else if (input->PushKey(DIK_DOWN)) { object3ds[0].position.y -= 1.0f; }
		//	if (input->PushKey(DIK_RIGHT)) { object3ds[0].position.x += 1.0f; }
		//	else if (input->PushKey(DIK_LEFT)) { object3ds[0].position.x -= 1.0f; }
		//}

		//for (size_t i = 0; i < _countof(object3ds); i++)
		//{
		//	UpdateObject3d(&object3ds[i], matView, matProjection);
		//}


		//// 4.�`��R�}���h��������

		dxCommon->PreDraw();

//�ŏ��̃V�[���̕`��

		//3d�I�u�W�F�N�g�`��O����
		Object3d::PreDraw(dxCommon->GetCommandlist());

		//3d�I�u�W�F�N�g�̕`��
		object3d->Draw();

		//3d�I�u�W�F�N�g�`��㏈��
		Object3d::PostDraw();

		//�X�v���C�g�O����

		/*sprite->Draw();*/

//�ŏ��̃V�[���̕`��

		dxCommon->PostDraw();
		//// �p�C�v���C���X�e�[�g�ƃ��[�g�V�O�l�`���̐ݒ�R�}���h
		//dxCommon->GetCommandlist()->SetPipelineState(pipelineState.Get());
		//dxCommon->GetCommandlist()->SetGraphicsRootSignature(rootSignature.Get());

		//// �v���~�e�B�u�`��̐ݒ�R�}���h
		//dxCommon->GetCommandlist()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST); // �O�p�`���X�g

		//// ���_�o�b�t�@�r���[�̐ݒ�R�}���h
		//dxCommon->GetCommandlist()->IASetVertexBuffers(0, 1, &vbView);

		//// �萔�o�b�t�@�r���[(CBV)�̐ݒ�R�}���h
		//dxCommon->GetCommandlist()->SetGraphicsRootConstantBufferView(0, constBuffMaterial->GetGPUVirtualAddress());

		//ID3D12DescriptorHeap* ppHeaps[] = { srvHeap.Get() };
		//// SRV�q�[�v�̐ݒ�R�}���h
		//dxCommon->GetCommandlist()->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
		//// SRV�q�[�v�̐擪�n���h�����擾�iSRV���w���Ă���͂��j
		//D3D12_GPU_DESCRIPTOR_HANDLE srvGpuHandle = srvHeap->GetGPUDescriptorHandleForHeapStart();
		////2���ڂ��w�������悤�ɂ���SRV�̃n���h�������[�g�p�����[�^1�Ԃɐݒ�
		//srvGpuHandle.ptr += incrementSize;
		//// SRV�q�[�v�̐擪�ɂ���SRV�����[�g�p�����[�^1�Ԃɐݒ�
		//dxCommon->GetCommandlist()->SetGraphicsRootDescriptorTable(1, srvGpuHandle);

		//// �C���f�b�N�X�o�b�t�@�r���[�̐ݒ�R�}���h
		//dxCommon->GetCommandlist()->IASetIndexBuffer(&ibView);


		////�S�I�u�W�F�N�g�ɂ��ď���
		//for (int i = 0; i < _countof(object3ds); i++) {
		//	DrawObject3d(&object3ds[i], dxCommon->GetCommandlist(), vbView, ibView, _countof(indices));
		//}

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

	//3d�I�u�W�F�N�g���
	delete object3d;

	//delete spriteCommon;

//��ՃV�X�e���̏I��

	return 0;
}

