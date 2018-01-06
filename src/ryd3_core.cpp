#include "ryd3_core.h"

#include <iostream>

#include "GL/glew.h"
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include "ryd3_ResourceManager.h"
#include "ryd3_music.h"
#include "ryd3_sound.h"

namespace Ryd3 {

Core::Core(unsigned int windowWidth, unsigned int windowHeight) {
	mainWindow = NULL;
	glContext = NULL;
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
}

Core::~Core() {
	Mix_Quit();
	Mix_CloseAudio();
	IMG_Quit();
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
}

bool Core::initialise(unsigned int numSoundChannels) {
	setupWindow();
	if (!setupContext()) {
		SDL_DestroyWindow(mainWindow);
		SDL_Quit();
		return false;
	}

	if (!initialiseImage()) {
		SDL_DestroyWindow(mainWindow);
		SDL_GL_DeleteContext(glContext);
		SDL_Quit();
		return false;
	}

	if (!initialiseMixer(numSoundChannels)) {
		SDL_DestroyWindow(mainWindow);
		SDL_GL_DeleteContext(glContext);
		IMG_Quit();
		SDL_Quit();
		return false;
	}
	return true;
}

void Core::playMusic(const std::string &filename, int loops) {
	curMusic = ResourceManager::getResourceManager()->getResource<Music>(filename);
	curMusic->playMusic(loops);
}

void Core::stopMusic() {
	Mix_HaltMusic();
	curMusic = NULL;
}

bool Core::playSound(const std::string &filename) {
	return ResourceManager::getResourceManager()->getResource<Sound>(filename)->playSound();
}

bool Core::setupWindow() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "SDL could not be initialised! SDL Error: "
			<< SDL_GetError() << std::endl;
		return false;
	}

	mainWindow = SDL_CreateWindow("Ryd3ngine Window",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth,
		windowHeight, SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN);

	if (mainWindow == NULL) {
		std::cerr << "SDL Window could not be created! SDL Error: "
			<< SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

bool Core::setupContext() {
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
		glViewport(0, 0, windowWidth, windowHeight);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	return true;
}

bool Core::initialiseImage() {
	if (!IMG_Init(IMG_INIT_PNG)) {
		std::cerr << "SDL Image could not be initialised! SDL Error: "
			<< SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

bool Core::initialiseMixer(unsigned int numChannels) {
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, numChannels, 4096) == -1) {
		std::cerr << "SDL Mixer could not be initialised! SDL Error: "
			<< Mix_GetError() << std::endl;
		return false;
	}
	int mixFlags = MIX_INIT_MP3|MIX_INIT_OGG;
	int initialisedFlags = Mix_Init(mixFlags);
	if (initialisedFlags&mixFlags != mixFlags) {
		std::cerr << "Failed to initialise support for following music formats:" << std::endl;
		if (initialisedFlags&MIX_INIT_MP3 == 0) {
			std::cerr << "MP3" << std::endl;
		}
		if (initialisedFlags&MIX_INIT_OGG == 0) {
			std::cerr << "OGG" << std::endl;
		}
		std::cerr << "SDL Error: " << Mix_GetError();
	}
	return true;
}

void Core::swapWindow() {
	SDL_GL_SwapWindow(mainWindow);
}

}
