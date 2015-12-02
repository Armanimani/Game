#include "Camera.h"
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <math.h>
using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::mat4;
using glm::rotate;
using glm::radians;

Camera::Camera()
{
}


Camera::~Camera()
{
}


glm::mat4 Camera::getViewMatrix(){

	return glm::lookAt(position, viewPosition, upDirection);

}


glm::vec3 Camera::getPosition(){
	return this->position;
}


glm::vec3 Camera::getViewDirection(){
	return this->viewDirection;
}

glm::vec3 Camera::getUpDirection(){
	return this->upDirection;
}

glm::vec3 Camera::getViewPosition(){
	return this->viewPosition;
}

void Camera::setPosition(glm::vec3 position){
	this->position = position;
}

void Camera::setViewDirection(glm::vec3 viewDirection){
	this->viewDirection = viewDirection;
}

void Camera::setUpDirection(glm::vec3){
	this->upDirection = upDirection;
}

void Camera::setViewPosition(glm::vec3 ViewPosition){
	this->viewPosition = ViewPosition;
}



void Camera::cameraTranslate(glm::vec2 Delta){

	glm::vec3 newDeltaPosition = (rightDirection*Delta.x + upDirection * Delta.y);
	position.x += newDeltaPosition.x;
	position.y += newDeltaPosition.y;
	position.z += newDeltaPosition.z;

	viewPosition.x += newDeltaPosition.x;
	viewPosition.y += newDeltaPosition.y;
	viewPosition.z += newDeltaPosition.z;

}

void Camera::cameraZoom(float delta){

	glm::vec3 viewDirection = glm::normalize(position - viewPosition);
	glm::vec3 zoomIncreament = -viewDirection* delta;

	if ((position - viewPosition).x * (position - viewPosition).x + (position - viewPosition).y * (position - viewPosition).y
		+ (position - viewPosition).z * (position - viewPosition).z > zoomIncreament.x* zoomIncreament.x + zoomIncreament.y * zoomIncreament.y
		+ zoomIncreament.z * zoomIncreament.z || delta < 0){
		position += zoomIncreament;
	}

}

void Camera::cameraRotateX(float Delta){

	GLfloat phi = Delta;

	vec4 distance = vec4(position - viewPosition, 1.0f);
	mat4 rotation = rotate(radians(-phi), rightDirection);
	vec4 newdistance = rotation * distance;
	position = viewPosition + vec3(newdistance);
	upDirection = cross(rightDirection, normalize(vec3(-newdistance)));
	upDirection = normalize(upDirection);

}

void Camera::cameraRotateY(float Delta){

	GLfloat phi = Delta;

	vec4 distance = vec4(position - viewPosition, 1.0f);
	mat4 rotation = rotate(radians(-phi), upDirection);
	vec4 newdistance = rotation * distance;
	position = viewPosition + vec3(newdistance);
	rightDirection = cross(upDirection, normalize(vec3(newdistance)));
	rightDirection = normalize(rightDirection);

}

void Camera::cameraRotateZ(float Delta){

	GLfloat phi = Delta;

	vec4 distance = vec4(position - viewPosition, 1.0f);
	mat4 rotation = rotate(radians(-phi), viewDirection);
	rightDirection = vec3(rotation * vec4(rightDirection, 1.0));
	rightDirection = normalize(rightDirection);
	upDirection = vec3(rotation * vec4(upDirection, 1.0));
	upDirection = normalize(upDirection);

}

void Camera::cameraOrbit(glm::vec2 Delta){

	GLfloat phi = Delta.x;

	vec4 distance = vec4(position - viewPosition, 1.0f);
	mat4 rotation = rotate(radians(-phi), upDirection);
	vec4 newdistance = rotation * distance;
	position = viewPosition + vec3(newdistance);
	rightDirection = cross(upDirection, normalize(vec3(newdistance)));
	rightDirection = normalize(rightDirection);



	phi = Delta.y;

	distance = vec4(position - viewPosition, 1.0f);
	rotation = rotate(radians(-phi), rightDirection);
	newdistance = rotation * distance;
	position = viewPosition + vec3(newdistance);
	upDirection = cross(rightDirection, normalize(vec3(-newdistance)));
	upDirection = normalize(upDirection);


}

void Camera::reset(){

	position = glm::vec3(0.0f, 0.0f, 0.0f);
	viewPosition = glm::vec3(0.0f, 0.0f, -3.0f);
	viewDirection = glm::vec3(0.0f, 0.0f, -1.0f);
	upDirection = glm::vec3(0.0f, 1.0f, 0.0f);
	rightDirection = glm::vec3(1.0f, 0.0f, 0.0f);

}