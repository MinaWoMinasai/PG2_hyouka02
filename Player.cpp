#include "Player.h"
#include "Novice.h"

Player::Player() {

	player_ = kPlayer;
	bullet = new Bullet;

}

Player::~Player() {


	delete bullet;


}

void Player::Initialization() {

	player_ = kPlayer;

}

Actor Player::GetBullet() {

	bullet_ = bullet->GetBullet();
	return bullet_;
}

int Player::GetBulletIsAlive() {


	bulletIsAlive_ = bullet->GetIsAlive();
	return bulletIsAlive_;

}

void Player::Update(const char(keys)[], const char(preKeys)[]) {

	// 方向キーで移動
	if (keys[DIK_W]) {
		player_.pos.y -= player_.velocity.y;
		direction = UP;
	}

	if (keys[DIK_S]) {
		player_.pos.y += player_.velocity.y;
		direction = DOWN;
	}

	if (keys[DIK_A]) {
		player_.pos.x -= player_.velocity.x;
		direction = LEFT;
	}

	if (keys[DIK_D]) {
		player_.pos.x += player_.velocity.x;
		direction = RIGHT;
	}

	// スペースキーで弾を撃つ
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

		bullet->BulletDeploy(direction, player_.pos);

	}

	// 弾の更新処理
	if (bullet->GetIsAlive()) {
		bullet->Update();
	}

}

void Player::HitAction() {

	player_.isAlive = false;

}

void Player::Draw() {

	// 弾の描画処理

	if (bullet->GetIsAlive()) {
		bullet->Draw();
	}


	// 自機の描画
	Novice::DrawEllipse(
		static_cast<int>(player_.pos.x), static_cast<int>(player_.pos.y),
		static_cast<int>(player_.radius.x), static_cast<int>(player_.radius.y), 0.0f,
		0xFFFFFFFF,
		kFillModeSolid
	);

}

