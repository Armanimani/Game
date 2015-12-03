#include "GL\glew.h"
#include "src\Engine\Renderer\ColoredModelRenderer.h"
#include "glm\glm.hpp"

using glm::mat4;
void ColoredModelRenderer::installShaders(){

	shader.installShader();
	
}

void ColoredModelRenderer::assignScene(Scene &scene){

	this->scene = &scene;
	shader.initialize(scene);

}


void ColoredModelRenderer::cleanUp(){
	
	shader.cleanUp();
}

void ColoredModelRenderer::prepare(){

	
}


void ColoredModelRenderer::render(){

	for (auto entity : entities){

		shader.render(entity);
	}
		
}
