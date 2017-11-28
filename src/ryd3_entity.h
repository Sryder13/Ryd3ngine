#ifndef RYD3_ENTITY_H
#define RYD3_ENTITY_H

#include <iostream>
#include "glm/vec3.hpp"
#include "glm/gtc/quaternion.hpp"

class Model;

class Entity {
	public:
		Entity();
		virtual ~Entity();
		void drawEntity();
		void update();

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

#endif
