#include "src\Engine\Shader\BasicTexturedShader.h"
#include "src\Engine\Model\TexturedModel.h"
#include "src\Engine\Math\GLMath.h"

using glm::mat4;

void BasicTexturedShader::installShader(){

	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* adapter[1];
	std::string temp = readShaderCode("src/Engine/Shader/GLSL/BasicTexturedShaderVertexShader.glsl").c_str();
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	temp = readShaderCode("src/Engine/Shader/GLSL/BasicTexturedShaderFragmentShader.glsl").c_str();
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

void BasicTexturedShader::render(ModelEntity &entity){

	startProgram();
	loadTransformationMatrix(GLMath::createTransformationMatrix(entity.getPosition(), entity.getRotation(), entity.getScale()));
	glBindVertexArray(entity.model->getVertexArrayObjectID());
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, entity.model->getTexture().bufferID);

	glDrawElements(GL_TRIANGLES, entity.model->getIndicies().size(), GL_UNSIGNED_INT, 0);
	stopProgram();
}

void BasicTexturedShader::getAllUniformLocations(){

	std::string string = "transformationMatrix";
	location_transformationMatrix = getUniformLocation(string);

}

void BasicTexturedShader::loadTransformationMatrix(mat4 &matrix){

	loadToUniform(location_transformationMatrix, matrix);
}