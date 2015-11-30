#pragma once
#include <vector>
#include "src\Engine\Model\Model.h"
#include "src\Engine\Entities\Entity.h"
#include "src\Engine\Shader\BasicShader.h"
#include "src\Engine\Shader\BasicTexturedShader.h"

class Renderer{

public:

	void initialize();
	void cleanUp();
	void prepare();
	void render();
	void render(Entity &entity);
	inline void processEntities(Entity entity){ entities.push_back(entity); }
	
private:

	std::vector<Entity> entities;

	BasicShader basicShader;
	BasicTexturedShader basicTexturedShader;


	Shader* getShader(int ShaderID);
	
};