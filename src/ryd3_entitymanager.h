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
		static EntityManager *getEntityManager() {static EntityManager eManager; return &eManager;}
		virtual ~EntityManager();
		void addEntity(Entity *entity);
		void removeEntity(Entity *entity);
		void drawEntities(Camera &camera, GLuint shaderProgram);
		void updateEntities();
		void clearEntities();
	private:
		EntityManager() {}
		EntityManager(EntityManager const&);
		void operator=(EntityManager const&);

		std::list<Entity *> entityList;
};

}

#endif
