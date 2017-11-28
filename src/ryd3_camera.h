#ifndef RYD3_CAMERA_H
#define RYD3_CAMERA_H

#include <iostream>
#include "glm/vec3.hpp"
#include "glm/fwd.hpp"

class Camera {
	public:
		Camera() : Camera(glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0), 90.0f) {};
		Camera(glm::vec3 position, glm::vec3 lookAt, float fieldOfView);
		virtual ~Camera();
		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix(unsigned int windowWidth,
			unsigned int windowHeight, float nZPlane, float fZPlane);

		glm::vec3 getPosition() {return this->position;};
		void setPosition(glm::vec3 newPosition) {this->position = newPosition;};
		glm::vec3 getlookAt() {return this->lookAt;};
		void setRotation(glm::vec3 newLookAt) {this->lookAt = newLookAt;};
		float getFieldOfView() {return this->fieldOfView;};
		void setFieldOfView(float newFieldOfView) {this->fieldOfView = newFieldOfView;};
	private:
		glm::vec3 position;
		glm::vec3 lookAt;
		float fieldOfView;
};

#endif
