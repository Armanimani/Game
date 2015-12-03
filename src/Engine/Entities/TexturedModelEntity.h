#pragma once
#include "src\Engine\Entities\Entity.h"
#include "src\Engine\Model\TexturedModel.h"

class TexturedModelEntity : public Entity{

public:

	TexturedModelEntity(TexturedModel *model) : model(model){}
	TexturedModelEntity(TexturedModel *model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) {

		this->model = model;
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
	}

	TexturedModel *model;

private:


};
