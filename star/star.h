#pragma once
#include "../object2D.h"
#include "../transform2D.h"
#include "../inamic/inamic.h"


class Stea
{
public:
    explicit Stea(float x, float y, float z, float speed, glm::vec3 color);
    ~Stea();
    Mesh* getMesh();
    glm::mat3 getPosition();
    void Update(float deltaTime, std::vector <Inamic*> i);
    bool isAlive();
    float getX();
    float getY();
    float getRadius();
    void setIsDead();

private:


    Mesh* star_mesh;
    float speed;
    float radius;
    float x, y, z;
    glm::mat3 position;
    float scale;
    float rotation;
    float rotation_step;
    bool isDead;
    glm::vec3 color;


};