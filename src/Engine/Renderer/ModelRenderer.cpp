#include "GL\glew.h"
#include "src\Engine\Renderer\ModelRenderer.h"
#include "glm\glm.hpp"

using glm::mat4;
void ModelRenderer::installShaders(){

	basicShader.installShader();
	basicTexturedShader.installShader();

}

void ModelRenderer::initialize( mat4 &projectionMatrix, mat4 &viewMatrix){

	basicShader.initialize(projectionMatrix, viewMatrix);
	basicTexturedShader.initialize(projectionMatrix, viewMatrix);

}
void ModelRenderer::cleanUp(){
	
	basicShader.cleanUp();
	basicTexturedShader.cleanUp();
}

void ModelRenderer::prepare(){

	

}


void ModelRenderer::render(){

	for (auto ModelEntity : entities){

		Shader *shader = getShader(ModelEntity.getShaderID());
		shader->render(ModelEntity);
	}
		
}

void ModelRenderer::render(ModelEntity &ModelEntity){

	
	glBindVertexArray(ModelEntity.model->getVertexArrayObjectID());
	glDrawElements(GL_TRIANGLES, ModelEntity.model->getIndicies().size(), GL_UNSIGNED_SHORT, 0);


}


Shader* ModelRenderer::getShader(int ID){

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