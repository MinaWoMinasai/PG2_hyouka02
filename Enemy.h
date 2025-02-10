#pragma once
#include "Struct.h"

class Enemy
{

public:

	// ������
	void Initialization();

	// �Q�b�^�[
	Vector2<float> GetPos() { return enemy_.pos; }
	Vector2<float> GetVelocity() { return enemy_.velocity; }
	Vector2<float> GetRadius() { return enemy_.radius; }
	Actor GetEnemy() { return enemy_; }
	int GetIsAlive() { return enemy_.isAlive; }

	// �����蔻��
	void HitAction();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

private:

	Actor enemy_;
	Actor kEnemy = {

		360.0f, 360.0f,
		16.0f, 16.0f,
		4.0f, 4.0f,
		true,
		false


	};

	int respownTimer = 60;

};

