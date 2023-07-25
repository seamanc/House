#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

Camera::Camera()
{
	position = glm::vec3(0.0f, 0.0f, 3.0f);
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	right = glm::vec3(1.0f, 0.0f, 0.0f);
	worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
}

glm::mat4 Camera::viewMatrix()
{
	return glm::lookAt(position, position + front, up);
}

glm::vec3 Camera::getFront()
{
	return front;
}

glm::vec3 Camera::getRight()
{
	return right;
}

void Camera::move(glm::vec3 vec)
{
	position += vec;
}

void Camera::rotate(float degrees, glm::vec3 axis)
{
	front = glm::rotate(front, degrees, axis);
	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}