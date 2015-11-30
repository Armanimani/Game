#pragma once
#include <GL\glew.h>
#include <glm\glm.hpp>
#include <vector>
#include "src\Engine\Texture\Texture.h"


class Model {

public:
	Model();
	Model(std::vector<float> verts, std::vector<GLuint> ind) : verts(verts), indicies(ind){}

	virtual void load();
	virtual void cleanUp();

	inline void setVerts(std::vector<float> verts){ this->verts = verts; }
	inline void setIndinces(std::vector<GLuint> indices){ this->indicies = indices; }
	inline void setVertexArrayObjectID(GLuint vertexArrayObjectID){ this->vertexArrayObjectID = vertexArrayObjectID; }
	inline void setVertexBufferID(GLuint vertexBufferID){ this->vertexBufferID = vertexBufferID; }
	inline void setIndexBufferID(GLuint indexBufferID){ this->indexBufferID = indexBufferID; };

	inline const std::vector<float>& getVerts(){ return verts; }
	inline const std::vector<GLuint>& getIndicies(){ return indicies; }
	inline const GLuint& getVertexArrayObjectID(){ return vertexArrayObjectID; }
	inline const GLuint& getVertexBufferID(){ return vertexBufferID; }
	inline const GLuint& getIndexBufferID(){ return indexBufferID; };

	virtual const Texture& getTexture() { return texture; };




protected:
	
	std::vector<float> verts;
	std::vector<GLuint> indicies;
	Texture texture;

	GLuint vertexArrayObjectID;
	GLuint vertexBufferID;
	GLuint indexBufferID;

	void setupVAOandVBO();

};
