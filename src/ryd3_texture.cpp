#include "ryd3_texture.h"
#include "SDL2/SDL_image.h"

namespace Ryd3 {

Texture::Texture() {
	// nothing needed right now
}

bool Texture::load(const std::string &filename) {
	SDL_Surface *surface = IMG_Load(filename.c_str());
	if (surface == NULL) {
		std::cerr << "Could not load image: " << filename << "SDL_Image error: "
			<< IMG_GetError() << std::endl;
		glBindTexture(GL_TEXTURE_2D, 0);
		return false;
	} else {
		GLuint imageMode;

		if (surface->format->BitsPerPixel == 3) {
			imageMode = GL_RGB;
		} else if (surface->format->BitsPerPixel == 4) {
			imageMode = GL_RGBA;
		} else {
			std::cerr << "Image wrong format: " << filename << std::endl;
			SDL_FreeSurface(surface);
			glBindTexture(GL_TEXTURE_2D, 0);
			return false;
		}

		setFilename(filename);

		glGenTextures(1, &textureId);
		glBindTexture(GL_TEXTURE_2D, textureId);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		if (GLEW_SGIS_generate_mipmap)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
			glHint(GL_GENERATE_MIPMAP_HINT_SGIS, GL_NICEST);

			glTexImage2D(GL_TEXTURE_2D, 0, imageMode, surface->w, surface->h, 0,
				imageMode, GL_UNSIGNED_BYTE, surface->pixels);
		}
		else
		{
			gluBuild2DMipmaps(GL_TEXTURE_2D, imageMode, surface->w, surface->h,
				imageMode, GL_UNSIGNED_BYTE, surface->pixels);
		}

		SDL_FreeSurface(surface);

		return true;
	}
}

Texture::~Texture() {
	glDeleteTextures(1, &textureId);
}

}
