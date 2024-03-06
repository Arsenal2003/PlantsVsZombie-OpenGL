#pragma once

#include "lab_m1/Tema1/inamic/inamic.h"





Inamic::Inamic(float x, float y, float z, float speed, int life, glm::vec3 colorBody, glm::vec3 colorHead)
{
	radius = 50;
	scale = 1;
	isDead = false;
	this->life = life;
	this->x = x;
	this->y = y;
	this->z = z;
	this->speed = speed;
	this->colorHead = glm::vec3(colorHead);
	this->colorBody = glm::vec3(colorBody);
	position = transform2D::Translate(x, y) * glm::mat3(1);
	hexagon_head = object2D::CreateHexagon("inamic_body", glm::vec3(0, 0, z + 1), radius / 1.5, colorHead, true);
	hexagon_body = object2D::CreateHexagon("inamic_head", glm::vec3(0, 0, z), radius, colorBody, true);
	
}


void Inamic::Update(float deltaTime) {
	if (isDead == true && scale <= 0)
		return;

	if (x <= 20 || life <= 0) {
		scale -= 1 * deltaTime ;
		if (scale <= 0)
			isDead = true;
	}
	else
		x -=   speed * deltaTime;
	
	position =  transform2D::Translate(x, y) * transform2D::Scale(scale, scale) * glm::mat3(1);
}



bool Inamic::isAlive() {
	return !isDead;
}



Mesh* Inamic::getMeshHexBody() {
	return hexagon_body;
}
Mesh* Inamic::getMeshHexHead() {
	return hexagon_head;
}

glm::mat3 Inamic::getPosition() {
	return position;
}

float Inamic::getX() {
	return x;
}

float Inamic::getY() {
	return y;
}

int Inamic::getLife() {
	return life;
}

void Inamic::setLife(int newLife) {
	life = newLife;
	if (life == 0)
		isDead = true;
}


float Inamic::getRadius() {
	return radius;
}

glm::vec3 Inamic::getColorB() {
	return colorBody;
}

Inamic::~Inamic()
{
}