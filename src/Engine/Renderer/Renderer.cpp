#include "src\Engine\Renderer\Renderer.h"
using glm::mat4;
Renderer::Renderer(){

}

Renderer::~Renderer(){

}

void Renderer::initialize(){

	modelRenderer.installShaders();
	modelRenderer.initialize(projectionMatrix, viewMatrix);
}

void Renderer::assignCamera(Camera &camera){
	
	this->camera = &camera;
}

void Renderer::setProjectionMatrix(glm::mat4 projectionMatrix){

	this->projectionMatrix = projectionMatrix;
}

void Renderer::prepare(){

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Renderer::cleanUp(){

	modelRenderer.cleanUp();
}

void Renderer::render(){

	prepare();
	viewMatrix = camera->getViewMatrix();

	modelRenderer.render();
}

void Renderer::processEntity(ModelEntity &ModelEntity){

	modelRenderer.processEntities(ModelEntity);


}
