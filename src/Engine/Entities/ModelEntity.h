#pragma once;
#include "src\Engine\Model\Model.h"
#include "src\Engine\Model\ColoredModel.h"
#include "src\Engine\Model\TexturedModel.h"
#include <glm\glm.hpp>

class ModelEntity{

public:

	ModelEntity(Model *model, int shaderID) : model(model), shaderID(shaderID){}
	ModelEntity(Model *model, int shaderID, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) :
		model(model), shaderID(shaderID), position(position), rotation(rotation), scale(scale){}


	inline int& getShaderID() { return shaderID; }
	inline Model& getModel(){ return *model; }
	inline glm::vec3& getPosition(){ return position; }
	inline glm::vec3& getRotation(){ return rotation; }
	inline glm::vec3& getScale(){ return scale; }

	Model *model;


private:

	int shaderID;

	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
};