#pragma once
#include <cstdlib>
#include <string>
#include "Renderer.h"
#include "ResourceManager.h"
#include "Physics.h"

//Author: Calum Mackervoy
//Purpose: Provides structure for a menu screen & functionality for displaying/responding to it

using std::string;

const uint8_t MAX_MENU_OPTIONS = 8;

struct MenuSetup {
	string title;
	string options[MAX_MENU_OPTIONS];
	int numOptions;
};

//TODO: expand functionality to have form input

class Menu {
public:
	Menu(Renderer* r, ResourceManager* rm, MenuSetup setup);
	~Menu();

	//@return the index of the option selected or -1 for none
	int pollInput(sf::Vector2i clickpos);
	void display();

protected:
	Renderer* r;
	ResourceManager* rm;
	MenuSetup menu;
	int startIndex;
	int endIndex;
	int optionHeight;
};