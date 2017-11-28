#include "ryd3_core.h"

#include <iostream>

#include "GL/glew.h"
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_image.h"

Ryd3Core::Ryd3Core() {
	mainWindow = NULL;
	glContext = NULL;
}

Ryd3Core::~Ryd3Core() {
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
}

bool Ryd3Core::setupWindow() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not be initialised! SDL Error: "
			<< SDL_GetError() << std::endl;
		return false;
	}

	mainWindow = SDL_CreateWindow("Ryd3ngine Window",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,
		SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN);

	if (mainWindow == NULL) {
		std::cerr << "SDL Window could not be created! SDL Error: "
			<< SDL_GetError() << std::endl;
		return false;
	} else {
		return setupContext();
	}
	return true;
}

bool Ryd3Core::setupContext() {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	glContext = SDL_GL_CreateContext(mainWindow);
	if (glContext == NULL) {
		std::cerr << "OpenGL Context could not be created! SDL Error: "
			<< SDL_GetError() << std::endl;
		SDL_DestroyWindow(mainWindow);
		return false;
	} else {
		GLenum glewError = glewInit();
		if (glewError != GLEW_OK) {
			std::cerr << "GLEW failed to initialise. GLEW Error: "
				<< glewGetErrorString(glewError) << std::endl;
			return false;
		}

		std::cout << "GL_VERSION   : " << glGetString(GL_VERSION) << std::endl;
		std::cout << "GL_VENDOR    : " << glGetString(GL_VENDOR) << std::endl;
		std::cout << "GL_RENDERER  : " << glGetString(GL_RENDERER) << std::endl;

		if (SDL_GL_SetSwapInterval(1) < 0) {
			std::cerr << "Warning: Unable to set VSync! SDL Error: "
				<< SDL_GetError() << std::endl;
		}

		glDisable(GL_DEPTH_TEST);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glViewport(0, 0, 640, 480);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glClear(GL_COLOR_BUFFER_BIT);

		return initialiseImage();
	}
}

bool Ryd3Core::initialiseImage() {
	if (!IMG_Init(IMG_INIT_PNG)) {
		std::cerr << "SDL Image could not be initialised! SDL Error: "
			<< SDL_GetError() << std::endl;
		return false;
	} else {
		return true;
	}
}

void Ryd3Core::swapWindow() {
	SDL_GL_SwapWindow(mainWindow);
}
