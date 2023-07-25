#include "Cube.h"
#include <glm/gtc/matrix_transform.hpp>

Cube::Cube(Camera* camera) : shader(CUBE_VERTEX, CUBE_FRAGMENT)
{
	this->camera = camera;
	// Generate vertex objects
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeData), cubeData, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Generate matrices
	model = glm::mat4(1.0f);
	view = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

void Cube::setRotation(float degrees, glm::vec3 axis)
{
	model = glm::mat4(1.0f);
	model = glm::rotate(model, degrees, axis);
}

void Cube::addRotation(float degrees, glm::vec3 axis)
{
	model = glm::rotate(model, degrees, axis);
}

void Cube::draw() 
{
	shader.use();
	shader.setUniformMat4(model, "model");

	view = camera->viewMatrix();
	shader.setUniformMat4(view, "view");

	shader.setUniformMat4(projection, "projection");
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}