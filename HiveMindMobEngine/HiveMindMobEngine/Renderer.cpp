#include "Renderer.h"

Renderer::Renderer(ResourceManager* rm) {
	//TODO: make this part of the resource manager?
	//create the SFML window
	window = new sf::RenderWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "The Hive-Mind Mob");

	//cap framerate to 60FPS
	window->setFramerateLimit(60);

	this->rm = rm;
	selected = -1;
}

Renderer::~Renderer() {
	window->close();
	delete window;
}

sf::Texture* Renderer::getTexture(string filepath, bool smooth) {
	//making a sprite
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(filepath)) {
		std::cout << "Failed to load texture" << std::endl;
		//texture = sf::Texture(); //default
	}
	if (smooth) {
		texture->setSmooth(true); //makes boundaries less visible
	}

	return texture;
}

sf::Text* Renderer::getText(string message, sf::Font* font,
	int size, sf::Color colour) {

	sf::Text* text = new sf::Text;
	text->setFont(*font);
	text->setString(message);
	text->setCharacterSize(size);
	text->setFillColor(colour);

	return text;
}

void Renderer::drawBasicScene(Element* e) {
	window->clear(sf::Color::Black);
	if (e == NULL || e->model == NULL) return;
	window->draw(*e->model);
	window->display();
}

void Renderer::drawScene() {
	window->clear(sf::Color::Black);

	for (int i = 0; i < MAX_ELEMS; i++) {
		Element* temp = rm->getSceneElem(i);
		if (temp == NULL || temp->model == NULL) continue;

		//draw em
		window->draw(*temp->model);
	}

	//draw the hud over the top of everything else
	for (int i = 0; i < MAX_ELEMS; i++) {
		Element* temp = rm->getHudElem(i);
		if (temp == NULL || temp->model == NULL) continue;

		window->draw(*(temp->model));
	}

	window->display();
}