#pragma once
#include "Player.h"
#include "Enemy.h"
#include "HitJudgment.h"
#include "Struct.h"

class Scene
{

public:

	Scene();

	~Scene();

	/// <summary>
	/// シーンを変える関数
	/// </summary>
	/// <param name="keys">キー</param>
	/// <param name="preKeys">キー</param>
	void SwitchScene(const char(&keys)[], const char(&preKeys)[]);

	enum GameScene {

		TITLE,
		GAME,
		GAMEOVER,
		CLEAR,

	};

private:

	// シーンの変数
	int scene = TITLE;

	// 包含する
	Player* player;
	Enemy* enemy;

	// 敵のhp
	int hp = 2;

};

