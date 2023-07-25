#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

// Defines camera used to look at scenes
class Camera
{
public:
	Camera();

	// returns view matrix used for vertex shaders
	glm::mat4 viewMatrix();

	glm::vec3 getFront();
	glm::vec3 getRight();

	// functions to handle camera's movements
	void move(glm::vec3 vec);
	void rotate(float degrees, glm::vec3 axis);
private:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;
};

#endif
