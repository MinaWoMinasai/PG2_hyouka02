#include "Enemy.h"
#include "Novice.h"

void Enemy::Initialization() {

	enemy_ = kEnemy;

}


void Enemy::Update() {

	if (enemy_.isAlive) {

		// 画面端で固定(押し戻し)
		if (enemy_.pos.x < kLeftX + enemy_.radius.x) {
			enemy_.pos.x = kLeftX + enemy_.radius.x;
			enemy_.velocity.x = -enemy_.velocity.x;
		}

		if (enemy_.pos.x > kRightX - enemy_.radius.x) {
			enemy_.pos.x = kRightX - enemy_.radius.x;
			enemy_.velocity.x = -enemy_.velocity.x;
		}

		if (enemy_.pos.y < kTopY + enemy_.radius.y) {
			enemy_.pos.y = kTopY + enemy_.radius.y;
			enemy_.velocity.y = -enemy_.velocity.y;
		}

		if (enemy_.pos.y > kBottomY - enemy_.radius.y) {
			enemy_.pos.y = kBottomY - enemy_.radius.y;
			enemy_.velocity.y = -enemy_.velocity.y;
		}
	} else {

		respownTimer--;

	}

	if (respownTimer <= 0) {
		enemy_.isAlive = true;
		respownTimer = 60;
	}

}

void Enemy::HitAction() {

	enemy_.isAlive = false;

}

void Enemy::Draw() {

	// 敵の描画
	if (enemy_.isAlive) {
		Novice::DrawEllipse(
			static_cast<int>(enemy_.pos.x), static_cast<int>(enemy_.pos.y),
			static_cast<int>(enemy_.radius.x), static_cast<int>(enemy_.radius.y), 0.0f,
			0xFF0000FF,
			kFillModeSolid
		);
	}

}

