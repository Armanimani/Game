#include "src\Engine\Model\ShapeGenerator.h"
#include <QtCore\qstring.h>
#include <QtCore\qfile.h>
#include <iostream>
#include <QtCore\qtextstream.h>
#include <vector>
#include <glm\glm.hpp>

using std::vector;

ColoredModel ShapeGenerator::create_colored_triangle(){

	ColoredModel ret;

	vector<float> verts = {

		+0.0f, +1.0f, +0.0f,
		+1.0f, +0.0f, +0.0f,

		-1.0f, -1.0f, +0.0f,
		+0.0f, +1.0f, +0.0f,

		+1.0f, -1.0f, +0.0,
		+0.0f, +0.0f, +1.0f,
	};

	vector<GLuint> indicies = { 0, 1, 2 };

	ret.setVerts(verts);
	ret.setIndinces(indicies);

	return ret;
}

TexturedModel ShapeGenerator::create_textured_triangle(){

	TexturedModel ret;
	Texture texture;
	vector<float> verts = {

		+0.0f, +1.0f, +0.0f,
		+0.0f, -1.0f,

		-1.0f, -1.0f, +0.0f,
		+0.0f, -0.0f,

		+1.0f, -1.0f, +0.0,
		+1.0f, -0.0f,
	};

	vector<GLuint> indicies = { 0, 1, 2 };

	texture.path = "res/texture/test.png";
	texture.width = 296;
	texture.height = 296;
	
	ret.setVerts(verts);
	ret.setIndinces(indicies);
	ret.setTexture(texture);
	return ret;
}

Model ShapeGenerator::createCubeTest(){

	Model ret;

	//Vertex vert[] = {

	//	glm::vec3(-1.0f, +1.0f, +1.0f), // 0
	//	glm::vec3(+1.0f, +0.0f, +0.0f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(+1.0f, +1.0f, +1.0f), // 1
	//	glm::vec3(+0.0f, +1.0f, +0.0f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(+1.0f, +1.0f, -1.0f), // 2
	//	glm::vec3(+0.0f, +0.0f, +1.0f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(-1.0f, +1.0f, -1.0f), // 3
	//	glm::vec3(+1.0f, +1.0f, +1.0f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),


	//	glm::vec3(-1.0f, +1.0f, -1.0f), // 4
	//	glm::vec3(+1.0f, +0.0f, +1.0f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(+1.0f, +1.0f, -1.0f), // 5
	//	glm::vec3(+0.0f, +0.5f, +0.2f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(+1.0f, -1.0f, -1.0f), // 6
	//	glm::vec3(+0.8f, +0.6f, +0.4f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(-1.0f, -1.0f, -1.0f), // 7
	//	glm::vec3(+0.3f, +1.0f, +0.5f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),


	//	glm::vec3(+1.0f, +1.0f, -1.0f), // 8
	//	glm::vec3(+0.2f, +0.5f, +0.2f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(+1.0f, +1.0f, +1.0f), // 9
	//	glm::vec3(+0.9f, +0.3f, +0.7f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(+1.0f, -1.0f, +1.0f), // 10
	//	glm::vec3(+0.3f, +0.7f, +0.5f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(+1.0f, -1.0f, -1.0f), // 11
	//	glm::vec3(+0.5f, +0.7f, +0.5f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),


	//	glm::vec3(-1.0f, +1.0f, +1.0f), // 12
	//	glm::vec3(+0.7f, +0.8f, +0.2f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(-1.0f, +1.0f, -1.0f), // 13
	//	glm::vec3(+0.5f, +0.7f, +0.3f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(-1.0f, -1.0f, -1.0f), // 14
	//	glm::vec3(+0.4f, +0.7f, +0.7f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(-1.0f, -1.0f, +1.0f), // 15
	//	glm::vec3(+0.2f, +0.5f, +1.0f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),


	//	glm::vec3(+1.0f, +1.0f, +1.0f), // 16
	//	glm::vec3(+0.6f, +1.0f, +0.7f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(-1.0f, +1.0f, +1.0f), // 17
	//	glm::vec3(+0.6f, +0.4f, +0.8f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(-1.0f, -1.0f, +1.0f), // 18
	//	glm::vec3(+0.2f, +0.8f, +0.7f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(+1.0f, -1.0f, +1.0f), // 19
	//	glm::vec3(+0.2f, +0.7f, +1.0f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),


	//	glm::vec3(+1.0f, -1.0f, -1.0f), // 20
	//	glm::vec3(+0.8f, +0.3f, +0.7f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(-1.0f, -1.0f, -1.0f), // 21
	//	glm::vec3(+0.8f, +0.9f, +0.5f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(-1.0f, -1.0f, +1.0f), // 22
	//	glm::vec3(+0.5f, +0.8f, +0.5f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f),

	//	glm::vec3(+1.0f, -1.0f, +1.0f), // 23
	//	glm::vec3(+0.9f, +1.0f, +0.2f), // Colour
	//	glm::vec3(+0.0f, +0.0f, +0.0f)

	//};

	//ret.numVerticies = NUMBER_ARRAY_ELEMENTS(vert);
	//ret.verticies = new Vertex[ret.numVerticies];
	//memcpy(ret.verticies, vert, sizeof(vert));

	//GLushort indicies[] = {
	//	0, 1, 2, 0, 2, 3, // Top
	//	4, 5, 6, 4, 6, 7, // Front
	//	8, 9, 10, 8, 10, 11, // Right
	//	12, 13, 14, 12, 14, 15, // Left
	//	16, 17, 18, 16, 18, 19, // Back
	//	20, 21, 22, 20, 22, 23, // Bottom
	//};



	//ret.numIndicies = NUMBER_ARRAY_ELEMENTS(indicies);
	//ret.indicies = new GLushort[ret.numIndicies];
	//memcpy(ret.indicies, indicies, sizeof(indicies));

	return ret;
}

ColoredModel ShapeGenerator::createTexturedObjectFromObjFile(QString fileName) {

	ColoredModel ret;
	QString path = fileName;
	QFile file(path);
	file.open(QIODevice::ReadOnly);
	QTextStream input(&file);

	if (!file.exists()){
		std::cout << "File does not exists";
		return ret;
	}

	std::vector<float> vertexPositions;
	std::vector<float> texturePositions;
	std::vector<int> indexOrders;

	while (!input.atEnd()){

		QString line = input.readLine();
		QStringList list = line.split(" ");

		if (list.at(0) == "v"){

			vertexPositions.push_back(list.at(1).toFloat());
			vertexPositions.push_back(list.at(2).toFloat());
			vertexPositions.push_back(list.at(3).toFloat());
		}

		if  (list.at(0) == "vt"){

			texturePositions.push_back(list.at(1).toFloat());
			texturePositions.push_back(list.at(2).toFloat());
		}

		if (list.at(0) == "f"){

			for (int i = 1; i != 4; ++i){

				QString line2 = list.at(i);
				QStringList prop = line2.split("/");

				indexOrders.push_back(prop.at(0).toFloat());
				indexOrders.push_back(prop.at(1).toFloat());
			}
		}
	}

	vector<float> verts;
	vector<GLuint> index;
	for (int j = 0; j != indexOrders.size(); j = j + 2){

		int num = indexOrders[j];
		verts.push_back(num * 3);
		verts.push_back(num * 3 + 1);
		verts.push_back(num * 3 + 2);

		index.push_back(num);

		num = indexOrders[j + 1] - 1;

		verts.push_back(1.0f);
		verts.push_back(1.0f);
		verts.push_back(1.0f);


	}

	ret.setVerts(verts);
	ret.setIndinces(index);

	//Texture texture;
	//texture.path = "res/texture/cat.png";
	//texture.width = 512;
	//texture.height = 1024;
	//ret.setTexture(texture);
	
	return ret;
}
