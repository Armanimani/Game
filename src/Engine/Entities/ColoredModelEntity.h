#pragma once
#include "src\Engine\Entities\Entity.h"
#include "src\Engine\Model\ColoredModel.h"

class ColoredModelEntity : public Entity{

public:

	ColoredModelEntity(ColoredModel *model) : model(model){}
	ColoredModelEntity(ColoredModel *model, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale) {

		this->model = model;
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
	}

	ColoredModel *model;

private:


};
