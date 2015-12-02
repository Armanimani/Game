#include "src\Engine\Shader\BasicTexturedShader.h"
#include "src\Engine\Model\TexturedModel.h"

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

void BasicTexturedShader::render(ModelEntity &ModelEntity){

	startProgram();
	glBindVertexArray(ModelEntity.model->getVertexArrayObjectID());
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, ModelEntity.model->getTexture().bufferID);

	glDrawElements(GL_TRIANGLES, ModelEntity.model->getIndicies().size(), GL_UNSIGNED_INT, 0);
	stopProgram();
}