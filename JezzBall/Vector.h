#pragma once

namespace JezzBall {
	class Vector {
	public:
		Vector();
		Vector(float, float);
		float x;
		float y;
		float size();
		float dotProduct(Vector*, float angle);
		float angleCollision(Vector*);
		float collisionX(Vector*);
		float collisionY(Vector*);
	};
}