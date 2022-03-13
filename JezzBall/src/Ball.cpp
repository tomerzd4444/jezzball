#include <iostream>
#include <vector>
#include "Ball.h"
#include <string>
#include <GLFW/glfw3.h>
using namespace JezzBall;

Ball::Ball() {
	position = new float[2];
	direction = new float[2];
	radius = 0.02;
}

Ball::Ball(float pos[], float dir[]){
	position = pos;
	direction = dir;
	radius = 0.02;
}

bool Ball::checkCollide(Wall* wall){
	return wall->topLeft[0] < this->position[0] && wall->botRight[0] > this->position[0]
		&& wall->topLeft[1] < this->position[1] && wall->botRight[1] > this->position[1];
}

void Ball::draw() {
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex2f(this->position[0], this->position[1]); // center of circle
	for (int i = 0; i <= 20; i++) {
		glVertex2f(
			(this->position[0] + (this->radius * cos(i * 2.0*3.1415926 / 20))), (this->position[1] + (this->radius * sin(i * 2.0 * 3.1415926 / 20)))
		);
	}
	glEnd();
}

void Ball::update(){
	this->position[0] += this->direction[0];
	this->position[1] += this->direction[1];
	//this->position[0] += this->direction[0] * sin(this->direction[1] * 3.1415926 / 180);
	//this->position[1] += this->direction[0] * cos(this->direction[1] * 3.1415926 / 180);
}

void Ball::ballsCollide(Ball** balls){
	for (int i = 0; i < sizeof(balls); i++) {
		Ball* ball = balls[i];
		if (ball == this) continue;

	}

}

void Ball::collideBorder() {
	if (this->position[0] - this->radius <= -1 || this->position[0] + this->radius >= 1) {
		this->direction[0] *= -1;
	}
	if (this->position[1] - this->radius <= -1 || this->position[1] + this->radius >= 1) {
		this->direction[1] *= -1;
	}
}


std::string Ball::toString() {
	return "Ball({ " + std::to_string(this->position[0]) + ", " + std::to_string(this->position[1]) + "})";
}