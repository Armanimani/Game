#pragma once
#include "src\Engine\Shader\Shader.h"
#include "glm\glm.hpp"
#include "src\Engine\Lights\AmbinetLight.h"
#include "src\Engine\Lights\Light.h"
#include "src\Engine\Entities\ColoredModelEntity.h"

class ColoredModelShader : public Shader{


public:

	void installShader();
	void render(ColoredModelEntity &ModelEntity);

	void loadLightColor(glm::vec3 color);
	void loadLightPosition(glm::vec3 position);
	void loadAmbientLightning(glm::vec3 color);

	void loadAmbientLight(AmbientLight &light);
	void loadLight(Light &light);

private:
	
	GLuint location_lightColor;
	GLuint location_lightPosition;
	GLuint location_ambientLightning;


	void getAllUniformLocations();

};