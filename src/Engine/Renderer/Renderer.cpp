#include "GL\glew.h"
#include "src\Engine\Renderer\Renderer.h"

void Renderer::initialize(){

	basicShader.installShader();
	basicTexturedShader.installShader();

}

void Renderer::cleanUp(){
	
	basicShader.cleanUp();
	basicTexturedShader.cleanUp();
}

void Renderer::prepare(){

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);

}


void Renderer::render(){

	for (auto entity : entities){

		Shader *shader = getShader(entity.getShaderID());
		shader->render(entity);
	}
		
}

void Renderer::render(Entity &entity){

	
	glBindVertexArray(entity.model->getVertexArrayObjectID());
	glDrawElements(GL_TRIANGLES, entity.model->getIndicies().size(), GL_UNSIGNED_SHORT, 0);


}


Shader* Renderer::getShader(int ID){

	switch (ID){
	default:{
		return nullptr;
		break;
	}
	case(1) : {
		return &basicShader;
		break;
	}
	case(2) : {
		return &basicTexturedShader;
		break;
	}
	}

	
}