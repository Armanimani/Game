#version 430

in layout(location = 0) vec3 position;
in layout(location = 1) vec3 Color;
in layout(location = 3) vec3 normal;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

uniform vec3 lightPosition;

out vec3 daColor;
out vec3 surfaceNormal;
out vec3 toLightVector;

void main(){
	
	vec4 worldPosition = transformationMatrix * vec4(position,1.0);
	gl_Position = projectionMatrix * viewMatrix * worldPosition;
	
	surfaceNormal = (transformationMatrix * vec4(normal,0.0)).xyz;
	toLightVector = lightPosition - worldPosition.xyz;

	daColor = Color;

};