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
#include"Sprite.h"
#include"SpriteCommon.h"
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

//�e�N�X�`���̍ő喇��
const int spriteSRVCount = 512;

//�萔�o�b�t�@�p�f�[�^�\����
struct ConstBufferData {
	XMFLOAT4 color;		//�F(RGBA)
	XMMATRIX mat;		//3D�ϊ��s��
};


//���_�f�[�^
struct VertexPosUv
{
	XMFLOAT3 pos;	//xyz���W
	XMFLOAT2 uv;	//uv���W
};

//�p�C�v���C���Z�b�g
struct PipelineSet
{
	//�p�C�v���C���X�e�[�g�I�u�W�F�N�g
	ComPtr<ID3D12PipelineState>pipelinestate;
	//���[�g�V�O�l�`��
	ComPtr<ID3D12RootSignature>rootsignature;
};

//�X�v���C�g1�����̃f�[�^
struct Sprite
{
	ComPtr<ID3D12Resource> vertBuff;				//���_�o�b�t�@
	D3D12_VERTEX_BUFFER_VIEW vbView{};				//���_�o�b�t�@�r���[
	ComPtr<ID3D12Resource> constBuff;				//�萔�o�b�t�@�r���[
	float rotation = 0.0f;			//Z������̉�]��
	XMFLOAT3 position = { 0,0,0 };	//���W
	XMMATRIX matWorld;				//���[���h�s��
	//XMFLOAT4 color = { 1,1,1,1 };	//�F
	UINT texNumber = 0;				//�e�L�X�g�ԍ�
	XMFLOAT2 size = { 100,100 };
};

//�X�v���C�g�̋��ʃf�[�^
struct SpriteCommon
{
	//�p�C�v���C���Z�b�g
	PipelineSet pipelineSet;
	//�ˉe�s��
	XMMATRIX matProjection{};
	//�e�N�X�`���p�f�X�N���v�^�q�[�v�̐���
	ComPtr<ID3D12DescriptorHeap>descHeap;
	//�e�N�X�`�����\�[�X(�e�N�X�`���o�b�t�@)�̔z��
	ComPtr<ID3D12Resource>texBuff[spriteSRVCount];

};

//�p�C�v���C������
PipelineSet Pipeline3D(ID3D12Device* dev)
{
	HRESULT result;
	ComPtr<ID3DBlob> vsBlob; // ���_�V�F�[�_�I�u�W�F�N�g
	ComPtr<ID3DBlob> psBlob; // �s�N�Z���V�F�[�_�I�u�W�F�N�g
	ComPtr<ID3DBlob> errorBlob; // �G���[�I�u�W�F�N�g

	// ���_�V�F�[�_�̓ǂݍ��݂ƃR���p�C��
	result = D3DCompileFromFile(
		L"Resources/shaders/BasicVS.hlsl", // �V�F�[�_�t�@�C����
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, // �C���N���[�h�\�ɂ���
		"main", "vs_5_0", // �G���g���[�|�C���g���A�V�F�[�_�[���f���w��
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // �f�o�b�O�p�ݒ�
		0,
		&vsBlob, &errorBlob);

	// �G���[�Ȃ�
	if (FAILED(result)) {
		// errorBlob����G���[���e��string�^�ɃR�s�[
		std::string error;
		error.resize(errorBlob->GetBufferSize());

		std::copy_n((char*)errorBlob->GetBufferPointer(),
			errorBlob->GetBufferSize(),
			error.begin());
		error += "\n";
		// �G���[���e���o�̓E�B���h�E�ɕ\��
		OutputDebugStringA(error.c_str());
		assert(0);
	}

	// �s�N�Z���V�F�[�_�̓ǂݍ��݂ƃR���p�C��
	result = D3DCompileFromFile(
		L"Resources/shaders/BasicPS.hlsl",   // �V�F�[�_�t�@�C����
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, // �C���N���[�h�\�ɂ���
		"main", "ps_5_0", // �G���g���[�|�C���g���A�V�F�[�_�[���f���w��
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // �f�o�b�O�p�ݒ�
		0,
		&psBlob, &errorBlob);

	// �G���[�Ȃ�
	if (FAILED(result)) {
		// errorBlob����G���[���e��string�^�ɃR�s�[
		std::string error;
		error.resize(errorBlob->GetBufferSize());

		std::copy_n((char*)errorBlob->GetBufferPointer(),
			errorBlob->GetBufferSize(),
			error.begin());
		error += "\n";
		// �G���[���e���o�̓E�B���h�E�ɕ\��
		OutputDebugStringA(error.c_str());
		assert(0);
	}

	// ���_���C�A�E�g
	D3D12_INPUT_ELEMENT_DESC inputLayout[] = {
		{ // xyz���W(1�s�ŏ������ق������₷��)
			"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,
			D3D12_APPEND_ALIGNED_ELEMENT,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
		},
		{//�@���x�N�g��
			"NORMAL",0,DXGI_FORMAT_R32G32B32_FLOAT,0,
			D3D12_APPEND_ALIGNED_ELEMENT,
		D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0
		},

		{ // uv���W(1�s�ŏ������ق������₷��)
			"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0,
			D3D12_APPEND_ALIGNED_ELEMENT,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
		},
	};

	// �f�X�N���v�^�����W�̐ݒ�
	D3D12_DESCRIPTOR_RANGE descriptorRange{};
	descriptorRange.NumDescriptors = 1;         //��x�̕`��Ɏg���e�N�X�`����1���Ȃ̂�1
	descriptorRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
	descriptorRange.BaseShaderRegister = 0;     //�e�N�X�`�����W�X�^0��
	descriptorRange.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;

	// ���[�g�p�����[�^�̐ݒ�
	D3D12_ROOT_PARAMETER rootParams[3] = {};
	// �萔�o�b�t�@0��
	rootParams[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;   // ���
	rootParams[0].Descriptor.ShaderRegister = 0;                   // �萔�o�b�t�@�ԍ�
	rootParams[0].Descriptor.RegisterSpace = 0;                    // �f�t�H���g�l
	rootParams[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;  // �S�ẴV�F�[�_���猩����
	// �e�N�X�`�����W�X�^0��
	rootParams[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;   //���
	rootParams[1].DescriptorTable.pDescriptorRanges = &descriptorRange;		  //�f�X�N���v�^�����W
	rootParams[1].DescriptorTable.NumDescriptorRanges = 1;              		  //�f�X�N���v�^�����W��
	rootParams[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;               //�S�ẴV�F�[�_���猩����
	// �萔�o�b�t�@1��
	rootParams[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;   //���
	rootParams[2].Descriptor.ShaderRegister = 1;		  //�f�X�N���v�^�����W
	rootParams[2].Descriptor.RegisterSpace = 0;              		  //�f�X�N���v�^�����W��
	rootParams[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;                // �f�t�H���g�l

	// �e�N�X�`���T���v���[�̐ݒ�
	D3D12_STATIC_SAMPLER_DESC samplerDesc{};
	samplerDesc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //���J��Ԃ��i�^�C�����O�j
	samplerDesc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //�c�J��Ԃ��i�^�C�����O�j
	samplerDesc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //���s�J��Ԃ��i�^�C�����O�j
	samplerDesc.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;  //�{�[�_�[�̎��͍�
	samplerDesc.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;                   //�S�ă��j�A���
	samplerDesc.MaxLOD = D3D12_FLOAT32_MAX;                                 //�~�b�v�}�b�v�ő�l
	samplerDesc.MinLOD = 0.0f;                                              //�~�b�v�}�b�v�ŏ��l
	samplerDesc.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
	samplerDesc.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;           //�s�N�Z���V�F�[�_����̂ݎg�p�\

	// �O���t�B�b�N�X�p�C�v���C���ݒ�
	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc{};

	// �V�F�[�_�[�̐ݒ�
	pipelineDesc.VS.pShaderBytecode = vsBlob->GetBufferPointer();
	pipelineDesc.VS.BytecodeLength = vsBlob->GetBufferSize();
	pipelineDesc.PS.pShaderBytecode = psBlob->GetBufferPointer();
	pipelineDesc.PS.BytecodeLength = psBlob->GetBufferSize();

	// �T���v���}�X�N�̐ݒ�
	pipelineDesc.SampleMask = D3D12_DEFAULT_SAMPLE_MASK; // �W���ݒ�

	// ���X�^���C�U�̐ݒ�
	pipelineDesc.RasterizerState.CullMode = D3D12_CULL_MODE_BACK;  // �J�����O���Ȃ�
	pipelineDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID; // �|���S�����h��Ԃ�
	pipelineDesc.RasterizerState.DepthClipEnable = true; // �[�x�N���b�s���O��L����

	// �����_�[�^�[�Q�b�g�̃u�����h�ݒ�
	D3D12_RENDER_TARGET_BLEND_DESC& blenddesc = pipelineDesc.BlendState.RenderTarget[0];
	blenddesc.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL; // RBGA�S�Ẵ`�����l����`��

	//blenddesc.BlendEnable = true;                   // �u�����h��L���ɂ���
	//blenddesc.BlendOpAlpha = D3D12_BLEND_OP_ADD;    // ���Z
	//blenddesc.SrcBlendAlpha = D3D12_BLEND_ONE;      // �\�[�X�̒l��100% �g��
	//blenddesc.DestBlendAlpha = D3D12_BLEND_ZERO;    // �f�X�g�̒l��  0% �g��

	//// ����������
	//blenddesc.BlendOp = D3D12_BLEND_OP_ADD;             // ���Z
	//blenddesc.SrcBlend = D3D12_BLEND_SRC_ALPHA;         // �\�[�X�̃A���t�@�l
	//blenddesc.DestBlend = D3D12_BLEND_INV_SRC_ALPHA;    // 1.0f-�\�[�X�̃A���t�@�l

	// ���_���C�A�E�g�̐ݒ�
	pipelineDesc.InputLayout.pInputElementDescs = inputLayout;
	pipelineDesc.InputLayout.NumElements = _countof(inputLayout);

	// �}�`�̌`��ݒ�
	pipelineDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;

	// ���̑��̐ݒ�
	pipelineDesc.NumRenderTargets = 1; // �`��Ώۂ�1��
	pipelineDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB; // 0�`255�w���RGBA
	pipelineDesc.SampleDesc.Count = 1; // 1�s�N�Z���ɂ�1��T���v�����O

	//�f�v�X�X�e���V���X�e�[�g�̐ݒ�
	pipelineDesc.DepthStencilState.DepthEnable = true;
	pipelineDesc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
	pipelineDesc.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_LESS;
	pipelineDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;

	// ���[�g�V�O�l�`��
	//ComPtr<ID3D12RootSignature> rootSignature;
	// ���[�g�V�O�l�`���̐ݒ�
	D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc{};
	rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
	rootSignatureDesc.pParameters = rootParams; //���[�g�p�����[�^�̐擪�A�h���X
	rootSignatureDesc.NumParameters = _countof(rootParams);        //���[�g�p�����[�^��

	rootSignatureDesc.pStaticSamplers = &samplerDesc;
	rootSignatureDesc.NumStaticSamplers = 1;

	//�p�C�v���C���Ɓ�V�O�l�`���̃Z�b�g
	PipelineSet pipelineSet;

	// ���[�g�V�O�l�`���̃V���A���C�Y
	ComPtr<ID3DBlob> rootSigBlob;
	result = D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1_0,
		&rootSigBlob, &errorBlob);
	assert(SUCCEEDED(result));
	result = dev->CreateRootSignature(0, rootSigBlob->GetBufferPointer(), rootSigBlob->GetBufferSize(),
		IID_PPV_ARGS(&pipelineSet.rootsignature));
	assert(SUCCEEDED(result));

	// �p�C�v���C���Ƀ��[�g�V�O�l�`�����Z�b�g
	pipelineDesc.pRootSignature = pipelineSet.rootsignature.Get();

	// �p�C�v�����X�e�[�g�̐���
	result = dev->CreateGraphicsPipelineState(&pipelineDesc, IID_PPV_ARGS(&pipelineSet.pipelinestate));
	assert(SUCCEEDED(result));


	//�p�C�v���C���ƃ��[�g�V�O�l�`����Ԃ�
	return pipelineSet;
}

PipelineSet PipelineSprite(ID3D12Device* dev)
{
	HRESULT result;
	ComPtr<ID3DBlob> vsBlob; // ���_�V�F�[�_�I�u�W�F�N�g
	ComPtr<ID3DBlob> psBlob; // �s�N�Z���V�F�[�_�I�u�W�F�N�g
	ComPtr<ID3DBlob> errorBlob; // �G���[�I�u�W�F�N�g

	// ���_�V�F�[�_�̓ǂݍ��݂ƃR���p�C��
	result = D3DCompileFromFile(
		L"Resources/shaders/SpriteVS.hlsl", // �V�F�[�_�t�@�C����
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, // �C���N���[�h�\�ɂ���
		"main", "vs_5_0", // �G���g���[�|�C���g���A�V�F�[�_�[���f���w��
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // �f�o�b�O�p�ݒ�
		0,
		&vsBlob, &errorBlob);

	// �G���[�Ȃ�
	if (FAILED(result)) {
		// errorBlob����G���[���e��string�^�ɃR�s�[
		std::string error;
		error.resize(errorBlob->GetBufferSize());

		std::copy_n((char*)errorBlob->GetBufferPointer(),
			errorBlob->GetBufferSize(),
			error.begin());
		error += "\n";
		// �G���[���e���o�̓E�B���h�E�ɕ\��
		OutputDebugStringA(error.c_str());
		assert(0);
	}

	// �s�N�Z���V�F�[�_�̓ǂݍ��݂ƃR���p�C��
	result = D3DCompileFromFile(
		L"Resources/shaders/SpritePS.hlsl",   // �V�F�[�_�t�@�C����
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, // �C���N���[�h�\�ɂ���
		"main", "ps_5_0", // �G���g���[�|�C���g���A�V�F�[�_�[���f���w��
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // �f�o�b�O�p�ݒ�
		0,
		&psBlob, &errorBlob);

	// �G���[�Ȃ�
	if (FAILED(result)) {
		// errorBlob����G���[���e��string�^�ɃR�s�[
		std::string error;
		error.resize(errorBlob->GetBufferSize());

		std::copy_n((char*)errorBlob->GetBufferPointer(),
			errorBlob->GetBufferSize(),
			error.begin());
		error += "\n";
		// �G���[���e���o�̓E�B���h�E�ɕ\��
		OutputDebugStringA(error.c_str());
		assert(0);
	}

	// ���_���C�A�E�g
	D3D12_INPUT_ELEMENT_DESC inputLayout[] = {
		{ // xyz���W(1�s�ŏ������ق������₷��)
			"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,
			D3D12_APPEND_ALIGNED_ELEMENT,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
		},

		{ // uv���W(1�s�ŏ������ق������₷��)
			"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0,
			D3D12_APPEND_ALIGNED_ELEMENT,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
		},
	};




	// �f�X�N���v�^�����W�̐ݒ�
	CD3DX12_DESCRIPTOR_RANGE descriptorRange{};
	descriptorRange.Init(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 1, 0);
	//descriptorRange.NumDescriptors = 1;         //��x�̕`��Ɏg���e�N�X�`����1���Ȃ̂�1
	//descriptorRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
	//descriptorRange.BaseShaderRegister = 0;     //�e�N�X�`�����W�X�^0��
	//descriptorRange.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;

	//// ���[�g�p�����[�^�̐ݒ�
	//D3D12_ROOT_PARAMETER rootParams[3] = {};
	//// �萔�o�b�t�@0��
	//rootParams[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;   // ���
	//rootParams[0].Descriptor.ShaderRegister = 0;                   // �萔�o�b�t�@�ԍ�
	//rootParams[0].Descriptor.RegisterSpace = 0;                    // �f�t�H���g�l
	//rootParams[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;  // �S�ẴV�F�[�_���猩����
	//// �e�N�X�`�����W�X�^0��
	//rootParams[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;   //���
	//rootParams[1].DescriptorTable.pDescriptorRanges = &descriptorRange;		  //�f�X�N���v�^�����W
	//rootParams[1].DescriptorTable.NumDescriptorRanges = 1;              		  //�f�X�N���v�^�����W��
	//rootParams[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;               //�S�ẴV�F�[�_���猩����
	//// �萔�o�b�t�@1��
	//rootParams[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;   //���
	//rootParams[2].Descriptor.ShaderRegister = 1;		  //�f�X�N���v�^�����W
	//rootParams[2].Descriptor.RegisterSpace = 0;              		  //�f�X�N���v�^�����W��
	//rootParams[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;                // �f�t�H���g�l

	CD3DX12_ROOT_PARAMETER rootParams[2];
	rootParams[0].InitAsConstantBufferView(0);
	rootParams[1].InitAsDescriptorTable(1, &descriptorRange, D3D12_SHADER_VISIBILITY_ALL);

	// �e�N�X�`���T���v���[�̐ݒ�
	D3D12_STATIC_SAMPLER_DESC samplerDesc{};
	samplerDesc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //���J��Ԃ��i�^�C�����O�j
	samplerDesc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //�c�J��Ԃ��i�^�C�����O�j
	samplerDesc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //���s�J��Ԃ��i�^�C�����O�j
	samplerDesc.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;  //�{�[�_�[�̎��͍�
	samplerDesc.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;                   //�S�ă��j�A���
	samplerDesc.MaxLOD = D3D12_FLOAT32_MAX;                                 //�~�b�v�}�b�v�ő�l
	samplerDesc.MinLOD = 0.0f;                                              //�~�b�v�}�b�v�ŏ��l
	samplerDesc.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
	samplerDesc.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;           //�s�N�Z���V�F�[�_����̂ݎg�p�\

	// �O���t�B�b�N�X�p�C�v���C���ݒ�
	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc{};

	// �V�F�[�_�[�̐ݒ�
	pipelineDesc.VS.pShaderBytecode = vsBlob->GetBufferPointer();
	pipelineDesc.VS.BytecodeLength = vsBlob->GetBufferSize();
	pipelineDesc.PS.pShaderBytecode = psBlob->GetBufferPointer();
	pipelineDesc.PS.BytecodeLength = psBlob->GetBufferSize();

	// �T���v���}�X�N�̐ݒ�
	pipelineDesc.SampleMask = D3D12_DEFAULT_SAMPLE_MASK; // �W���ݒ�

	// ���X�^���C�U�̐ݒ�
	pipelineDesc.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
	pipelineDesc.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;  // �J�����O���Ȃ�
	//pipelineDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID; // �|���S�����h��Ԃ�
	//pipelineDesc.RasterizerState.DepthClipEnable = true; // �[�x�N���b�s���O��L����

	// �����_�[�^�[�Q�b�g�̃u�����h�ݒ�
	D3D12_RENDER_TARGET_BLEND_DESC& blenddesc = pipelineDesc.BlendState.RenderTarget[0];
	blenddesc.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL; // RBGA�S�Ẵ`�����l����`��

	//blenddesc.BlendEnable = true;                   // �u�����h��L���ɂ���
	//blenddesc.BlendOpAlpha = D3D12_BLEND_OP_ADD;    // ���Z
	//blenddesc.SrcBlendAlpha = D3D12_BLEND_ONE;      // �\�[�X�̒l��100% �g��
	//blenddesc.DestBlendAlpha = D3D12_BLEND_ZERO;    // �f�X�g�̒l��  0% �g��

	//// ����������
	//blenddesc.BlendOp = D3D12_BLEND_OP_ADD;             // ���Z
	//blenddesc.SrcBlend = D3D12_BLEND_SRC_ALPHA;         // �\�[�X�̃A���t�@�l
	//blenddesc.DestBlend = D3D12_BLEND_INV_SRC_ALPHA;    // 1.0f-�\�[�X�̃A���t�@�l

	// ���_���C�A�E�g�̐ݒ�
	pipelineDesc.InputLayout.pInputElementDescs = inputLayout;
	pipelineDesc.InputLayout.NumElements = _countof(inputLayout);

	// �}�`�̌`��ݒ�
	pipelineDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;

	// ���̑��̐ݒ�
	pipelineDesc.NumRenderTargets = 1; // �`��Ώۂ�1��
	pipelineDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB; // 0�`255�w���RGBA
	pipelineDesc.SampleDesc.Count = 1; // 1�s�N�Z���ɂ�1��T���v�����O

	//�f�v�X�X�e���V���X�e�[�g�̐ݒ�
	pipelineDesc.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
	pipelineDesc.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_ALWAYS; // ��ɏ㏑�����[��

	pipelineDesc.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
	pipelineDesc.DepthStencilState.DepthEnable = false;
	//pipelineDesc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
	//pipelineDesc.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_ALWAYS;
	//pipelineDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;

	// ���[�g�V�O�l�`��
	//ComPtr<ID3D12RootSignature> rootSignature;
	// ���[�g�V�O�l�`���̐ݒ�
	D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc{};
	rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
	rootSignatureDesc.pParameters = rootParams; //���[�g�p�����[�^�̐擪�A�h���X
	rootSignatureDesc.NumParameters = _countof(rootParams);        //���[�g�p�����[�^��

	rootSignatureDesc.pStaticSamplers = &samplerDesc;
	rootSignatureDesc.NumStaticSamplers = 1;

	//�p�C�v���C���Ɓ�V�O�l�`���̃Z�b�g
	PipelineSet pipelineSet;

	// ���[�g�V�O�l�`���̃V���A���C�Y
	ComPtr<ID3DBlob> rootSigBlob;
	result = D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1_0,
		&rootSigBlob, &errorBlob);
	assert(SUCCEEDED(result));
	result = dev->CreateRootSignature(0, rootSigBlob->GetBufferPointer(), rootSigBlob->GetBufferSize(),
		IID_PPV_ARGS(&pipelineSet.rootsignature));
	assert(SUCCEEDED(result));

	// �p�C�v���C���Ƀ��[�g�V�O�l�`�����Z�b�g
	pipelineDesc.pRootSignature = pipelineSet.rootsignature.Get();

	// �p�C�v�����X�e�[�g�̐���
	result = dev->CreateGraphicsPipelineState(&pipelineDesc, IID_PPV_ARGS(&pipelineSet.pipelinestate));
	assert(SUCCEEDED(result));


	//�p�C�v���C���ƃ��[�g�V�O�l�`����Ԃ�
	return pipelineSet;
}

SpriteCommon SpriteCommonCreate(ID3D12Device* dev, int window_width, int window_height)
{
	HRESULT result = S_FALSE;

	//�V���ȃX�v���C�g���ʃf�[�^�𐶐�
	SpriteCommon spriteCommon{};

	//�X�v���C�g�p�p�C�v���C������
	spriteCommon.pipelineSet = PipelineSprite(dev);

	//���s���e�s�񐶐�
	spriteCommon.matProjection = XMMatrixOrthographicOffCenterLH(0.0f, (float)window_width, (float)window_height, 0.0f, 0.0f, 1.0f);

	//HRESULT result = S_FALSE;

	//�f�X�N���v�^�q�[�v�𐶐�
	D3D12_DESCRIPTOR_HEAP_DESC descHeapDesc = {};
	descHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
	descHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
	descHeapDesc.NumDescriptors = spriteSRVCount;
	result = dev->CreateDescriptorHeap(&descHeapDesc, IID_PPV_ARGS(&spriteCommon.descHeap));

	return spriteCommon;

}

//�X�v���C�g�P�̕`��
void SpriteDraw(const Sprite& sprite, ID3D12GraphicsCommandList* cmdList, const SpriteCommon& spriteCommon, ID3D12Device* dev)
{
	// ���_�o�b�t�@�̐ݒ�R�}���h
	cmdList->IASetVertexBuffers(0, 1, &sprite.vbView);

	// �萔�o�b�t�@(CBV)�̐ݒ�R�}���h
	cmdList->SetGraphicsRootConstantBufferView(0, sprite.constBuff->GetGPUVirtualAddress());

	//�V�F�[�_�[���\�[�X�r���[���Z�b�g
	cmdList->SetGraphicsRootDescriptorTable(1, CD3DX12_GPU_DESCRIPTOR_HANDLE(spriteCommon.descHeap->GetGPUDescriptorHandleForHeapStart(),
		sprite.texNumber, dev->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV)));

	//�|���S���̕`��
	cmdList->DrawInstanced(4, 1, 0, 0);

}

//�X�v���C�g�P�̕`��o�b�t�@�̓]��
void SpriteTransferVertexBuffer(const Sprite& sprite) {
	HRESULT result = S_FALSE;

	//���_�f�[�^
	VertexPosUv vertices[] = {
		{{},{0.0f,1.0f}},
		{{},{0.0f,0.0f}},
		{{},{1.0f,1.0f}},
		{{},{1.0f,0.0f}},
	};

	enum { LB, LT, RB, RT };

	vertices[LB].pos = { 0.0f,sprite.size.y,0.0f };
	vertices[LT].pos = { 0.0f,0.0f,0.0f };
	vertices[RB].pos = { sprite.size.x,sprite.size.y,0.0f };
	vertices[RT].pos = { sprite.size.x,0.0f,0.0f };

	VertexPosUv* vertMap = nullptr;
	result = sprite.vertBuff->Map(0, nullptr, (void**)&vertMap);
	memcpy(vertMap, vertices, sizeof(vertices));
	sprite.vertBuff->Unmap(0, nullptr);
}

//�X�v���C�g����
Sprite SpriteCreate(ID3D12Device* dev, int window_width, int window_height, UINT texNumber, const SpriteCommon& spriteCommon)
{
	HRESULT result = S_FALSE;

	//�V�����X�v���C�g�����
	Sprite sprite{};

	//���_�f�[�^
	VertexPosUv vertices[] = {
		{{	0.0f, 100.0f,	0.0f},{0.0f,1.0f}},
		{{	0.0f,	0.0f,	0.0f},{0.0f,0.0f}},
		{{100.0f, 100.0f,	0.0f},{1.0f,1.0f}},
		{{100.0f,	0.0f,	0.0f},{1.0f,0.0f}},
	};

	// �q�[�v�v���p�e�B
	CD3DX12_HEAP_PROPERTIES heapPropsVertexBuffer = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	// ���\�[�X�ݒ�
	CD3DX12_RESOURCE_DESC resourceDescVertexBuffer = CD3DX12_RESOURCE_DESC::Buffer(sizeof(VertexPosUv));

	//�e�N�X�`���ԍ����R�s�[
	sprite.texNumber = texNumber;

	//���_�o�b�t�@����
	result = dev->CreateCommittedResource(
		&heapPropsVertexBuffer, // �q�[�v�ݒ�
		D3D12_HEAP_FLAG_NONE,
		&resourceDescVertexBuffer, // ���\�[�X�ݒ�
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&sprite.vertBuff));
	assert(SUCCEEDED(result));

	if (spriteCommon.texBuff[sprite.texNumber]) {
		//�e�N�X�`�����擾
		D3D12_RESOURCE_DESC resDesc = spriteCommon.texBuff[sprite.texNumber]->GetDesc();
		//�X�v���C�g�̑傫�����摜�̉𑜓x�ɍ��킹��
		sprite.size = { (float)resDesc.Width,(float)resDesc.Height };
	}
	//���_�o�b�t�@�f�[�^�]��
	SpriteTransferVertexBuffer(sprite);

	//���_�o�b�t�@�ւ̃f�[�^�]��
	VertexPosUv* vertMap = nullptr;
	result = sprite.vertBuff->Map(0, nullptr, (void**)&vertMap);
	memcpy(vertMap, vertices, sizeof(vertices));
	sprite.vertBuff->Unmap(0, nullptr);

	// ���_�o�b�t�@�r���[�̍쐬
	// GPU���z�A�h���X
	sprite.vbView.BufferLocation = sprite.vertBuff->GetGPUVirtualAddress();
	// ���_�o�b�t�@�̃T�C�Y
	sprite.vbView.SizeInBytes = sizeof(vertices);
	// ���_1���̃f�[�^�T�C�Y
	sprite.vbView.StrideInBytes = sizeof(vertices[0]);

	// �q�[�v�v���p�e�B
	CD3DX12_HEAP_PROPERTIES heapPropsConstantBuffer = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	// ���\�[�X�ݒ�
	CD3DX12_RESOURCE_DESC resourceDescConstantBuffer = CD3DX12_RESOURCE_DESC::Buffer((sizeof(ConstBufferData) + 0xff) & ~0xff);

	// �萔�o�b�t�@�̐���
	result = dev->CreateCommittedResource(
		&heapPropsConstantBuffer, // �q�[�v�ݒ�
		D3D12_HEAP_FLAG_NONE,
		&resourceDescConstantBuffer, // ���\�[�X�ݒ�
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&sprite.constBuff));
	assert(SUCCEEDED(result));

	// �萔�o�b�t�@�Ƀf�[�^�]��
	ConstBufferData* constMap = nullptr;
	result = sprite.constBuff->Map(0, nullptr, (void**)&constMap); // �}�b�s���O
	constMap->color = XMFLOAT4(1, 1, 1, 1);
	assert(SUCCEEDED(result));

	//���s���e�s��
	constMap->mat = XMMatrixOrthographicOffCenterLH(0.0f, window_width, window_height, 0.0f, 0.0f, 1.0f);
	sprite.constBuff->Unmap(0, nullptr);

	return sprite;
}

//�X�v���C�g�P�̍X�V
void SpriteUpdate(Sprite& sprite, const SpriteCommon& spriteCommon)
{
	sprite.matWorld = XMMatrixIdentity();

	sprite.matWorld *= XMMatrixRotationZ(XMConvertToRadians(sprite.rotation));

	sprite.matWorld *= XMMatrixTranslation(sprite.position.x, sprite.position.y, sprite.position.z);


	// �萔�o�b�t�@�Ƀf�[�^�]��
	ConstBufferData* constMap = nullptr;
	HRESULT result = sprite.constBuff->Map(0, nullptr, (void**)&constMap); // �}�b�s���O
	constMap->mat = sprite.matWorld * spriteCommon.matProjection;
	sprite.constBuff->Unmap(0, nullptr);

}

//�X�v���C�g���ʃO���t�B�b�N�R�}���h�̃Z�b�g
void SpriteCommonBeginDraw(const SpriteCommon& spritecommon, ID3D12GraphicsCommandList* cmdList)
{
	// �p�C�v���C���X�e�[�g�ƃ��[�g�V�O�l�`���̐ݒ�R�}���h
	cmdList->SetPipelineState(spritecommon.pipelineSet.pipelinestate.Get());
	cmdList->SetGraphicsRootSignature(spritecommon.pipelineSet.rootsignature.Get());

	// �v���~�e�B�u�`��̐ݒ�R�}���h
	cmdList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP); // �O�p�`���X�g

	//�e�N�X�`���p�ŃX�N���v�^�q�[�v�̐ݒ�
	ID3D12DescriptorHeap* ppHeaps[] = { spritecommon.descHeap.Get() };
	cmdList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
}

//�X�v���C�g���ʃe�N�X�`���ǂݍ���
void SpriteCommonLoadTexture(SpriteCommon& spriteCommon, UINT texnumber, const wchar_t* filename, ID3D12Device* dev) {

	assert(texnumber <= spriteSRVCount - 1);

	HRESULT result;
	TexMetadata metadata{};
	ScratchImage scratchImg{};

	// WIC�e�N�X�`���̃��[�h
	result = LoadFromWICFile(filename, WIC_FLAGS_NONE, &metadata, scratchImg);
	assert(SUCCEEDED(result));

	ScratchImage mipChain{};
	// �~�b�v�}�b�v����
	result = GenerateMipMaps(
		scratchImg.GetImages(), scratchImg.GetImageCount(), scratchImg.GetMetadata(),
		TEX_FILTER_DEFAULT, 0, mipChain);
	if (SUCCEEDED(result)) {
		scratchImg = std::move(mipChain);
		metadata = scratchImg.GetMetadata();
	}

	// �ǂݍ��񂾃f�B�t���[�Y�e�N�X�`����SRGB�Ƃ��Ĉ���
	metadata.format = MakeSRGB(metadata.format);

	// ���\�[�X�ݒ�
	CD3DX12_RESOURCE_DESC texresDesc = CD3DX12_RESOURCE_DESC::Tex2D(
		metadata.format, metadata.width, (UINT)metadata.height, (UINT16)metadata.arraySize,
		(UINT16)metadata.mipLevels);

	// �q�[�v�v���p�e�B
	CD3DX12_HEAP_PROPERTIES heapProps =
		CD3DX12_HEAP_PROPERTIES(D3D12_CPU_PAGE_PROPERTY_WRITE_BACK, D3D12_MEMORY_POOL_L0);

	// �e�N�X�`���p�o�b�t�@�̐���
	result = dev->CreateCommittedResource(
		&heapProps, D3D12_HEAP_FLAG_NONE, &texresDesc,
		D3D12_RESOURCE_STATE_GENERIC_READ, // �e�N�X�`���p�w��
		nullptr, IID_PPV_ARGS(&spriteCommon.texBuff[texnumber]));
	assert(SUCCEEDED(result));

	// �e�N�X�`���o�b�t�@�Ƀf�[�^�]��
	for (size_t i = 0; i < metadata.mipLevels; i++) {
		const Image* img = scratchImg.GetImage(i, 0, 0); // ���f�[�^���o
		result = spriteCommon.texBuff[texnumber]->WriteToSubresource(
			(UINT)i,
			nullptr,              // �S�̈�փR�s�[
			img->pixels,          // ���f�[�^�A�h���X
			(UINT)img->rowPitch,  // 1���C���T�C�Y
			(UINT)img->slicePitch // 1���T�C�Y
		);
		assert(SUCCEEDED(result));
	}

	// �V�F�[�_���\�[�X�r���[�쐬
	D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc{}; // �ݒ�\����
	D3D12_RESOURCE_DESC resDesc = spriteCommon.texBuff[texnumber]->GetDesc();

	srvDesc.Format = resDesc.Format;
	srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
	srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;//2D�e�N�X�`��
	srvDesc.Texture2D.MipLevels = 1;

	dev->CreateShaderResourceView(spriteCommon.texBuff[texnumber].Get(), //�r���[�Ɗ֘A�t����o�b�t�@
		&srvDesc, //�e�N�X�`���ݒ���
		CD3DX12_CPU_DESCRIPTOR_HANDLE(spriteCommon.descHeap->GetCPUDescriptorHandleForHeapStart(), texnumber, dev->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV))
	);

	//return S_OK;
}

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


	////�X�v���C�g���ʕ��̏�����
	//spriteCommon = new SpriteCommon();
	//spriteCommon->Initialize(dxCommon);

//��ՃV�X�e���̏�����

//�ŏ��̃V�[���̏�����
	//�e�L�X�g
	//�X�v���C�g���ʃf�[�^
	SpriteCommon spritecommon;
	//�X�v���C�g���ʃf�[�^����
	spritecommon = SpriteCommonCreate(dxCommon->GetDevice(), winApp->window_width, winApp->window_height);

	//�X�v���C�g���ʃe�N�X�`���ǂݍ���
	SpriteCommonLoadTexture(spritecommon, 0, L"Resources/title.png", dxCommon->GetDevice());	//�^�C�g������
	//�������
	SpriteCommonLoadTexture(spritecommon, 1, L"Resources/tutorial.png", dxCommon->GetDevice());			//�������
	//�Q�[���I�[�o�[
	SpriteCommonLoadTexture(spritecommon, 2, L"Resources/gameover.png", dxCommon->GetDevice());		//�Q�[���I�[�o�[�̕���
	//�X�e�[�W�N���A
	SpriteCommonLoadTexture(spritecommon, 3, L"Resources/clear.png", dxCommon->GetDevice());

	//�X�v���C�g
	Sprite titleSprite;			//�^�C�g��
	Sprite tutorialSprite;		//�������
	Sprite gameoverSprite;		//�Q�[���I�[�o�[
	Sprite stageClearSprite;	//�X�e�[�W�N���A

	//�^�C�g��
	//�X�v���C�g�ɉ��Ԃ̃e�N�X�`�����g����
	titleSprite.texNumber = 0;
	//�X�v���C�g�̐���
	titleSprite = SpriteCreate(dxCommon->GetDevice(), winApp->window_width, winApp->window_height, titleSprite.texNumber, spritecommon);
	//�T�C�Y
	titleSprite.size = { winApp->window_width, winApp->window_height };
	//���_�o�b�t�@�ɔ��f
	SpriteTransferVertexBuffer(titleSprite);

	//�������
	//�X�v���C�g�ɉ��Ԃ̃e�N�X�`�����g����
	tutorialSprite.texNumber = 1;
	//�X�v���C�g�̐���
	tutorialSprite = SpriteCreate(dxCommon->GetDevice(), winApp->window_width, winApp->window_height, tutorialSprite.texNumber, spritecommon);
	//�T�C�Y
	tutorialSprite.size = { winApp->window_width, winApp->window_height };
	//���_�o�b�t�@�ɔ��f
	SpriteTransferVertexBuffer(tutorialSprite);

	//�Q�[���I�[�o�[
	//�X�v���C�g�ɉ��Ԃ̃e�N�X�`�����g����
	gameoverSprite.texNumber = 2;
	//�X�v���C�g�̐���
	gameoverSprite = SpriteCreate(dxCommon->GetDevice(), winApp->window_width, winApp->window_height, gameoverSprite.texNumber, spritecommon);
	//�T�C�Y
	gameoverSprite.size = { winApp->window_width, winApp->window_height };
	//���_�o�b�t�@�ɔ��f
	SpriteTransferVertexBuffer(gameoverSprite);

	//�X�e�[�W�N���A
	//�X�v���C�g�ɉ��Ԃ̃e�N�X�`�����g����
	stageClearSprite.texNumber = 3;
	//�X�v���C�g�̐���
	stageClearSprite = SpriteCreate(dxCommon->GetDevice(), winApp->window_width, winApp->window_height, stageClearSprite.texNumber, spritecommon);
	//�T�C�Y
	stageClearSprite.size = { winApp->window_width, winApp->window_height };
	//���_�o�b�t�@�ɔ��f
	SpriteTransferVertexBuffer(stageClearSprite);

	PipelineSet spritePipelineSet = PipelineSprite(dxCommon->GetDevice());

	//OBJ���烂�f���f�[�^��ǂݍ���
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
	//��
	XMFLOAT3 minModel3 = {}, maxModel3 = {};
	Model* model3 = Model::LoadFromObj("redcube", minModel3, maxModel3);
	minModel3 = model3->GetminModel();
	maxModel3 = model3->GetmaxModel();
	//��
	XMFLOAT3 minModel4 = {}, maxModel4 = {};
	Model* model4 = Model::LoadFromObj("wallcube", minModel4, maxModel4);
	minModel4 = model4->GetminModel();
	maxModel4 = model4->GetmaxModel();


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


	//��
	const int wallnum = 70;
	Object3d* wall[wallnum];
	float wallSize = 2.0f;
	for (int i = 0; i < wallnum; i++) {
		wall[i] = Object3d::Create();
		//�I�u�W�F�N�g�Ƀ��f����R�Â���
		wall[i]->SetModel(model4);
		wall[i]->SetScale({ wallSize,wallSize,wallSize });
	}

	//���ړ���
	const int besideWallnum = 20;
	Object3d* besideWall[besideWallnum];
	bool isLeftMove[besideWallnum];
	for (int i = 0; i < besideWallnum; i++) {
		besideWall[i] = Object3d::Create();
		besideWall[i]->SetModel(model4);
		besideWall[i]->SetScale({ wallSize,wallSize,wallSize });
		isLeftMove[i] = false;
	}
	//�c�ړ���
	const int verticalWallnum =20;
	Object3d* verticalWall[verticalWallnum];
	bool isUpMove[verticalWallnum];
	for (int i = 0; i < verticalWallnum; i++) {
		verticalWall[i] = Object3d::Create();
		verticalWall[i]->SetModel(model4);
		verticalWall[i]->SetScale({ wallSize,wallSize,wallSize });
		isUpMove[i] = false;
	}

	//��
	Object3d* floor;
	floor = Object3d::Create();
	floor->SetModel(model3);
	floor->SetScale({ 30,1,3000 });
	floor->SetPosition({ 0,-15,0 });

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

		switch (scene)
		{
		case title:
			//�X�v���C�g
			SpriteUpdate(titleSprite, spritecommon);
			//�X�y�[�X�����ꂽ��
			if (input->TriggerKey(DIK_SPACE)) {
				//������
				isDead = 0;
				Player->SetPosition({ 0, 0, 0 });
				eye.z = -30;
				target.z = 0;
				isStart = false;
				isGoal = false;

				//�����Ȃ���
				wall[0]->SetPosition({ wallSize * -5, wallSize * 0, wallSize * 100 });
				wall[1]->SetPosition({ wallSize * 0, wallSize * 0, wallSize * 100 });
				wall[2]->SetPosition({ wallSize * 5, wallSize * 0, wallSize * 100 });

				wall[3]->SetPosition({ wallSize * 0, wallSize * 5, wallSize * 150 });
				wall[4]->SetPosition({ wallSize * 0, wallSize * 0, wallSize * 150 });
				wall[5]->SetPosition({ wallSize * 0, wallSize * 3, wallSize * 150 });

				wall[6]->SetPosition({ wallSize * -10, wallSize * 0, wallSize * 250 });
				wall[7]->SetPosition({ wallSize * -5, wallSize * 0, wallSize * 250 });
				wall[8]->SetPosition({ wallSize * 5, wallSize * 0, wallSize * 250 });
				wall[9]->SetPosition({ wallSize * 10, wallSize * 0, wallSize * 250 });

				wall[10]->SetPosition({ wallSize * -5, wallSize * -5, wallSize * 550 });
				wall[11]->SetPosition({ wallSize * 0, wallSize * 0, wallSize * 550 });
				wall[12]->SetPosition({ wallSize * 5, wallSize * 5, wallSize * 550 });

				wall[13]->SetPosition({ wallSize * -5, wallSize * 5, wallSize * 650 });
				wall[14]->SetPosition({ wallSize * 0, wallSize * 0, wallSize * 650 });
				wall[15]->SetPosition({ wallSize * 5, wallSize * -5, wallSize * 650 });

				wall[16]->SetPosition({ wallSize * -5, wallSize * 0, wallSize * 700 });
				wall[17]->SetPosition({ wallSize * 0, wallSize * -5, wallSize * 700 });
				wall[18]->SetPosition({ wallSize * 0, wallSize * 5, wallSize * 700 });
				wall[19]->SetPosition({ wallSize * 5, wallSize * 0, wallSize * 700 });

				wall[20]->SetPosition({ wallSize * -5, wallSize * -5, wallSize * 800 });
				wall[21]->SetPosition({ wallSize * -5, wallSize * 5, wallSize * 800 });
				wall[22]->SetPosition({ wallSize * 0, wallSize * 5, wallSize * 800 });
				wall[23]->SetPosition({ wallSize * 0, wallSize * 0, wallSize * 800 });
				wall[24]->SetPosition({ wallSize * 5, wallSize * -5, wallSize * 800 });
				wall[25]->SetPosition({ wallSize * 5, wallSize * 0, wallSize * 800 });

				wall[26]->SetPosition({ wallSize * -5, wallSize * 0, wallSize * 1000 });
				wall[27]->SetPosition({ wallSize * 0, wallSize * -5, wallSize * 1000 });
				wall[28]->SetPosition({ wallSize * 0, wallSize * 5, wallSize * 1000 });
				wall[29]->SetPosition({ wallSize * 5, wallSize * 0, wallSize * 1000 });

				wall[30]->SetPosition({ wallSize * 0, wallSize * 0, wallSize * 1010 });
				wall[31]->SetPosition({ wallSize * 1, wallSize * 1, wallSize * 1020 });
				wall[32]->SetPosition({ wallSize * 2, wallSize * 2, wallSize * 1030 });
				wall[33]->SetPosition({ wallSize * 3, wallSize * 3, wallSize * 1040 });
				wall[34]->SetPosition({ wallSize * 4, wallSize * 4, wallSize * 1050 });
				wall[35]->SetPosition({ wallSize * 5, wallSize * 5, wallSize * 1060 });
				wall[36]->SetPosition({ wallSize * 4, wallSize * -1, wallSize * 1070 });
				wall[37]->SetPosition({ wallSize * 3, wallSize * -2, wallSize * 1080 });
				wall[38]->SetPosition({ wallSize * 2, wallSize * -3, wallSize * 1090 });
				wall[39]->SetPosition({ wallSize * 1, wallSize * -4, wallSize * 1100 });
				wall[40]->SetPosition({ wallSize * 0, wallSize * -5, wallSize * 1110 });
				wall[41]->SetPosition({ wallSize * -1, wallSize * -4, wallSize * 1120 });
				wall[42]->SetPosition({ wallSize * -2, wallSize * -3, wallSize * 1130 });
				wall[43]->SetPosition({ wallSize * -3, wallSize * -2, wallSize * 1140 });
				wall[44]->SetPosition({ wallSize * -4, wallSize * -1, wallSize * 1150 });
				wall[45]->SetPosition({ wallSize * -5, wallSize * 0, wallSize * 1160 });
				wall[46]->SetPosition({ wallSize * -4, wallSize * 1, wallSize * 1170 });
				wall[47]->SetPosition({ wallSize * -3, wallSize * 2, wallSize * 1180 });
				wall[48]->SetPosition({ wallSize * -2, wallSize * 3, wallSize * 1190 });
				wall[49]->SetPosition({ wallSize * -1, wallSize * 4, wallSize * 1200 });
				wall[50]->SetPosition({ wallSize * 0, wallSize * 5, wallSize * 1210 });
				wall[51]->SetPosition({ wallSize * 1, wallSize * 4, wallSize * 1220 });
				wall[52]->SetPosition({ wallSize * 2, wallSize * 3, wallSize * 1230 });
				wall[53]->SetPosition({ wallSize * 3, wallSize * 2, wallSize * 1240 });
				wall[54]->SetPosition({ wallSize * 4, wallSize * 1, wallSize * 1250 });
				wall[55]->SetPosition({ wallSize * 5, wallSize * 0, wallSize * 1260 });
				wall[56]->SetPosition({ wallSize * 4, wallSize * 1, wallSize * 1270 });
				wall[57]->SetPosition({ wallSize * 3, wallSize * 2, wallSize * 1280 });
				wall[58]->SetPosition({ wallSize * 2, wallSize * 3, wallSize * 1290 });
				wall[59]->SetPosition({ wallSize * 1, wallSize * 4, wallSize * 1300 });
				wall[60]->SetPosition({ wallSize * 0, wallSize * 5, wallSize * 1310 });
				wall[61]->SetPosition({ wallSize * -1, wallSize * 4, wallSize * 1320 });
				wall[62]->SetPosition({ wallSize * -2, wallSize * 3, wallSize * 1330 });
				wall[63]->SetPosition({ wallSize * -3, wallSize * 2, wallSize * 1340 });
				wall[64]->SetPosition({ wallSize * -4, wallSize * 1, wallSize * 1350 });
				wall[65]->SetPosition({ wallSize * -5, wallSize * 0, wallSize * 1360 });
				wall[66]->SetPosition({ wallSize * -4, wallSize * -1, wallSize * 1370 });
				wall[67]->SetPosition({ wallSize * -3, wallSize * -2, wallSize * 1380 });
				wall[68]->SetPosition({ wallSize * -2, wallSize * -3, wallSize * 1390 });
				wall[69]->SetPosition({ wallSize * -1, wallSize * -4, wallSize * 1400 });
				
				//���ړ��̕�
				besideWall[0]->SetPosition({ wallSize * -5,wallSize * 0,wallSize * 350 });
				besideWall[1]->SetPosition({ wallSize * 0,wallSize * 5,wallSize * 350 });
				besideWall[2]->SetPosition({ wallSize * 5,wallSize * -5,wallSize * 350 });

				besideWall[3]->SetPosition({ wallSize * -5,wallSize * 0,wallSize * 550 });
				besideWall[4]->SetPosition({ wallSize * 0,wallSize * 5,wallSize * 550 });
				besideWall[5]->SetPosition({ wallSize * 5,wallSize * -5,wallSize * 550 });

				besideWall[6]->SetPosition({ wallSize * -5,wallSize * 0,wallSize * 900 });
				besideWall[7]->SetPosition({ wallSize * 0,wallSize * 5,wallSize * 900 });

				besideWall[8]->SetPosition({ wallSize * 5,wallSize * -5,wallSize * 1000 });
				besideWall[9]->SetPosition({ wallSize * -5,wallSize * 0,wallSize * 1000 });

				besideWall[10]->SetPosition({ wallSize * -5,wallSize * 0,wallSize * 1050 });
				besideWall[11]->SetPosition({ wallSize * 0,wallSize * 5,wallSize * 1100 });
				besideWall[12]->SetPosition({ wallSize * 5,wallSize * -5,wallSize * 1150 });

				besideWall[13]->SetPosition({ wallSize * -5,wallSize * 0,wallSize * 1200 });
				besideWall[14]->SetPosition({ wallSize * 0,wallSize * 5,wallSize * 1250 });
				besideWall[15]->SetPosition({ wallSize * 5,wallSize * -5,wallSize * 1300 });

				besideWall[16]->SetPosition({ wallSize * -5,wallSize * 0,wallSize * 1400 });
				besideWall[17]->SetPosition({ wallSize * 0,wallSize * 5,wallSize * 1450 });

				besideWall[18]->SetPosition({ wallSize * 5,wallSize * -5,wallSize * 1200 });
				besideWall[19]->SetPosition({ wallSize * -5,wallSize * 0,wallSize * 1300 });

				//�c�ړ��̕�
				verticalWall[0]->SetPosition({ wallSize * 0,wallSize * 0,wallSize * 450 });
				verticalWall[1]->SetPosition({ wallSize * -5,wallSize * -2,wallSize * 450 });
				verticalWall[2]->SetPosition({ wallSize * 5,wallSize * 3,wallSize * 450 });

				verticalWall[3]->SetPosition({ wallSize * 5,wallSize * 0,wallSize * 650 });
				verticalWall[4]->SetPosition({ wallSize * -5,wallSize * -2,wallSize * 650 });
				verticalWall[5]->SetPosition({ wallSize * 0,wallSize * 3,wallSize * 650 });

				verticalWall[6]->SetPosition({ wallSize * -5,wallSize * 0,wallSize * 900 });
				verticalWall[7]->SetPosition({ wallSize * 5,wallSize * -2,wallSize * 900 });

				verticalWall[8]->SetPosition({ wallSize * 5,wallSize * 3,wallSize * 1000 });
				verticalWall[9]->SetPosition({ wallSize * 0,wallSize * 0,wallSize * 1000 });

				verticalWall[10]->SetPosition({ wallSize * 0,wallSize * 0,wallSize * 1050 });
				verticalWall[11]->SetPosition({ wallSize * -5,wallSize * -2,wallSize * 1100 });
				verticalWall[12]->SetPosition({ wallSize * 5,wallSize * 3,wallSize * 1150 });
				verticalWall[13]->SetPosition({ wallSize * 5,wallSize * 0,wallSize * 1200 });
				verticalWall[14]->SetPosition({ wallSize * -5,wallSize * -2,wallSize * 1250 });
				verticalWall[15]->SetPosition({ wallSize * 0,wallSize * 3,wallSize * 1300 });
				verticalWall[16]->SetPosition({ wallSize * -5,wallSize * 0,wallSize * 1350 });
				verticalWall[17]->SetPosition({ wallSize * 5,wallSize * -2,wallSize * 1400 });
				verticalWall[18]->SetPosition({ wallSize * 5,wallSize * 3,wallSize * 1450 });
				verticalWall[19]->SetPosition({ wallSize * 4,wallSize * 0,wallSize * 1350 });
				scene = game;
			}
			break;

		case game:
			//�������
			if (isStart == false) {
				//�X�v���C�g
				SpriteUpdate(tutorialSprite, spritecommon);
				if (input->TriggerKey(DIK_SPACE)) {
					isStart = true;
				}
			}
			else if (isStart == true) {
				if (isDead == false) {
					playerPosition = Player->GetPosition();
					// �I�u�W�F�N�g�ړ�
					if (input->PushKey(DIK_RIGHT) || input->PushKey(DIK_LEFT) || input->PushKey(DIK_A) || input->PushKey(DIK_D))
					{
						// ���݂̍��W���擾
						playerPosition = Player->GetPosition();
						// �ړ���̍��W���v�Z
						if (playerPosition.x < 10.0f) {
							if (input->PushKey(DIK_RIGHT) || input->PushKey(DIK_D)) { playerPosition.x += 0.2f; }
						}
						if (playerPosition.x > -10.0f) {
							if (input->PushKey(DIK_LEFT) || input->PushKey(DIK_A)) { playerPosition.x -= 0.2f; }
						}
						// ���W�̕ύX�𔽉f
						Player->SetPosition(playerPosition);
					}
					playerPosition.z += 1.0f;
					//�㉺�ړ��̏���
					if (input->PushKey(DIK_SPACE)) {

						if (upSpeed <= 0.5) {
							upSpeed += 0.05f;
						}
					}
					else {

						if (upSpeed > -0.5) {
							upSpeed -= 0.05f;
						}
						else {
							upSpeed = -0.5f;
						}
					}
					playerPosition.y += upSpeed;
					if (playerPosition.y >= 10.0f) {
						playerPosition.y = 10.0f;
					}

					Player->SetPosition(playerPosition);
					eye.z += 1.0f;
					target.z += 1.0f;

					//�J����
					//�r���[�ϊ��s��
					matView = DirectX::XMMatrixLookAtLH(XMLoadFloat3(&eye), XMLoadFloat3(&target), XMLoadFloat3(&up));

					////�V��
					//skyCylinder->Update(matView);

					//���ړ��̕�
					XMFLOAT3 besidePosition;
					for (int i = 0; i < besideWallnum; i++) {
						if (isLeftMove[i] == false) {
							besidePosition = besideWall[i]->GetPosition();
							besidePosition.x += 0.5;
							besideWall[i]->SetPosition(besidePosition);
							if (besidePosition.x >= 10.0) {
								isLeftMove[i] = true;
							}
						}
						else if (isLeftMove[i] == true) {
							besidePosition = besideWall[i]->GetPosition();
							besidePosition.x -= 0.5;
							besideWall[i]->SetPosition(besidePosition);
							if (besidePosition.x <= -10.0) {
								isLeftMove[i] = false;
							}
						}
						besideWall[i]->Update(matView);
					}

					//�c�ړ��̕�
					XMFLOAT3 verticalPosition;
					for (int i = 0; i < verticalWallnum; i++) {
						if (isUpMove[i] == true) {
							verticalPosition = verticalWall[i]->GetPosition();
							verticalPosition.y += 0.5;
							verticalWall[i]->SetPosition(verticalPosition);
							if (verticalPosition.y >= 10.0) {
								isUpMove[i] = false;
							}
						}
						else if (isUpMove[i] == false) {
							verticalPosition = verticalWall[i]->GetPosition();
							verticalPosition.y -= 0.5;
							verticalWall[i]->SetPosition(verticalPosition);
							if (verticalPosition.y <= -15.0) {
								isUpMove[i] = true;
							}
						}
						verticalWall[i]->Update(matView);
					}

					//��
					for (int i = 0; i < wallnum; i++) {
						wall[i]->Update(matView);
					}


					//��ՃV�X�e���̍X�V
					Player->Update(matView);

					floor->Update(matView);

					//�����蔻��
					for (int i = 0; i < wallnum; i++) {
						if (CheakCollision(Player->GetPosition(), wall[i]->GetPosition(), Player->GetScale(), wall[i]->GetScale(), minModel2, minModel3, maxModel2, maxModel3)) {
							isDead = true;
						}
					}
					//�����蔻��
					for (int i = 0; i < besideWallnum; i++) {
						if (CheakCollision(Player->GetPosition(), besideWall[i]->GetPosition(), Player->GetScale(), besideWall[i]->GetScale(), minModel2, minModel3, maxModel2, maxModel3)) {
							isDead = true;
						}
					}
					//�����蔻��
					for (int i = 0; i < verticalWallnum; i++) {
						if (CheakCollision(Player->GetPosition(), verticalWall[i]->GetPosition(), Player->GetScale(), verticalWall[i]->GetScale(), minModel2, minModel3, maxModel2, maxModel3)) {
							isDead = true;
						}
					}
					//�����蔻��
					if (CheakCollision(Player->GetPosition(), floor->GetPosition(), Player->GetScale(), floor->GetScale(), minModel2, minModel3, maxModel2, maxModel3)) {
						isDead = true;
					}
					//�S�[��
					if (Player->GetPosition().z>=3000) {
  						isGoal = true;
					}

				}
				else if (isDead == true) {
					scene = gameover;
				}
				if (isGoal == true) {
					scene = clear;
				}
			}
			break;
		case clear:
			SpriteUpdate(stageClearSprite, spritecommon);
			if (input->TriggerKey(DIK_SPACE)) {
				scene = title;
			}
			break;

		case gameover:
			SpriteUpdate(gameoverSprite, spritecommon);
			if (input->TriggerKey(DIK_SPACE)) {
				scene = title;
			}
			break;
		}




		//// 4.�`��R�}���h��������

		dxCommon->PreDraw();

		//�ŏ��̃V�[���̕`��

		switch (scene)
		{
		case title:

			break;
		case game:
			//3d�I�u�W�F�N�g�`��O����
			Object3d::PreDraw(dxCommon->GetCommandlist());

			//3d�I�u�W�F�N�g�̕`��
			/*skyCylinder->Draw();*/

			//�v���C���[�̕`��
			Player->Draw();
			//��
			floor->Draw();

			//��
			for (int i = 0; i < wallnum; i++) {
				if (wall[i]->GetPosition().z + maxModel3.z >= Player->GetPosition().z - minModel2.z) {
					wall[i]->Draw();
				}
			}
			//���ړ���
			for (int i = 0; i < besideWallnum; i++) {
				if (besideWall[i]->GetPosition().z + maxModel3.z >= Player->GetPosition().z - minModel2.z) {
					besideWall[i]->Draw();
				}
			}
			//�c�ړ���
			for (int i = 0; i < verticalWallnum; i++) {
				if (verticalWall[i]->GetPosition().z + maxModel3.z >= Player->GetPosition().z - minModel2.z) {
					verticalWall[i]->Draw();
				}
			}
			//3d�I�u�W�F�N�g�`��㏈��
			Object3d::PostDraw();
			break;
		case clear:
			break;
		case gameover:
			break;
		}

		//�X�v���C�g���ʃR�}���h
		SpriteCommonBeginDraw(spritecommon, dxCommon->GetCommandlist());
		switch (scene)
		{
		case title:
			SpriteDraw(titleSprite, dxCommon->GetCommandlist(), spritecommon, dxCommon->GetDevice());
			break;
		case game:
			if (isStart == false) {
				SpriteDraw(tutorialSprite, dxCommon->GetCommandlist(), spritecommon, dxCommon->GetDevice());
			}
			break;
		case clear:
			SpriteDraw(stageClearSprite, dxCommon->GetCommandlist(), spritecommon, dxCommon->GetDevice());
			break;
		case gameover:
			SpriteDraw(gameoverSprite, dxCommon->GetCommandlist(), spritecommon, dxCommon->GetDevice());
			break;
		}


		//�X�v���C�g�O����

		/*sprite->Draw();*/

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
	//3d�I�u�W�F�N�g���
	delete Player;
	//�V�����
	delete skyCylinder;
	//3D���f�����
	delete model;
	delete model2;
	delete model3;
	delete model4;
	//�ǉ��
	for (int i = 0; i < wallnum; i++) {
		delete wall[i];
	}
	//���ړ��ǉ��
	for (int i = 0; i < besideWallnum; i++) {
		delete besideWall[i];
	}
	//�c�ړ����
	for (int i = 0; i < verticalWallnum; i++) {
		delete verticalWall[i];
	}
	//���J��
	delete floor;

	//delete spriteCommon;

	//��ՃV�X�e���̏I��

	return 0;
}

