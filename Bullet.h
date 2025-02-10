#pragma once
#include "Struct.h"
class Bullet
{

public:

	Bullet();

	// ゲッター
	Vector2<float> GetPos() { return bullet_.pos; }
	Vector2<float> GetVelocity() { return bullet_.velocity; }
	Vector2<float> GetRadius() { return bullet_.radius; }
	Actor GetBullet() { return bullet_; }
	int GetIsAlive() { return bullet_.isAlive; }

	// セッター
	void SetVelocity(Vector2<float> velocity) {

		bullet_.velocity = velocity;

	}

	void SetIsHit(int isShot) {

		isShot = true;

	}

	// 初期化
	void Initialization();

	// 弾の配置
	void BulletDeploy(int direction, Vector2<float> pos);

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

private:

	Actor bullet_;
	Actor kBullet_ = { 100.0f, 100.0f, 16.0f, 16.0f, 0.0f, 0.0f, false, false };
	const float kMoveSpeed_ = 5.0f;

};

