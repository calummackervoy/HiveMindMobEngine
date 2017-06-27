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
	endIndex = startIndex + i;
}

//TODO
int Menu::pollInput(sf::Vector2f clickpos) {
	if (startIndex == -1 || endIndex == -1) return -1;

	//what is in the clickposition?

	//flags no input found
	return -1;
}