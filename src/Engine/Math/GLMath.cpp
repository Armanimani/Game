#include "src\Engine\Math\GLMath.h"
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtx\transform.hpp>

using glm::mat4;
using glm::vec3;

mat4 GLMath::createTransformationMatrix(vec3 &translation, vec3 &rotation, vec3 &scale){

	mat4 translationMatrix = glm::translate(translation);
	mat4 rotationMatrix_x = glm::rotate(translationMatrix, glm::radians(rotation.x), vec3(1.0f, 0.0f, 0.0f));
	mat4 rotationMatrix_y = glm::rotate(rotationMatrix_x, glm::radians(rotation.y), vec3(0.0f, 1.0f, 0.0f));
	mat4 rotationMatrix_z = glm::rotate(rotationMatrix_y, glm::radians(rotation.z), vec3(0.0f, 0.0f, 1.0f));
	mat4 scaleMatrix = glm::scale(rotationMatrix_z, scale);

	return scaleMatrix;

}

glm::mat4 GLMath::createProjectionMatrix(float FOV, float aspectRatio, float farPlane, float nearPlane){

	return  glm::perspective(glm::radians(FOV), aspectRatio, nearPlane, farPlane);

}

