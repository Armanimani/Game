#pragma once
#include "src\Engine\Scene\Scene.h"
#include "src\Engine\Settings\EngineSettings.h"
#include <vector>

class SceneManager{

public: 

	SceneManager();
	
	void initialize(EngineSettings &settings);

	inline void addScene(Scene scene){ scenes.push_back(scene);  }

protected:

	EngineSettings *settings;

	std::vector<Scene> scenes;

};