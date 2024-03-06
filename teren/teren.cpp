#pragma once

#include "lab_m1/Tema1/teren/teren.h"


#include <iostream>
using namespace std;

Teren::Teren()
{


    terain_mesh = object2D::CreateRectangle("terain", glm::vec3(0,0,0), 100, 100, glm::vec3(0, 0.8, 0), true);
    box_select_mesh = object2D::CreateRectangle("box", glm::vec3(0, 0, 0), 100, 100, glm::vec3(0.62f, 0.65f, 0.63f), false);
    dead_zone = object2D::CreateRectangle("dead_zone", glm::vec3(0, 0, 0), 20, 400, glm::vec3(0.9, 0.1, 0), true);
    heart_fill = object2D::CreateHeart("inima_fill", glm::vec3(0, 0, 1), 100, glm::vec3(1, 0, 0), true);
    heart_no_fill = object2D::CreateHeart("inima_no_fill", glm::vec3(0, 0, 1), 100, glm::vec3(1, 0, 0), false);
    star_value = object2D::CreateStar("star", glm::vec3(0, 0, 0), 20, glm::vec3(0.62f,0.65f,0.63f), true);
    star_random = object2D::CreateStar("star", glm::vec3(0, 0, 10), 10, glm::vec3(1, 0.97f, 0.27f), true);
    max_lives = 3;
    nr_lives = max_lives;
    nr_stars = 0;
    max_stars = 12;

    hp_inamici = 1;
    speed_inamici = 40;
    nr_inamici_spawn = 3;

    puncte_cumparare_turete.push_back(std::make_tuple(650, 650));
    puncte_cumparare_turete.push_back(std::make_tuple(800, 650));
    puncte_cumparare_turete.push_back(std::make_tuple(950, 650));
    puncte_cumparare_turete.push_back(std::make_tuple(1100, 650));

    roz_t = new Tureta(get<0>(puncte_cumparare_turete[0]), get<1>(puncte_cumparare_turete[0]), 1, roz);
    alb_t = new Tureta(get<0>(puncte_cumparare_turete[1]), get<1>(puncte_cumparare_turete[1]), 1, alb);
    mov_t = new Tureta(get<0>(puncte_cumparare_turete[2]), get<1>(puncte_cumparare_turete[2]), 1, mov);
    albastru_t = new Tureta(get<0>(puncte_cumparare_turete[3]), get<1>(puncte_cumparare_turete[3]), 1, albastru);

    for (int i = 0; i < 9; i++) {
        turete.push_back(new Tureta(0,0,1,roz));
        turete[i] = NULL;
    }


    puncte_plots.push_back(std::make_tuple(150, 100));
    puncte_plots.push_back(std::make_tuple(300, 100));
    puncte_plots.push_back(std::make_tuple(450, 100));    
    
    puncte_plots.push_back(std::make_tuple(150, 250));
    puncte_plots.push_back(std::make_tuple(300, 250));
    puncte_plots.push_back(std::make_tuple(450, 250));
    
    puncte_plots.push_back(std::make_tuple(150, 400));
    puncte_plots.push_back(std::make_tuple(300, 400));
    puncte_plots.push_back(std::make_tuple(450, 400));

    
   

}


void Teren::Update(float deltaTime) {
    timer_inamici += deltaTime;
    timer_puncte += deltaTime;

    
    if (timer_inamici >= interval_spawn_inamici) {
        interval_spawn_inamici = 4 + rand() % 10  + 0.1 * (rand() % 10);
        timer_inamici = 0;
        nr_inamici_spawn = rand() % 3 + 3;
        for (int i = 0; i < nr_inamici_spawn; i++) {
            switch ( rand()%4)
            {
            case 0: inamici.push_back(new Inamic(1200 + rand() % 100, 100.f + (rand() % 3) * 150.f, 1, speed_inamici + rand()%50 , hp_inamici, roz, portocaliu));
                break;
            case 1:inamici.push_back(new Inamic(1200 + rand() % 100, 100.f + (float)(rand() % 3) * 150.f, 3, speed_inamici + rand() % 50, hp_inamici, alb, portocaliu));
                break;
            case 2: inamici.push_back(new Inamic(1200 + rand() % 100, 100.f + (float)(rand() % 3) * 150.f, 5, speed_inamici + rand() % 50, hp_inamici, albastru, portocaliu));
                break;
            case 3: inamici.push_back(new Inamic(1200 + rand() % 100, 100.f + (float)(rand() % 3) * 150.f, 7, speed_inamici + rand() % 50, hp_inamici, mov, portocaliu));
                break;
            default:
                break;
            }
                
        }

    
    }

    if (timer_puncte >= interval_spawn_puncte) {
        timer_puncte = 0;
        interval_spawn_puncte = 6 + rand() % 5 + 0.1 * (rand() % 10);
        nr_puncte = rand() % 2 + 3;
        
        for (int i = 0; i < nr_puncte; i++) {
            puncte.push_back(new Stea(100 + rand() % 780, rand() % 500, 10, 0, glm::vec3(1, 0.97f, 0.27f)));
        
        }
    
    }



}


Mesh* Teren::getTerain() {
    return terain_mesh;
}
Mesh* Teren::getDeadZone() {
    return dead_zone;
}
Mesh* Teren::getHeartFill() {
    return heart_fill;
}
Mesh* Teren::getHeartNoFill() {
    return heart_no_fill;
}
Mesh* Teren::getStarRandom() {
    return star_random;
}
Mesh* Teren::getStarValue() {
    return star_value;
}

int Teren::getMaxLives() {
    return max_lives;
}

int Teren::getLives() {
    return nr_lives;
}
int Teren::getMaxStars() {
    return max_stars;
}
int Teren::getStars() {
    return nr_stars;
}

void Teren::setStars(int i) {
    nr_stars = i;
}
void Teren::setLifes(int i) {
    nr_lives = i;
}

bool Teren::isInSquare(int x, int y, int x_sq_c, int y_sq_c, float radius) {
    if (x >= x_sq_c - radius && x <= x_sq_c + radius)
        if (y >= y_sq_c - radius && y <= y_sq_c + radius)
            return true;

    return false;
}


Teren::~Teren()
{
}