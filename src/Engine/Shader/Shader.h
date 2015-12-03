#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <fstream>
#include "src\Engine\Entities\Entity.h"
#include "src\Engine\Scene\Scene.h"
class Shader
{
public:
	void startProgram();
	void stopProgram();
	virtual void installShader();

	void initialize(Scene &scene);
	virtual void Shader::render(Entity &entity);
	void loadTransformationMatrix(glm::mat4 &matrix);
	void loadProjectionMatrix();
	void loadViewMatrix();
	virtual void loadShineDamper(GLfloat);
	virtual void loadCameraPosition(glm::vec3 position);

	void cleanUp();

protected:
	GLuint programID;
	GLuint vertexShaderID;
	GLuint fragmentShaderID;

	Scene *scene;

	GLuint location_transformationMatrix;
	GLuint location_projectionMatrix;
	GLuint location_viewMatrix;


	std::string readShaderCode(const GLchar* fileName);

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

