#pragma once
#include "src\Engine\Model\Model.h"

class TexturedModel : public Model{

public:

	TexturedModel();
	void load();
	void cleanUp();

	inline void setTexture(Texture texture){ this->texture = texture; }
	inline Texture& getTexture(){ return texture; }


protected:

	void loadTexture();
};