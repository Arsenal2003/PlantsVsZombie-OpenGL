#pragma once

#include "lab_m1/Tema1/star/star.h"
#include <iostream>
#include <tuple>
using namespace std;




Stea::Stea(float x, float y, float z, float speed, glm::vec3 color1)
{
	radius = 50;
	scale = 1;
	isDead = false;
	rotation = 0;
	rotation_step = 100;
	this->x = x;
	this->y = y;
	this->z = z;
	this->speed = speed;
	color = glm::vec3(color1);
	position = transform2D::Translate(x, y) * glm::mat3(1);
	star_mesh = object2D::CreateStar("star", glm::vec3(0, 0, z + 1), radius, color1, true);
	

}


void Stea::Update(float deltaTime, vector <Inamic*> inamici) {
	
	if (isDead == true && scale <= 0)
		return;
	rotation -= rotation_step * deltaTime;

	if (x >= 1200) {
		scale -= 1 * deltaTime;
		if (scale <= 0)
			isDead = true;
	}
	else {
		x += speed * deltaTime;
		for (int j = 0; j < inamici.size(); j++) {
			if ((color.x == inamici[j]->getColorB().x && color.y == inamici[j]->getColorB().y && color.z == inamici[j]->getColorB().z)) {
				float d = glm::distance(x, inamici[j]->getX());
				if (y == inamici[j]->getY()) {
					if (d <= radius + inamici[j]->getRadius()) {
						isDead = true;
						inamici[j]->setLife(inamici[j]->getLife() - 1);
						if (inamici[j]->getLife() == 0)
							inamici[j]->setLife(0);
					}
				}
			}
		}

	}
	position = transform2D::Translate(x, y) * transform2D::Scale(scale, scale) * transform2D::Rotate(rotation) * glm::mat3(1)  ;
}


bool Stea::isAlive() {
	return !isDead;
}



Mesh* Stea::getMesh() {
	return star_mesh;
}


glm::mat3 Stea::getPosition() {
	return position;
}


float Stea::getX() {
	return x;
}
float Stea::getY() {
	return y;
}
float Stea::getRadius() {
	return radius;
}

void Stea::setIsDead() {
	isDead = !isDead;
}

Stea::~Stea()
{
}