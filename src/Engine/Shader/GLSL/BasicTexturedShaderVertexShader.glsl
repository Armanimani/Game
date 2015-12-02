#version 430

in layout(location = 0) vec3 vertexPosition;
in layout(location = 1) vec2 vertexTexture;

out vec3 theColor;
out vec2 theTexture;

uniform mat4 transformationMatrix;

void main(){
	
	gl_Position = transformationMatrix * vec4(vertexPosition,1.0);
	theTexture = vertexTexture;

};