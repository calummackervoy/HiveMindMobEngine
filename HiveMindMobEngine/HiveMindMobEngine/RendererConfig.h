#pragma once
#include <SFML\Graphics.hpp>

//TODO: support for different sized windows

const int MAX_ELEMS = 128; //max graphical elements in a scene
const int WIN_HEIGHT = 1000;
const int WIN_WIDTH = 1800;

enum ElementType : uint8_t {
	SPRITE,
	CIRCLE_SHAPE,
	SQUARE_SHAPE,
	TEXT
};

struct Element {
	int index; //index in the scene
	sf::Drawable* model = NULL;
	sf::Texture* texture = NULL;
	ElementType elemType = SPRITE;
};

//functions for converting between world space co-ords and view space co-ords
// ScreenX = 2*WorldX - 2*WorldY
// ScreenY = WorldX + WorldY
static sf::Vector2f worldToScreen(sf::Vector2f v) {
	return sf::Vector2f(2.0f*v.x - 2.0f*v.y, v.x + v.y);
}

// WorldX = (ScreenX + 2*ScreenY)/4
// WorldY = (2*ScreenY - ScreenX)/4
static sf::Vector2f screenToWorld(sf::Vector2f v) {
	return sf::Vector2f((v.x + 2.0f*v.y) / 4.0f, (2.0f*v.y - v.x) / 4.0f);
}