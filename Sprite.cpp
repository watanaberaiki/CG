//#include"Sprite.h"
//
//void Sprite::Initialize(SpriteCommon* spritecommon_)
//{
//	spritecomon = spritecommon_;
//
//	// ���_�o�b�t�@�̐ݒ�
//	D3D12_HEAP_PROPERTIES heapProp{}; // �q�[�v�ݒ�
//	heapProp.Type = D3D12_HEAP_TYPE_UPLOAD; // GPU�ւ̓]���p
//
//	// ���_�o�b�t�@�̐���
//	result = spritecomon->GetDxCommon()->GetDevice()->CreateCommittedResource(
//		&heapProp, // �q�[�v�ݒ�
//		D3D12_HEAP_FLAG_NONE,
//		&spritecomon->GetResourceDesc(), // ���\�[�X�ݒ�
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&vertBuff));
//	assert(SUCCEEDED(result));
//
//	// GPU��̃o�b�t�@�ɑΉ��������z������(���C����������)���擾
//	result = vertBuff->Map(0, nullptr, (void**)&vertMap);
//	assert(SUCCEEDED(result));
//	// �S���_�ɑ΂���
//	for (int i = 0; i < _countof(vertices); i++) {
//		vertMap[i] = vertices[i]; // ���W���R�s�[
//	}
//	// �q���������
//	vertBuff->Unmap(0, nullptr);
//
//	// GPU���z�A�h���X
//	vbView.BufferLocation = vertBuff->GetGPUVirtualAddress();
//	// ���_�o�b�t�@�̃T�C�Y
//	vbView.SizeInBytes = spritecomon->GetSizeVB();
//	// ���_1���̃f�[�^�T�C�Y
//	vbView.StrideInBytes = sizeof(vertices[0]);
//
//	Update();
//
//	{
//		// �q�[�v�ݒ�
//		D3D12_HEAP_PROPERTIES cbHeapProp{};
//		cbHeapProp.Type = D3D12_HEAP_TYPE_UPLOAD;                   // GPU�ւ̓]���p
//		// ���\�[�X�ݒ�
//		D3D12_RESOURCE_DESC cbResourceDesc{};
//		cbResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
//		cbResourceDesc.Width = (sizeof(ConstBufferDataTransform) + 0xff) & ~0xff;   // 256�o�C�g�A���C�������g
//		cbResourceDesc.Height = 1;
//		cbResourceDesc.DepthOrArraySize = 1;
//		cbResourceDesc.MipLevels = 1;
//		cbResourceDesc.SampleDesc.Count = 1;
//		cbResourceDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
//
//		// �萔�o�b�t�@�̐���
//		result = spritecomon->GetDxCommon()->GetDevice()->CreateCommittedResource(
//			&cbHeapProp, // �q�[�v�ݒ�
//			D3D12_HEAP_FLAG_NONE,
//			&cbResourceDesc, // ���\�[�X�ݒ�
//			D3D12_RESOURCE_STATE_GENERIC_READ,
//			nullptr,
//			IID_PPV_ARGS(&constBuffTransform));
//		assert(SUCCEEDED(result));
//
//		// �萔�o�b�t�@�̃}�b�s���O
//		result = constBuffTransform->Map(0, nullptr, (void**)&constMapTransform); // �}�b�s���O
//		assert(SUCCEEDED(result));
//	}
//
//	//���s���e�s��̌v�Z
//	constMapTransform->mat = XMMatrixIdentity();
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
//	// �ˉe�s��v�Z
//	matProjection = XMMatrixOrthographicOffCenterLH(
//		0.0f, (float)WinApp::window_width,
//		(float)WinApp::window_height, 0.0f,
//		0.0f, 1.0f);
//
//	// �萔�o�b�t�@�̐���
//	result = spritecomon->GetDxCommon()->GetDevice()->CreateCommittedResource(
//		&cbHeapProp, // �q�[�v�ݒ�
//		D3D12_HEAP_FLAG_NONE,
//		&cbResourceDesc, // ���\�[�X�ݒ�
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&constBuffMaterial));
//	assert(SUCCEEDED(result));
//
//	// �萔�o�b�t�@�̃}�b�s���O
//	result = constBuffMaterial->Map(0, nullptr, (void**)&constMapMaterial); // �}�b�s���O
//	assert(SUCCEEDED(result));
//
//	// �l���������ނƎ����I�ɓ]�������
//	constMapMaterial->color = XMFLOAT4(1, 0, 0, 0.5f);              // RGBA�Ŕ������̐�
//}
//
//void Sprite::Draw()
//{
//	matRot = XMMatrixIdentity();
//	matRot *= XMMatrixRotationZ(XMConvertToRadians(rotation));//Z�������0�x��]���Ă���
//	matTrans = XMMatrixTranslation(position.x, position.y, 0.0f);//(-50,0,0)���s�ړ�
//
//	matWorld = XMMatrixIdentity();//�ό`�����Z�b�g
//	matWorld *= matRot;//���[���h�s��ɃX�P�[�����O�𔽉f
//	matWorld *= matTrans;
//
//
//	// �萔�o�b�t�@�Ƀf�[�^�]��
//	HRESULT result = constBuffTransform->Map(0, nullptr, (void**)&constMapTransform);
//	if (SUCCEEDED(result)) {
//		constMapTransform->mat = matWorld * matProjection;	// �s��̍���	
//	}
//	result = constBuffMaterial->Map(0, nullptr, (void**)&constMapMaterial);
//	if (SUCCEEDED(result)) {
//		constMapMaterial->color = color;
//	}
//
//	spritecomon->SetTextureCommands(textureIndex_);
//
//	//���_�o�b�t�@�r���[�̐ݒ�R�}���h
//	spritecomon->GetDxCommon()->GetCommandlist()->IASetVertexBuffers(0, 1, &vbView);
//	// �萔�o�b�t�@�r���[(CBV)�̐ݒ�R�}���h
//	spritecomon->GetDxCommon()->GetCommandlist()->SetGraphicsRootConstantBufferView(0, constBuffMaterial->GetGPUVirtualAddress());
//	// �萔�o�b�t�@�r���[(CBV)�̐ݒ�R�}���h
//	spritecomon->GetDxCommon()->GetCommandlist()->SetGraphicsRootConstantBufferView(2, constBuffTransform->GetGPUVirtualAddress());
//	// �`��R�}���h
//	spritecomon->GetDxCommon()->GetCommandlist()->DrawInstanced(_countof(vertices), 1, 0, 0); // �S�Ă̒��_���g���ĕ`��
//}
//
//void Sprite::Update()
//{
//	ID3D12Resource* textureBuffer = spritecomon->GetTextureBuffer(textureIndex_);
//
//	float left = (0.0f - anchorpoint.x) * size_.x;
//	float right = (1.0f - anchorpoint.x) * size_.x;
//	float top = (0.0f - anchorpoint.x) * size_.y;
//	float bottom = (1.0f - anchorpoint.x) * size_.y;
//
//	if (isFlipX)
//	{// ���E����ւ�
//		left = -left;
//		right = -right;
//	}
//
//	if (isFlipY)
//	{// �㉺����ւ�
//		top = -top;
//		bottom = -bottom;
//	}
//
//	vertices[LB].pos = { left,	bottom,	0.0f }; // ����
//	vertices[LT].pos = { left,	top,	0.0f }; // ����
//	vertices[RB].pos = { right,	bottom,	0.0f }; // �E��
//	vertices[RT].pos = { right,	top,	0.0f }; // �E��
//
//	//�w��ԍ��̉摜���ǂݍ��ݍς݂Ȃ�
//	if (textureBuffer) {
//		//�e�N�X�`�����擾
//		D3D12_RESOURCE_DESC resDesc = textureBuffer->GetDesc();
//
//		float tex_left = textureLeftTop.x / resDesc.Width;
//		float tex_right = (textureLeftTop.x + textureSize.x) / resDesc.Width;
//		float tex_top = textureLeftTop.y / resDesc.Height;
//		float texbottom = (textureLeftTop.y + textureSize.y) / resDesc.Height;
//		//���_UV�ɔ��f����
//		vertices[LB].uv = { tex_left,texbottom };
//		vertices[LT].uv = { tex_left,tex_top };
//		vertices[RB].uv = { tex_right,texbottom };
//		vertices[RT].uv = { tex_right,tex_top };
//
//	}
//
//	result = vertBuff->Map(0, nullptr, (void**)&vertMap);
//	if (SUCCEEDED(result)) {
//		memcpy(vertMap, vertices, sizeof(vertices));
//		vertBuff->Unmap(0, nullptr);
//	}
//}
//
//void Sprite::SetPozition(const XMFLOAT2& position_)
//{
//	position = position_;
//	Update();
//}
//
//void Sprite::SetRotation(float rotation_)
//{
//	rotation = rotation_;
//	Update();
//}
//
//void Sprite::SetSize(XMFLOAT2 size)
//{
//	size_ = size;
//	Update();
//}
//
//void Sprite::SetIsFlipY(bool isFlipY)
//{
//	this->isFlipY = isFlipY;
//
//	Update();
//}
//
//void Sprite::SetIsFlipX(bool isFlipX)
//{
//	this->isFlipX = isFlipX;
//
//	Update();
//}
//
