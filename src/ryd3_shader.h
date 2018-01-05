#ifndef RYD3_SHADER_H
#define RYD3_SHADER_H

#include <iostream>
#include <GL/glew.h>
#include <map>

namespace Ryd3 {

class Shader {
	public:
		Shader();
		virtual ~Shader();
		void loadShaderFile(const std::string &filename, GLenum type);
		void loadShaderText(const std::string &shaderSrc, GLenum type);
		void createAndLink();
		void registerAttribute(const std::string &attribute);
		void registerUniform(const std::string &uniform);
		GLuint getProgramID() {return this->shaderProgram;}
		GLuint getAttribLocation(const std::string &attrib);
		GLuint getUniformLocation(const std::string &uniform);
		void bind();
		void unbind();

	private:
		GLuint shaderProgram;
		int numShaders;
		GLuint shaders[2]; // vertex and fragment
		std::map<std::string, GLuint> attribList;
		std::map<std::string, GLuint> uniformLocationList;
		enum ShaderType {
			Shader_Vertex,
			Shader_Fragment
		};
};

}

#endif
