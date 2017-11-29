#ifndef RYD3_ENTITYMANAGER_H
#define RYD3_ENTITYMANAGER_H

#include <iostream>
#include <list>

#include <GL/glew.h>

namespace Ryd3 {

class Entity;
class Camera;

class EntityManager {
	public:
		EntityManager();
		virtual ~EntityManager();
		void addEntity(Entity *entity);
		void removeEntity(Entity *entity);
		void drawEntities(Camera &camera, GLuint shaderProgram);
		void clearEntities();
	private:
		std::list<Entity *> entityList;
};

}

#endif
