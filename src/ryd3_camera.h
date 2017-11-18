#include <iostream>
#include "glm/vec3.hpp"
#include "glm/gtc/quaternion.hpp"

class Camera {
	public:
		Camera();
		virtual ~Camera();
		void updateProjectionMatrix();
		void updateModelViewMatrix();

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