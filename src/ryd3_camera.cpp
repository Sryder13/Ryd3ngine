#include "ryd3_camera.h"

#include "glm/gtc/matrix_transform.hpp"

namespace Ryd3 {

Camera::Camera(glm::vec3 position, glm::vec3 lookAt, float fieldOfView,
	unsigned int viewportWidth, unsigned int viewportHeight, float nZPlane,
	float fZPlane) {
	this->position = position;
	this->lookAt = lookAt;
	this->fieldOfView = fieldOfView;
	this->viewportWidth = viewportWidth;
	this->viewportHeight = viewportHeight;
	this->nZPlane = nZPlane;
	this->fZPlane = fZPlane;
}

Camera::~Camera() {

}

glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(position, lookAt, glm::vec3(0.0, 1.0,0.0));
}

glm::mat4 Camera::getProjectionMatrix() {
	return glm::perspective(glm::radians(fieldOfView),
		(float)viewportWidth / viewportHeight, nZPlane, fZPlane);
}

}
