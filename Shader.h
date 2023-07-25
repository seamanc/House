#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>

// Handles use and configuration of bounded vertex and fragment shaders
class Shader
{
public:
	unsigned int ID;
	
	// Creates shader program with specifed vertex and fragment shaders.
	Shader(const char* vertexPath, const char* fragmentPath);

	// Activates shader for drawing with OpenGL
	void use();

	// Functions for setting uniforms in shaders
	void setUniformInt(int i, const char* name);
	void setUniformMat4(glm::mat4 mat, const char* name);

private:
	void checkCompileErrors(GLuint shader, std::string type);
};

#endif