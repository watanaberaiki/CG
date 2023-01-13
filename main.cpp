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
//#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
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
////定数バッファ用データ構造体(マテリアル)
//struct ConstBufferDataMaterial {
//	XMFLOAT4 color;		//色(RGBA)
//};
//
////定数バッファ用データ構造体(3D変換行列)
//struct ConstBufferDataTransform {
//	XMMATRIX mat;		//3D変換行列
//};
//
////3Dオブジェクト型
//struct Object3d
//{
//	//定数バッファ(行列用)
//	ComPtr<ID3D12Resource> constBuffTransform;
//	//定数バッファマップ(行列用)
//	ConstBufferDataTransform* constMapTransform = 0;
//	//アフィン変換情報
//	XMFLOAT3 scale = { 1,1,1 };
//	XMFLOAT3 rotation = { 0,0,0 };
//	XMFLOAT3 position = { 0,0,0 };
//	//ワールド変換行列
//	XMMATRIX matWorld = {};
//	//親オブジェクトへのポインタ
//	Object3d* parent = nullptr;
//};
//
//
////3Dオブジェクトの初期化
//void InitializeObject3d(Object3d* object, ID3D12Device* device) {
//	HRESULT result;
//
//	//定数バッファのヒープ設定
//	D3D12_HEAP_PROPERTIES heapProp{};
//	heapProp.Type = D3D12_HEAP_TYPE_UPLOAD;
//	// 定数バッファのリソース設定
//	D3D12_RESOURCE_DESC resdesc{};
//	resdesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
//	resdesc.Width = (sizeof(ConstBufferDataTransform) + 0xff) & ~0xff;
//	resdesc.Height = 1;
//	resdesc.DepthOrArraySize = 1;
//	resdesc.MipLevels = 1;
//	resdesc.SampleDesc.Count = 1;
//	resdesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
//
//	// 定数バッファの生成
//	result = device->CreateCommittedResource(
//		&heapProp, // ヒープ設定
//		D3D12_HEAP_FLAG_NONE,
//		&resdesc, // リソース設定
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&object->constBuffTransform));
//	assert(SUCCEEDED(result));
//
//	// 定数バッファのマッピング
//	result = object->constBuffTransform->Map(0, nullptr, (void**)&object->constMapTransform); // マッピング
//	assert(SUCCEEDED(result));
//
//}
//
//void UpdateObject3d(Object3d* object, XMMATRIX& matView, XMMATRIX& matProjection) {
//
//	XMMATRIX matScale, matRot, matTrans;
//
//	//スケール、回転、平行移動行列の計算
//	matScale = XMMatrixScaling(object->scale.x, object->scale.y, object->scale.z);
//
//	matRot = XMMatrixIdentity();
//	matRot *= XMMatrixRotationZ(object->rotation.z);
//	matRot *= XMMatrixRotationX(object->rotation.x);
//	matRot *= XMMatrixRotationY(object->rotation.y);
//
//	matTrans = XMMatrixTranslation(object->position.x, object->position.y, object->position.z);
//
//	//ワールド行列の合成
//	object->matWorld = XMMatrixIdentity();
//	object->matWorld *= matScale;
//	object->matWorld *= matRot;
//	object->matWorld *= matTrans;
//
//	//親オブジェクトがあれば
//	if (object->parent != nullptr)
//	{
//		//親オブジェクトのワールド行列をかける
//		object->matWorld *= object->parent->matWorld;
//	}
//
//	//定数バッファへデータ転送
//	object->constMapTransform->mat = object->matWorld * matView * matProjection;
//
//}
//
//void DrawObject3d(Object3d* object, ID3D12GraphicsCommandList* commandList, D3D12_VERTEX_BUFFER_VIEW& vbView,
//	D3D12_INDEX_BUFFER_VIEW& ibView, UINT numIndices)
//{
//	//頂点バッファの設定
//	commandList->IASetVertexBuffers(0, 1, &vbView);
//	//インデックスバッファの設定
//	commandList->IASetIndexBuffer(&ibView);
//	//定数バッファビュー
//	commandList->SetGraphicsRootConstantBufferView(2, object->constBuffTransform->GetGPUVirtualAddress());
//
//	//描画コマンド
//	commandList->DrawIndexedInstanced(numIndices, 1, 0, 0, 0);
//}

////ウィンドウプロージャ
//LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
//	//メッセージに応じてゲーム固有の処理を行う
//	switch (msg) {
//		//ウィンドウが破棄された
//	case WM_DESTROY:
//		//OSも対して、アプリの終了を伝える
//		PostQuitMessage(0);
//		return 0;
//	}
//	//標準のメッセージ処理を行う
//	return DefWindowProc(hwnd, msg, wparam, lparam);
//}

enum Scene {
	title,
	game,
	clear,
	gameover
};

//テクスチャの最大枚数
const int spriteSRVCount = 512;

//定数バッファ用データ構造体
struct ConstBufferData {
	XMFLOAT4 color;		//色(RGBA)
	XMMATRIX mat;		//3D変換行列
};


//頂点データ
struct VertexPosUv
{
	XMFLOAT3 pos;	//xyz座標
	XMFLOAT2 uv;	//uv座標
};

//パイプラインセット
struct PipelineSet
{
	//パイプラインステートオブジェクト
	ComPtr<ID3D12PipelineState>pipelinestate;
	//ルートシグネチャ
	ComPtr<ID3D12RootSignature>rootsignature;
};

//スプライト1枚分のデータ
struct Sprite
{
	ComPtr<ID3D12Resource> vertBuff;				//頂点バッファ
	D3D12_VERTEX_BUFFER_VIEW vbView{};				//頂点バッファビュー
	ComPtr<ID3D12Resource> constBuff;				//定数バッファビュー
	float rotation = 0.0f;			//Z軸周りの回転軸
	XMFLOAT3 position = { 0,0,0 };	//座標
	XMMATRIX matWorld;				//ワールド行列
	//XMFLOAT4 color = { 1,1,1,1 };	//色
	UINT texNumber = 0;				//テキスト番号
	XMFLOAT2 size = { 100,100 };
};

//スプライトの共通データ
struct SpriteCommon
{
	//パイプラインセット
	PipelineSet pipelineSet;
	//射影行列
	XMMATRIX matProjection{};
	//テクスチャ用デスクリプタヒープの生成
	ComPtr<ID3D12DescriptorHeap>descHeap;
	//テクスチャリソース(テクスチャバッファ)の配列
	ComPtr<ID3D12Resource>texBuff[spriteSRVCount];

};

//パイプライン生成
PipelineSet Pipeline3D(ID3D12Device* dev)
{
	HRESULT result;
	ComPtr<ID3DBlob> vsBlob; // 頂点シェーダオブジェクト
	ComPtr<ID3DBlob> psBlob; // ピクセルシェーダオブジェクト
	ComPtr<ID3DBlob> errorBlob; // エラーオブジェクト

	// 頂点シェーダの読み込みとコンパイル
	result = D3DCompileFromFile(
		L"Resources/shaders/BasicVS.hlsl", // シェーダファイル名
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, // インクルード可能にする
		"main", "vs_5_0", // エントリーポイント名、シェーダーモデル指定
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // デバッグ用設定
		0,
		&vsBlob, &errorBlob);

	// エラーなら
	if (FAILED(result)) {
		// errorBlobからエラー内容をstring型にコピー
		std::string error;
		error.resize(errorBlob->GetBufferSize());

		std::copy_n((char*)errorBlob->GetBufferPointer(),
			errorBlob->GetBufferSize(),
			error.begin());
		error += "\n";
		// エラー内容を出力ウィンドウに表示
		OutputDebugStringA(error.c_str());
		assert(0);
	}

	// ピクセルシェーダの読み込みとコンパイル
	result = D3DCompileFromFile(
		L"Resources/shaders/BasicPS.hlsl",   // シェーダファイル名
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, // インクルード可能にする
		"main", "ps_5_0", // エントリーポイント名、シェーダーモデル指定
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // デバッグ用設定
		0,
		&psBlob, &errorBlob);

	// エラーなら
	if (FAILED(result)) {
		// errorBlobからエラー内容をstring型にコピー
		std::string error;
		error.resize(errorBlob->GetBufferSize());

		std::copy_n((char*)errorBlob->GetBufferPointer(),
			errorBlob->GetBufferSize(),
			error.begin());
		error += "\n";
		// エラー内容を出力ウィンドウに表示
		OutputDebugStringA(error.c_str());
		assert(0);
	}

	// 頂点レイアウト
	D3D12_INPUT_ELEMENT_DESC inputLayout[] = {
		{ // xyz座標(1行で書いたほうが見やすい)
			"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,
			D3D12_APPEND_ALIGNED_ELEMENT,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
		},
		{//法線ベクトル
			"NORMAL",0,DXGI_FORMAT_R32G32B32_FLOAT,0,
			D3D12_APPEND_ALIGNED_ELEMENT,
		D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0
		},

		{ // uv座標(1行で書いたほうが見やすい)
			"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0,
			D3D12_APPEND_ALIGNED_ELEMENT,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
		},
	};

	// デスクリプタレンジの設定
	D3D12_DESCRIPTOR_RANGE descriptorRange{};
	descriptorRange.NumDescriptors = 1;         //一度の描画に使うテクスチャが1枚なので1
	descriptorRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
	descriptorRange.BaseShaderRegister = 0;     //テクスチャレジスタ0番
	descriptorRange.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;

	// ルートパラメータの設定
	D3D12_ROOT_PARAMETER rootParams[3] = {};
	// 定数バッファ0番
	rootParams[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;   // 種類
	rootParams[0].Descriptor.ShaderRegister = 0;                   // 定数バッファ番号
	rootParams[0].Descriptor.RegisterSpace = 0;                    // デフォルト値
	rootParams[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;  // 全てのシェーダから見える
	// テクスチャレジスタ0番
	rootParams[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;   //種類
	rootParams[1].DescriptorTable.pDescriptorRanges = &descriptorRange;		  //デスクリプタレンジ
	rootParams[1].DescriptorTable.NumDescriptorRanges = 1;              		  //デスクリプタレンジ数
	rootParams[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;               //全てのシェーダから見える
	// 定数バッファ1番
	rootParams[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;   //種類
	rootParams[2].Descriptor.ShaderRegister = 1;		  //デスクリプタレンジ
	rootParams[2].Descriptor.RegisterSpace = 0;              		  //デスクリプタレンジ数
	rootParams[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;                // デフォルト値

	// テクスチャサンプラーの設定
	D3D12_STATIC_SAMPLER_DESC samplerDesc{};
	samplerDesc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //横繰り返し（タイリング）
	samplerDesc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //縦繰り返し（タイリング）
	samplerDesc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //奥行繰り返し（タイリング）
	samplerDesc.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;  //ボーダーの時は黒
	samplerDesc.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;                   //全てリニア補間
	samplerDesc.MaxLOD = D3D12_FLOAT32_MAX;                                 //ミップマップ最大値
	samplerDesc.MinLOD = 0.0f;                                              //ミップマップ最小値
	samplerDesc.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
	samplerDesc.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;           //ピクセルシェーダからのみ使用可能

	// グラフィックスパイプライン設定
	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc{};

	// シェーダーの設定
	pipelineDesc.VS.pShaderBytecode = vsBlob->GetBufferPointer();
	pipelineDesc.VS.BytecodeLength = vsBlob->GetBufferSize();
	pipelineDesc.PS.pShaderBytecode = psBlob->GetBufferPointer();
	pipelineDesc.PS.BytecodeLength = psBlob->GetBufferSize();

	// サンプルマスクの設定
	pipelineDesc.SampleMask = D3D12_DEFAULT_SAMPLE_MASK; // 標準設定

	// ラスタライザの設定
	pipelineDesc.RasterizerState.CullMode = D3D12_CULL_MODE_BACK;  // カリングしない
	pipelineDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID; // ポリゴン内塗りつぶし
	pipelineDesc.RasterizerState.DepthClipEnable = true; // 深度クリッピングを有効に

	// レンダーターゲットのブレンド設定
	D3D12_RENDER_TARGET_BLEND_DESC& blenddesc = pipelineDesc.BlendState.RenderTarget[0];
	blenddesc.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL; // RBGA全てのチャンネルを描画

	//blenddesc.BlendEnable = true;                   // ブレンドを有効にする
	//blenddesc.BlendOpAlpha = D3D12_BLEND_OP_ADD;    // 加算
	//blenddesc.SrcBlendAlpha = D3D12_BLEND_ONE;      // ソースの値を100% 使う
	//blenddesc.DestBlendAlpha = D3D12_BLEND_ZERO;    // デストの値を  0% 使う

	//// 半透明合成
	//blenddesc.BlendOp = D3D12_BLEND_OP_ADD;             // 加算
	//blenddesc.SrcBlend = D3D12_BLEND_SRC_ALPHA;         // ソースのアルファ値
	//blenddesc.DestBlend = D3D12_BLEND_INV_SRC_ALPHA;    // 1.0f-ソースのアルファ値

	// 頂点レイアウトの設定
	pipelineDesc.InputLayout.pInputElementDescs = inputLayout;
	pipelineDesc.InputLayout.NumElements = _countof(inputLayout);

	// 図形の形状設定
	pipelineDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;

	// その他の設定
	pipelineDesc.NumRenderTargets = 1; // 描画対象は1つ
	pipelineDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB; // 0～255指定のRGBA
	pipelineDesc.SampleDesc.Count = 1; // 1ピクセルにつき1回サンプリング

	//デプスステンシルステートの設定
	pipelineDesc.DepthStencilState.DepthEnable = true;
	pipelineDesc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
	pipelineDesc.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_LESS;
	pipelineDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;

	// ルートシグネチャ
	//ComPtr<ID3D12RootSignature> rootSignature;
	// ルートシグネチャの設定
	D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc{};
	rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
	rootSignatureDesc.pParameters = rootParams; //ルートパラメータの先頭アドレス
	rootSignatureDesc.NumParameters = _countof(rootParams);        //ルートパラメータ数

	rootSignatureDesc.pStaticSamplers = &samplerDesc;
	rootSignatureDesc.NumStaticSamplers = 1;

	//パイプラインと√シグネチャのセット
	PipelineSet pipelineSet;

	// ルートシグネチャのシリアライズ
	ComPtr<ID3DBlob> rootSigBlob;
	result = D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1_0,
		&rootSigBlob, &errorBlob);
	assert(SUCCEEDED(result));
	result = dev->CreateRootSignature(0, rootSigBlob->GetBufferPointer(), rootSigBlob->GetBufferSize(),
		IID_PPV_ARGS(&pipelineSet.rootsignature));
	assert(SUCCEEDED(result));

	// パイプラインにルートシグネチャをセット
	pipelineDesc.pRootSignature = pipelineSet.rootsignature.Get();

	// パイプランステートの生成
	result = dev->CreateGraphicsPipelineState(&pipelineDesc, IID_PPV_ARGS(&pipelineSet.pipelinestate));
	assert(SUCCEEDED(result));


	//パイプラインとルートシグネチャを返す
	return pipelineSet;
}

PipelineSet PipelineSprite(ID3D12Device* dev)
{
	HRESULT result;
	ComPtr<ID3DBlob> vsBlob; // 頂点シェーダオブジェクト
	ComPtr<ID3DBlob> psBlob; // ピクセルシェーダオブジェクト
	ComPtr<ID3DBlob> errorBlob; // エラーオブジェクト

	// 頂点シェーダの読み込みとコンパイル
	result = D3DCompileFromFile(
		L"Resources/shaders/SpriteVS.hlsl", // シェーダファイル名
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, // インクルード可能にする
		"main", "vs_5_0", // エントリーポイント名、シェーダーモデル指定
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // デバッグ用設定
		0,
		&vsBlob, &errorBlob);

	// エラーなら
	if (FAILED(result)) {
		// errorBlobからエラー内容をstring型にコピー
		std::string error;
		error.resize(errorBlob->GetBufferSize());

		std::copy_n((char*)errorBlob->GetBufferPointer(),
			errorBlob->GetBufferSize(),
			error.begin());
		error += "\n";
		// エラー内容を出力ウィンドウに表示
		OutputDebugStringA(error.c_str());
		assert(0);
	}

	// ピクセルシェーダの読み込みとコンパイル
	result = D3DCompileFromFile(
		L"Resources/shaders/SpritePS.hlsl",   // シェーダファイル名
		nullptr,
		D3D_COMPILE_STANDARD_FILE_INCLUDE, // インクルード可能にする
		"main", "ps_5_0", // エントリーポイント名、シェーダーモデル指定
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // デバッグ用設定
		0,
		&psBlob, &errorBlob);

	// エラーなら
	if (FAILED(result)) {
		// errorBlobからエラー内容をstring型にコピー
		std::string error;
		error.resize(errorBlob->GetBufferSize());

		std::copy_n((char*)errorBlob->GetBufferPointer(),
			errorBlob->GetBufferSize(),
			error.begin());
		error += "\n";
		// エラー内容を出力ウィンドウに表示
		OutputDebugStringA(error.c_str());
		assert(0);
	}

	// 頂点レイアウト
	D3D12_INPUT_ELEMENT_DESC inputLayout[] = {
		{ // xyz座標(1行で書いたほうが見やすい)
			"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,
			D3D12_APPEND_ALIGNED_ELEMENT,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
		},

		{ // uv座標(1行で書いたほうが見やすい)
			"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0,
			D3D12_APPEND_ALIGNED_ELEMENT,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
		},
	};




	// デスクリプタレンジの設定
	CD3DX12_DESCRIPTOR_RANGE descriptorRange{};
	descriptorRange.Init(D3D12_DESCRIPTOR_RANGE_TYPE_SRV, 1, 0);
	//descriptorRange.NumDescriptors = 1;         //一度の描画に使うテクスチャが1枚なので1
	//descriptorRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
	//descriptorRange.BaseShaderRegister = 0;     //テクスチャレジスタ0番
	//descriptorRange.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;

	//// ルートパラメータの設定
	//D3D12_ROOT_PARAMETER rootParams[3] = {};
	//// 定数バッファ0番
	//rootParams[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;   // 種類
	//rootParams[0].Descriptor.ShaderRegister = 0;                   // 定数バッファ番号
	//rootParams[0].Descriptor.RegisterSpace = 0;                    // デフォルト値
	//rootParams[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;  // 全てのシェーダから見える
	//// テクスチャレジスタ0番
	//rootParams[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;   //種類
	//rootParams[1].DescriptorTable.pDescriptorRanges = &descriptorRange;		  //デスクリプタレンジ
	//rootParams[1].DescriptorTable.NumDescriptorRanges = 1;              		  //デスクリプタレンジ数
	//rootParams[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;               //全てのシェーダから見える
	//// 定数バッファ1番
	//rootParams[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;   //種類
	//rootParams[2].Descriptor.ShaderRegister = 1;		  //デスクリプタレンジ
	//rootParams[2].Descriptor.RegisterSpace = 0;              		  //デスクリプタレンジ数
	//rootParams[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;                // デフォルト値

	CD3DX12_ROOT_PARAMETER rootParams[2];
	rootParams[0].InitAsConstantBufferView(0);
	rootParams[1].InitAsDescriptorTable(1, &descriptorRange, D3D12_SHADER_VISIBILITY_ALL);

	// テクスチャサンプラーの設定
	D3D12_STATIC_SAMPLER_DESC samplerDesc{};
	samplerDesc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //横繰り返し（タイリング）
	samplerDesc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //縦繰り返し（タイリング）
	samplerDesc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //奥行繰り返し（タイリング）
	samplerDesc.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;  //ボーダーの時は黒
	samplerDesc.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;                   //全てリニア補間
	samplerDesc.MaxLOD = D3D12_FLOAT32_MAX;                                 //ミップマップ最大値
	samplerDesc.MinLOD = 0.0f;                                              //ミップマップ最小値
	samplerDesc.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
	samplerDesc.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;           //ピクセルシェーダからのみ使用可能

	// グラフィックスパイプライン設定
	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc{};

	// シェーダーの設定
	pipelineDesc.VS.pShaderBytecode = vsBlob->GetBufferPointer();
	pipelineDesc.VS.BytecodeLength = vsBlob->GetBufferSize();
	pipelineDesc.PS.pShaderBytecode = psBlob->GetBufferPointer();
	pipelineDesc.PS.BytecodeLength = psBlob->GetBufferSize();

	// サンプルマスクの設定
	pipelineDesc.SampleMask = D3D12_DEFAULT_SAMPLE_MASK; // 標準設定

	// ラスタライザの設定
	pipelineDesc.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
	pipelineDesc.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;  // カリングしない
	//pipelineDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID; // ポリゴン内塗りつぶし
	//pipelineDesc.RasterizerState.DepthClipEnable = true; // 深度クリッピングを有効に

	// レンダーターゲットのブレンド設定
	D3D12_RENDER_TARGET_BLEND_DESC& blenddesc = pipelineDesc.BlendState.RenderTarget[0];
	blenddesc.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL; // RBGA全てのチャンネルを描画

	//blenddesc.BlendEnable = true;                   // ブレンドを有効にする
	//blenddesc.BlendOpAlpha = D3D12_BLEND_OP_ADD;    // 加算
	//blenddesc.SrcBlendAlpha = D3D12_BLEND_ONE;      // ソースの値を100% 使う
	//blenddesc.DestBlendAlpha = D3D12_BLEND_ZERO;    // デストの値を  0% 使う

	//// 半透明合成
	//blenddesc.BlendOp = D3D12_BLEND_OP_ADD;             // 加算
	//blenddesc.SrcBlend = D3D12_BLEND_SRC_ALPHA;         // ソースのアルファ値
	//blenddesc.DestBlend = D3D12_BLEND_INV_SRC_ALPHA;    // 1.0f-ソースのアルファ値

	// 頂点レイアウトの設定
	pipelineDesc.InputLayout.pInputElementDescs = inputLayout;
	pipelineDesc.InputLayout.NumElements = _countof(inputLayout);

	// 図形の形状設定
	pipelineDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;

	// その他の設定
	pipelineDesc.NumRenderTargets = 1; // 描画対象は1つ
	pipelineDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB; // 0～255指定のRGBA
	pipelineDesc.SampleDesc.Count = 1; // 1ピクセルにつき1回サンプリング

	//デプスステンシルステートの設定
	pipelineDesc.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
	pipelineDesc.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_ALWAYS; // 常に上書きルール

	pipelineDesc.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
	pipelineDesc.DepthStencilState.DepthEnable = false;
	//pipelineDesc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
	//pipelineDesc.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_ALWAYS;
	//pipelineDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;

	// ルートシグネチャ
	//ComPtr<ID3D12RootSignature> rootSignature;
	// ルートシグネチャの設定
	D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc{};
	rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
	rootSignatureDesc.pParameters = rootParams; //ルートパラメータの先頭アドレス
	rootSignatureDesc.NumParameters = _countof(rootParams);        //ルートパラメータ数

	rootSignatureDesc.pStaticSamplers = &samplerDesc;
	rootSignatureDesc.NumStaticSamplers = 1;

	//パイプラインと√シグネチャのセット
	PipelineSet pipelineSet;

	// ルートシグネチャのシリアライズ
	ComPtr<ID3DBlob> rootSigBlob;
	result = D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1_0,
		&rootSigBlob, &errorBlob);
	assert(SUCCEEDED(result));
	result = dev->CreateRootSignature(0, rootSigBlob->GetBufferPointer(), rootSigBlob->GetBufferSize(),
		IID_PPV_ARGS(&pipelineSet.rootsignature));
	assert(SUCCEEDED(result));

	// パイプラインにルートシグネチャをセット
	pipelineDesc.pRootSignature = pipelineSet.rootsignature.Get();

	// パイプランステートの生成
	result = dev->CreateGraphicsPipelineState(&pipelineDesc, IID_PPV_ARGS(&pipelineSet.pipelinestate));
	assert(SUCCEEDED(result));


	//パイプラインとルートシグネチャを返す
	return pipelineSet;
}

SpriteCommon SpriteCommonCreate(ID3D12Device* dev, int window_width, int window_height)
{
	HRESULT result = S_FALSE;

	//新たなスプライト共通データを生成
	SpriteCommon spriteCommon{};

	//スプライト用パイプライン生成
	spriteCommon.pipelineSet = PipelineSprite(dev);

	//平行投影行列生成
	spriteCommon.matProjection = XMMatrixOrthographicOffCenterLH(0.0f, (float)window_width, (float)window_height, 0.0f, 0.0f, 1.0f);

	//HRESULT result = S_FALSE;

	//デスクリプタヒープを生成
	D3D12_DESCRIPTOR_HEAP_DESC descHeapDesc = {};
	descHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
	descHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
	descHeapDesc.NumDescriptors = spriteSRVCount;
	result = dev->CreateDescriptorHeap(&descHeapDesc, IID_PPV_ARGS(&spriteCommon.descHeap));

	return spriteCommon;

}

//スプライト単体描画
void SpriteDraw(const Sprite& sprite, ID3D12GraphicsCommandList* cmdList, const SpriteCommon& spriteCommon, ID3D12Device* dev)
{
	// 頂点バッファの設定コマンド
	cmdList->IASetVertexBuffers(0, 1, &sprite.vbView);

	// 定数バッファ(CBV)の設定コマンド
	cmdList->SetGraphicsRootConstantBufferView(0, sprite.constBuff->GetGPUVirtualAddress());

	//シェーダーリソースビューをセット
	cmdList->SetGraphicsRootDescriptorTable(1, CD3DX12_GPU_DESCRIPTOR_HANDLE(spriteCommon.descHeap->GetGPUDescriptorHandleForHeapStart(),
		sprite.texNumber, dev->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV)));

	//ポリゴンの描画
	cmdList->DrawInstanced(4, 1, 0, 0);

}

//スプライト単体描画バッファの転送
void SpriteTransferVertexBuffer(const Sprite& sprite) {
	HRESULT result = S_FALSE;

	//頂点データ
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

//スプライト生成
Sprite SpriteCreate(ID3D12Device* dev, int window_width, int window_height, UINT texNumber, const SpriteCommon& spriteCommon)
{
	HRESULT result = S_FALSE;

	//新しいスプライトを作る
	Sprite sprite{};

	//頂点データ
	VertexPosUv vertices[] = {
		{{	0.0f, 100.0f,	0.0f},{0.0f,1.0f}},
		{{	0.0f,	0.0f,	0.0f},{0.0f,0.0f}},
		{{100.0f, 100.0f,	0.0f},{1.0f,1.0f}},
		{{100.0f,	0.0f,	0.0f},{1.0f,0.0f}},
	};

	// ヒーププロパティ
	CD3DX12_HEAP_PROPERTIES heapPropsVertexBuffer = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	// リソース設定
	CD3DX12_RESOURCE_DESC resourceDescVertexBuffer = CD3DX12_RESOURCE_DESC::Buffer(sizeof(VertexPosUv));

	//テクスチャ番号をコピー
	sprite.texNumber = texNumber;

	//頂点バッファ生成
	result = dev->CreateCommittedResource(
		&heapPropsVertexBuffer, // ヒープ設定
		D3D12_HEAP_FLAG_NONE,
		&resourceDescVertexBuffer, // リソース設定
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&sprite.vertBuff));
	assert(SUCCEEDED(result));

	if (spriteCommon.texBuff[sprite.texNumber]) {
		//テクスチャ情報取得
		D3D12_RESOURCE_DESC resDesc = spriteCommon.texBuff[sprite.texNumber]->GetDesc();
		//スプライトの大きさを画像の解像度に合わせる
		sprite.size = { (float)resDesc.Width,(float)resDesc.Height };
	}
	//頂点バッファデータ転送
	SpriteTransferVertexBuffer(sprite);

	//頂点バッファへのデータ転送
	VertexPosUv* vertMap = nullptr;
	result = sprite.vertBuff->Map(0, nullptr, (void**)&vertMap);
	memcpy(vertMap, vertices, sizeof(vertices));
	sprite.vertBuff->Unmap(0, nullptr);

	// 頂点バッファビューの作成
	// GPU仮想アドレス
	sprite.vbView.BufferLocation = sprite.vertBuff->GetGPUVirtualAddress();
	// 頂点バッファのサイズ
	sprite.vbView.SizeInBytes = sizeof(vertices);
	// 頂点1つ分のデータサイズ
	sprite.vbView.StrideInBytes = sizeof(vertices[0]);

	// ヒーププロパティ
	CD3DX12_HEAP_PROPERTIES heapPropsConstantBuffer = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
	// リソース設定
	CD3DX12_RESOURCE_DESC resourceDescConstantBuffer = CD3DX12_RESOURCE_DESC::Buffer((sizeof(ConstBufferData) + 0xff) & ~0xff);

	// 定数バッファの生成
	result = dev->CreateCommittedResource(
		&heapPropsConstantBuffer, // ヒープ設定
		D3D12_HEAP_FLAG_NONE,
		&resourceDescConstantBuffer, // リソース設定
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&sprite.constBuff));
	assert(SUCCEEDED(result));

	// 定数バッファにデータ転送
	ConstBufferData* constMap = nullptr;
	result = sprite.constBuff->Map(0, nullptr, (void**)&constMap); // マッピング
	constMap->color = XMFLOAT4(1, 1, 1, 1);
	assert(SUCCEEDED(result));

	//平行投影行列
	constMap->mat = XMMatrixOrthographicOffCenterLH(0.0f, window_width, window_height, 0.0f, 0.0f, 1.0f);
	sprite.constBuff->Unmap(0, nullptr);

	return sprite;
}

//スプライト単体更新
void SpriteUpdate(Sprite& sprite, const SpriteCommon& spriteCommon)
{
	sprite.matWorld = XMMatrixIdentity();

	sprite.matWorld *= XMMatrixRotationZ(XMConvertToRadians(sprite.rotation));

	sprite.matWorld *= XMMatrixTranslation(sprite.position.x, sprite.position.y, sprite.position.z);


	// 定数バッファにデータ転送
	ConstBufferData* constMap = nullptr;
	HRESULT result = sprite.constBuff->Map(0, nullptr, (void**)&constMap); // マッピング
	constMap->mat = sprite.matWorld * spriteCommon.matProjection;
	sprite.constBuff->Unmap(0, nullptr);

}

//スプライト共通グラフィックコマンドのセット
void SpriteCommonBeginDraw(const SpriteCommon& spritecommon, ID3D12GraphicsCommandList* cmdList)
{
	// パイプラインステートとルートシグネチャの設定コマンド
	cmdList->SetPipelineState(spritecommon.pipelineSet.pipelinestate.Get());
	cmdList->SetGraphicsRootSignature(spritecommon.pipelineSet.rootsignature.Get());

	// プリミティブ形状の設定コマンド
	cmdList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP); // 三角形リスト

	//テクスチャ用でスクリプタヒープの設定
	ID3D12DescriptorHeap* ppHeaps[] = { spritecommon.descHeap.Get() };
	cmdList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
}

//スプライト共通テクスチャ読み込み
void SpriteCommonLoadTexture(SpriteCommon& spriteCommon, UINT texnumber, const wchar_t* filename, ID3D12Device* dev) {

	assert(texnumber <= spriteSRVCount - 1);

	HRESULT result;
	TexMetadata metadata{};
	ScratchImage scratchImg{};

	// WICテクスチャのロード
	result = LoadFromWICFile(filename, WIC_FLAGS_NONE, &metadata, scratchImg);
	assert(SUCCEEDED(result));

	ScratchImage mipChain{};
	// ミップマップ生成
	result = GenerateMipMaps(
		scratchImg.GetImages(), scratchImg.GetImageCount(), scratchImg.GetMetadata(),
		TEX_FILTER_DEFAULT, 0, mipChain);
	if (SUCCEEDED(result)) {
		scratchImg = std::move(mipChain);
		metadata = scratchImg.GetMetadata();
	}

	// 読み込んだディフューズテクスチャをSRGBとして扱う
	metadata.format = MakeSRGB(metadata.format);

	// リソース設定
	CD3DX12_RESOURCE_DESC texresDesc = CD3DX12_RESOURCE_DESC::Tex2D(
		metadata.format, metadata.width, (UINT)metadata.height, (UINT16)metadata.arraySize,
		(UINT16)metadata.mipLevels);

	// ヒーププロパティ
	CD3DX12_HEAP_PROPERTIES heapProps =
		CD3DX12_HEAP_PROPERTIES(D3D12_CPU_PAGE_PROPERTY_WRITE_BACK, D3D12_MEMORY_POOL_L0);

	// テクスチャ用バッファの生成
	result = dev->CreateCommittedResource(
		&heapProps, D3D12_HEAP_FLAG_NONE, &texresDesc,
		D3D12_RESOURCE_STATE_GENERIC_READ, // テクスチャ用指定
		nullptr, IID_PPV_ARGS(&spriteCommon.texBuff[texnumber]));
	assert(SUCCEEDED(result));

	// テクスチャバッファにデータ転送
	for (size_t i = 0; i < metadata.mipLevels; i++) {
		const Image* img = scratchImg.GetImage(i, 0, 0); // 生データ抽出
		result = spriteCommon.texBuff[texnumber]->WriteToSubresource(
			(UINT)i,
			nullptr,              // 全領域へコピー
			img->pixels,          // 元データアドレス
			(UINT)img->rowPitch,  // 1ラインサイズ
			(UINT)img->slicePitch // 1枚サイズ
		);
		assert(SUCCEEDED(result));
	}

	// シェーダリソースビュー作成
	D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc{}; // 設定構造体
	D3D12_RESOURCE_DESC resDesc = spriteCommon.texBuff[texnumber]->GetDesc();

	srvDesc.Format = resDesc.Format;
	srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
	srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;//2Dテクスチャ
	srvDesc.Texture2D.MipLevels = 1;

	dev->CreateShaderResourceView(spriteCommon.texBuff[texnumber].Get(), //ビューと関連付けるバッファ
		&srvDesc, //テクスチャ設定情報
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

//Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	//　基盤システムの初期化
		//ポインタ
	Input* input = nullptr;
	WinApp* winApp = nullptr;
	DirectXCommon* dxCommon = nullptr;
	/*SpriteCommon* spriteCommon = nullptr;*/


	//WindowsAPIの初期化
	winApp = new WinApp();
	winApp->Initialize();

	//DirectXの初期化
	dxCommon = new DirectXCommon();
	dxCommon->Initialize(winApp);


	//入力の初期化
	input = new Input();
	input->Initialize(winApp);

	//3Dオブジェクト静的初期化
	Object3d::StaticInitialize(dxCommon->GetDevice(), winApp->window_width, winApp->window_height);


	////スプライト共通部の初期化
	//spriteCommon = new SpriteCommon();
	//spriteCommon->Initialize(dxCommon);

//基盤システムの初期化

//最初のシーンの初期化
	//テキスト
	//スプライト共通データ
	SpriteCommon spritecommon;
	//スプライト共通データ生成
	spritecommon = SpriteCommonCreate(dxCommon->GetDevice(), winApp->window_width, winApp->window_height);

	//スプライト共通テクスチャ読み込み
	SpriteCommonLoadTexture(spritecommon, 0, L"Resources/title.png", dxCommon->GetDevice());	//タイトル文字
	//操作説明
	SpriteCommonLoadTexture(spritecommon, 1, L"Resources/tutorial.png", dxCommon->GetDevice());			//操作説明
	//ゲームオーバー
	SpriteCommonLoadTexture(spritecommon, 2, L"Resources/gameover.png", dxCommon->GetDevice());		//ゲームオーバーの文字
	//ステージクリア
	SpriteCommonLoadTexture(spritecommon, 3, L"Resources/clear.png", dxCommon->GetDevice());

	//スプライト
	Sprite titleSprite;			//タイトル
	Sprite tutorialSprite;		//操作説明
	Sprite gameoverSprite;		//ゲームオーバー
	Sprite stageClearSprite;	//ステージクリア

	//タイトル
	//スプライトに何番のテクスチャを使うか
	titleSprite.texNumber = 0;
	//スプライトの生成
	titleSprite = SpriteCreate(dxCommon->GetDevice(), winApp->window_width, winApp->window_height, titleSprite.texNumber, spritecommon);
	//サイズ
	titleSprite.size = { winApp->window_width, winApp->window_height };
	//頂点バッファに反映
	SpriteTransferVertexBuffer(titleSprite);

	//操作説明
	//スプライトに何番のテクスチャを使うか
	tutorialSprite.texNumber = 1;
	//スプライトの生成
	tutorialSprite = SpriteCreate(dxCommon->GetDevice(), winApp->window_width, winApp->window_height, tutorialSprite.texNumber, spritecommon);
	//サイズ
	tutorialSprite.size = { winApp->window_width, winApp->window_height };
	//頂点バッファに反映
	SpriteTransferVertexBuffer(tutorialSprite);

	//ゲームオーバー
	//スプライトに何番のテクスチャを使うか
	gameoverSprite.texNumber = 2;
	//スプライトの生成
	gameoverSprite = SpriteCreate(dxCommon->GetDevice(), winApp->window_width, winApp->window_height, gameoverSprite.texNumber, spritecommon);
	//サイズ
	gameoverSprite.size = { winApp->window_width, winApp->window_height };
	//頂点バッファに反映
	SpriteTransferVertexBuffer(gameoverSprite);

	//ステージクリア
	//スプライトに何番のテクスチャを使うか
	stageClearSprite.texNumber = 3;
	//スプライトの生成
	stageClearSprite = SpriteCreate(dxCommon->GetDevice(), winApp->window_width, winApp->window_height, stageClearSprite.texNumber, spritecommon);
	//サイズ
	stageClearSprite.size = { winApp->window_width, winApp->window_height };
	//頂点バッファに反映
	SpriteTransferVertexBuffer(stageClearSprite);

	PipelineSet spritePipelineSet = PipelineSprite(dxCommon->GetDevice());

	//OBJからモデルデータを読み込む
	//円柱
	XMFLOAT3 minModel = {}, maxModel = {};
	Model* model = Model::LoadFromObj("cylinder", minModel, maxModel);
	minModel = model->GetminModel();
	maxModel = model->GetmaxModel();
	//プレイヤー
	XMFLOAT3 minModel2 = {}, maxModel2 = {};
	Model* model2 = Model::LoadFromObj("cube", minModel2, maxModel2);
	minModel2 = model2->GetminModel();
	maxModel2 = model2->GetmaxModel();
	//壁
	XMFLOAT3 minModel3 = {}, maxModel3 = {};
	Model* model3 = Model::LoadFromObj("redcube", minModel3, maxModel3);
	minModel3 = model3->GetminModel();
	maxModel3 = model3->GetmaxModel();
	//壁
	XMFLOAT3 minModel4 = {}, maxModel4 = {};
	Model* model4 = Model::LoadFromObj("wallcube", minModel4, maxModel4);
	minModel4 = model4->GetminModel();
	maxModel4 = model4->GetmaxModel();


	//天球(円柱)
	Object3d* skyCylinder = Object3d::Create();
	skyCylinder->SetModel(model);
	skyCylinder->SetScale({ 50,50,500 });
	skyCylinder->SetRotation({ 90,0,0 });

	//プレイヤー
	Object3d* Player = Object3d::Create();
	//オブジェクトにモデルを紐づける
	Player->SetModel(model2);
	//プレイヤー座標保存用
	DirectX::XMFLOAT3 playerPosition;
	//死んだ判定
	bool isDead = false;
	Player->SetScale({ 1.0f,1.0f,1.0f });
	float upSpeed = 0.0f;
	bool isStart = false;
	bool isGoal = false;


	//壁
	const int wallnum = 70;
	Object3d* wall[wallnum];
	float wallSize = 2.0f;
	for (int i = 0; i < wallnum; i++) {
		wall[i] = Object3d::Create();
		//オブジェクトにモデルを紐づける
		wall[i]->SetModel(model4);
		wall[i]->SetScale({ wallSize,wallSize,wallSize });
	}

	//横移動壁
	const int besideWallnum = 20;
	Object3d* besideWall[besideWallnum];
	bool isLeftMove[besideWallnum];
	for (int i = 0; i < besideWallnum; i++) {
		besideWall[i] = Object3d::Create();
		besideWall[i]->SetModel(model4);
		besideWall[i]->SetScale({ wallSize,wallSize,wallSize });
		isLeftMove[i] = false;
	}
	//縦移動壁
	const int verticalWallnum =20;
	Object3d* verticalWall[verticalWallnum];
	bool isUpMove[verticalWallnum];
	for (int i = 0; i < verticalWallnum; i++) {
		verticalWall[i] = Object3d::Create();
		verticalWall[i]->SetModel(model4);
		verticalWall[i]->SetScale({ wallSize,wallSize,wallSize });
		isUpMove[i] = false;
	}

	//床
	Object3d* floor;
	floor = Object3d::Create();
	floor->SetModel(model3);
	floor->SetScale({ 30,1,3000 });
	floor->SetPosition({ 0,-15,0 });

	//ビュー変換行列
	XMMATRIX matView;
	XMFLOAT3 eye(0, 5, -30);	//視点座標
	XMFLOAT3 target(0, 0, 0);	//注視点座標
	XMFLOAT3 up(0, 1, 0);		//上方向ベクトル
	matView = DirectX::XMMatrixLookAtLH(XMLoadFloat3(&eye), XMLoadFloat3(&target), XMLoadFloat3(&up));
	float angle = 0.0f;//カメラの回転角

	//シーン
	Scene scene = Scene::title;

	//最初のシーンの初期化

#ifdef _DEBUG

#endif

//	//描画初期化処理 ここから
//	//スケーリング倍率
//	XMFLOAT3 scale;
//	//回転角
//	XMFLOAT3 rotation;
//	//座標
//	XMFLOAT3 position;
//
//	//スケーリング倍率
//	scale = { 1.0f,1.0f,1.0f };
//	//回転角
//	rotation = { 0.0f,0.0f,0.0f };
//	//座標
//	position = { 0.0f,0.0f,0.0f };
//

//
//	// 頂点データ構造体
//	struct Vertex
//	{
//		XMFLOAT3 pos;	// xyz座標
//		XMFLOAT3 normal;//法線ベクトル
//		XMFLOAT2 uv;	// uv座標
//	};
//	// 頂点データ
//	Vertex vertices[] = {
//		// x      y     z       u     v
//		//前
//		{{-5.0f, -5.0f, -5.0f},{}, {0.0f, 1.0f}}, // 左下
//		{{-5.0f, 5.0f, -5.0f}, {}, {0.0f, 0.0f}}, // 左上
//		{{5.0f, -5.0f, -5.0f},{}, {1.0f, 1.0f}}, // 右下
//		{{5.0f, 5.0f, -5.0f}, {},{1.0f, 0.0f}}, // 右上
//		//後(前面とZ座標の符号が逆)
//		{{-5.0f, -5.0f, 5.0f},{}, {0.0f, 1.0f}}, // 左下
//		{{-5.0f, 5.0f, 5.0f},{}, {0.0f, 0.0f}}, // 左上
//		{{5.0f, -5.0f, 5.0f},{}, {1.0f, 1.0f}}, // 右下
//		{{5.0f, 5.0f, 5.0f},{}, {1.0f, 0.0f}}, // 右上
//		//左
//		{{-5.0f, -5.0f, -5.0f},{}, {0.0f, 1.0f}}, // 左下
//		{{-5.0f, -5.0f, 5.0f},{}, {0.0f, 0.0f}}, // 左上
//		{{-5.0f, 5.0f, -5.0f},{}, {1.0f, 1.0f}}, // 右下
//		{{-5.0f, 5.0f, 5.0f},{}, {1.0f, 0.0f}}, // 右上
//		//右(左面とX座標の符号が逆)
//		{{5.0f, -5.0f, -5.0f}, {},{0.0f, 1.0f}}, // 左下
//		{{5.0f, -5.0f, 5.0f},{}, {0.0f, 0.0f}}, // 左上
//		{{5.0f, 5.0f, -5.0f},{}, {1.0f, 1.0f}}, // 右下
//		{{5.0f, 5.0f, 5.0f},{}, {1.0f, 0.0f}}, // 右上
//		//下
//		{{-5.0f, -5.0f, -5.0f},{}, {0.0f, 1.0f}}, // 左下
//		{{-5.0f, -5.0f, 5.0f},{}, {0.0f, 0.0f}}, // 左上
//		{{5.0f, -5.0f, -5.0f} ,{}, {1.0f, 1.0f}}, // 右下
//		{{5.0f, -5.0f, 5.0f}, {},{1.0f, 0.0f}}, // 右上
//		//上(下面とY座標の符号が逆)
//		//下
//		{{-5.0f, 5.0f, -5.0f},{}, {0.0f, 1.0f}}, // 左下
//		{{-5.0f, 5.0f, 5.0f}, {},{0.0f, 0.0f}}, // 左上
//		{{5.0f, 5.0f, -5.0f},{}, {1.0f, 1.0f}}, // 右下
//		{{5.0f, 5.0f, 5.0f},{}, {1.0f, 0.0f}}, // 右上
//
//	};
//
//
//
//	// インデックスデータ
//	unsigned short indices[] = {
//		//前
//		0, 1, 2, // 三角形1つ目
//		2, 1, 3, // 三角形2つ目
//		//後
//		5,4,7,	//三角形3つ目
//		7,4,6,	//三角形4つ目
//		//左
//		8,9,10,
//		10,9,11,
//		//右
//		13,12,15,
//		15,12,14,
//		//下
//		17,16,19,
//		19,16,18,
//		//上
//		20,21,22,
//		22,21,23,
//
//	};
//
//	// 頂点データ全体のサイズ = 頂点データ一つ分のサイズ * 頂点データの要素数
//	UINT sizeVB = static_cast<UINT>(sizeof(vertices[0]) * _countof(vertices));
//
//	// 頂点バッファの設定
//	D3D12_HEAP_PROPERTIES heapProp{}; // ヒープ設定
//	heapProp.Type = D3D12_HEAP_TYPE_UPLOAD; // GPUへの転送用
//	// リソース設定
//	D3D12_RESOURCE_DESC resDesc{};
//	resDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
//	resDesc.Width = sizeVB; // 頂点データ全体のサイズ
//	resDesc.Height = 1;
//	resDesc.DepthOrArraySize = 1;
//	resDesc.MipLevels = 1;
//	resDesc.SampleDesc.Count = 1;
//	resDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
//
//	// 頂点バッファの生成
//	ComPtr<ID3D12Resource> vertBuff = nullptr;
//	result = dxCommon->GetDevice()->CreateCommittedResource(
//		&heapProp, // ヒープ設定
//		D3D12_HEAP_FLAG_NONE,
//		&resDesc, // リソース設定
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&vertBuff));
//	assert(SUCCEEDED(result));
//
//
//
//	// GPU上のバッファに対応した仮想メモリ(メインメモリ上)を取得
//	Vertex* vertMap = nullptr;
//	result = vertBuff->Map(0, nullptr, (void**)&vertMap);
//
//	// 繋がりを解除
//	vertBuff->Unmap(0, nullptr);
//
//	// 頂点バッファビューの作成
//	D3D12_VERTEX_BUFFER_VIEW vbView{};
//	// GPU仮想アドレス
//	vbView.BufferLocation = vertBuff->GetGPUVirtualAddress();
//	// 頂点バッファのサイズ
//	vbView.SizeInBytes = sizeVB;
//	// 頂点データ1つ分のサイズ
//	vbView.StrideInBytes = sizeof(vertices[0]);
//
//	ID3DBlob* vsBlob = nullptr; // 頂点シェーダオブジェクト
//	ID3DBlob* psBlob = nullptr; // ピクセルシェーダオブジェクト
//	ID3DBlob* errorBlob = nullptr; // エラーオブジェクト
//
//	// 頂点シェーダの読み込みとコンパイル
//	result = D3DCompileFromFile(
//		L"Resources/shaders/BasicVS.hlsl",  // シェーダファイル名
//		nullptr,
//		D3D_COMPILE_STANDARD_FILE_INCLUDE, // インクルード可能にする
//		"main", "vs_5_0", // エントリーポイント名、シェーダーモデル指定
//		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // デバッグ用設定
//		0,
//		&vsBlob, &errorBlob);
//
//	// エラーなら
//	if (FAILED(result)) {
//		// errorBlobからエラー内容をstring型にコピー
//		std::string error;
//		error.resize(errorBlob->GetBufferSize());
//
//		std::copy_n((char*)errorBlob->GetBufferPointer(),
//			errorBlob->GetBufferSize(),
//			error.begin());
//		error += "\n";
//		// エラー内容を出力ウィンドウに表示
//		OutputDebugStringA(error.c_str());
//		assert(0);
//	}
//
//	// ピクセルシェーダの読み込みとコンパイル
//	result = D3DCompileFromFile(
//		L"Resources/shaders/BasicPS.hlsl",   // シェーダファイル名
//		nullptr,
//		D3D_COMPILE_STANDARD_FILE_INCLUDE, // インクルード可能にする
//		"main", "ps_5_0", // エントリーポイント名、シェーダーモデル指定
//		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION, // デバッグ用設定
//		0,
//		&psBlob, &errorBlob);
//
//	// エラーなら
//	if (FAILED(result)) {
//		// errorBlobからエラー内容をstring型にコピー
//		std::string error;
//		error.resize(errorBlob->GetBufferSize());
//
//		std::copy_n((char*)errorBlob->GetBufferPointer(),
//			errorBlob->GetBufferSize(),
//			error.begin());
//		error += "\n";
//		// エラー内容を出力ウィンドウに表示
//		OutputDebugStringA(error.c_str());
//		assert(0);
//	}
//
//	// 頂点レイアウト
//	D3D12_INPUT_ELEMENT_DESC inputLayout[] = {
//		{ // xyz座標(1行で書いたほうが見やすい)
//			"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
//		},
//
//		{//法線ベクトル(1行ｓｗ書いたほうが見やすい)
//			"NORMAL",0,DXGI_FORMAT_R32G32B32_FLOAT,0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA,0
//		},
//
//		{ // uv座標(1行で書いたほうが見やすい)
//			"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0,D3D12_APPEND_ALIGNED_ELEMENT,D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0
//		},
//	};
//
//
//	// グラフィックスパイプライン設定
//	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc{};
//
//	// シェーダーの設定
//	pipelineDesc.VS.pShaderBytecode = vsBlob->GetBufferPointer();
//	pipelineDesc.VS.BytecodeLength = vsBlob->GetBufferSize();
//	pipelineDesc.PS.pShaderBytecode = psBlob->GetBufferPointer();
//	pipelineDesc.PS.BytecodeLength = psBlob->GetBufferSize();
//
//	// サンプルマスクの設定
//	pipelineDesc.SampleMask = D3D12_DEFAULT_SAMPLE_MASK; // 標準設定
//
//	// ラスタライザの設定
//	pipelineDesc.RasterizerState.CullMode = D3D12_CULL_MODE_BACK;  // カリングしない
//	pipelineDesc.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID; // ポリゴン内塗りつぶし
//	pipelineDesc.RasterizerState.DepthClipEnable = true; // 深度クリッピングを有効に
//
//	// ブレンドステート
//	//pipelineDesc.BlendState.RenderTarget[0].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;  // RBGA全てのチャンネルを描画
//	D3D12_RENDER_TARGET_BLEND_DESC& blenddesc = pipelineDesc.BlendState.RenderTarget[0];
//	blenddesc.RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
//	blenddesc.BlendEnable = true;
//	blenddesc.BlendOpAlpha = D3D12_BLEND_OP_ADD;
//	blenddesc.SrcBlendAlpha = D3D12_BLEND_ONE;
//	blenddesc.DestBlendAlpha = D3D12_BLEND_ZERO;
//
//	////加算合成
//	//blenddesc.BlendOp = D3D12_BLEND_OP_ADD;			//加算
//	//blenddesc.SrcBlend = D3D12_BLEND_ONE;			//ソースの値を100%使う
//	//blenddesc.DestBlend = D3D12_BLEND_ONE;			//デストの値を100%使う
//
//	////減算合成
//	//blenddesc.BlendOp = D3D12_BLEND_OP_REV_SUBTRACT;	//デストからソースを減算
//	//blenddesc.SrcBlend = D3D12_BLEND_ONE;				//ソースの値を100%使う
//	//blenddesc.DestBlend = D3D12_BLEND_ONE;				//デストの値を100%使う
//	//
//	////色反転
//	//blenddesc.BlendOp = D3D12_BLEND_OP_ADD;				//加算
//	//blenddesc.SrcBlend = D3D12_BLEND_INV_DEST_COLOR;	//1.0f-デストカラーの値
//	//blenddesc.DestBlend = D3D12_BLEND_ZERO;				//使わない
//
//	//半透明合成
//	blenddesc.BlendOp = D3D12_BLEND_OP_ADD;				//加算
//	blenddesc.SrcBlend = D3D12_BLEND_SRC_ALPHA;			//ソースのアルファ値
//	blenddesc.DestBlend = D3D12_BLEND_INV_SRC_ALPHA;	//1.0f-ソースのアルファ値
//
//
//	// 頂点レイアウトの設定
//	pipelineDesc.InputLayout.pInputElementDescs = inputLayout;
//	pipelineDesc.InputLayout.NumElements = _countof(inputLayout);
//
//	// 図形の形状設定
//	pipelineDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
//
//	// その他の設定
//	pipelineDesc.NumRenderTargets = 1; // 描画対象は1つ
//	pipelineDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB; // 0～255指定のRGBA
//	pipelineDesc.SampleDesc.Count = 1; // 1ピクセルにつき1回サンプリング
//
//	// デスクリプタレンジの設定
//	D3D12_DESCRIPTOR_RANGE descriptorRange{};
//	descriptorRange.NumDescriptors = 1;         //一度の描画に使うテクスチャが1枚なので1
//	descriptorRange.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
//	descriptorRange.BaseShaderRegister = 0;     //テクスチャレジスタ0番
//	descriptorRange.OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
//
//	// テクスチャサンプラーの設定
//	D3D12_STATIC_SAMPLER_DESC samplerDesc{};
//	samplerDesc.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //横繰り返し（タイリング）
//	samplerDesc.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //縦繰り返し（タイリング）
//	samplerDesc.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;                 //奥行繰り返し（タイリング）
//	samplerDesc.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;  //ボーダーの時は黒
//	samplerDesc.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;                   //全てリニア補間
//	samplerDesc.MaxLOD = D3D12_FLOAT32_MAX;                                 //ミップマップ最大値
//	samplerDesc.MinLOD = 0.0f;                                              //ミップマップ最小値
//	samplerDesc.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
//	samplerDesc.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;           //ピクセルシェーダからのみ使用可能
//
//	// ルートパラメータの設定
//	D3D12_ROOT_PARAMETER rootParams[3] = {};
//	rootParams[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;    // 定数バッファビュー
//	rootParams[0].Descriptor.ShaderRegister = 0;                    // 定数バッファ番号
//	rootParams[0].Descriptor.RegisterSpace = 0;                     // デフォルト値
//	rootParams[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;   //全てのシェーダから見える
//	// テクスチャレジスタ0番
//	rootParams[1].ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;   //種類
//	rootParams[1].DescriptorTable.pDescriptorRanges = &descriptorRange;		  //デスクリプタレンジ
//	rootParams[1].DescriptorTable.NumDescriptorRanges = 1;              		  //デスクリプタレンジ数
//	rootParams[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;               //全てのシェーダから見える
//	//定数バッファ1番
//	rootParams[2].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;    // 定数バッファビュー
//	rootParams[2].Descriptor.ShaderRegister = 1;                    // 定数バッファ番号
//	rootParams[2].Descriptor.RegisterSpace = 0;                     // デフォルト値
//	rootParams[2].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;   //全てのシェーダから見える
//	// ルートシグネチャ
//	ComPtr<ID3D12RootSignature> rootSignature;
//	// ルートシグネチャの設定
//	D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc{};
//	rootSignatureDesc.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
//	rootSignatureDesc.pParameters = rootParams; //ルートパラメータの先頭アドレス
//	rootSignatureDesc.NumParameters = _countof(rootParams);        //ルートパラメータ数
//	rootSignatureDesc.pStaticSamplers = &samplerDesc;
//	rootSignatureDesc.NumStaticSamplers = 1;
//
//
//
//
//	// ルートシグネチャのシリアライズ
//	ComPtr<ID3DBlob> rootSigBlob = nullptr;
//	result = D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1_0, &rootSigBlob, &errorBlob);
//	assert(SUCCEEDED(result));
//	result = dxCommon->GetDevice()->CreateRootSignature(0, rootSigBlob->GetBufferPointer(), rootSigBlob->GetBufferSize(), IID_PPV_ARGS(&rootSignature));
//	assert(SUCCEEDED(result));
//
//
//	// パイプラインにルートシグネチャをセット
//	pipelineDesc.pRootSignature = rootSignature.Get();
//
//	//デスステンシルステートの設定
//	pipelineDesc.DepthStencilState.DepthEnable = true;//深度テストを行う
//	pipelineDesc.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;//書き込み許可
//	pipelineDesc.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_LESS;//小さければ合格
//	pipelineDesc.DSVFormat = DXGI_FORMAT_D32_FLOAT;//深度値フォーマット
//
//	// パイプランステートの生成
//	ComPtr<ID3D12PipelineState> pipelineState = nullptr;
//	result = dxCommon->GetDevice()->CreateGraphicsPipelineState(&pipelineDesc, IID_PPV_ARGS(&pipelineState));
//	assert(SUCCEEDED(result));
//
//
//
//
//	// ヒープ設定
//	D3D12_HEAP_PROPERTIES cbHeapProp{};
//	cbHeapProp.Type = D3D12_HEAP_TYPE_UPLOAD;                   // GPUへの転送用
//	// リソース設定
//	D3D12_RESOURCE_DESC cbResourceDesc{};
//	cbResourceDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
//	cbResourceDesc.Width = (sizeof(ConstBufferDataMaterial) + 0xff) & ~0xff;   // 256バイトアラインメント
//	cbResourceDesc.Height = 1;
//	cbResourceDesc.DepthOrArraySize = 1;
//	cbResourceDesc.MipLevels = 1;
//	cbResourceDesc.SampleDesc.Count = 1;
//	cbResourceDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
//
//	ComPtr<ID3D12Resource> constBuffMaterial = nullptr;
//	// 定数バッファの生成
//	result = dxCommon->GetDevice()->CreateCommittedResource(
//		&cbHeapProp, // ヒープ設定
//		D3D12_HEAP_FLAG_NONE,
//		&cbResourceDesc, // リソース設定
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&constBuffMaterial));
//	assert(SUCCEEDED(result));
//
//	// 定数バッファのマッピング
//	ConstBufferDataMaterial* constMapMaterial = nullptr;
//	result = constBuffMaterial->Map(0, nullptr, (void**)&constMapMaterial); // マッピング
//	assert(SUCCEEDED(result));
//
//	// 値を書き込むと自動的に転送される
//	constMapMaterial->color = XMFLOAT4(1, 1, 1, 1.0f);              // RGBAで半透明の赤
//
//
//	//3Dオブジェクトの数
//	const size_t kObjectCount = 50;
//	//3Dオブジェクトの配列
//	Object3d object3ds[kObjectCount];
//
//	for (int i = 0; i < _countof(object3ds); i++) {
//		//初期化
//		InitializeObject3d(&object3ds[i], dxCommon->GetDevice());
//
//		//ここから↓は親子構造のサンプル
//		//先頭以外なら
//		if (i > 0) {
//			//一つ前のオブジェクトを親オブジェクトとする
//			object3ds[i].parent = &object3ds[i - 1];
//			//親オブジェクトの9割の大きさ
//			object3ds[i].scale = { 0.9f,0.9f,0.9f };
//			//親オブジェクトに対してZ軸周りに30度回転
//			object3ds[i].rotation = { 0.0f,0.0f,XMConvertToRadians(30.0f) };
//
//			//親オブジェクトに対してZ方向-8.0ずらす
//			object3ds[i].position = { 0.0f,0.0f,-8.0f };
//		}
//	}
//
//
//	////平行投影行列の計算
//	//constMapTransform->mat = XMMatrixOrthographicOffCenterLH(
//	//0.0f,window_width,
//	//window_height,0.0f ,
//	//0.0f,1.0f
//	//);
//
//	//透視投影変換行列の計算
//	XMMATRIX matProjection = XMMatrixPerspectiveFovLH(
//		XMConvertToRadians(45.0f),
//		(float)WinApp::window_width / WinApp::window_height,
//		0.1f, 1000.0f
//	);
//
//
//	//ワールド変換行列
//	XMMATRIX matWorld;
//	matWorld = XMMatrixIdentity();
//
//	//matScale = XMMatrixScaling(1.0f, 0.5f, 1.0f);
//	//matWorld *= matScale;//ワールド行列にスケーリング
//
//	//matWorld *= matRot;
//	//matTrans = XMMatrixTranslation(-50.0f, 0, 0);
//	//matWorld *= matTrans;
//
//	////定数バッファに転送
//	//constMapTransform->mat = matWorld*matView * matProjection;
//
//
//
////// 横方向ピクセル数
////const size_t textureWidth = 256;
////// 縦方向ピクセル数
////const size_t textureHeight = 256;
////// 配列の要素数
////const size_t imageDataCount = textureWidth * textureHeight;
////// 画像イメージデータ配列
////XMFLOAT4* imageData = new XMFLOAT4[imageDataCount]; // ※必ず後で解放する
//
////// 全ピクセルの色を初期化
////for (size_t i = 0; i < imageDataCount; i++) {
////		imageData[i].x = 1.0f;    // R
////		imageData[i].y = 0.0f;    // G
////		imageData[i].z = 0.0f;    // B
////		imageData[i].w = 1.0f;    // A
////}
//
//
//	//画像1枚目
//	TexMetadata metadata{};
//	ScratchImage scratchImg{};
//	// WICテクスチャのロード
//	result = LoadFromWICFile(
//		L"Resources/mario.jpg",   //「Resources」フォルダの「lavender.jpg」
//		WIC_FLAGS_NONE,
//		&metadata, scratchImg);
//
//	ScratchImage mipChain{};
//	// ミップマップ生成
//	result = GenerateMipMaps(
//		scratchImg.GetImages(), scratchImg.GetImageCount(), scratchImg.GetMetadata(),
//		TEX_FILTER_DEFAULT, 0, mipChain);
//	if (SUCCEEDED(result)) {
//		scratchImg = std::move(mipChain);
//		metadata = scratchImg.GetMetadata();
//	}
//
//	// 読み込んだディフューズテクスチャをSRGBとして扱う
//	metadata.format = MakeSRGB(metadata.format);
//
//	// ヒープ設定
//	D3D12_HEAP_PROPERTIES textureHeapProp{};
//	textureHeapProp.Type = D3D12_HEAP_TYPE_CUSTOM;
//	textureHeapProp.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_WRITE_BACK;
//	textureHeapProp.MemoryPoolPreference = D3D12_MEMORY_POOL_L0;
//	// リソース設定
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
//	// テクスチャバッファの生成
//	ComPtr<ID3D12Resource> texBuff = nullptr;
//	result = dxCommon->GetDevice()->CreateCommittedResource(
//		&textureHeapProp,
//		D3D12_HEAP_FLAG_NONE,
//		&textureResourceDesc,
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&texBuff));
//	// 全ミップマップについて
//	for (size_t i = 0; i < metadata.mipLevels; i++) {
//		// ミップマップレベルを指定してイメージを取得
//		const Image* img = scratchImg.GetImage(i, 0, 0);
//		// テクスチャバッファにデータ転送
//		result = texBuff->WriteToSubresource(
//			(UINT)i,
//			nullptr,              // 全領域へコピー
//			img->pixels,          // 元データアドレス
//			(UINT)img->rowPitch,  // 1ラインサイズ
//			(UINT)img->slicePitch // 1枚サイズ
//		);
//		assert(SUCCEEDED(result));
//	}
//
//	//画像2枚目
//	TexMetadata metadata2{};
//	ScratchImage scratchImg2{};
//
//	// WICテクスチャのロード
//	result = LoadFromWICFile(
//		L"Resources/reimu.png",   //「Resources」フォルダの「reimu.jpg」
//		WIC_FLAGS_NONE,
//		&metadata2, scratchImg2);
//	ScratchImage mipChain2{};
//	// ミップマップ生成
//	result = GenerateMipMaps(
//		scratchImg2.GetImages(), scratchImg2.GetImageCount(), scratchImg2.GetMetadata(),
//		TEX_FILTER_DEFAULT, 0, mipChain2);
//	if (SUCCEEDED(result)) {
//		scratchImg2 = std::move(mipChain2);
//		metadata2 = scratchImg2.GetMetadata();
//	}
//
//	// 読み込んだディフューズテクスチャをSRGBとして扱う
//	metadata2.format = MakeSRGB(metadata2.format);
//
//	// リソース設定
//	D3D12_RESOURCE_DESC textureResourceDesc2{};
//	textureResourceDesc2.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
//	textureResourceDesc2.Format = metadata2.format;
//	textureResourceDesc2.Width = metadata2.width;
//	textureResourceDesc2.Height = (UINT)metadata2.height;
//	textureResourceDesc2.DepthOrArraySize = (UINT16)metadata2.arraySize;
//	textureResourceDesc2.MipLevels = (UINT16)metadata2.mipLevels;
//	textureResourceDesc2.SampleDesc.Count = 1;
//
//	// テクスチャバッファの生成
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
//	// 全ミップマップについて
//	for (size_t i = 0; i < metadata2.mipLevels; i++) {
//		// ミップマップレベルを指定してイメージを取得
//		const Image* img2 = scratchImg2.GetImage(i, 0, 0);
//		// テクスチャバッファにデータ転送
//		result = texBuff2->WriteToSubresource(
//			(UINT)i,
//			nullptr,              // 全領域へコピー
//			img2->pixels,          // 元データアドレス
//			(UINT)img2->rowPitch,  // 1ラインサイズ
//			(UINT)img2->slicePitch // 1枚サイズ
//		);
//		assert(SUCCEEDED(result));
//	}
//
//
//	//// 元データ解放
//	//delete[] imageData;
//
//	// SRVの最大個数
//	const size_t kMaxSRVCount = 2056;
//
//	// デスクリプタヒープの設定
//	D3D12_DESCRIPTOR_HEAP_DESC srvHeapDesc = {};
//	srvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
//	srvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;//シェーダから見えるように
//	srvHeapDesc.NumDescriptors = kMaxSRVCount;
//
//	// 設定を元にSRV用デスクリプタヒープを生成
//	ComPtr<ID3D12DescriptorHeap> srvHeap = nullptr;
//	result = dxCommon->GetDevice()->CreateDescriptorHeap(&srvHeapDesc, IID_PPV_ARGS(&srvHeap));
//	assert(SUCCEEDED(result));
//
//	//SRVヒープの先頭ハンドルを取得
//	D3D12_CPU_DESCRIPTOR_HANDLE srvHandle = srvHeap->GetCPUDescriptorHandleForHeapStart();
//
//	// シェーダリソースビュー設定
//	D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc{};
//	srvDesc.Format = textureResourceDesc.Format;
//	srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
//	srvDesc.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
//	srvDesc.Texture2D.MipLevels = textureResourceDesc.MipLevels;
//
//	// ハンドルの指す位置にシェーダーリソースビュー作成
//	dxCommon->GetDevice()->CreateShaderResourceView(texBuff.Get(), &srvDesc, srvHandle);
//
//
//	//二枚目の画像用
//	//一つハンドルを進める
//	UINT incrementSize = dxCommon->GetDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
//	srvHandle.ptr += incrementSize;
//
//	// シェーダリソースビュー設定
//	D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc2{};
//	srvDesc2.Format = textureResourceDesc2.Format;
//	srvDesc2.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
//	srvDesc2.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
//	srvDesc2.Texture2D.MipLevels = textureResourceDesc2.MipLevels;
//
//	// ハンドルの指す位置にシェーダーリソースビュー作成
//	dxCommon->GetDevice()->CreateShaderResourceView(texBuff2.Get(), &srvDesc2, srvHandle);
//
//
//
//	// インデックスデータ全体のサイズ
//	UINT sizeIB = static_cast<UINT>(sizeof(uint16_t) * _countof(indices));
//
//	// リソース設定
//	resDesc.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
//	resDesc.Width = sizeIB; // インデックス情報が入る分のサイズ
//	resDesc.Height = 1;
//	resDesc.DepthOrArraySize = 1;
//	resDesc.MipLevels = 1;
//	resDesc.SampleDesc.Count = 1;
//	resDesc.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
//
//	// インデックスバッファの生成
//	ComPtr<ID3D12Resource> indexBuff = nullptr;
//
//	result = dxCommon->GetDevice()->CreateCommittedResource(
//		&heapProp, // ヒープ設定
//		D3D12_HEAP_FLAG_NONE,
//		&resDesc, // リソース設定
//		D3D12_RESOURCE_STATE_GENERIC_READ,
//		nullptr,
//		IID_PPV_ARGS(&indexBuff));
//
//	// インデックスバッファをマッピング
//	uint16_t* indexMap = nullptr;
//	result = indexBuff->Map(0, nullptr, (void**)&indexMap);
//	// 全インデックスに対して
//	for (int i = 0; i < _countof(indices); i++)
//	{
//		indexMap[i] = indices[i];   // インデックスをコピー
//	}
//	// マッピング解除
//	indexBuff->Unmap(0, nullptr);
//
//	// インデックスバッファビューの作成
//	D3D12_INDEX_BUFFER_VIEW ibView{};
//	ibView.BufferLocation = indexBuff->GetGPUVirtualAddress();
//	ibView.Format = DXGI_FORMAT_R16_UINT;
//	ibView.SizeInBytes = sizeIB;

	//描画初期化処理 ここまで

	//ゲームループ
	while (true) {
		//　基盤システムの更新


		//メッセージがある？
		if (winApp->ProcessMesseage()) {
			//ゲームループを抜ける
			break;
		}

		//DirectX毎フレーム処理 ここから

		//入力の更新
		input->Update();

		switch (scene)
		{
		case title:
			//スプライト
			SpriteUpdate(titleSprite, spritecommon);
			//スペース押されたら
			if (input->TriggerKey(DIK_SPACE)) {
				//初期化
				isDead = 0;
				Player->SetPosition({ 0, 0, 0 });
				eye.z = -30;
				target.z = 0;
				isStart = false;
				isGoal = false;

				//動かない壁
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
				
				//横移動の壁
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

				//縦移動の壁
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
			//操作説明
			if (isStart == false) {
				//スプライト
				SpriteUpdate(tutorialSprite, spritecommon);
				if (input->TriggerKey(DIK_SPACE)) {
					isStart = true;
				}
			}
			else if (isStart == true) {
				if (isDead == false) {
					playerPosition = Player->GetPosition();
					// オブジェクト移動
					if (input->PushKey(DIK_RIGHT) || input->PushKey(DIK_LEFT) || input->PushKey(DIK_A) || input->PushKey(DIK_D))
					{
						// 現在の座標を取得
						playerPosition = Player->GetPosition();
						// 移動後の座標を計算
						if (playerPosition.x < 10.0f) {
							if (input->PushKey(DIK_RIGHT) || input->PushKey(DIK_D)) { playerPosition.x += 0.2f; }
						}
						if (playerPosition.x > -10.0f) {
							if (input->PushKey(DIK_LEFT) || input->PushKey(DIK_A)) { playerPosition.x -= 0.2f; }
						}
						// 座標の変更を反映
						Player->SetPosition(playerPosition);
					}
					playerPosition.z += 1.0f;
					//上下移動の処理
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

					//カメラ
					//ビュー変換行列
					matView = DirectX::XMMatrixLookAtLH(XMLoadFloat3(&eye), XMLoadFloat3(&target), XMLoadFloat3(&up));

					////天球
					//skyCylinder->Update(matView);

					//横移動の壁
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

					//縦移動の壁
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

					//壁
					for (int i = 0; i < wallnum; i++) {
						wall[i]->Update(matView);
					}


					//基盤システムの更新
					Player->Update(matView);

					floor->Update(matView);

					//当たり判定
					for (int i = 0; i < wallnum; i++) {
						if (CheakCollision(Player->GetPosition(), wall[i]->GetPosition(), Player->GetScale(), wall[i]->GetScale(), minModel2, minModel3, maxModel2, maxModel3)) {
							isDead = true;
						}
					}
					//当たり判定
					for (int i = 0; i < besideWallnum; i++) {
						if (CheakCollision(Player->GetPosition(), besideWall[i]->GetPosition(), Player->GetScale(), besideWall[i]->GetScale(), minModel2, minModel3, maxModel2, maxModel3)) {
							isDead = true;
						}
					}
					//当たり判定
					for (int i = 0; i < verticalWallnum; i++) {
						if (CheakCollision(Player->GetPosition(), verticalWall[i]->GetPosition(), Player->GetScale(), verticalWall[i]->GetScale(), minModel2, minModel3, maxModel2, maxModel3)) {
							isDead = true;
						}
					}
					//当たり判定
					if (CheakCollision(Player->GetPosition(), floor->GetPosition(), Player->GetScale(), floor->GetScale(), minModel2, minModel3, maxModel2, maxModel3)) {
						isDead = true;
					}
					//ゴール
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




		//// 4.描画コマンドここから

		dxCommon->PreDraw();

		//最初のシーンの描画

		switch (scene)
		{
		case title:

			break;
		case game:
			//3dオブジェクト描画前処理
			Object3d::PreDraw(dxCommon->GetCommandlist());

			//3dオブジェクトの描画
			/*skyCylinder->Draw();*/

			//プレイヤーの描画
			Player->Draw();
			//床
			floor->Draw();

			//壁
			for (int i = 0; i < wallnum; i++) {
				if (wall[i]->GetPosition().z + maxModel3.z >= Player->GetPosition().z - minModel2.z) {
					wall[i]->Draw();
				}
			}
			//横移動壁
			for (int i = 0; i < besideWallnum; i++) {
				if (besideWall[i]->GetPosition().z + maxModel3.z >= Player->GetPosition().z - minModel2.z) {
					besideWall[i]->Draw();
				}
			}
			//縦移動壁
			for (int i = 0; i < verticalWallnum; i++) {
				if (verticalWall[i]->GetPosition().z + maxModel3.z >= Player->GetPosition().z - minModel2.z) {
					verticalWall[i]->Draw();
				}
			}
			//3dオブジェクト描画後処理
			Object3d::PostDraw();
			break;
		case clear:
			break;
		case gameover:
			break;
		}

		//スプライト共通コマンド
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


		//スプライト前処理

		/*sprite->Draw();*/

	//最初のシーンの描画

		dxCommon->PostDraw();


		// 4.描画コマンドここまで


		////DirectX毎フレーム処理 ここまで
	}

	//　基盤システムの終了


	//入力開放
	delete input;
	//WindowsAPIの終了処理
	winApp->Finalize();
	//WindowsAPIの解放
	delete winApp;
	//DirectX解放
	delete dxCommon;
	//3dオブジェクト解放
	delete Player;
	//天球解放
	delete skyCylinder;
	//3Dモデル解放
	delete model;
	delete model2;
	delete model3;
	delete model4;
	//壁解放
	for (int i = 0; i < wallnum; i++) {
		delete wall[i];
	}
	//横移動壁解放
	for (int i = 0; i < besideWallnum; i++) {
		delete besideWall[i];
	}
	//縦移動解放
	for (int i = 0; i < verticalWallnum; i++) {
		delete verticalWall[i];
	}
	//床開放
	delete floor;

	//delete spriteCommon;

	//基盤システムの終了

	return 0;
}

