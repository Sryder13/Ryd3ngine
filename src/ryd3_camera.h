#ifndef RYD3_CAMERA_H
#define RYD3_CAMERA_H

#include <iostream>
#include "glm/vec3.hpp"
#include "glm/fwd.hpp"

namespace Ryd3 {

class Camera {
	public:
		Camera() : Camera(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f), 90.0f, 640,
			480, 0.1f, 100.0f) {};
		Camera(glm::vec3 position, glm::vec3 lookAt, float fieldOfView,
			unsigned int viewportWidth, unsigned int viewportHeight,
			float nZPlane, float fZPlane);
		virtual ~Camera();
		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix();

		glm::vec3 getPosition() {return this->position;};
		void setPosition(glm::vec3 newPosition) {this->position = newPosition;};
		glm::vec3 getLookAt() {return this->lookAt;};
		void setLookAt(glm::vec3 newLookAt) {this->lookAt = newLookAt;};
		float getFieldOfView() {return this->fieldOfView;};
		void setFieldOfView(float newFieldOfView) {this->fieldOfView = newFieldOfView;};
		float getNZPlane() {return this->nZPlane;};
		void setNZPlane(float newNZPlane) {this->nZPlane = newNZPlane;};
		float getFZPlane() {return this->fZPlane;};
		void setFZPlane(float newFZPlane) {this->fZPlane = newFZPlane;};
	private:
		glm::vec3 position;
		glm::vec3 lookAt;
		float fieldOfView;
		unsigned int viewportWidth;
		unsigned int viewportHeight;
		float nZPlane;
		float fZPlane;
};

}

#endif
