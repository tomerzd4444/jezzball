#include <iostream>
#include <string>
#include <vector>
#include "Wall.h"
#include <GLFW/glfw3.h>
using namespace JezzBall;

Wall::Wall(){
	topLeft = new float[2];
	botRight = new float[2];
	leftUpDone = false;
	rightDownDone = false;
	horizontal = true;

}

Wall::Wall(float tf[], float br[], bool hor) {
	topLeft = tf;
	botRight = br;
	horizontal = hor;
	leftUpDone = false;
	rightDownDone = false;
}

Wall::Wall(float tf[], float br[], bool hor, bool lud, bool rdd) {
	topLeft = tf;
	botRight = br;
	horizontal = hor;
	leftUpDone = lud;
	rightDownDone = rdd;
}

void Wall::draw() {
	glColor3f(1, 0, 0);
	glRectf(this->topLeft[0], this->topLeft[1], this->botRight[0], this->botRight[1]);
}

bool Wall::update() {
	if (horizontal) {
		if (this->topLeft[0] > -1)
			this->topLeft[0] -= this->wallSpeed;
		if (this->botRight[0] < 1)
			this->botRight[0] += this->wallSpeed;
		return this->topLeft[0] > -1 || this->botRight[0] < 1;
	}
	if (this->topLeft[1] > -1)
		this->topLeft[1] -= this->wallSpeed;
	if (this->botRight[1] < 1)
		this->botRight[1] += this->wallSpeed;
	return this->topLeft[1] > -1 || this->botRight[1] < 1;
}

std::string Wall::toString() {
	return "Wall({" + std::to_string(this->topLeft[0]) + ", " + std::to_string(this->topLeft[1]) + "}, {" +
		std::to_string(this->botRight[0]) + ", " + std::to_string(this->botRight[1]) + "})";
}