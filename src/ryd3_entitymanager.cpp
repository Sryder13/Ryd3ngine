#include "ryd3_entitymanager.h"

#include <algorithm>

#include "ryd3_entity.h"
#include "ryd3_camera.h"

namespace Ryd3 {

void EntityManager::addEntity(Entity *entity) {
	entityList.push_back(entity);
}

void EntityManager::removeEntity(Entity *entity) {
	std::list<Entity *>::iterator it;
	it = std::find(entityList.begin(), entityList.end(), entity);
	if (it != entityList.end()) {
		entityList.erase(it);
		delete entity;
	} else {
		std::cout << "Entity was not in the entity list!" << std::endl;
	}
}

void EntityManager::drawEntities(Camera &camera, GLuint shaderProgram) {
	for (std::list<Entity *>::iterator it = entityList.begin(); it != entityList.end(); it++) {
		(*it)->drawEntity(camera.getViewMatrix(),
			camera.getProjectionMatrix(), shaderProgram);
	}
}

void EntityManager::clearEntities() {
	for (std::list<Entity *>::iterator it = entityList.begin(); it != entityList.end(); it++) {
		delete (*it);
	}
	entityList.clear();
}

}
