#pragma once
#include "src\Engine\Model\Model.h"
#include <vector>

class Loader{

public:
	
	void processModel(Model *model);
	void load();

	

private:

	std::vector<Model*> models;

};

// need to add cleanup method