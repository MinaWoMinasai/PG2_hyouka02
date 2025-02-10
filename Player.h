#pragma once
#include "HitJudgment.h"
#include "Struct.h"
#include "Bullet.h"

class Player
{

public:

	Player();

	~Player();

	// 初期化
	void Initialization();

	Vector2<float> GetPos() { return player_.pos; }
	Vector2<float> GetVelocity() { return player_.velocity; }
	Vector2<float> GetRadius() { return player_.radius; }
	int GetIsAlive() { return player_.isAlive; }
	Actor GetPlayer() { return player_; }
	Actor GetBullet();
	int GetBulletIsAlive();

	// セッター
	void SetIsHit(int isAlive) {

		isAlive = true;

	}

	// 更新処理
	void Update(const char(keys)[], const char(preKeys)[]);

	// あたり判定
	void HitAction();

	// 描画処理
	void Draw();

private:

	Actor player_;

	Actor kPlayer = { 100.0f, 100.0f, 32.0f, 32.0f, 3.0f, 3.0f, true, false };

	Actor bullet_;
	int bulletIsAlive_;

	// 弾を包含
	Bullet* bullet;

	int direction = RIGHT;

};

