#ifndef RYD3_TEXTURE_H
#define RYD3_TEXTURE_H

#include <iostream>
#include "GL/glew.h"

#include "ryd3_ResourceManager.h"

class Texture : Resource {
	public:
		Texture();
		virtual ~Texture();
		bool load(const std::string &filename);
		void bindTexture() {glBindTexture(GL_TEXTURE_2D, textureId);}
	private:
		GLuint textureId;
};

#endif
