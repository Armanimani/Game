#include "src\Engine\Renderer\Renderer.h"
using glm::mat4;
Renderer::Renderer(){

}

Renderer::~Renderer(){

}

void Renderer::initialize(){

	coloredModelRenderer.installShaders();

	texturedModelRenderer.installShaders();
}

void Renderer::assignScene(Scene &scene){

	this->scene = &scene;
	coloredModelRenderer.assignScene(scene);
	texturedModelRenderer.assignScene(scene);
}


void Renderer::prepare(){

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Renderer::cleanUp(){

	coloredModelRenderer.cleanUp();
	texturedModelRenderer.cleanUp();
}

void Renderer::render(){

	prepare();

	coloredModelRenderer.render();
	texturedModelRenderer.render();
}

void Renderer::processEntity(ColoredModelEntity &entity){

	coloredModelRenderer.processEntities(entity);


}

void Renderer::processEntity(TexturedModelEntity &entity){

	texturedModelRenderer.processEntities(entity);
}