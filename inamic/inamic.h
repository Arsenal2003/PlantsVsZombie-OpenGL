#pragma once
#include "../object2D.h"
#include "../transform2D.h"



class Inamic 
{
public:
    explicit Inamic(float x, float y, float z,float speed, int lifes, glm::vec3 colorB, glm::vec3 colorH);
    ~Inamic();
    Mesh* getMeshHexBody();
    Mesh* getMeshHexHead();
    glm::mat3 getPosition();
    void Update(float deltaTime);
    bool isAlive();
    float getX();
    float getY();
    float getRadius();
    int getLife();
    void setLife(int life);
    glm::vec3 getColorB();
    

private:


    Mesh* hexagon_head;
    Mesh* hexagon_body;
    float speed;
    float radius;
    float x, y, z;
    glm::mat3 position;
    float scale;
    int life;
    bool isDead;
    glm::vec3 colorBody;
    glm::vec3 colorHead;
    
    
    
};