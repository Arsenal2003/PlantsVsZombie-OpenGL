#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateRectangle(
    const std::string &name,
    glm::vec3 point,
    float width,
    float height,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 middlePoint = point;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(middlePoint - glm::vec3(width/2, height/2, 0), color),
        VertexFormat(middlePoint - glm::vec3(width / 2, -height/2, 0), color),
        VertexFormat(middlePoint + glm::vec3(width / 2, height / 2, 0), color),
        VertexFormat(middlePoint + glm::vec3(width/2, -height/2, 0), color)
        
    };

    Mesh* rectangle = new Mesh(name);

    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}


Mesh* object2D::CreateHexagon(
    const std::string& name,
    glm::vec3 point,
    float radius,
    glm::vec3 color,
    bool fill) {

    
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(point + radius * glm::vec3(glm::cos(0), glm::sin(0) , 0), color),
        VertexFormat(point + radius * glm::vec3(glm::cos(1.04), glm::sin(1.04) , 0)  , color),
        VertexFormat(point + radius * glm::vec3(glm::cos(2.09), glm::sin(2.09) , 0), color),
        VertexFormat(point + radius * glm::vec3(glm::cos(3.14), glm::sin(3.14) , 0), color),
        VertexFormat(point + radius * glm::vec3(glm::cos(4.18), glm::sin(4.18) , 0), color),
        VertexFormat(point + radius * glm::vec3(glm::cos(5.23), glm::sin(5.23) , 0), color),
        

    };
    
    Mesh* hexagon = new Mesh(name);

    std::vector<unsigned int> indices = { 0, 1, 2, 3, 4, 5 };

    if (!fill) {
        hexagon->SetDrawMode(GL_LINE_LOOP);
    }
    else {
      
        indices.push_back(0);
        indices.push_back(2);
        indices.push_back(3);
        indices.push_back(0);
        indices.push_back(3);
        indices.push_back(5);
    }

    hexagon->InitFromData(vertices, indices);
    return hexagon;



}


Mesh* object2D::CreateRomb(
    const std::string& name,
    glm::vec3 point,
    float d1,
    float d2,
    glm::vec3 color,
    bool fill) {

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(point + glm::vec3(d1/2, 0, 0), color),
        VertexFormat(point + glm::vec3(0, -d2/2, 0)  , color),
        VertexFormat(point + glm::vec3(-d1/2, 0, 0), color),
        VertexFormat(point + glm::vec3(0, d2/2, 0), color),

    };

    Mesh* romb = new Mesh(name);

    std::vector<unsigned int> indices = { 0, 1, 2, 3};

    if (!fill) {
        romb->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
       
    }

    romb->InitFromData(vertices, indices);
    return romb;

}


Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 point,
    float radius,
    glm::vec3 color,
    bool fill) {

    float ratio = 2.61;
    std::vector<VertexFormat> vertices =
    {  // big pentagon 
        VertexFormat(point + radius * glm::vec3(glm::cos(1.57), glm::sin(1.57) , 0), color),
        VertexFormat(point + radius * glm::vec3(glm::cos(2.82), glm::sin(2.82) , 0)  , color),
        VertexFormat(point + radius * glm::vec3(glm::cos(4.08), glm::sin(4.08) , 0), color),
        VertexFormat(point + radius * glm::vec3(glm::cos(5.34), glm::sin(5.34) , 0), color),
        VertexFormat(point + radius * glm::vec3(glm::cos(6.56), glm::sin(6.56) , 0), color),
        
        // small pentagon 
        VertexFormat(point + radius / ratio * glm::vec3(glm::cos(4.71), glm::sin(4.71) , 0), color),
        VertexFormat(point + radius / ratio * glm::vec3(glm::cos(5.96), glm::sin(5.96) , 0), color),
        VertexFormat(point + radius / ratio * glm::vec3(glm::cos(7.22), glm::sin(7.22) , 0), color),
        VertexFormat(point + radius / ratio * glm::vec3(glm::cos(8.48), glm::sin(8.48) , 0), color),
        VertexFormat(point + radius / ratio * glm::vec3(glm::cos(9.73), glm::sin(9.73) , 0), color),

    };

    Mesh* star = new Mesh(name);

    std::vector<unsigned int> indices;

    if (!fill) {
        star->SetDrawMode(GL_LINE_LOOP);
        indices.push_back(0);
        indices.push_back(8);
        indices.push_back(1);
        indices.push_back(9);
        indices.push_back(2);
        indices.push_back(5);
        indices.push_back(3);
        indices.push_back(6);
        indices.push_back(4);
        indices.push_back(7);

    }
    else {
        
        indices.push_back(1);
        indices.push_back(7);
        indices.push_back(3);
        indices.push_back(0);
        indices.push_back(6);
        indices.push_back(2);
        indices.push_back(4);
        indices.push_back(2);
        indices.push_back(8);
    }

    star->InitFromData(vertices, indices);
    return star;

}


Mesh* object2D::CreateHeart(
    const std::string& name,
    glm::vec3 point,
    float size,
    glm::vec3 color,
    bool fill) {

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(point + glm::vec3(size * glm::sqrt(2) / 2, 0, 0), color),
        VertexFormat(point + glm::vec3(0, -size * glm::sqrt(2) / 2, 0)  , color),
        VertexFormat(point + glm::vec3(-size * glm::sqrt(2) / 2, 0, 0), color),
        VertexFormat(point + glm::vec3(0, size * glm::sqrt(2) / 2, 0), color),
        VertexFormat(point, color),
        VertexFormat(point + size/2 * glm::vec3(glm::cos(0.785), glm::sin(0.785) , 0), color),
        VertexFormat(point + size / 2 * glm::vec3(glm::cos(2.35), glm::sin(2.35) , 0)  , color),

    };

    Mesh* heart = new Mesh(name);

    std::vector<unsigned int> indices;

    if (!fill) {
        heart->SetDrawMode(GL_LINE_LOOP);
        indices.push_back(4);
        indices.push_back(6);
        indices.push_back(2);
        indices.push_back(1);
        indices.push_back(0);
        indices.push_back(5);
    }
    else {

        indices.push_back(4);
        indices.push_back(6);
        indices.push_back(1);

        indices.push_back(6);
        indices.push_back(2);
        indices.push_back(1);

        indices.push_back(5);
        indices.push_back(4);
        indices.push_back(1);

        indices.push_back(0);
        indices.push_back(5);
        indices.push_back(1);


    }

    heart->InitFromData(vertices, indices);
    return heart;


}