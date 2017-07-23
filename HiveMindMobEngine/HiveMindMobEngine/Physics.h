#pragma once
#include "RendererConfig.h"

struct BoundingBox {
	int height;
	int width;
	//note: position is position of bottom-left of square
	int x;
	int y;
};

class Physics {
public:
	Physics();
	~Physics();

	//interface detection with any BoundingBox
	bool interfaceBoundingBox(sf::Vector2i pos, BoundingBox area);

	//TODO: ray casting

private:

};