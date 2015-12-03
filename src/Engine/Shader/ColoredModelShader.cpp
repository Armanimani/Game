#include "src\Engine\Shader\ColoredModelShader.h"
#include "src\Engine\Math\GLMath.h"

using glm::mat4;

void ColoredModelShader::installShader(){
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* adapter[1];
	std::string temp = readShaderCode("src/Engine/Shader/GLSL/ColoredModelShaderVS.glsl").c_str();
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	temp = readShaderCode("src/Engine/Shader/GLSL/ColoredModelShaderFS.glsl").c_str();
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

void ColoredModelShader::loadLightColor(glm::vec3 color){

	loadToUniform(location_lightColor, color);

}

void ColoredModelShader::loadLightPosition(glm::vec3 position){

	loadToUniform(location_lightPosition, position);

}

void ColoredModelShader::loadAmbientLightning(glm::vec3 color){

	loadToUniform(location_ambientLightning, color);
}


void ColoredModelShader::loadAmbientLight(AmbientLight &light){

	loadAmbientLightning(light.getColor());

}

void ColoredModelShader::loadLight(Light &light){

	loadLightColor(light.getColor());
	loadLightPosition(light.getPosition());
}


void ColoredModelShader::render(ColoredModelEntity &entity){
	
	startProgram();

	loadTransformationMatrix(GLMath::createTransformationMatrix(entity.getPosition(), entity.getRotation(), entity.getScale()));
	loadProjectionMatrix();
	loadViewMatrix();

	glBindVertexArray(entity.model->getVertexArrayObjectID());
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glDrawElements(GL_TRIANGLES, entity.model->getIndicies().size(), GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);

	stopProgram();
}

void ColoredModelShader::getAllUniformLocations(){

	std::string string = " ";

	string = "transformationMatrix";
	location_transformationMatrix = getUniformLocation(string);

	string = "projectionMatrix";
	location_projectionMatrix = getUniformLocation(string);

	string = "viewMatrix";
	location_viewMatrix = getUniformLocation(string);

	string = "ambinetLightning";
	location_ambientLightning = getUniformLocation(string);

	string = "lightColor";
	location_lightColor = getUniformLocation(string);

	string = "lightPosition";
	location_lightPosition = getUniformLocation(string);
}
