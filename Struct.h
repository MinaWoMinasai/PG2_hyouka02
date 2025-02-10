#pragma once

	template <typename T>
	struct Vector2 {
		T x;
		T y;
	};

	struct Actor {

		Vector2<float> pos;
		Vector2<float> radius;
		Vector2<float> velocity;

		int isAlive = true;
		int isHit = false;

	};

	// 壁
	const float kLeftX = 0.0f;
	const float kRightX = 1280.0f;
	const float kTopY = 0.0f;
	const float kBottomY = 720.0f;

	enum Direction {
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};


