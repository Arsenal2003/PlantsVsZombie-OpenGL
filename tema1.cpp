#pragma once
#include "lab_m1/Tema1/tema1.h"


using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{   
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);


    teren = new Teren();


    roz = glm::vec3(0.98f, 0.01f, 0.631f);
    portocaliu = glm::vec3(1.f, 0.6f, 0.2f);
    maro = glm::vec3(0.6, 0.29, 0);
    alb = glm::vec3(1, 1, 1);
    mov = glm::vec3(0.38, 0.03, 0.37);
    albastru = glm::vec3(0.1, 0.2, 0.9);


    
    star1 = new Stea(0, 0, 10, 0, glm::vec3(0.62f, 0.65f, 0.63f));
    tureta = new Tureta(100,100,1, roz);
    

   
}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{


    if (teren->getLives() == 0) {
        exit(0);
    }

    // afisare viata
    for (int i = 0; i < teren->getMaxLives(); i++) {
        if(i < teren->getLives())
            RenderMesh2D(teren->getHeartFill(), shaders["VertexColor"], transform2D::Translate(150 * (i + 1), 650));
        else
            RenderMesh2D(teren->getHeartNoFill(), shaders["VertexColor"], transform2D::Translate(150 * (i + 1), 650));    
    }
    // afisare nr puncte obtinute 
    for (int i = 0; i < teren->getMaxStars(); i++) {
        if (i < teren->getStars())
            RenderMesh2D(teren->getStarValue(), shaders["VertexColor"], transform2D::Translate(50 + 40 * (i + 1), 550));
    }

    // afisare turete de cumparat
    {
        RenderMesh2D(teren->box_select_mesh, shaders["VertexColor"], teren->roz_t->getPosition());
        RenderMesh2D(teren->box_select_mesh, shaders["VertexColor"], teren->alb_t->getPosition());
        RenderMesh2D(teren->box_select_mesh, shaders["VertexColor"], teren->albastru_t->getPosition());
        RenderMesh2D(teren->box_select_mesh, shaders["VertexColor"], teren->mov_t->getPosition());


        {
            RenderMesh2D(teren->roz_t->getMeshRomb(), shaders["VertexColor"], teren->roz_t->getPosition());
            RenderMesh2D(teren->roz_t->getMeshDreptunghi(), shaders["VertexColor"], teren->roz_t->getPosition());
            RenderMesh2D(teren->getStarValue(), shaders["VertexColor"], transform2D::Translate(630, 580));
            RenderMesh2D(teren->getStarValue(), shaders["VertexColor"], transform2D::Translate(670, 580));
        }
        
        {
            RenderMesh2D(teren->alb_t->getMeshRomb(), shaders["VertexColor"], teren->alb_t->getPosition());
            RenderMesh2D(teren->alb_t->getMeshDreptunghi(), shaders["VertexColor"], teren->alb_t->getPosition());
            RenderMesh2D(teren->getStarValue(), shaders["VertexColor"], transform2D::Translate(800,580));
        }
        {
            RenderMesh2D(teren->mov_t->getMeshRomb(), shaders["VertexColor"], teren->mov_t->getPosition());
            RenderMesh2D(teren->mov_t->getMeshDreptunghi(), shaders["VertexColor"], teren->mov_t->getPosition());
            RenderMesh2D(teren->getStarValue(), shaders["VertexColor"], transform2D::Translate(950, 580));

        }
        {
            RenderMesh2D(teren->albastru_t->getMeshRomb(), shaders["VertexColor"], teren->albastru_t->getPosition());
            RenderMesh2D(teren->albastru_t->getMeshDreptunghi(), shaders["VertexColor"], teren->albastru_t->getPosition());
            RenderMesh2D(teren->getStarValue(), shaders["VertexColor"], transform2D::Translate(1060, 580));
            RenderMesh2D(teren->getStarValue(), shaders["VertexColor"], transform2D::Translate(1100, 580));
            RenderMesh2D(teren->getStarValue(), shaders["VertexColor"], transform2D::Translate(1140, 580));
        }
    
    }




    { // render terain plots 
        RenderMesh2D(teren->getDeadZone(), shaders["VertexColor"], transform2D::Translate(50, 250));
        
        RenderMesh2D(teren->getTerain(), shaders["VertexColor"], transform2D::Translate(get<0>(teren->puncte_plots[0]), get<1>(teren->puncte_plots[0])));
        RenderMesh2D(teren->getTerain(), shaders["VertexColor"], transform2D::Translate(get<0>(teren->puncte_plots[1]), get<1>(teren->puncte_plots[1])));
        RenderMesh2D(teren->getTerain(), shaders["VertexColor"], transform2D::Translate(get<0>(teren->puncte_plots[2]), get<1>(teren->puncte_plots[2])));

        RenderMesh2D(teren->getTerain(), shaders["VertexColor"], transform2D::Translate(get<0>(teren->puncte_plots[3]), get<1>(teren->puncte_plots[3])));
        RenderMesh2D(teren->getTerain(), shaders["VertexColor"], transform2D::Translate(get<0>(teren->puncte_plots[4]), get<1>(teren->puncte_plots[4])));
        RenderMesh2D(teren->getTerain(), shaders["VertexColor"], transform2D::Translate(get<0>(teren->puncte_plots[5]), get<1>(teren->puncte_plots[5])));

        RenderMesh2D(teren->getTerain(), shaders["VertexColor"], transform2D::Translate(get<0>(teren->puncte_plots[6]), get<1>(teren->puncte_plots[6])));
        RenderMesh2D(teren->getTerain(), shaders["VertexColor"], transform2D::Translate(get<0>(teren->puncte_plots[7]), get<1>(teren->puncte_plots[7])));
        RenderMesh2D(teren->getTerain(), shaders["VertexColor"], transform2D::Translate(get<0>(teren->puncte_plots[8]), get<1>(teren->puncte_plots[8])));
    }
    
    
    if (click_tureta == true) {
        if (tip_tureta == 0) {
            RenderMesh2D(teren->roz_t->getMeshRomb(), shaders["VertexColor"], transform2D::Translate(x_tureta,y_tureta));
            RenderMesh2D(teren->roz_t->getMeshDreptunghi(), shaders["VertexColor"], transform2D::Translate(x_tureta, y_tureta));
            cost_tureta = 2;
        }
        if (tip_tureta == 1) {
            RenderMesh2D(teren->alb_t->getMeshRomb(), shaders["VertexColor"], transform2D::Translate(x_tureta, y_tureta));
            RenderMesh2D(teren->alb_t->getMeshDreptunghi(), shaders["VertexColor"], transform2D::Translate(x_tureta, y_tureta));
            cost_tureta = 1;
        }
        if (tip_tureta == 2) {
            RenderMesh2D(teren->mov_t->getMeshRomb(), shaders["VertexColor"], transform2D::Translate(x_tureta, y_tureta));
            RenderMesh2D(teren->mov_t->getMeshDreptunghi(), shaders["VertexColor"], transform2D::Translate(x_tureta, y_tureta));
            cost_tureta = 1;
        }
        if (tip_tureta == 3) {
            RenderMesh2D(teren->albastru_t->getMeshRomb(), shaders["VertexColor"], transform2D::Translate(x_tureta, y_tureta));
            RenderMesh2D(teren->albastru_t->getMeshDreptunghi(), shaders["VertexColor"], transform2D::Translate(x_tureta, y_tureta));
            cost_tureta = 3;
        }
    
    
    }


    teren->Update(deltaTimeSeconds);


    // puncte
    for (int i = 0; i < teren->puncte.size(); i++) {
        if (teren->puncte[i]->isAlive()) {
            RenderMesh2D(teren->puncte[i]->getMesh(), shaders["VertexColor"], teren->puncte[i]->getPosition() );

        }
        else {
            teren->puncte.erase(teren->puncte.begin() + i);
            i--;
        }

    }
    
    // turete
    Stea* s;
    for (int i = 0; i < teren->turete.size(); i++) {
        if (teren->turete[i] != NULL)
            if (teren->turete[i]->isAlive()) {
                if (teren->turete[i] != NULL) {
                    s = teren->turete[i]->Update(deltaTimeSeconds, teren->inamici);
                    if (s != NULL) {
                        teren->proiectile.push_back(s);
                    }

                RenderMesh2D(teren->turete[i]->getMeshRomb(), shaders["VertexColor"], teren->turete[i]->getPosition());
                RenderMesh2D(teren->turete[i]->getMeshDreptunghi(), shaders["VertexColor"], teren->turete[i]->getPosition());
            }
        }    
    }


   // proiectile  
    for (int i = 0; i < teren->proiectile.size(); i++) {
        teren->proiectile[i]->Update(deltaTimeSeconds,teren->inamici);
        if (!teren->proiectile[i]->isAlive()) {
            teren->proiectile.erase(teren->proiectile.begin() + i);
            i--;
        }
        else {
            RenderMesh2D(teren->proiectile[i]->getMesh(), shaders["VertexColor"], teren->proiectile[i]->getPosition());
            
        
        }
    
    
    }


    // inamici 
    for (int i = 0; i < teren->inamici.size(); i++) {
        teren->inamici[i]->Update(deltaTimeSeconds);

        if (teren->inamici[i]->isAlive()) {
            RenderMesh2D(teren->inamici[i]->getMeshHexBody(), shaders["VertexColor"], teren->inamici[i]->getPosition() * transform2D::Rotate(1.57f));
            RenderMesh2D(teren->inamici[i]->getMeshHexHead(), shaders["VertexColor"], teren->inamici[i]->getPosition());
        }
        else {
            if (teren->inamici[i]->getX() <= 40)
                teren->setLifes(teren->getLives() - 1);
            teren->inamici.erase(teren->inamici.begin() + i);
            i--;
        }
    }
     





    
    



}


void Tema1::FrameEnd()
{
    
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
    // Treat continuous update based on input


}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event

    
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event


}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
    if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT) == true && click_tureta == true) {
        x_tureta = mouseX;
        y_tureta = 720 - mouseY;
    }
    else {
        click_tureta = false;
        tip_tureta = -1;
        x_tureta = -100;
        y_tureta = -100;
    }
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    
    // Add mouse button press event
    if (button == GLFW_MOUSE_BUTTON_LEFT|| button == GLFW_MOUSE_BUTTON_3) {
        //cout << "ceva";
        for (int i = 0; i < teren->puncte_plots.size(); i++) {
            if (teren->isInSquare(mouseX, 720 - mouseY, get<0>(teren->puncte_plots[i]), get<1>(teren->puncte_plots[i]), 100) == true) {
                if (teren->turete[i] != NULL)
                    teren->turete[i]->destroy = true;

            }

        }

    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT ||button == GLFW_MOUSE_BUTTON_2) {
        
        //for (int i = 0; i < teren->puncte_plots.size(); i++) {
        //    if (teren->isInSquare(mouseX, 720 - mouseY, get<0>(teren->puncte_plots[i]), get<1>(teren->puncte_plots[i]), 100) == true) {
        //        teren->turete[i] = new Tureta(get<0>(teren->puncte_plots[i]), get<1>(teren->puncte_plots[i]), 1, roz);
        //                
        //    }
        //
        //}

        for (int i = 0; i < teren->puncte_cumparare_turete.size(); i++) {
            if (teren->isInSquare(mouseX, 720 - mouseY, get<0>(teren->puncte_cumparare_turete[i]), get<1>(teren->puncte_cumparare_turete[i]), 100) == true) {

                tip_tureta = i;
                switch (tip_tureta)
                {
                case 0: cost_tureta = 2; break;
                case 1: cost_tureta = 1; break;
                case 2: cost_tureta = 1; break;
                case 3: cost_tureta = 3; break;
                default:
                    break;
                }
          
                if (teren->getStars() - cost_tureta >= 0) {
                    click_tureta = true;
                    teren->setStars(teren->getStars() - cost_tureta);
                }
                else {
                    tip_tureta = -1;
                }
                

  
            }

        }

        
        for (int i = 0; i < teren->puncte.size(); i++) {
            
            if (teren->isInSquare(mouseX, 720 - mouseY, teren->puncte[i]->getX(), teren->puncte[i]->getY(), teren->puncte[i]->getRadius()) == true) {
                teren->puncte[i]->setIsDead();
                if(teren->getStars() <= 12)
                    teren->setStars(teren->getStars() + 1);
                teren->puncte.erase(teren->puncte.begin() + i);
                i--;
            }
            
        }


    }
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
    bool placed = false;
    for (int i = 0; i < teren->puncte_plots.size(); i++) {
        if (teren->isInSquare(mouseX, 720 - mouseY, get<0>(teren->puncte_plots[i]), get<1>(teren->puncte_plots[i]), 100) == true) {
            placed = true;
            if(tip_tureta == 0)
                teren->turete[i] = new Tureta(get<0>(teren->puncte_plots[i]), get<1>(teren->puncte_plots[i]), 1, roz);
            if (tip_tureta == 1)
                teren->turete[i] = new Tureta(get<0>(teren->puncte_plots[i]), get<1>(teren->puncte_plots[i]), 1, alb);
            if (tip_tureta == 2)
                teren->turete[i] = new Tureta(get<0>(teren->puncte_plots[i]), get<1>(teren->puncte_plots[i]), 1, mov);
            if (tip_tureta == 3)
                teren->turete[i] = new Tureta(get<0>(teren->puncte_plots[i]), get<1>(teren->puncte_plots[i]), 1, albastru);
            x_tureta = -100;
            y_tureta = -100;
            click_tureta = false;
            tip_tureta = -1;
            return;
        }

    }
    if (placed == false) {
        if(teren->getStars() - cost_tureta >=0 )
            teren->setStars(teren->getStars() + cost_tureta);
    
    }
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
    // Treat mouse scroll event
}


void Tema1::OnWindowResize(int width, int height)
{
    // Treat window resize event

}
