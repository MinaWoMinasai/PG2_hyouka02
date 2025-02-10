#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet()
{

	bullet_ = kBullet_;

}

void Bullet::Initialization() {

	bullet_ = kBullet_;

}

void Bullet::BulletDeploy(int direction, Vector2<float> pos) {

	if (!bullet_.isAlive) {

		bullet_.pos = pos;

		if (direction == LEFT) {
			bullet_.velocity = { -kMoveSpeed_, 0.0f };
		}

		if (direction == RIGHT) {
			bullet_.velocity = { kMoveSpeed_, 0.0f };
		}

		if (direction == UP) {
			bullet_.velocity = { 0.0f ,  -kMoveSpeed_ };
		}

		if (direction == DOWN) {
			bullet_.velocity = { 0.0f, kMoveSpeed_ };
		}

		bullet_.isAlive = true;

	}
}



void Bullet::Update() {

	if (bullet_.isAlive) {
		bullet_.pos.x += bullet_.velocity.x;
		bullet_.pos.y += bullet_.velocity.y;

		if (bullet_.pos.y <= kTopY - bullet_.radius.y) {
			bullet_.isAlive = false;
		}
	}

}

void Bullet::Draw() {
	if (bullet_.isAlive) {

		Novice::DrawEllipse(
			static_cast<int>(bullet_.pos.x),
			static_cast<int>(bullet_.pos.y),
			static_cast<int>(bullet_.radius.x),
			static_cast<int>(bullet_.radius.y),
			0.0f, 0x00FF00FF, kFillModeSolid
		);
	}
}
