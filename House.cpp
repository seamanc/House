#include "House.h"

House::House(Camera* camera)
{
	this->camera = camera;

	Cube frontWall1(camera);
	frontWall1.setTexture("brickwall.jpg");
	frontWall1.setTranslation(glm::vec3(-1.0f, 1.0f, 2.0f));
	frontWall1.setScale(glm::vec3(1.0f, 2.0f, 0.5f));
	parts.push_back(frontWall1);

	Cube frontWall2(camera);
	frontWall2.setTexture("brickwall.jpg");
	frontWall2.setTranslation(glm::vec3(1.0f, 1.0f, 2.0f));
	frontWall2.setScale(glm::vec3(1.0f, 2.0f, 0.5f));
	parts.push_back(frontWall2);

	Cube leftWall(camera);
	leftWall.setTexture("brickwall.jpg");
	leftWall.setTranslation(glm::vec3(-1.75f, 1.0f, 0.25f));
	leftWall.setScale(glm::vec3(0.5f, 2.0f, 4.0f));
	parts.push_back(leftWall);

	Cube rightWall(camera);
	rightWall.setTexture("brickwall.jpg");
	rightWall.setTranslation(glm::vec3(1.75f, 1.0f, 0.25f));
	rightWall.setScale(glm::vec3(0.5f, 2.0f, 4.0f));
	parts.push_back(rightWall);

	Cube backWall(camera);
	backWall.setTexture("brickwall.jpg");
	backWall.setTranslation(glm::vec3(0.0f, 1.0f, -2.0f));
	backWall.setScale(glm::vec3(4.0f, 2.0f, 0.5));
	parts.push_back(backWall);

	Cube roof1(camera);
	roof1.setTexture("stone.jpg");
	roof1.setTranslation(glm::vec3(0.0f, 2.25f, 0.0f));
	roof1.setScale(glm::vec3(5.0f, 0.5f, 5.5f));
	parts.push_back(roof1);

	Cube roof2(camera);
	roof2.setTexture("stone.jpg");
	roof2.setTranslation(glm::vec3(0.0f, 2.75f, 0.0f));
	roof2.setScale(glm::vec3(4.0f, 0.5f, 4.5f));
	parts.push_back(roof2);
}

void House::draw()
{
	for (Cube cube : parts)
		cube.draw();
}