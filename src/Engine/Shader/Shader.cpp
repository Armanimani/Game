#include "src\Engine\Shader\Shader.h"
#include <fstream>
#include <iostream>

void Shader::installShader(){

}

void Shader::startProgram(){

	glUseProgram(programID);
}

void Shader::stopProgram(){

	glUseProgram(0);
}

void Shader::render(ModelEntity &ModelEntity){

}

void Shader::cleanUp(){

	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	glDeleteProgram(programID);
}


std::string Shader::readShaderCode(const GLchar* fileName){

	std::ifstream input(fileName);
	if (!input.good()){
		std::cout << "File failed to load"<<std::endl;
		exit(1);
	}
	return std::string(std::istreambuf_iterator<char>(input), std::istreambuf_iterator<char>());
}


void Shader::bindAttributes(GLuint &attribute, std::string &varriableName){

	glBindAttribLocation(programID, attribute, varriableName.c_str());
}

GLint Shader::getUniformLocation(std::string &uniformName){

	const GLchar* adapter[1];
	std::string temp = uniformName.c_str();
	adapter[0] = temp.c_str();
	return glGetUniformLocation(programID, adapter[0]);
}

void Shader::getAllUniformLocations(){

}


void Shader::loadToUniform(GLuint &location, bool &data){

	if (data == true){
		glUniform1f(location, data);
	}
	else {
		glUniform1f(location, data);
	}

}
void Shader::loadToUniform(GLuint &location, GLfloat &data){

	glUniform1f(location, data);
}

void Shader::loadToUniform(GLuint &location, glm::vec3 &data){

	glUniform3fv(location, 1, &data[0]);
}

void Shader::loadToUniform(GLuint &location, glm::mat4 &data){

	glUniformMatrix4fv(location, 1, GL_FALSE, &data[0][0]);
}


bool Shader::checkStatus(GLuint objectID, PFNGLGETSHADERIVPROC objectPropertyGetter,
	PFNGLGETSHADERINFOLOGPROC getInfoLogFun, GLenum statusType){

	GLint status;
	objectPropertyGetter(objectID, statusType, &status);
	if (status != GL_TRUE){
		GLint infoLogLength;
		objectPropertyGetter(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* buffer = new GLchar[infoLogLength];
		GLsizei bufferSize;
		getInfoLogFun(objectID, infoLogLength, &bufferSize, buffer);

		std::cout << buffer << std::endl;

		delete[] buffer;
		return false;
	}
	return true;
}

bool Shader::checkShaderStatus(GLuint ShaderID){

	return checkStatus(ShaderID, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS);
}

bool Shader::checkProgramStatus(GLuint programID){

	return checkStatus(programID, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS);

}

void Shader::loadTransformationMatrix(glm::mat4 &matrix){

}
void Shader::loadProjectionMatrix(glm::mat4 &matrix){

}
void Shader::loadViewMatrix(glm::mat4 &matrix){

}
void Shader::loadShineDamper(GLfloat){

}
void Shader::loadCameraPosition(glm::vec3 position){

}