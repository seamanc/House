#include "Cube.h"
#include "stb_image.h"

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

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

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Generate matrices
	model = glm::mat4(1.0f);
	view = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

void Cube::setTranslation(glm::vec3 vec)
{
	model = glm::translate(model, vec);
}

void Cube::setRotation(float degrees, glm::vec3 axis)
{
	model = glm::rotate(model, degrees, axis);
}

void Cube::setScale(glm::vec3 vec)
{
	model = glm::scale(model, vec);
}

void Cube::draw() 
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	shader.use();
	shader.setUniformMat4(model, "model");

	view = camera->viewMatrix();
	shader.setUniformMat4(view, "view");

	shader.setUniformMat4(projection, "projection");
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Cube::setTexture(const char* fileName)
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char* data = stbi_load(fileName, &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	
	shader.use();
	shader.setUniformInt(0, "ourTexture");
}