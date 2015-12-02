#include "src\Engine\Model\TexturedModel.h"
#include "middlewares\SOIL\include\SOIL\SOIL.h"

TexturedModel::TexturedModel(){

}

void TexturedModel::load(){

	setupVAOandVBO();
	loadTexture();

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
}

void TexturedModel::cleanUp(){

}

void TexturedModel::loadTexture(){

	glGenTextures(1, &texture.bufferID);
	glBindTexture(GL_TEXTURE_2D, texture.bufferID);

	unsigned char* image = SOIL_load_image(texture.path.c_str(), &texture.width, &texture.height, 0, SOIL_LOAD_RGB);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width, texture.height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
}
