#ifndef RYD3_CAMERA_H
#define RYD3_CAMERA_H

#include <iostream>
#include "glm/vec3.hpp"
#include "glm/gtc/quaternion.hpp"

class Camera {
	public:
		Camera() : Camera(glm::vec3(0.0), glm::quat(1.0, 0.0, 0.0, 0.0), 90.0f) {};
		Camera(glm::vec3 position, glm::quat rotation, float fieldOfView);
		virtual ~Camera();

		glm::vec3 getPosition() {return this->position;};
		void setPosition(glm::vec3 newPosition) {this->position = newPosition;};
		glm::quat getRotation() {return this->rotation;};
		void setRotation(glm::quat newRotation) {this->rotation = newRotation;};
		float getFieldOfView() {return this->fieldOfView;};
		void setFieldOfView(float newFieldOfView) {this->fieldOfView = newFieldOfView;};
	private:
		glm::vec3 position;
		glm::quat rotation;
		float fieldOfView;
};

#endif
