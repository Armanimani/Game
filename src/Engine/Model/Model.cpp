#include "src\Engine\Model\Model.h"

Model::Model(){


}

void Model::load(){


}


void Model::cleanUp(){


}

void Model::setupVAOandVBO(){

	glGenVertexArrays(1, &vertexArrayObjectID);
	glBindVertexArray(vertexArrayObjectID);

	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(float), &verts[0], GL_STATIC_DRAW);


	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(GLuint), &indicies[0], GL_STATIC_DRAW);

}