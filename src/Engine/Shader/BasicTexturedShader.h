#pragma once
#include "src\Engine\Shader\Shader.h"

class BasicTexturedShader : public Shader {

public:

	void installShader();

	void render(ModelEntity &ModelEntity);

};