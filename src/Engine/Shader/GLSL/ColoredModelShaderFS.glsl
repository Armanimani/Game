#version 430

in vec3 theColor;
in vec3 surfaceNormal;
in vec3 toLightVector;


uniform vec3 lightColor;

out vec4 dacolor;

void main(){

	vec3 unitNormal = normalize(surfaceNormal);
	vec3 unitLightVector = normalize(toLightVector);

	float nDot1 = dot(unitNormal,unitLightVector);

	float brightness = max(nDot1,0.0);

	vec3 diffuse = brightness * lightColor;

	dacolor = vec4(diffuse , 1.0) * vec4(theColor,1.0);
};