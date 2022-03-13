#pragma once
#include <iostream>
#include <vector>
#include "Wall.h"
#include <GLFW/glfw3.h>

namespace JezzBall {
	class Ball {
	public:
		Ball();
		Ball(float[], float[]);
		float* position; // [x, y]
		float* direction; // [vx, vy]
		float radius;
		std::string toString();
		bool checkCollide(Wall*);
		void ballsCollide(Ball**);
		void collideBorder();
		void draw();
		void update();
	};
	
}
