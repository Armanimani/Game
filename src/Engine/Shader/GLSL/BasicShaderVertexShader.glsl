#version 430

in layout(location = 0) vec3 position;
in layout(location = 1) vec3 vertexColor;

uniform mat4 transformationMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

out vec3 theColor;

void main(){
	
	gl_Position = projectionMatrix * viewMatrix * transformationMatrix * vec4(position,1.0);
	theColor = vertexColor;

};