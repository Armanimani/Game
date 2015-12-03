#version 430

in vec2 theTexture;

out vec4 dacolor;

uniform sampler2D textureSampler;

void main(){

	dacolor = texture(textureSampler, theTexture);
};