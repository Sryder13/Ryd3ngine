#ifndef RYD3_CORE_H
#define RYD3_CORE_H

#include <vector>
#include "SDL2/SDL.h"
#include "GL/glew.h"

#include "ryd3_camera.h"
#include "ryd3_entity.h"

class Music;

class Ryd3Core {
public:
	Ryd3Core();
	virtual ~Ryd3Core();
	bool setupWindow();
	bool setupContext();
	bool initialiseImage();
	void swapWindow();
	void addEntity(Entity entity);
	void drawEntities();
	Camera &getCamera() {return this->camera;};
	void playMusic(const std::string &filename);
	void stopMusic();
	bool playSound(const std::string &filename);
	void clearColourBuffer() {glClear(GL_COLOR_BUFFER_BIT);}
	void clearDepthBuffer() {glClear(GL_DEPTH_BUFFER_BIT);}

	void getCurMusic();
private:
	SDL_Window *mainWindow;
	SDL_GLContext glContext;
	std::vector<Entity> entityList;
	Music *curMusic;
	Camera camera;
};

#endif
