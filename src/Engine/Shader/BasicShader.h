#pragma once
#include "src\Engine\Shader\Shader.h"
class BasicShader : public Shader{


public:

	void installShader();

	void render(ModelEntity &ModelEntity);

private:

};