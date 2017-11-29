#ifndef RYD3_ENTITY_H
#define RYD3_ENTITY_H

#include <iostream>
#include "glm/vec3.hpp"
#include "glm/gtc/quaternion.hpp"

#include <GL/glew.h>

namespace Ryd3 {

class Model;
class Camera;

class Entity {
	public:
		Entity() : Entity(glm::vec3(0.0), glm::vec3(1.0), glm::quat(0.0, 0.0, 0.0, 0.0)) {};
		Entity(glm::vec3 position, glm::vec3 scale, glm::quat rotation);
		virtual ~Entity();
		void drawEntity(glm::mat4 viewMatrix, glm::mat4 projectionMatrix,
			GLuint shaderProgram);
		virtual void update();

		Model getModel();
		bool setModel(Model &model);
		glm::vec3 getPosition() {return this->position;};
		void setPosition(glm::vec3 newPosition) {this->position = newPosition;};
		glm::vec3 getScale() {return this->scale;};
		void setScale(glm::vec3 newScale) {this->scale = newScale;};
		glm::quat getRotation() {return this->rotation;};
		void setRotation(glm::quat newRotation) {this->rotation = newRotation;};
	private:
		glm::vec3 position;
		glm::vec3 scale;
		glm::quat rotation;
		Model *model;
};

}

#endif
