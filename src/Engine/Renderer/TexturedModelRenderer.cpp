#include "GL\glew.h"
#include "src\Engine\Renderer\TexturedModelRenderer.h"
#include "glm\glm.hpp"

using glm::mat4;
void TexturedModelRenderer::installShaders(){

	shader.installShader();
}

void TexturedModelRenderer::assignScene(Scene &scene){

	shader.initialize(scene);

}



void TexturedModelRenderer::cleanUp(){

	shader.cleanUp();
}

void TexturedModelRenderer::prepare(){

}


void TexturedModelRenderer::render(){

	for (auto entity : entities){

		shader.render(entity);
	}

}
