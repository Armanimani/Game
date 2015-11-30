#include "src\Engine\Loader\Loader.h"
using std::vector;


void Loader::processModel(Model *model){

	models.push_back(model);

}
void Loader::load(){

	for (auto model : models){

		model->load();
	}

}
