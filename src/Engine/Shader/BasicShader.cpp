#include "src\Engine\Shader\BasicShader.h"

void BasicShader::installShader(){
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* adapter[1];
	std::string temp = readShaderCode("src/Engine/Shader/GLSL/BasicShaderVertexShader.glsl").c_str();
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	temp = readShaderCode("src/Engine/Shader/GLSL/BasicShaderFragmentShader.glsl").c_str();
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

void BasicShader::render(ModelEntity &ModelEntity){
	
	startProgram();
	glBindVertexArray(ModelEntity.model->getVertexArrayObjectID());
	glDrawElements(GL_TRIANGLES, ModelEntity.model->getIndicies().size(), GL_UNSIGNED_INT, 0);
	stopProgram();
}