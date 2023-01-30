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


	SpriteCommon* spriteCommon = nullptr;
	//スプライト共通部分の初期化
	spriteCommon = new SpriteCommon;
	spriteCommon->Initialize(dxCommon);

//基盤システムの初期化

//最初のシーンの初期化
	//テキスト
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


	/*OBJからモデルデータを読み込む*/
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
		skyCylinder->Update(matView);
		Player->Update(matView);


		//// 4.描画コマンドここから

		dxCommon->PreDraw();
		Object3d::PreDraw(dxCommon->GetCommandlist());
		//最初のシーンの描画

		skyCylinder->Draw();
		Player->Draw();

		Object3d::PostDraw();

		sprite->Draw();
		sprite1->Draw();

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
	////3dオブジェクト解放
	//delete Player;
	//////天球解放
	////delete skyCylinder;
	//////3Dモデル解放
	////delete model;

	//delete model2;
	//delete model3;
	//delete model4;
	////壁解放
	//for (int i = 0; i < wallnum; i++) {
	//	delete wall[i];
	//}
	////横移動壁解放
	//for (int i = 0; i < besideWallnum; i++) {
	//	delete besideWall[i];
	//}
	////縦移動解放
	//for (int i = 0; i < verticalWallnum; i++) {
	//	delete verticalWall[i];
	//}
	////床開放
	//delete floor;

	//delete spriteCommon;

	//基盤システムの終了

	return 0;
}

