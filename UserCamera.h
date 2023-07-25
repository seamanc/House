#ifndef USER_CAMERA_H
#define USER_CAMERA_H

#include "Camera.h"

enum CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

// Class for controlling camera based on user inputs
class UserCamera
{
public:
	Camera camera;

	// Camera movement based on camera orientation
	void move(CameraMovement direction, float deltaTime);

	// Camera rotation determined by x and y mouse position offsets
	// TODO: currently does not account for lookAt flip
	void rotate(float xoffset, float yoffset);

	void setSpeed(float speed);

private:
	float speed = 2.5f;
	float sensitivity = 0.001f;
};

#endif // !USER_CAMERA_H
