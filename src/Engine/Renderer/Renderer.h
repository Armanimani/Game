#pragma once
#include "src\Engine\Renderer\ModelRenderer.h"

class Renderer {

public:

	Renderer();
	~Renderer();

	void initialize();
	void prepare();
	void cleanUp();

	void render();

	void processEntity(ModelEntity &entity);


private:

	ModelRenderer modelRenderer;

};