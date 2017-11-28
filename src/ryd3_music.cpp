#include "ryd3_music.h"

Music::~Music() {
	Mix_FreeMusic(data);
}

bool Music::load(const std::string &filename) {
	Mix_LoadMUS(filename.c_str());
	if (data == NULL) {
		std::cerr << "Failed to load Music: " << filename << "SDL error:"
			<< Mix_GetError() << std::endl;
		return false;
	}
	return true;
}

bool Music::playMusic(int loops) {
	if (Mix_PlayMusic(data, loops) == -1) {
		return false;
	}
	return true;
}
