#pragma once
#include "../object2D.h"
#include "../transform2D.h"
#include "lab_m1/Tema1/inamic/inamic.h"
#include "lab_m1/Tema1/star/star.h"




class Tureta
{
public:
    explicit Tureta(float x, float y, float z, glm::vec3 color);
    ~Tureta();
    Mesh* getMeshRomb();
    Mesh* getMeshDreptunghi();
    glm::mat3 getPosition();
    Stea* Update(float deltaTime, std::vector<Inamic*> i);
    bool isAlive();
    float getX();
    float getY();
    float getRadius();
    bool destroy;

private:


    Mesh* tureta_dreptunghi;
    Mesh* tureta_romb;
    float radius;
    float speed;
    float x, y, z;
    glm::mat3 position;
    float scale;
    bool isDead;
    float timer;
    float interval;
    glm::vec3 color;

};