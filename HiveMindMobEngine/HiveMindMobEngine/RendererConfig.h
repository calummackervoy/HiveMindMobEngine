#pragma once
#include <SFML\Graphics.hpp>

//TODO: support for different sized windows

const int MAX_ELEMS = 128; //max graphical elements in a scene
const int WIN_HEIGHT = 800;
const int WIN_WIDTH = 800;

enum ElementType : uint8_t {
	SPRITE,
	CIRCLE_SHAPE,
	SQUARE_SHAPE
};

struct Element {
	int index; //index in the scene
	sf::Drawable* model = NULL;
	sf::Texture* texture = NULL;
	ElementType elemType = SPRITE;
};