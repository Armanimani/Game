#pragma once
#include <glm\glm.hpp>

class Light{

public:
	Light(glm::vec3 position, glm::vec3 color) : position(position), color(color){}

	inline void setPosition(glm::vec3 position) { this->position = position; }
	inline void setColor(glm::vec3 color) { this->color = color; }

	inline glm::vec3& getPosition() { return position; }
	inline glm::vec3& getColor() { return color; }

private:

	glm::vec3 position;
	glm::vec3 color;

};