#pragma once
#include "src\Engine\Lights\LightManager.h"
#include "src\Engine\Camera\Camera.h"
#include "glm\glm.hpp"
#include "src\Engine\Math\GLMath.h"


class Scene{

public:

	LightManager lightManager;

	inline void assignCamera(Camera &camera){ this->camera = &camera; }
	inline glm::mat4& getProjectionMatrix(){ return projectionMatrix; }
	inline void setProjectionMatrix(glm::mat4 matrix){ projectionMatrix = matrix; }
	inline glm::mat4 getViewMatrix(){ return camera->getViewMatrix(); }

	
private:

	Camera *camera;
	glm::mat4 projectionMatrix;


};