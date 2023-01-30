#pragma once
#include"DirectXCommon.h"
#include <DirectXTex.h>
#include <array>
#include <string>

using namespace DirectX;


//�X�v���C�g���ʕ���
class SpriteCommon {
public:
	struct Vertex
	{
		XMFLOAT3 pos; // xyz���W
		XMFLOAT2 uv;  // uv���W
	};
	// �萔�o�b�t�@�p�f�[�^�\���́i�}�e���A���j
	struct ConstBufferDataMaterial {
		XMFLOAT4 color; // �F (RGBA)
	};
	//�萔�o�b�t�@�p�\���́i�RD�ϊ��s��j
	struct ConstBufferDataTransform {
		XMMATRIX mat;	//3D�ϊ��s��
	};
public:
	//������
	void Initialize(DirectXCommon* dxcommon);

	DirectXCommon* GetDxCommon() { return dxcommon_; }

	ID3D12RootSignature* GetRootSignature() { return rootSignature; }

	ID3D12PipelineState* GetPipelineState() { return pipelineState; }

	ID3D12DescriptorHeap* GetSrvHeap() { return srvHeap; }

	D3D12_CPU_DESCRIPTOR_HANDLE GetSrvHandle() { return srvHandle; }

	UINT GetSizeVB() { return sizeVB; }

	D3D12_RESOURCE_DESC& GetResourceDesc() { return resDesc; }

	void LoadTexture(uint32_t index, const std::string& fileName);

	void SetTextureCommands(uint32_t index);

	Microsoft::WRL::ComPtr<ID3D12Resource> GetTexBuff(uint32_t index) { return texBuff[index]; }

	ID3D12Resource* GetTextureBuffer(uint32_t index)const { return texBuff[index].Get(); }

	//SRV�p�f�X�N���v�^�q�[�v
	ID3D12DescriptorHeap* srvHeap = nullptr;
private:
	// ���_�f�[�^
	Vertex vertices[4] = {
		// x      y     z       u     v
		{{-0.4f, -0.7f, 0.0f}, {0.0f, 1.0f}}, // ����
		{{-0.4f, +0.7f, 0.0f}, {0.0f, 0.0f}}, // ����
		{{+0.4f, -0.7f, 0.0f}, {1.0f, 1.0f}}, // �E��
		{{+0.4f, +0.7f, 0.0f}, {1.0f, 0.0f}}, // �E��
	};
	// SRV�̍ő��
	static const size_t kMaxSRVCount = 2056;

	DirectXCommon* dxcommon_ = nullptr;
	ID3DBlob* vsBlob = nullptr; // ���_�V�F�[�_�I�u�W�F�N�g
	ID3DBlob* psBlob = nullptr; // �s�N�Z���V�F�[�_�I�u�W�F�N�g
	ID3DBlob* errorBlob = nullptr; // �G���[�I�u�W�F�N�g
	HRESULT result;

	// ���[�g�V�O�l�`��
	ID3D12RootSignature* rootSignature;
	// �p�C�v�����X�e�[�g�̐���
	ID3D12PipelineState* pipelineState = nullptr;
	std::array<Microsoft::WRL::ComPtr<ID3D12Resource>, kMaxSRVCount>texBuff;

	//�������s�N�Z����
	const size_t textureWidth = 256;
	//�c�����s�N�Z����
	const size_t textureHeight = 256;
	//�z��̗v�f��
	const size_t imageDataCount = textureWidth * textureHeight;

	//SRV�q�[�v�̐擪�n���h�����擾
	D3D12_CPU_DESCRIPTOR_HANDLE srvHandle;

	TexMetadata metadata{};
	ScratchImage scratchImg{};
	D3D12_HEAP_PROPERTIES textureHeapProp{};
	D3D12_RESOURCE_DESC textureResourceDesc{};

	D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc{};
	// �O���t�B�b�N�X�p�C�v���C���ݒ�
	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc{};
	// �f�X�N���v�^�q�[�v�̐ݒ�
	D3D12_DESCRIPTOR_HEAP_DESC srvHeapDesc = {};

	UINT sizeVB;

	D3D12_RESOURCE_DESC resDesc{};

	//�f�t�H���g�e�N�X�`���i�[�f�B���N�g��
	static std::string kDefaultTextureDirectoryPath;

	UINT incrementSize;
};