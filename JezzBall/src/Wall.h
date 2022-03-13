#pragma once
#include <iostream>
#include <vector>

namespace JezzBall {
	class Wall {
	public:
		Wall();
		Wall(float[], float[], bool);
		Wall(float[], float[], bool, bool, bool);
		float* topLeft;
		float* botRight;
		bool horizontal;
		bool leftUpDone;
		bool rightDownDone;
		bool update();
		void draw();
		std::string toString();
	private:
		float wallSpeed = 0.01;
	};

}