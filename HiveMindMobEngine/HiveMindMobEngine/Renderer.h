#pragma once
#include "ResourceManager.h"
#include "GridOverlay.h"
#include <string.h>
#include <iostream>

//Author: Calum Mackervoy
//Purpose: Renderer subsystem, manages graphics

using sf::CircleShape;

class Renderer {
public:
	Renderer(ResourceManager* rm);
	~Renderer();

	//method for generating a sprite
	Element* getSprite(std::string filepath, sf::Vector2f pos, bool smooth = false);

	//method for retreiving a texture from file
	sf::Texture* getTexture(std::string filepath, bool smooth = true);

	//method for constructing an SFML text object
	sf::Text* getText(std::string message, sf::Font* font,
		int size = 24, sf::Color colour = sf::Color::Black);

	//method for generating a triangle-fan shape
	static sf::VertexArray* getTriangleFan(int numPoints, sf::Vector2f pos, int distApart, sf::Color colour, int slant = 1);
	//method for changing the colour of a triangle fan
	void changeFanColour(int numPoints, sf::Color colour, sf::VertexArray* fan);

	inline sf::RenderWindow* getWindow() { return window; };
	inline int getSelected() { return selected; };
	inline void setSelected(int val) {
		if (val < -1 || val > MAX_ELEMS) throw std::exception("Bad value for selected");
		selected = val;
	};

	//function for drawing a very simple temporary scene with single element e.g. intro or game over animation
	void drawBasicScene(Element* e);
	//main scene drawing
	//TODO: this call may be unecessary and may need to be redesigned
	void drawScene();
	//hud & overlay drawing
	void drawHud();
	void clearScene() { rm->clearScene(); };
	void clearAll() { clearScene(); rm->clearHud(); }

private:
	//accesses the resource manager to access its elements
	ResourceManager* rm;
	sf::RenderWindow* window;
	//GridOverlay* gridOver;

	int selected; //index of selected element
	bool overlayActive; //whether a grid overlay is to be drawn or not

	inline Element* getSceneElem(int i) { return rm->getSceneElem(i); };
	inline Element* getHudElem(int i) { return rm->getHudElem(i); };
};