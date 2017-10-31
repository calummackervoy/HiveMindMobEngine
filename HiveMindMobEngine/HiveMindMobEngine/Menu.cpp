#include "Menu.h"

Menu::Menu(Renderer* r, ResourceManager* rm, MenuSetup setup, MenuDisplayMode mode) {
	this->r = r;
	this->rm = rm;
	this->mode = mode;
	menu = setup;
	startIndex = -1;
	endIndex = -1;

	//display it on the renderer
	display();
}

Menu::~Menu() {
	//handle special cases
	//start of menu was unsuccessful
	if (startIndex == -1 || endIndex == -1) return;

	for (int i = startIndex; i <= endIndex; i++) {
		rm->removeHudElem(i);
	}
}

void Menu::display(sf::Vector2f mousepos) {
	switch (mode) {
	case MENU_MAIN:
		return displayLarge();
	case MENU_MOUSE:
		return displayMouse(mousepos);
	default:
		Logger::logError("Menu display",
			"display() call with unrecognised display mode","Mode", (int)mode);
	}
}

//better colours in below
void Menu::displayLarge() {
	//box background
	int left = WIN_WIDTH * 0.1;
	int width = WIN_WIDTH - left;
	int top = WIN_HEIGHT * 0.1;
	int height = std::min((WIN_HEIGHT - top), (menu.numOptions + 1) * 75);
	int halfWidth = width * 0.5;

	sf::RectangleShape* bg = new sf::RectangleShape(sf::Vector2f(width, height));
	bg->setFillColor(sf::Color::White);
	bg->setPosition(left, top);
	
	startIndex = rm->addHudElem(bg);
	if (startIndex == -1) {
		//failed menu display not enough resources
		return;
	}
	endIndex = startIndex + 1;

	//title
	sf::Text* title = r->getText(menu.title, rm->fonts[FONT_ABEL_REGULAR],
		42, sf::Color::Black);
	title->setPosition((left + halfWidth), top + 30);

	//failed menu display not enough resources
	if (rm->addHudElem(title) == -1) {
		return;
	}
	endIndex++;

	//each option
	int i = 0;
	while (i < menu.numOptions) {
		sf::Text* text = r->getText(menu.optionLabels[i], rm->fonts[FONT_ABEL_REGULAR],
			24, sf::Color::Black);
		text->setPosition((left + halfWidth), top + (30 * (i + 3)));

		//failed menu display not enough resources
		if (rm->addHudElem(text) == -1) return;
		endIndex++;
		i++;
	}
}

void Menu::displayMouse(sf::Vector2f mousepos) {
	int widestWidth = -1;

	const int TEXT_SIZE = 14;

	//work out height of background as text height * number of options
	int height = (TEXT_SIZE * menu.numOptions) + 5;
	//std::cout << "height: " << height << std::endl;

	//draw the background of the menu
	sf::RectangleShape* bg = new sf::RectangleShape(sf::Vector2f(100, height));
	bg->setFillColor(sf::Color::White);
	rm->addHudElem(bg);

	//set position to mouse position
	bg->setPosition(mousepos);

	//set up text for each option
	for (int i = 0; i < menu.numOptions; i++) {
		sf::Text* text = r->getText(menu.optionLabels[i], rm->fonts[FONT_ABEL_REGULAR],
			TEXT_SIZE, sf::Color::Black);
		
		//move down the menu to the slot option
		sf::Vector2f pos;
		pos.x = mousepos.x;
		pos.y = mousepos.y + (i * TEXT_SIZE);

		text->setPosition(pos);
		
		int temp = rm->addHudElem(text);
		if (temp == -1) {
			//failed menu display not enough resources
			return;
		}
		else {
			//am I the first iteration?
			if (startIndex == -1) startIndex = temp;
			endIndex = temp;
		}
	}
}

//TODO: optimisations in knowing whether it's top or bottom half (from window size)
//TODO: this is currently a bit dodgy
MenuAction Menu::pollInput(sf::Vector2i clickpos) {
	if (startIndex == -1 || endIndex == -1) return MENU_ACTION_NONE;

	//what is in the clickposition?
	//loop from start index (+2 to avoid background & title) to end index
	int count = 0;

	for (int i = startIndex + 2; i < endIndex; i++) {
		//check the position of this option vs position of click
		sf::Text* temp = (sf::Text*)rm->getHudElem(i);

		//create a bounding box physics can use
		sf::FloatRect r = temp->getGlobalBounds();
		BoundingBox me;
		me.height = r.height;
		me.width = r.width;
		me.x = r.left;
		me.y = r.top - r.height;

		if (Physics::interfaceBoundingBox(clickpos, me)) {
			//std::cout << count << " selected!" << std::endl;
			return menu.optionActions[count];
		}

		count++;
	}

	//flags no input found
	return MENU_ACTION_NONE;
}