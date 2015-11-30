#pragma once
#include "src\Engine\Model\Model.h"
#include "src\Engine\Model\ColoredModel.h"
#include "src\Engine\Model\TexturedModel.h"
#include <QtCore\qstring.h>
#include <glm\glm.hpp>
class ShapeGenerator
{

public:
	static ColoredModel create_colored_triangle();
	static TexturedModel create_textured_triangle();
	static Model createCubeTest();
	static Model createObjectFromObjFile(QString fileName, glm::vec3 &color = glm::vec3(0.0f, 0.0f, 0.0f));

};

