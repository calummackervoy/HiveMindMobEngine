#include "Menu.h"

Menu::Menu(Renderer* r, ResourceManager* rm, MenuSetup setup) {
	this->r = r;
	this->rm = rm;
	menu = setup;
	startIndex = -1;
	endIndex = -1;

	//display it on the renderer
	display();
}

Menu::~Menu() {
	if (startIndex == -1 || endIndex == -1) return;
	for (int i = startIndex; i < endIndex; i++) {
		rm->removeHudElem(i);
	}
}

//better colours in below
void Menu::display() {
	//box background
	int left = WIN_WIDTH * 0.1;
	int width = WIN_WIDTH - left;
	int top = WIN_HEIGHT * 0.1;
	int height = std::min((WIN_HEIGHT - top), (menu.numOptions + 1) * 75);

	Element* bg = new Element;
	bg->elemType = SQUARE_SHAPE;
	bg->model = new sf::RectangleShape(sf::Vector2f(width, height));

	sf::RectangleShape* mod = (sf::RectangleShape*)(bg->model);
	mod->setFillColor(sf::Color::White);
	mod->setPosition(left, top);
	rm->addHudElem(bg);
	//failed menu display not enough resources
	if (bg->index == -1) {
		return;
	}
	else startIndex = bg->index;

	//title
	Element* title = new Element;
	sf::Text* titleText = r->getText(menu.title, rm->fonts[FONT_ABEL_REGULAR],
		42, sf::Color::Black);
	titleText->setPosition((left + width * 0.5), top + 30);
	title->elemType = TEXT;
	title->model = titleText;
	rm->addHudElem(title);
	//failed menu display not enough resources
	if (title->index == -1) return;

	//each option
	int i = 0;
	while (i < menu.numOptions) {
		Element* opt = new Element;
		sf::Text* text = r->getText(menu.options[i], rm->fonts[FONT_ABEL_REGULAR],
			24, sf::Color::Black);
		text->setPosition((left + width * 0.5), top + (30 * (i + 3)));
		opt->elemType = TEXT;
		opt->model = text;
		rm->addHudElem(opt);
		//failed menu display not enough resources
		if (opt->index == -1) return;
		i++;
	}
	//plus 2 for the background and title
	endIndex = startIndex + 2 + i;
}

//TODO: optimisations in knowing whether it's top or bottom half (from window size)
//TODO: this is currently a bit dodgy
int Menu::pollInput(sf::Vector2i clickpos) {
	if (startIndex == -1 || endIndex == -1) return -1;

	//what is in the clickposition?
	//loop from start index (+2 to avoid background & title) to end index
	for (int i = startIndex + 2; i < endIndex; i++) {
		//check the position of this option vs position of click
		Element* temp = rm->getHudElem(i);
		
		if (temp->elemType = TEXT) {
			sf::Text* t = (sf::Text*)temp->model;

			//create a bounding box physics can use
			sf::FloatRect r = t->getGlobalBounds();
			BoundingBox me;
			me.height = r.height;
			me.width = r.width;
			me.x = r.left;
			me.y = r.top - r.height;

			if (Physics::interfaceBoundingBox(clickpos, me)) {
				std::cout << i << " selected!" << std::endl;
				return i;
			}
		}
	}

	//flags no input found
	return -1;
}