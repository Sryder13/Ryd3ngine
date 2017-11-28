#include "ryd3_sound.h"

Sound::~Sound() {
	Mix_FreeChunk(data);
}

bool Sound::load(const std::string &filename) {
	data = Mix_LoadWAV(filename.c_str());

	if (data == NULL) {
		std::cerr << "Failed to load sound file: " << filename << "SDL error: "
			<< Mix_GetError() << std::endl;
		return false;
	}

	return true;
}

bool Sound::playSound() {
	if (Mix_PlayChannel(-1, data, 0) == -1) {
		return false;
	}
	return true;
}
