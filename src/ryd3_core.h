#ifndef RYD3_CORE_H
#define RYD3_CORE_H

#include <list>
#include "SDL2/SDL.h"
#include "GL/glew.h"

#include "ryd3_camera.h"
#include "ryd3_entitymanager.h"
#include "ryd3_entity.h"

namespace Ryd3 {

class Music;

class Core {
public:
	Core(unsigned int windowWidth, unsigned int windowHeight);
	virtual ~Core();
	bool initialise(unsigned int numSoundChannels);
	void swapWindow();
	Camera &getCamera() {return this->camera;};
	void playMusic(const std::string &filename, int loops);
	void stopMusic();
	bool playSound(const std::string &filename);
	void clearColourBuffer() {glClear(GL_COLOR_BUFFER_BIT);}
	void clearDepthBuffer() {glClear(GL_DEPTH_BUFFER_BIT);}

	Music *getCurMusic() {return this->curMusic;};
private:
	SDL_Window *mainWindow;
	SDL_GLContext glContext;
	unsigned int windowWidth;
	unsigned int windowHeight;
	Music *curMusic;
	Camera camera;

	bool setupWindow();
	bool setupContext();
	bool initialiseImage();
	bool initialiseMixer(unsigned int numChannels);
};

}

#endif
