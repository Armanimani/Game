#pragma once
#include "src\Engine\Shader\Shader.h"
#include "glm\glm.hpp"
class BasicShader : public Shader{


public:

	void installShader();
	void render(ModelEntity &ModelEntity);

private:

	void getAllUniformLocations();

};