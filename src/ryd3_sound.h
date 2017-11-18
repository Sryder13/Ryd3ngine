#include <iostream>
#include "SDL2/SDL_mixer.h"

#include "ryd3_ResourceManager.h"

class Sound : Resource {
	public:
		Sound();
		virtual ~Sound();
		bool load(const std::string &filename);
		void playSound();
	private:
		Mix_Chunk *data;
};