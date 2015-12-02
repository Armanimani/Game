#pragma once
#include <vector>
#include "src\Engine\Model\Model.h"
#include "src\Engine\Entities\ModelEntity.h"
#include "src\Engine\Shader\BasicShader.h"
#include "src\Engine\Shader\BasicTexturedShader.h"

class ModelRenderer{

public:

	void initialize();
	void cleanUp();
	void prepare();
	void render();
	void render(ModelEntity &ModelEntity);
	inline void processEntities(ModelEntity ModelEntity){ entities.push_back(ModelEntity); }
	
private:

	std::vector<ModelEntity> entities;

	BasicShader basicShader;
	BasicTexturedShader basicTexturedShader;


	Shader* getShader(int ShaderID);
	
};