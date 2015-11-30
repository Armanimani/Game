#include "src\Engine\Model\ColoredModel.h"

ColoredModel::ColoredModel(){

}

void ColoredModel::load(){

	setupVAOandVBO();
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
}

void ColoredModel::cleanUp(){


}