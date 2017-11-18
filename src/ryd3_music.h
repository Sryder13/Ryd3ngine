#include <iostream>
#include "SDL2/SDL_mixer.h"

#include "ryd3_ResourceManager.h"

class Music : Resource {
	public:
		Music();
		virtual ~Music();
		bool load(const std::string &filename);
		void playMusic();
	private:
		Mix_Music *data;
};