//#include"SpriteCommon.h"
//#include <string>
//#include <d3dcompiler.h>
//
//#pragma comment(lib, "d3dcompiler.lib")
//
//
//void SpriteCommon::Initialize(DirectXCommon* dxcommon)
//{
//	assert(dxcommon);
//	dxcommon_ = dxcommon;
//
//	// ���_�f�[�^�S�̂̃T�C�Y = ���_�f�[�^����̃T�C�Y * ���_�f�[�^�̗v�f��
//	sizeVB = static_cast<UINT>(sizeof(vertices[0]) * _countof(vertices));
//
//	// ���\�[�X�ݒ�
//	resDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
//	resDesc.Width = sizeVB; // ���_�f�[�^�S�̂̃T�C�Y
//	resDesc.Height = 1;
//	resDesc.DepthOrArraySize = 1;
//	resDesc.MipLevels = 1;
//	resDesc.SampleDesc.Count = 1;
//	resDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
//	// ���_�V�F�[�_�̓ǂݍ��݂ƃR���p�C��
//	result = D3DCompileFromFile(
//		L"Resources/shaders/SpriteVS.hlsl", // �V�F�[�_�t�@�C����
//		nullptr,
//		D3D_COMPILE_STANDARD_FILE_INCLUDE, // �C���N���[�h�\�ɂ���
//		"main", "vs_5_0", // �G���g���[�|�C���g���A�V�F�[�_�[���f���w��
//		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // �f�o�b�O�p�ݒ�
//		0,
//		&vsBlob, &errorBlob);
//	// �G���[�Ȃ�
//	if (FAILED(result)) {
//		// errorBlob����G���[���e��string�^�ɃR�s�[
//		std::string error;
//		error.resize(errorBlob->GetBufferSize());
//		std::copy_n((char*)errorBlob->GetBufferPointer(),
//			errorBlob->GetBufferSize(),
//			error.begin());
//		error += "\n";
//		// �G���[���e���o�̓E�B���h�E�ɕ\��
//		OutputDebugStringA(error.c_str());
//		assert(0);
//	}
//	// �s�N�Z���V�F�[�_�̓ǂݍ��݂ƃR���p�C��
//	result = D3DCompileFromFile(
//		L"Resources/shaders/SpritePS.hlsl", // �V�F�[�_�t�@�C����
//		nullptr,
//		D3D_COMPILE_STANDARD_FILE_INCLUDE, // �C���N���[�h�\�ɂ���
//		"main", "ps_5_0", // �G���g���[�|�C���g���A�V�F�[�_�[���f���w��
//		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // �f�o�b�O�p�ݒ�
//		0,
//		&psBlob, &errorBlob);
//	// �G���[�Ȃ�
//	if (FAILED(result)) {
//		// errorBlob����G���[���e��string�^�ɃR�s�[
//		std::string error;
//		error.resize(errorBlob->GetBufferSize());
//		std::copy_n((char*)errorBlob->GetBufferPointer(),
//			errorBlob->GetBufferSize(),
//			error.begin());
//		error += "\n";
//		// �G���[���e���o�̓E�B���h�E�ɕ\��
//		OutputDebugStringA(error.c_str());
//		assert(0);
//	}
//	// ���_���C�A�E�g
//	D3D12_INPUT_ELEMENT_DESC inputLayout[] = {
//	{ // xyz���W(1�s�ŏ������ق������₷��)
//		"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,
//		D3D12_APPEND_ALIGNED_ELEMENT,
//		D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
//	},
//	{ // uv���W(1�s�ŏ������ق������₷��)
//		"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0,
//		D3D12_APPEND_ALIGNED_ELEMENT,
//		D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
//	}, // (1�s�ŏ������ق������₷��)
//	};
//
//	// �V�F�[�_�[�̐ݒ�
//	pipelineDesc.VS.pShaderBytecode = vsBlob->GetBufferPointer();
//	pipelineDesc.VS.BytecodeLength = vsBlob->GetBufferSize();
//	pipelineDesc.PS.pShaderBytecode = psBlob->GetBufferPointer();
//	pipelineDesc.PS.BytecodeLength = psBlob->GetBufferSize();
//	// �T���v���}�X�N�̐ݒ�
//	pipelineDesc.SampleMask = D3D12_DEFAULT_SAMPLE_MASK; // �W���ݒ�
//
//	// ���X�^���C�U�̐ݒ�
//	pipelineDesc.RasterizerState.CullMode = D3D12_CULL_MODE_NONE; // �J�����O���Ȃ�
//	pipelineDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID; // �|���S�����h��Ԃ�
//	pipelineDesc.RasterizerState.DepthClipEnable = true; // �[�x�N���b�s���O��L����
//
//	D3D12_RENDER_TARGET_BLEND_DESC& blenddesc = pipelineDesc.BlendState.RenderTarget[0];
//	blenddesc.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;// RBGA�S�Ẵ`�����l����`��
//
//	blenddesc.BlendEnable = true;                   // �u�����h��L���ɂ���
//	blenddesc.BlendOpAlpha = D3D12_BLEND_OP_ADD;    // ���Z
//	blenddesc.SrcBlendAlpha = D3D12_BLEND_ONE;      // �\�[�X�̒l��100% �g��
//	blenddesc.DestBlendAlpha = D3D12_BLEND_ZERO;    // �f�X�g�̒l��  0% �g��
//
//	// ����������
//	blenddesc.BlendOp = D3D12_BLEND_OP_ADD;             // ���Z
//	blenddesc.SrcBlend = D3D12_BLEND_SRC_ALPHA;         // �\�[�X�̃A���t�@�l
//	blenddesc.DestBlend = D3D12_BLEND_INV_SRC_ALPHA;
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
//	pipelineDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB; // 0~255�w���RGBA
//	pipelineDesc.SampleDesc.Count = 1; // 1�s�N�Z���ɂ�1��T���v�����O
//
//	// �f�X�N���v�^�����W�̐ݒ�
//	D3D12_DESCRIPTOR_RANGE descriptorRange{};
//	descriptorRange.NumDescriptors = 1;         //��x�̕`��Ɏg���e�N�X�`����1���Ȃ̂�1
//	descriptorRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
//	descriptorRange.BaseShaderRegister = 0;     //�e�N�X�`�����W�X�^0��
//	descriptorRange.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
//
//	// ���[�g�p�����[�^�̐ݒ�
//	D3D12_ROOT_PARAMETER rootParams[3] = {};
//	// �萔�o�b�t�@0��
//	rootParams[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;   // ���
//	rootParams[0].Descriptor.ShaderRegister = 0;                   // �萔�o�b�t�@�ԍ�
//	rootParams[0].Descriptor.RegisterSpace = 0;                    // �f�t�H���g�l
//	rootParams[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;  // �S�ẴV�F�[�_���猩����
//	// �e�N�X�`�����W�X�^0��
//	rootParams[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;   //���
//	rootParams[1].DescriptorTable.pDescriptorRanges = &descriptorRange;		  //�f�X�N���v�^�����W
//	rootParams[1].DescriptorTable.NumDescriptorRanges = 1;              		  //�f�X�N���v�^�����W��
//	rootParams[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
//	//�萔�o�b�t�@1��
//	rootParams[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;   // ���
//	rootParams[2].Descriptor.ShaderRegister = 1;                   // �萔�o�b�t�@�ԍ�
//	rootParams[2].Descriptor.RegisterSpace = 0;                    // �f�t�H���g�l
//	rootParams[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;  // �S�ẴV�F�[�_���猩����
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
//
//	// ���[�g�V�O�l�`���̐ݒ�
//	rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
//	rootSignatureDesc.pParameters = rootParams;				//���[�g�p�����[�^�̐擪�A�h���X
//	rootSignatureDesc.NumParameters = _countof(rootParams);	//���[�g�p�����[�^��
//	rootSignatureDesc.pStaticSamplers = &samplerDesc;
//	rootSignatureDesc.NumStaticSamplers = 1;
//
//	// ���[�g�V�O�l�`���̃V���A���C�Y
//	ID3DBlob* rootSigBlob = nullptr;
//	result = D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1_0,
//		&rootSigBlob, &errorBlob);
//	assert(SUCCEEDED(result));
//	result = dxcommon_->GetDevice()->CreateRootSignature(0, rootSigBlob->GetBufferPointer(), rootSigBlob->GetBufferSize(),
//		IID_PPV_ARGS(&rootSignature));
//	assert(SUCCEEDED(result));
//	rootSigBlob->Release();
//
//	// �p�C�v���C���Ƀ��[�g�V�O�l�`�����Z�b�g
//	pipelineDesc.pRootSignature = rootSignature;
//	result = dxcommon_->GetDevice()->CreateGraphicsPipelineState(&pipelineDesc, IID_PPV_ARGS(&pipelineState));
//	assert(SUCCEEDED(result));
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
//	//�q�[�v�ݒ�
//	textureHeapProp.Type = D3D12_HEAP_TYPE_CUSTOM;
//	textureHeapProp.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_WRITE_BACK;
//	textureHeapProp.MemoryPoolPreference = D3D12_MEMORY_POOL_L0;
//
//	// ���\�[�X�ݒ�
//	textureResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
//	textureResourceDesc.Format = metadata.format;
//	textureResourceDesc.Width = metadata.width;
//	textureResourceDesc.Height = (UINT)metadata.height;
//	textureResourceDesc.DepthOrArraySize = (UINT16)metadata.arraySize;
//	textureResourceDesc.MipLevels = (UINT16)metadata.mipLevels;
//	textureResourceDesc.SampleDesc.Count = 1;
//
//	// �f�X�N���v�^�q�[�v�̐ݒ�
//	srvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
//	srvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;//�V�F�[�_���猩����悤��
//	srvHeapDesc.NumDescriptors = kMaxSRVCount;
//
//	// �ݒ������SRV�p�f�X�N���v�^�q�[�v�𐶐�
//	result = dxcommon_->GetDevice()->CreateDescriptorHeap(&srvHeapDesc, IID_PPV_ARGS(&srvHeap));
//	assert(SUCCEEDED(result));
//	incrementSize = dxcommon_->GetDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
//	srvHandle = srvHeap->GetCPUDescriptorHandleForHeapStart();
//}
//
//void SpriteCommon::LoadTexture(uint32_t index, const std::string& fileName)
//{
//	//�f�B���N�g���p�X�ƃt�@�C������A�����ăt���p�X�𓾂�
//	std::string fullPath = kDefaultTextureDirectoryPath + fileName;
//
//	//���C�h������ɕϊ������ۂ̕�����o�b�t�@�T�C�Y�̌v�Z
//	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, fullPath.c_str(), -1, nullptr, 0);
//
//	//���C�h������ɕϊ�
//	std::vector<wchar_t> wfilePath(filePathBufferSize);
//	MultiByteToWideChar(CP_ACP, 0, fullPath.c_str(), -1, wfilePath.data(), filePathBufferSize);
//
//
//	// WIC�e�N�X�`���̃��[�h
//	result = LoadFromWICFile(
//		wfilePath.data()/*L"Resources/meemu.jpg"*/,   //�uResources�v�t�H���_�́utexture.png�v
//		WIC_FLAGS_NONE,
//		&metadata, scratchImg);
//
//	// ���\�[�X�ݒ�
//	textureResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
//	textureResourceDesc.Format = metadata.format;
//	textureResourceDesc.Width = metadata.width;
//	textureResourceDesc.Height = (UINT)metadata.height;
//	textureResourceDesc.DepthOrArraySize = (UINT16)metadata.arraySize;
//	textureResourceDesc.MipLevels = (UINT16)metadata.mipLevels;
//	textureResourceDesc.SampleDesc.Count = 1;
//
//	result = dxcommon_->GetDevice()->CreateCommittedResource(
//		&textureHeapProp,
//		D3D12_HEAP_FLAG_NONE,
//		&textureResourceDesc,
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(texBuff[index].GetAddressOf()));
//
//	// �S�~�b�v�}�b�v�ɂ���
//	for (size_t i = 0; i < metadata.mipLevels; i++) {
//		// �~�b�v�}�b�v���x�����w�肵�ăC���[�W���擾
//		const Image* img = scratchImg.GetImage(i, 0, 0);
//		// �e�N�X�`���o�b�t�@�Ƀf�[�^�]��
//		result = texBuff[index]->WriteToSubresource(
//			(UINT)i,
//			nullptr,              // �S�̈�փR�s�[
//			img->pixels,          // ���f�[�^�A�h���X
//			(UINT)img->rowPitch,  // 1���C���T�C�Y
//			(UINT)img->slicePitch // 1���T�C�Y
//		);
//		assert(SUCCEEDED(result));
//	}
//
//	// �V�F�[�_���\�[�X�r���[�ݒ�
//	D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc{};
//	srvDesc.Format = resDesc.Format;
//	srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
//	srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
//	srvDesc.Texture2D.MipLevels = resDesc.MipLevels;
//	srvHandle.ptr += (incrementSize * index);
//
//	// �n���h���̎w���ʒu�ɃV�F�[�_�[���\�[�X�r���[�쐬
//	dxcommon_->GetDevice()->CreateShaderResourceView(texBuff[index].Get(), &srvDesc, srvHandle);
//}
//
//void SpriteCommon::SetTextureCommands(uint32_t index)
//{
//	// �p�C�v���C���X�e�[�g�ƃ��[�g�V�O�l�`���̐ݒ�R�}���h
//	dxcommon_->GetCommandlist()->SetPipelineState(pipelineState);
//	dxcommon_->GetCommandlist()->SetGraphicsRootSignature(rootSignature);
//
//	//�v���~�e�B�u�`��̐ݒ�R�}���h
//	dxcommon_->GetCommandlist()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);//�O�p���X�g
//	// SRV�q�[�v�̐ݒ�R�}���h
//	dxcommon_->GetCommandlist()->SetDescriptorHeaps(1, &srvHeap);
//	// SRV�q�[�v�̐擪�n���h�����擾�iSRV���w���Ă���͂��j
//	D3D12_GPU_DESCRIPTOR_HANDLE srvGpuHandle = srvHeap->GetGPUDescriptorHandleForHeapStart();
//	// SRV�q�[�v�̐擪�ɂ���SRV�����[�g�p�����[�^1�Ԃɐݒ�
//	srvGpuHandle.ptr += (incrementSize * index);
//	dxcommon_->GetCommandlist()->SetGraphicsRootDescriptorTable(1, srvGpuHandle);
//}