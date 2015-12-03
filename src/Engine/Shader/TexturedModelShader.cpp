#include "src\Engine\Shader\TexturedModelShader.h"
#include "src\Engine\Model\TexturedModel.h"
#include "src\Engine\Math\GLMath.h"

using glm::mat4;

void TexturedModelShader::installShader(){

	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* adapter[1];
	std::string temp = readShaderCode("src/Engine/Shader/GLSL/TexturedModelShaderVS.glsl").c_str();
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	temp = readShaderCode("src/Engine/Shader/GLSL/TexturedModelShaderFS.glsl").c_str();
	adapter[0] = temp.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

	if (!checkShaderStatus(vertexShaderID) | !checkShaderStatus(fragmentShaderID)){
		return;
	}

	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	glValidateProgram(programID);

	if (!checkProgramStatus(programID)){
		return;
	}

	getAllUniformLocations();
}

void TexturedModelShader::render(TexturedModelEntity &entity){

	startProgram();

	loadTransformationMatrix(GLMath::createTransformationMatrix(entity.getPosition(), entity.getRotation(), entity.getScale()));
	loadProjectionMatrix();
	loadViewMatrix();

	glBindVertexArray(entity.model->getVertexArrayObjectID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, entity.model->getTexture().bufferID);

	glDrawElements(GL_TRIANGLES, entity.model->getIndicies().size(), GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);


	stopProgram();
}

void TexturedModelShader::getAllUniformLocations(){

	std::string string = " ";

	string = "transformationMatrix";
	location_transformationMatrix = getUniformLocation(string);

	string = "projectionMatrix";
	location_projectionMatrix = getUniformLocation(string);

	string = "viewMatrix";
	location_viewMatrix = getUniformLocation(string);

}
