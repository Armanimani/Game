#pragma once
#include "src\Engine\Renderer\ModelRenderer.h"
#include "glm\glm.hpp"
#include "src\Engine\Camera\Camera.h"

class Renderer {

public:

	Renderer();
	~Renderer();

	void initialize();
	void prepare();
	void cleanUp();

	void render();

	void assignCamera(Camera &camera);
	void setProjectionMatrix(glm::mat4 projectionMatrix);

	void processEntity(ModelEntity &entity);


private:

	Camera *camera;

	ModelRenderer modelRenderer;
	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;

};