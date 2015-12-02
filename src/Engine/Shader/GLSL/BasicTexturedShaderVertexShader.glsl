#version 430

in layout(location = 0) vec3 vertexPosition;
in layout(location = 1) vec2 vertexTexture;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

out vec3 theColor;
out vec2 theTexture;

void main(){
	
	gl_Position = projectionMatrix * viewMatrix * transformationMatrix * vec4(vertexPosition,1.0);
	theTexture = vertexTexture;

};