#include "SDL2/SDL.h"

class Ryd3Core {
public:
	Ryd3Core();
	bool setupWindowandContext();
	void swapWindow();
	~Ryd3Core();
private:
	SDL_Window *mainWindow;
	SDL_GLContext glContext;
};