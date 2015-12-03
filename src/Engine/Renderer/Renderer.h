#pragma once
#include "src\Engine\Renderer\ColoredModelRenderer.h"
#include "src\Engine\Renderer\TexturedModelRenderer.h"
#include "glm\glm.hpp"
#include "src\Engine\Camera\Camera.h"
#include "src\Engine\Lights\LightManager.h"
#include "src\Engine\Scene\Scene.h"

class Renderer {

public:

	Renderer();
	~Renderer();

	void initialize();
	void prepare();
	void cleanUp();

	void assignScene(Scene &scene);

	void render();

	void processEntity(ColoredModelEntity &entity);
	void processEntity(TexturedModelEntity &entity);


private:

	ColoredModelRenderer coloredModelRenderer;
	TexturedModelRenderer texturedModelRenderer;

	Scene *scene;

};