#pragma once

#include "components/simple_scene.h"
#include "lab_m1/Tema1/object2D.h"
#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/inamic/inamic.h"
#include "lab_m1/Tema1/tureta/tureta.h"
#include "lab_m1/Tema1/teren/teren.h"
#include "lab_m1/Tema1/star/star.h"
#include "lab_m1/Tema1/teren/teren.h"
#include <vector>
#include <iostream>
#include<tuple>
using namespace std;

namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
     public:
        Tema1();
        ~Tema1();
        void Init() override;
        

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;


        Inamic *hex1;
        Stea *star1;
        Tureta* tureta;
        std::vector <Stea*> proiectile;
        Teren* teren;

        
        glm::vec3 roz;
        glm::vec3 rosu;
        glm::vec3 verde;
        glm::vec3 albastru;
        glm::vec3 portocaliu;
        glm::vec3 maro;
        glm::vec3 alb;
        glm::vec3 mov;

        int x_tureta = -100;
        int y_tureta = -100;
        int tip_tureta = -1;
        int cost_tureta = 0;
        bool click_tureta = false;
        
    };
}   // namespace m1
