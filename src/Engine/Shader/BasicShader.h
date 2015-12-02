#pragma once
#include "src\Engine\Shader\Shader.h"
class BasicShader : public Shader{


public:

	void installShader();

	void render(ModelEntity &ModelEntity);
	void loadTransformationMatrix(glm::mat4 &matrix);

private:

	GLuint location_transformationMatrix;
	
	void getAllUniformLocations();

};