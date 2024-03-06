#pragma once

#include "lab_m1/Tema1/tureta/tureta.h"





Tureta::Tureta(float x, float y, float z, glm::vec3 color)
{
	radius = 50;
	scale = 1;
	isDead = false;
	speed = 100.f;
	interval = 0.5f;
	timer = 0;
	destroy = false;
	this->x = x;
	this->y = y;
	this->z = z;
	this->color = glm::vec3(color);

	position = transform2D::Translate(x, y) * glm::mat3(1);

	tureta_romb = object2D::CreateRomb("tureta_romb", glm::vec3(-radius/2.f, 0, z+1), radius,radius*2, color, true);
	tureta_dreptunghi = object2D::CreateRectangle("tureta_dreptunghi", glm::vec3(0, 0, z), radius*1.5f, radius/2.f, color, true);

}


Stea* Tureta::Update(float deltaTime, std::vector <Inamic*> inamici) {
	Stea *stea = NULL;
	if (isDead == true && scale <= 0)
		return stea;
	if (destroy == true ) {
		scale -= 1 * deltaTime;
		if (scale <= 0)
			isDead = true;
	}
	else {
		for(int  j=0;j<inamici.size();j++)
			if (inamici[j]->getY() == y) {
				if (x + 2 * radius >= inamici[j]->getX() && inamici[j]->getX() >= x) {
					destroy = true;
					continue;
				}
			}


		timer += deltaTime;
		if (timer > interval) {
			timer = 0;
			for (int j = 0; j < inamici.size(); j++)
				if(inamici[j] != NULL && inamici[j]->isAlive() && inamici[j]->getY() == y && (color.x == inamici[j]->getColorB().x && color.y ==  inamici[j]->getColorB().y && color.z == inamici[j]->getColorB().z))
					stea = new Stea(x + 2 * radius, y, z, 200,color);
		}

	}


	position = transform2D::Translate(x, y) * transform2D::Scale(scale, scale) *glm::mat3(1);
	return stea;
}


bool Tureta::isAlive() {
	return !isDead;
}




Mesh* Tureta::getMeshRomb() {
	return tureta_romb;
}
Mesh* Tureta::getMeshDreptunghi() {
	return tureta_dreptunghi;
}

glm::mat3 Tureta::getPosition() {
	return position;
}

float Tureta::getX() {
	return x;
}

float Tureta::getY() {
	return y;
}



float Tureta::getRadius() {
	return radius;
}

Tureta::~Tureta()
{
}