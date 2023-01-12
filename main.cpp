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
	
//　最初のシーンの初期化
	Object3d* object3d = Object3d::Create();

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
//	float angle = 0.0f;//カメラの回転角
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
//	//ビュー変換行列
//	XMMATRIX matView;
//	XMFLOAT3 eye(0, 0, -100);	//視点座標
//	XMFLOAT3 target(0, 0, 0);	//注視点座標
//	XMFLOAT3 up(0, 1, 0);		//上方向ベクトル
//	matView = XMMatrixLookAtLH(XMLoadFloat3(&eye), XMLoadFloat3(&target), XMLoadFloat3(&up));
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

		// オブジェクト移動
		if (input->PushKey(DIK_UP) || input->PushKey(DIK_DOWN) || input->PushKey(DIK_RIGHT) || input->PushKey(DIK_LEFT)|| input->PushKey(DIK_W)|| input->PushKey(DIK_S))
		{
			// 現在の座標を取得
			DirectX::XMFLOAT3 position = object3d->GetPosition();

			// 移動後の座標を計算
			if (input->PushKey(DIK_UP)) { position.y += 1.0f; }
			else if (input->PushKey(DIK_DOWN)) { position.y -= 1.0f; }
			if (input->PushKey(DIK_RIGHT)) { position.x += 1.0f; }
			else if (input->PushKey(DIK_LEFT)) { position.x -= 1.0f; }
			if (input->PushKey(DIK_W)) { position.z += 1.0f; }
			else if (input->PushKey(DIK_S)) { position.z -= 1.0f; }

			// 座標の変更を反映
			object3d->SetPosition(position);
		}
		//基盤システムの更新
		object3d->Update();


		/*sprite->Update();*/

		//for (int i = 0; i < _countof(indices) / 3; i++)
		//{//三角形1つごとに計算していく
		//	//三角形のインデックスを取り出して、一時的な変数に入れる
		//	unsigned short indices0 = indices[i * 3 + 0];
		//	unsigned short indices1 = indices[i * 3 + 1];
		//	unsigned short indices2 = indices[i * 3 + 2];
		//	//三角形を構成する頂点座標をベクトルに代入
		//	XMVECTOR p0 = XMLoadFloat3(&vertices[indices0].pos);
		//	XMVECTOR p1 = XMLoadFloat3(&vertices[indices1].pos);
		//	XMVECTOR p2 = XMLoadFloat3(&vertices[indices2].pos);
		//	//p0→p1ベクトル、p0→p2ベクトルを計算(ベクトルの減算)
		//	XMVECTOR v1 = XMVectorSubtract(p1, p0);
		//	XMVECTOR v2 = XMVectorSubtract(p2, p0);
		//	//外積は両方から垂直なベクトル
		//	XMVECTOR normal = XMVector3Cross(v1, v2);
		//	//正規化(長さを1にする)
		//	normal = XMVector3Normalize(normal);
		//	//求めた法線を頂点データに代入
		//	XMStoreFloat3(&vertices[indices0].normal, normal);
		//	XMStoreFloat3(&vertices[indices1].normal, normal);
		//	XMStoreFloat3(&vertices[indices2].normal, normal);
		//}

		////全頂点に対して
		//for (int i = 0; i < _countof(vertices); i++) {
		//	vertMap[i] = vertices[i]; // 座標をコピー
		//}



		////カメラ
		//if (input->TriggerKey(DIK_D) || input->TriggerKey(DIK_A)) {
		//	if (input->TriggerKey(DIK_D)) {
		//		angle += XMConvertToRadians(1.0f);
		//	}
		//	else if (input->TriggerKey(DIK_A)) {
		//		angle -= XMConvertToRadians(1.0f);
		//	}
		//	//	angleラジアンだけY軸周りに回転。半径は-100
		//	eye.x = -100 * sinf(angle);
		//	eye.z = -100 * cosf(angle);
		//	//ビュー変換行列
		//	matView = XMMatrixLookAtLH(XMLoadFloat3(&eye), XMLoadFloat3(&target), XMLoadFloat3(&up));
		//}



		////座標操作

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


		//// 4.描画コマンドここから

		dxCommon->PreDraw();

//最初のシーンの描画

		//3dオブジェクト描画前処理
		Object3d::PreDraw(dxCommon->GetCommandlist());

		//3dオブジェクトの描画
		object3d->Draw();

		//3dオブジェクト描画後処理
		Object3d::PostDraw();

		//スプライト前処理

		/*sprite->Draw();*/

//最初のシーンの描画

		dxCommon->PostDraw();
		//// パイプラインステートとルートシグネチャの設定コマンド
		//dxCommon->GetCommandlist()->SetPipelineState(pipelineState.Get());
		//dxCommon->GetCommandlist()->SetGraphicsRootSignature(rootSignature.Get());

		//// プリミティブ形状の設定コマンド
		//dxCommon->GetCommandlist()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST); // 三角形リスト

		//// 頂点バッファビューの設定コマンド
		//dxCommon->GetCommandlist()->IASetVertexBuffers(0, 1, &vbView);

		//// 定数バッファビュー(CBV)の設定コマンド
		//dxCommon->GetCommandlist()->SetGraphicsRootConstantBufferView(0, constBuffMaterial->GetGPUVirtualAddress());

		//ID3D12DescriptorHeap* ppHeaps[] = { srvHeap.Get() };
		//// SRVヒープの設定コマンド
		//dxCommon->GetCommandlist()->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);
		//// SRVヒープの先頭ハンドルを取得（SRVを指しているはず）
		//D3D12_GPU_DESCRIPTOR_HANDLE srvGpuHandle = srvHeap->GetGPUDescriptorHandleForHeapStart();
		////2枚目を指し示すようにしたSRVのハンドルをルートパラメータ1番に設定
		//srvGpuHandle.ptr += incrementSize;
		//// SRVヒープの先頭にあるSRVをルートパラメータ1番に設定
		//dxCommon->GetCommandlist()->SetGraphicsRootDescriptorTable(1, srvGpuHandle);

		//// インデックスバッファビューの設定コマンド
		//dxCommon->GetCommandlist()->IASetIndexBuffer(&ibView);


		////全オブジェクトについて処理
		//for (int i = 0; i < _countof(object3ds); i++) {
		//	DrawObject3d(&object3ds[i], dxCommon->GetCommandlist(), vbView, ibView, _countof(indices));
		//}

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
	delete object3d;

	//delete spriteCommon;

//基盤システムの終了

	return 0;
}

