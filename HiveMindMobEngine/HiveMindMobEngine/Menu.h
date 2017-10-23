#pragma once
#include <cstdlib>
#include "Renderer.h"
#include "ResourceManager.h"
#include "Physics.h"

//Author: Calum Mackervoy
//Purpose: Provides structure for a menu screen & functionality for displaying/responding to it

const uint8_t MAX_MENU_OPTIONS = 8;

//defines possible option actions
enum MenuAction : uint8_t {
	MENU_ACTION_NONE,
	MENU_WORLD_NEW,
	MENU_WORLD_LOAD
};

struct MenuSetup {
	string title;
	string optionLabels[MAX_MENU_OPTIONS];
	MenuAction optionActions[MAX_MENU_OPTIONS];
	int numOptions;
};

//TODO: expand functionality to have form input

class Menu {
public:
	Menu(Renderer* r, ResourceManager* rm, MenuSetup setup);
	~Menu();

	//checks if an option has been selected and returns the selected action
	MenuAction pollInput(sf::Vector2i clickpos);
	void display();

protected:
	Renderer* r;
	ResourceManager* rm;
	MenuSetup menu;
	int startIndex;
	int endIndex;
};