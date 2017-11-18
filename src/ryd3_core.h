#include <vector>
#include "SDL2/SDL.h"
#include "GL/glew.h"

#include "ryd3_camera.h"

class Entity;
class Music;

class Ryd3Core {
public:
	Ryd3Core();
	virtual ~Ryd3Core();
	bool setupWindowandContext();
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