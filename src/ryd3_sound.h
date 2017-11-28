#ifndef RYD3_SOUND_H
#define RYD3_SOUND_H

#include <iostream>
#include "SDL2/SDL_mixer.h"

#include "ryd3_ResourceManager.h"

class Sound : public Resource {
	public:
		Sound();
		virtual ~Sound();
		bool load(const std::string &filename);
		bool playSound();
	private:
		Mix_Chunk *data;
};

#endif
