#ifndef RYD3_MODEL_H
#define RYD3_MODEL_H

#include <iostream>
#include <vector>
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/fwd.hpp"
#include "GL/glew.h"

#include "ryd3_ResourceManager.h"

class Texture;

class Model : public Resource {
	public:
		Model();
		virtual ~Model();
		virtual bool load(const std::string &filename);
		void drawModel(glm::vec3 position, glm::vec3 scale, glm::quat rotation);
	private:
		void setupArrayObject();

		GLuint vaoId;
		GLuint vertexBuffer;
		GLuint uvBuffer;
		GLuint normalBuffer;
		GLuint indicesBuffer;
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals;
		std::vector<unsigned short> indices;
		Texture * texture;
};

#endif
