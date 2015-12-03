#pragma once
#include "src\Engine\Shader\Shader.h"
#include "src\Engine\Entities\TexturedModelEntity.h"

class TexturedModelShader : public Shader {

public:

	void installShader();
	void render(TexturedModelEntity &entity);


private:

	void getAllUniformLocations();

};