#pragma once
#include <SFML\Graphics.hpp>
#include <stdint.h>

const uint8_t NUM_COLOURS = 20;
const sf::Uint8 ALPHA = 200;

enum ColourEnum : uint8_t {
	VERY_DARK_GREY,
	TAN_LIGHT_BROWN,
	BROWN,
	CEMENT,
	LIGHT_PINK,
	DARK_PINK,
	VIOLET,
	PURPLE,
	PLAYER_TWO_BLUE,
	PLAYER_ONE_RED,
	PLAYER_THREE_GREEN,
	BEIGE,
	ORANGE,
	VERY_LIGHT_BLUE,
	FOREST_GREEN,
	SWAMP_GREEN,
	GREEN_GREY,
	BLUE_GREY,
	RED_GREY,
	PURPLE_GREY
};

const sf::Color colours[NUM_COLOURS] = {
	sf::Color(50, 44, 45,ALPHA), //Very-dark-grey
	sf::Color(162,147,150,ALPHA), //Tan-light-brown
	sf::Color(141,84,46,ALPHA), //brown
	sf::Color(210,204,205,ALPHA), //cement
	sf::Color(255,236,255,ALPHA), //light pink
	sf::Color(254,184,252,ALPHA), //dark pink
	sf::Color(221,172,221,ALPHA), //violet
	sf::Color(211,120,245,ALPHA), //purple
	sf::Color(158,152,241,ALPHA), //player 2 blue
	sf::Color(252,116,119,ALPHA), //player 1 red
	sf::Color(138,210,136,ALPHA), //player 3 green
	sf::Color(240,245,135,ALPHA), //beige
	sf::Color(252,167,116,ALPHA), //orange
	sf::Color(201,247,250,ALPHA), //very light blue
	sf::Color(112,146,86,ALPHA), //forest green
	sf::Color(157,208,169,ALPHA), //swamp green
	sf::Color(138,154,133,ALPHA), //green grey
	sf::Color(133,133,154,ALPHA), //blue grey
	sf::Color(163,124,124,ALPHA), //red grey
	sf::Color(117,70,103,ALPHA) //purple grey
};