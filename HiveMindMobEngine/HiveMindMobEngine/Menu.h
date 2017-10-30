#pragma once
#include <cstdlib>
#include "Renderer.h"
#include "ResourceManager.h"
#include "Physics.h"
#include "Logger.h"

//Author: Calum Mackervoy
//Purpose: Provides structure for a menu screen & functionality for displaying/responding to it

const uint8_t MAX_MENU_OPTIONS = 8;

//defines possible option actions
enum MenuAction : uint8_t {
	MENU_ACTION_NONE,
	MENU_WORLD_NEW,
	MENU_WORLD_LOAD,
	MENU_COMMAND_MOVE,
	MENU_COMMAND_EXAMPLE_ONE,
	MENU_COMMAND_EXAMPLE_TWO
};

enum MenuDisplayMode : uint8_t {
	MENU_MAIN,
	MENU_MOUSE
};

struct MenuSetup {
	string title = "";
	string optionLabels[MAX_MENU_OPTIONS];
	MenuAction optionActions[MAX_MENU_OPTIONS];
	int numOptions;
};

class Menu {
public:
	Menu(Renderer* r, ResourceManager* rm, MenuSetup setup, MenuDisplayMode mode = MENU_MAIN);
	~Menu();

	//checks if an option has been selected and returns the selected action
	MenuAction pollInput(sf::Vector2i clickpos);
	//displays it in the preconfigured way
	void display();

protected:
	Renderer* r;
	ResourceManager* rm;
	MenuSetup menu;
	int startIndex;
	int endIndex;
	MenuDisplayMode mode;

	//displays menu in large mode (main menus)
	void displayLarge();
	//displays menu in mouse mode (action options)
	void displayMouse();
};