#include "Scene.h"
#include "Novice.h"
#include "HitJudgment.h"

Scene::Scene() {

	player = new Player;
	enemy = new Enemy;

}

Scene::~Scene() {

	delete player;
	delete enemy;

}

void Scene::SwitchScene(const char(&keys)[], const char(&preKeys)[]) {

	switch (scene)
	{

	case TITLE:

		// 初期化
		hp = 5;
		enemy->Initialization();
		player->Initialization();

		// 初期化をしてゲームを始める
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

			scene = GAME;

		}

		Novice::ScreenPrintf(20, 20, "Press SPACE to Game");

		break;

	case GAME:

		///
		/// ↓更新処理ここから
		///

		//* プレイヤーと弾の更新処理
		//--------------------------------------
		player->Update(keys, preKeys);

		//* 敵の更新処理
		//--------------------------------------
		enemy->Update();

		//* 当たり判定
		//--------------------------------------

		// 弾と敵の当たり判定
		if (enemy->GetIsAlive()) {
			if (HitCircle(player->GetBullet(), enemy->GetEnemy())) {

				enemy->HitAction();
				hp--;

			}
		}


		// 自機と敵の当たり判定
		if (HitCircle(player->GetPlayer(), enemy->GetEnemy())) {

			player->HitAction();

		}


		// プレイヤーのフラグが偽になったらゲームオーバー
		if (!player->GetIsAlive()) {

			scene = GAMEOVER;

		}

		// 敵のふらぐが偽になったらクリア
		if (hp <= 0) {

			scene = CLEAR;

		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///


		//--------------------------------------
		// 敵の描画処理
		//--------------------------------------
		enemy->Draw();

		//--------------------------------------
		// プレイヤーと弾の描画処理
		//--------------------------------------
		player->Draw();

		///
		/// ↑描画処理ここまで
		///

		break;

	case GAMEOVER:

		// タイトルへ
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

			scene = TITLE;

		}

		Novice::ScreenPrintf(640, 340, "GAME OVER");
		Novice::ScreenPrintf(600, 360, "Press SPACE to Title");

		break;

	case CLEAR:


		// タイトルへ
		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

			scene = TITLE;

		}

		Novice::ScreenPrintf(640, 340, "Clear!");
		Novice::ScreenPrintf(600, 360, "Press SPACE to Title");

		break;

	}

}
