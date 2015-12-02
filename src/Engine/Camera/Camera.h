#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include "src\Engine\Settings\EngineSettings.h"
class Camera
{
public:
	Camera();
	~Camera();

	glm::mat4 getViewMatrix();

	glm::vec3 getPosition();
	glm::vec3 getViewDirection();
	glm::vec3 getUpDirection();
	glm::vec3 getViewPosition();

	void setPosition(glm::vec3 position);
	void setViewDirection(glm::vec3 viewDirection);
	void setUpDirection(glm::vec3);
	void setViewPosition(glm::vec3 ViewPosition);

	void reset();

	void cameraTranslate(glm::vec2 Delta);
	void cameraZoom(float Delta);
	void cameraRotateX(float Delta);
	void cameraRotateY(float Delta);
	void cameraRotateZ(float Delta);
	void cameraOrbit(glm::vec2 Delta);

private:


	glm::vec3 position = glm::vec3(0.0f, 0.0f, 5.0f);
	glm::vec3 viewPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 viewDirection = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 upDirection = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 rightDirection = glm::vec3(1.0f, 0.0f, 0.0f);




};