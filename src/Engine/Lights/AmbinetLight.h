#pragma once
#include <glm\glm.hpp>

class AmbientLight{

public:
	AmbientLight(glm::vec3 color) : color(color) {}

	inline void setColor(glm::vec3 color) { this->color = color; }

	inline glm::vec3& getColor() { return color; }

private:

	glm::vec3 position;
	glm::vec3 color;
};