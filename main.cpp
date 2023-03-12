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
	//スプライト共通部の初期化
	spriteCommon = new SpriteCommon;
	spriteCommon->Initialize(dxCommon);


	//基盤システムの初期化

	spriteCommon->LoadTexture(0, "lavender.jpg");
	spriteCommon->LoadTexture(1, "mario.jpg");


	//最初のシーンの初期化
	Sprite* sprite0 = new Sprite();
	sprite0->Initialize(spriteCommon, 0);

	Sprite* sprite1 = new Sprite();
	sprite1->Initialize(spriteCommon, 1);
	sprite1->SetPosition({ 800,300 });
	/*OBJからモデルデータを読み込む*/
	//円柱
	XMFLOAT3 minModel = {}, maxModel = {};
	Model* model = Model::LoadFromObj("wallcube", minModel, maxModel);
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
	skyCylinder->SetScale({ 5,5,5 });
	skyCylinder->SetPosition({ -10,-5,0 });
	skyCylinder->SetRotation({ 0,0,0 });

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

		if (input->PushKey(DIK_SPACE)) {
			XMFLOAT2 sprite0pos = sprite0->GetPosition();
			sprite0pos.x += 0.5f;
			sprite0->SetPosition(sprite0pos);
		}
		if (input->TriggerKey(DIK_SPACE)) {
			XMFLOAT2 sprite1pos = sprite1->GetPosition();
			sprite1pos.x -= 1.5f;
			sprite1->SetPosition(sprite1pos);
		}
		sprite0->Update();
		sprite1->Update();

		//// 4.描画コマンドここから

		dxCommon->PreDraw();
		Object3d::PreDraw(dxCommon->GetCommandlist());
		//最初のシーンの描画

		skyCylinder->Draw();
		Player->Draw();

		Object3d::PostDraw();


		spriteCommon->PreDraw();

		sprite0->Draw();

		sprite1->Draw();

		spriteCommon->PostDraw();




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
	delete spriteCommon;
	delete sprite0;
	delete sprite1;
	//3dオブジェクト解放
	delete Player;
	//天球解放
	delete skyCylinder;
	//3Dモデル解放
	delete model;
	delete model2;

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
	//基盤システムの終了

	return 0;
}

