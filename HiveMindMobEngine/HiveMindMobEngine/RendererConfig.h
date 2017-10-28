#pragma once
#include "Typedef.h"
#include <SFML\Graphics.hpp>

//TODO: support for different sized windows

const std::string DEF_CHAR_SKIN = "../../assets/sprites/characters/individual/testchar_sw.png";
const int MAX_ELEMS = 128; //max graphical elements in a scene
const int WIN_HEIGHT = 1000;
const int WIN_WIDTH = 1800;
const suint TILE_SIZE = 64;
//const suint TILE_HEIGHT = TILE_SIZE * 2;
//const suint TILE_WIDTH = TILE_SIZE * 4;
const float TOLERATE = 0.1;

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
	return sf::Vector2f((v.x + 2.0f*v.y) * 0.25f, (2.0f*v.y - v.x) * 0.25f);
}

//function to evaluate if two float values are close enough to equal
static bool tolerate(float a, float b) {
	if (a - b < TOLERATE) return true;
	else return false;
}
//function to evaluate if two co-ords are close enough to equal
static bool tolerate(sf::Vector2f a, sf::Vector2f b) {
	if (tolerate(a.x, b.x) && tolerate(a.y, b.y)) return true;
	else return false;
}