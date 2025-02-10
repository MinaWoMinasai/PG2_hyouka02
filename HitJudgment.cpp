#include "HitJudgment.h"

int HitCircle(Actor circle1, Actor circle2) {

	if (circle1.radius.x + circle2.radius.x >=
		sqrtf(static_cast<float>(
			powf(circle1.pos.x - circle2.pos.x, 2) +
			powf(circle1.pos.y - circle2.pos.y, 2)))) {

		return true;

	}

	return false;
}
