#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

// Defines camera used to look at scenes
class Camera
{
public:
	// returns view matrix used for vertex shaders
	glm::mat4 viewMatrix();

	// functions to handle camera's movements
	void move(glm::vec3 vec);
	void rotate(glm::vec3 vec);
};

#endif
