#include "src\Engine\Renderer\Renderer.h"

Renderer::Renderer(){

}

Renderer::~Renderer(){

}

void Renderer::initialize(){

	modelRenderer.initialize();
}

void Renderer::prepare(){

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Renderer::cleanUp(){

	modelRenderer.cleanUp();
}

void Renderer::render(){

	modelRenderer.render();

}

void Renderer::processEntity(ModelEntity &ModelEntity){

	modelRenderer.processEntities(ModelEntity);

}