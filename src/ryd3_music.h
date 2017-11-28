#ifndef RYD3_MUSIC_H
#define RYD3_MUSIC_H

#include <iostream>
#include "SDL2/SDL_mixer.h"

#include "ryd3_ResourceManager.h"

class Music : public Resource {
	public:
		Music();
		virtual ~Music();
		bool load(const std::string &filename);
		void playMusic();
	private:
		Mix_Music *data;
};

#endif
