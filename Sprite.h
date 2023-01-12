//#pragma once
//#include"SpriteCommon.h"
//#include <DirectXMath.h>
//
//using namespace DirectX;
//
//
//// ���_�f�[�^�\����
//struct Vertex
//{
//	XMFLOAT3 pos; // xyz���W
//	XMFLOAT2 uv;  // uv���W
//};
////�X�v���C�g
//class Sprite {
//public:
//	// �萔�o�b�t�@�p�f�[�^�\���́i�}�e���A���j
//	struct ConstBufferDataMaterial {
//		XMFLOAT4 color; // �F (RGBA)
//	};
//	//�萔�o�b�t�@�p�\���́i�RD�ϊ��s��j
//	struct ConstBufferDataTransform {
//		XMMATRIX mat;	//3D�ϊ��s��
//	};
//
//	//���_�ԍ�
//	enum VertexNumber {
//		LB,//����
//		LT,//����
//		RB,//�E��
//		RT,//�E��
//	};
//public:
//	//������
//	void Initialize(SpriteCommon* spritecommon_);
//
//	void Draw();
//
//	void Update();
//
//	void SetPozition(const XMFLOAT2& position_);
//
//	const XMFLOAT2& GetPosition() const { return position; }
//
//	void SetRotation(float rotation_);
//
//	float GetRotation() { return rotation; }
//
//	void SetColor(const XMFLOAT4& color_) { color = color_; }
//
//	XMFLOAT4 GetColor() { return color; }
//
//	void SetScale(const XMFLOAT3& scale_) { scale = scale_; }
//
//	XMFLOAT3 GetScale() { return scale; }
//
//	void SetAnchorPoint(const XMFLOAT2& anchorPoint_) { anchorPoint = anchorPoint_; }
//
//	XMFLOAT2 GetAnchorPoint() { return anchorPoint; }
//
//	void SetTextureIndex(uint32_t texNmb) { textureIndex_ = texNmb; }
//
//	uint32_t GetTextureIndex() { return textureIndex_; }
//
//	void SetTexSize(XMFLOAT2 texSize) { textureSize = texSize; }
//
//	XMFLOAT2 GetTexSize() { return textureSize; }
//
//	XMFLOAT2 GetSize() { return size_; }
//
//	void SetSize(XMFLOAT2 size);
//
//	/// �㉺���]�̐ݒ�
//	void SetIsFlipY(bool isFlipY);
//
//	/// ���E���]�̐ݒ�
//	void SetIsFlipX(bool isFlipX);
//
//private:
//	SpriteCommon* spritecomon;
//	HRESULT result;
//	// ���_�f�[�^
//	Vertex vertices[4] = {
//		// x      y     z       u     v
//		{{-0.4f, -0.7f, 0.0f}, {0.0f, 1.0f}}, // ����
//		{{-0.4f, +0.7f, 0.0f}, {0.0f, 0.0f}}, // ����
//		{{+0.4f, -0.7f, 0.0f}, {1.0f, 1.0f}}, // �E��
//		{{+0.4f, +0.7f, 0.0f}, {1.0f, 0.0f}}, // �E��
//	};
//
//	// ���_�o�b�t�@�r���[�̍쐬
//	D3D12_VERTEX_BUFFER_VIEW vbView{};
//
//	XMMATRIX matScale;//�X�P�[�����O�s��
//	XMMATRIX matWorld;
//	XMMATRIX matRot;//��]�s��
//	XMMATRIX  matTrans;//���s�ړ��s��
//
//	//���W
//	XMFLOAT3 scale{ 0.5f, 0.5f, 1.0f };
//
//	XMFLOAT2 size_ = { 100.0f,100.0f };
//
//	float rotation = 0.0f;
//	XMFLOAT2 position = { 0.0f, 0.0f };
//
//	XMFLOAT4 color = { 1,1,1,1 };
//
//	XMFLOAT2 anchorPoint = { 0.0f,0.0f };
//
//	ID3D12Resource* constBuffTransform = nullptr;
//	ConstBufferDataTransform* constMapTransform = nullptr;
//
//	ConstBufferDataMaterial* constMapMaterial = nullptr;
//
//	ID3D12Resource* constBuffMaterial = nullptr;
//
//	Vertex vertices_[4];
//
//	Vertex* vertMap = nullptr;
//
//	//�e�N�X�`���ԍ�
//	uint32_t textureIndex_ = 0;
//
//	//�e�N�X�`��������W
//	XMFLOAT2 textureLeftTop = { 0.0f,0.0f };
//	//�e�N�X�`���؂�o���T�C�Y
//	XMFLOAT2 textureSize = { 100.0f,100.0f };
//
//	XMMATRIX matProjection;
//
//	// �A���J�[�|�C���g
//	XMFLOAT2 anchorpoint = { 0, 0 };
//
//	// ���_�o�b�t�@�̐���
//	ID3D12Resource* vertBuff = nullptr;
//
//	// ���E���]
//	bool isFlipX = false;
//	// �㉺���]
//	bool isFlipY = false;
//};
