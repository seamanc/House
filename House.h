#ifndef HOUSE_H
#define HOUSE_H

#include "Cube.h"

#include <vector>

class House
{
public:
	Camera* camera;

	House(Camera* camera);

	void draw();

private:
	std::vector<Cube> parts;
};

#endif

