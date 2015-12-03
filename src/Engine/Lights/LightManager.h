#pragma once
#include <vector>
#include "src\Engine\Lights\Light.h"
#include "src\Engine\Lights\AmbinetLight.h"
class LightManager{

public:

	inline void addLight(Light light) { lights.push_back(light); }
	inline void addAmbientLight(AmbientLight light) { ambientLights.push_back(light); }

private:

	std::vector<Light> lights;
	std::vector<AmbientLight> ambientLights;
};