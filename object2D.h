#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateRectangle(const std::string &name, glm::vec3 point, float width, float height, glm::vec3 color, bool fill = false);
    Mesh* CreateHexagon(const std::string& name, glm::vec3 point, float radius, glm::vec3 color, bool fill = false);
    Mesh* CreateRomb(const std::string& name, glm::vec3 point, float d1, float d2, glm::vec3 color, bool fill = false);
    Mesh* CreateStar(const std::string& name, glm::vec3 point, float radius, glm::vec3 color, bool fill = false);
    Mesh* CreateHeart(const std::string& name, glm::vec3 point, float size, glm::vec3 color, bool fill = false);
}
