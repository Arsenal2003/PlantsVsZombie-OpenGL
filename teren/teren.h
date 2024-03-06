#pragma once
#include "../object2D.h"
#include "../transform2D.h"
#include "../inamic/inamic.h"
#include "../tureta/tureta.h"
#include <vector>
#include<tuple>

class Teren
{
public:
    explicit Teren();
    ~Teren();
    bool isAlive();
    void Update(float deltaTime);
    Mesh* getTerain();
    Mesh* getDeadZone();
    Mesh* getHeartFill();
    Mesh* getHeartNoFill();
    Mesh* getStarRandom();
    Mesh* getStarValue(); 
    int getMaxStars();
    int getStars();
    int getMaxLives();
    int getLives();
    void setStars(int i);
    void setLifes(int i);
    bool isInSquare(int x, int y, int x_sq_c, int y_sq_c, float radius);
    std::vector <Inamic*> inamici;
    std::vector <Tureta*> turete;
    std::vector <Stea*> proiectile;
    std::vector <Stea*> puncte;
    std::vector <std::tuple<int, int>> puncte_cumparare_turete;
    std::vector <std::tuple<int, int>> puncte_plots;
    Tureta* roz_t;
    Tureta* alb_t;
    Tureta* albastru_t;
    Tureta* mov_t;
    Mesh* box_select_mesh;


private:
    
    Mesh* terain_mesh;
    Mesh* dead_zone;
    Mesh* heart_fill;
    Mesh* heart_no_fill;
    Mesh* star_value;
    Mesh* star_random;

    int nr_lives;
    int max_lives;

    float radius_terain;

    int nr_stars;
    int max_stars;

    float speed_inamici;
    int hp_inamici;
    int nr_inamici_spawn;
    float interval_spawn_inamici;
    float timer_inamici;

    int nr_puncte;
    float interval_spawn_puncte;
    float timer_puncte;

    glm::vec3 roz = glm::vec3(0.98f, 0.01f, 0.631f);
    glm::vec3 portocaliu = glm::vec3(1.f, 0.6f, 0.2f);
    glm::vec3 maro = glm::vec3(0.6, 0.29, 0);
    glm::vec3 alb = glm::vec3(1, 1, 1);
    glm::vec3 mov = glm::vec3(0.38, 0.03, 0.37);
    glm::vec3 albastru = glm::vec3(0.1,0.2,0.9);



};