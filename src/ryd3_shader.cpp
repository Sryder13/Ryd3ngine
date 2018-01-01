#include "ryd3_shader.h"

#include <fstream>

namespace Ryd3 {
	Shader::Shader() {
		shaders[Shader_Vertex] = 0;
		shaders[Shader_Fragment] = 0;
		shaderProgram = 0;
		numShaders = 0;
	}

	Shader::~Shader() {
		shaders[Shader_Vertex] = 0;
		shaders[Shader_Fragment] = 0;
		if (shaderProgram != 0) {
			glDeleteProgram(shaderProgram);
		}
	}

	void Shader::loadShaderText(const std::string &shaderSrc, GLenum type) {
		GLuint shader = glCreateShader(type);
		const char *shadercstr = shaderSrc.c_str();
		glShaderSource(shader, 1, &shadercstr, NULL);

		GLint status;
		glCompileShader(shader);
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE) {
			GLint infoLogLength;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);
			GLchar *strInfoLog = new GLchar[infoLogLength + 1];
			glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);
			std::cerr << "Shader Compile Error: " << strInfoLog << std::endl;
			delete[] strInfoLog;
			return;
		}
		if (type == GL_VERTEX_SHADER) {
			shaders[Shader_Vertex] = shader;
		}
		if (type == GL_FRAGMENT_SHADER) {
			shaders[Shader_Fragment] = shader;
		}
		numShaders++;
	}

	void Shader::createAndLink() {
		shaderProgram = glCreateProgram();
		if (shaders[Shader_Vertex] != 0) {
			glAttachShader(shaderProgram, shaders[Shader_Vertex]);
		}
		if (shaders[Shader_Fragment] != 0) {
			glAttachShader(shaderProgram, shaders[Shader_Fragment]);
		}

		GLint status;
		glLinkProgram(shaderProgram);
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
		if (status == GL_FALSE) {
			GLint infoLogLength;
			glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
			GLchar *strInfoLog = new GLchar[infoLogLength + 1];
			glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
			std::cerr << "Shader Link Error: " << strInfoLog << std::endl;
			delete[] strInfoLog;
		}

		glDetachShader(shaderProgram, shaders[Shader_Vertex]);
		glDetachShader(shaderProgram, shaders[Shader_Fragment]);

		glDeleteShader(shaders[Shader_Vertex]);
		glDeleteShader(shaders[Shader_Fragment]);
	}

	void Shader::registerAttribute(const std::string &attribute) {
		attribList[attribute] = glGetAttribLocation(shaderProgram, attribute.c_str());
	}

	void Shader::registerUniform(const std::string &uniform) {
		uniformLocationList[uniform] = glGetUniformLocation(shaderProgram, uniform.c_str());
	}

	GLuint Shader::getAttribLocation(const std::string &attribute) {
		return attribList[attribute];
	}

	GLuint Shader::getUniformLocation(const std::string &uniform) {
		return uniformLocationList[uniform];
	}

	void Shader::loadShaderFile(const std::string &filename, GLenum type) {
		std::ifstream fparser;
		fparser.open(filename, std::ios_base::in);
		if (fparser) {
			std::string buffer(std::istreambuf_iterator<char>(fparser), (std::istreambuf_iterator<char>()));
			loadShaderText(buffer, type);
		} else {
			std::cerr << "Invalid Shader path: " << filename << std::endl;
		}
	}

	void Shader::bind() {
		glUseProgram(shaderProgram);
	}

	void Shader::unbind() {
		glUseProgram(0);
	}
}