#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <fstream>
#include "src\Engine\Entities\ModelEntity.h"
class Shader
{
public:
	void startProgram();
	void stopProgram();
	virtual void installShader();

	virtual void render(ModelEntity &ModelEntity);

	virtual void loadTransformationMatrix(glm::mat4 &matrix);
	virtual void loadProjectionMatrix(glm::mat4 &matrix);
	virtual void loadViewMatrix(glm::mat4 &matrix);
	virtual void loadShineDamper(GLfloat);
	virtual void loadCameraPosition(glm::vec3 position);

	void cleanUp();

protected:
	GLuint programID;
	GLuint vertexShaderID;
	GLuint fragmentShaderID;

	std::string readShaderCode(const GLchar* fileName);

	void bindAttributes(GLuint &attribute, std::string &varriableName);
	GLint getUniformLocation(std::string &uniformName);
	virtual void getAllUniformLocations();

	void loadToUniform(GLuint &location, bool &data);
	void loadToUniform(GLuint &location, GLfloat &data);
	void loadToUniform(GLuint &location, glm::vec3 &data);
	void loadToUniform(GLuint &location, glm::mat4 &data);

	bool checkStatus(GLuint objectID, PFNGLGETSHADERIVPROC objectPropertyGetter,
		PFNGLGETSHADERINFOLOGPROC getInfoLogFun, GLenum statusType);
	bool checkShaderStatus(GLuint ShaderID);
	bool checkProgramStatus(GLuint programID);

};

