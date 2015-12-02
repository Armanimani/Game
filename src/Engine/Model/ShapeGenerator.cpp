#include "src\Engine\Model\ShapeGenerator.h"
#include <QtCore\qstring.h>
#include <QtCore\qfile.h>
#include <iostream>
#include <QtCore\qtextstream.h>
#include <vector>
#include <glm\glm.hpp>
#include <map>

using std::vector;
using std::map;

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

TexturedModel ShapeGenerator::loadTexturedModelOBJFile(OBJFile model) {

	TexturedModel ret;
	QString path = QString::fromStdString(model.modelPath);
	QFile file(path);
	file.open(QIODevice::ReadOnly);
	QTextStream input(&file);

	if (!file.exists()){
		std::cout << "File does not exists";
		return ret;
	}

	std::vector<float> vertexData;
	std::vector<float> normalData;
	std::vector<float> textureData;
	std::vector<int> faceData;

	while (!input.atEnd()){

		QString line = input.readLine();
		QStringList list = line.split(" ");

		if (list.at(0) == "v"){

			vertexData.push_back(list.at(1).toFloat());
			vertexData.push_back(list.at(2).toFloat());
			vertexData.push_back(list.at(3).toFloat());
		}

		if  (list.at(0) == "vt"){

			textureData.push_back(list.at(1).toFloat());
			textureData.push_back(list.at(2).toFloat());
		}

		if (list.at(0) == "n"){

			normalData.push_back(list.at(1).toFloat());
			normalData.push_back(list.at(2).toFloat());
			normalData.push_back(list.at(3).toFloat());
		}

		if (list.at(0) == "f"){

			for (int i = 1; i != 4; ++i){

				QString line2 = list.at(i);
				QStringList prop = line2.split("/");

				faceData.push_back(prop.at(0).toFloat());
				faceData.push_back(prop.at(1).toFloat());
				//faceData.push_back(prop.at(2).toFloat());
			}
		}
	}

	vector<float> verts;
	vector<GLuint> index;

	map<int, int>vertexTextureMap;
	map<int, int>vertexNormalMap;

	for (int i = 0; i != faceData.size(); i += 3){

		index.push_back(faceData[i] - 1);
		vertexTextureMap[faceData[i] - 1] = faceData[i + 1] - 1;
		//vertexNormalMap[faceData[i] - 1] = faceData[i + 2] - 1;
	}


	for (int i = 0; i != vertexTextureMap.size(); ++i){
		
		int ind = i;
		verts.push_back(vertexData[3 * ind]);
		verts.push_back(vertexData[3 * ind + 1]);
		verts.push_back(vertexData[3 * ind + 2]);
		
		ind = vertexTextureMap[i];
		verts.push_back(textureData[2 * ind]);
		verts.push_back(textureData[2 * ind + 1]);


	}


	
	
	ret.setVerts(verts);
	ret.setIndinces(index);

	Texture texture;
	texture.path = model.texturePath;
	texture.width = model.textureWidth;
	texture.height = model.textureHeight;
	ret.setTexture(texture);


	

	
	return ret;
}
