#include "src\Engine\Scene\SceneManager.h"
#include <vector>

using std::vector;

SceneManager::SceneManager(){

}

void SceneManager::initialize(EngineSettings &settings){

	this->settings = &settings;
}