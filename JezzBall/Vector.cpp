#include "Vector.h"
#include <iostream>
#include <math.h>
using namespace JezzBall;

Vector::Vector() {
	this->x = 0;
	this->y = 0;
}

Vector::Vector(float x, float y) {
	this->x = x;
	this->y = y;
}

float Vector::size() {
	return std::sqrt(this->x * this->x + this->y * this->y);
}

float Vector::dotProduct(Vector* vector, float angle) {
	return this->size() * vector->size() * std::cos(angle);
}

float Vector::angleCollision(Vector* vector) {
	return std::atan(this->y / this->x) + std::atan(vector->y / vector->x);
}

float Vector::collisionX(Vector* vector) {
	//float part1 = new Vector(v1)
	return 0.0f;
}

float Vector::collisionY(Vector* vector) {
	return 0.0f;
}