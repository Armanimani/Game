#pragma once
#include "src\Engine\Model\Model.h"
#include "src\Engine\Model\ColoredModel.h"
#include "src\Engine\Model\TexturedModel.h"
#include <QtCore\qstring.h>
#include <glm\glm.hpp>
#include "src\Engine\Model\OBJFile.h"
class ShapeGenerator
{

public:
	static ColoredModel create_colored_triangle();
	static TexturedModel create_textured_triangle();
	static Model createCubeTest();
	static TexturedModel loadTexturedModelOBJFile(OBJFile model);
	static ColoredModel loadColoredModelOBJFile(OBJFile model);


private:
	 
};

