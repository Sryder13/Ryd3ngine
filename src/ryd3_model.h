#include <iostream>
#include <vector>
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/fwd.hpp"
#include "GL/glew.h"

#include "ryd3_ResourceManager.h"

class Texture;

struct model_vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec4 colour;
	glm::vec2 texCoord;
};

class Model : Resource {
	public:
		Model();
		virtual ~Model();
		virtual bool load(const std::string &filename);
		void drawModel(glm::vec3 position, glm::vec3 scale, glm::quat rotation);
	private:
		GLuint vboId;
		std::vector<model_vertex> vertices;
		Texture *texture;
};