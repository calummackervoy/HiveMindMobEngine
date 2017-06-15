#pragma once
#include "ResourceManager.h"
#include <string.h>
#include <iostream>

//Author: Calum Mackervoy
//Purpose: Renderer subsystem, manages graphics

using std::string;
using sf::CircleShape;

class Renderer {
public:
	Renderer(ResourceManager* rm);
	~Renderer();

	//method for retreiving a texture from file
	sf::Texture* getTexture(string filepath, bool smooth = true);

	//method for constructing an SFML text object
	sf::Text* getText(string message, sf::Font* font,
		int size = 24, sf::Color colour = sf::Color::Black);

	inline sf::RenderWindow* getWindow() { return window; };
	inline int getSelected() { return selected; };
	inline void setSelected(int val) {
		if (val < -1 || val > MAX_ELEMS) throw std::exception("Bad value for selected");
		selected = val;
	};

	//function for drawing a very simple temporary scene with single element e.g. intro or game over animation
	void drawBasicScene(Element* e);
	//main scene drawing
	void drawScene();
	void clearScene() { rm->clearScene(); };

private:
	//accesses the resource manager to access its elements
	ResourceManager* rm;
	sf::RenderWindow* window;

	int selected; //index of selected element

	inline Element* getSceneElem(int i) { return rm->getSceneElem(i); };
	inline Element* getHudElem(int i) { return rm->getHudElem(i); };
};