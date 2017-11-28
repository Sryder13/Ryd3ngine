#include "ryd3_camera.h"

#include "glm/gtc/matrix_transform.hpp"

Camera::Camera(glm::vec3 position, glm::vec3 lookAt, float fieldOfView) {
	this->position = position;
	this->lookAt = lookAt;
	this->fieldOfView = fieldOfView;
}

Camera::~Camera() {

}

glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(position, lookAt, glm::vec3(0.0, 1.0,0.0));
}

glm::mat4 Camera::getProjectionMatrix(unsigned int windowWidth,
	unsigned int windowHeight, float nZPlane, float fZPlane) {
	return glm::perspective(glm::radians(fieldOfView),
		(float)windowWidth / windowHeight, nZPlane, fZPlane);
}
