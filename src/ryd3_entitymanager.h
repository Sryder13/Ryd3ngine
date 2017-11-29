#ifndef RYD3_ENTITYMANAGER_H
#define RYD3_ENTITYMANAGER_H

#include <iostream>
#include <list>

#include <GL/glew.h>

class Entity;
class Camera;

class Ryd3_EntityManager {
	public:
		Ryd3_EntityManager();
		virtual ~Ryd3_EntityManager();
		void addEntity(Entity *entity);
		void removeEntity(Entity *entity);
		void drawEntities(Camera &camera, GLuint shaderProgram);
		void clearEntities();
	private:
		std::list<Entity *> entityList;
};

#endif
