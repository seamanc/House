#include "UserCamera.h"

void UserCamera::move(CameraMovement direction, float deltaTime)
{
	float velocity = speed * deltaTime;
	if (direction == FORWARD)
		camera.move(camera.getFront() * velocity);
	if (direction == BACKWARD)
		camera.move(-camera.getFront() * velocity);
	if (direction == LEFT)
		camera.move(-camera.getRight() * velocity);
	if (direction == RIGHT)
		camera.move(camera.getRight() * velocity);
}

void UserCamera::rotate(float xoffset, float yoffset)
{
	float xval = xoffset * sensitivity;
	float yval = yoffset * sensitivity;

	camera.rotate(-xval, glm::vec3(0.0f, 1.0f, 0.0f));
	camera.rotate(yval, camera.getRight());
}