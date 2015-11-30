#pragma once
#include <glm\glm.hpp>

class GLMath{

public:
	static glm::mat4 createTransformationMatrix(glm::vec3 &translation, glm::vec3 &rotation, glm::vec3 &scale);

};