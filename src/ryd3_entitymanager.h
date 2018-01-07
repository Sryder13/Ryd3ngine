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
		std::list<Entity *>::iterator removeEntity(Entity *entity);
		void drawEntities(Camera &camera, GLuint shaderProgram);
		void updateEntities();
		void clearEntities();
		std::list<Entity *>::iterator getListBegin() {return entityList.begin();};
		std::list<Entity *>::iterator getListEnd() {return entityList.end();};
	private:
		EntityManager() {}
		EntityManager(EntityManager const&);
		void operator=(EntityManager const&);

		std::list<Entity *> entityList;
};

}

#endif
