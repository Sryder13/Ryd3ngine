#include "ryd3_entity.h"

#include "ryd3_model.h"
#include "ryd3_camera.h"

#include "glm/gtc/matrix_transform.hpp"

namespace Ryd3 {

Entity::Entity(glm::vec3 position, glm::vec3 scale, glm::quat rotation) {
	this->position = position;
	this->scale = scale;
	this->rotation = rotation;
}

void Entity::drawEntity(glm::mat4 viewMatrix, glm::mat4 projectionMatrix,
	GLuint shaderProgram) {
	if (model) {
		glm::mat4 positionMatrix = glm::translate(glm::mat4(), position);
		glm::mat4 rotationMatrix = glm::mat4_cast(rotation);
		glm::mat4 scaleMatrix = glm::scale(glm::mat4(), scale);

		glm::mat4 modelMatrix = positionMatrix * rotationMatrix * scaleMatrix;

		glm::mat4 mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;

		GLuint matrixLocation = glGetUniformLocation(shaderProgram,
			"ryd3_mvpMatrix");

		glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, &mvpMatrix[0][0]);

		model->drawModel();
	}
}

}
