#include "Renderer.h"

Renderer::Renderer(ResourceManager* rm) {
	//TODO: make this part of the resource manager?
	//create the SFML window
	window = new sf::RenderWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "The Hive-Mind Mob");

	//cap framerate to 60FPS
	window->setFramerateLimit(60);

	this->rm = rm;
	selected = -1;
	overlayActive = false;
	//gridOver = new GridOverlay();
}

Renderer::~Renderer() {
	window->close();
	delete window;
}

sf::Sprite* Renderer::getSprite(string filepath, sf::Vector2f pos, bool smooth) {
	sf::Sprite* e = new sf::Sprite;
	e->setTexture(*getTexture(filepath, smooth));

	//TODO: setOrigin
	e->setPosition(pos);
	return e;
}

sf::Texture* Renderer::getTexture(string filepath, bool smooth) {
	//making a sprite
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(filepath)) {
		std::cout << "Failed to load texture" << std::endl;
		texture->loadFromFile(DEF_CHAR_SKIN); //resort to default
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

sf::VertexArray* Renderer::getTriangleFan(int numPoints, sf::Vector2f pos, int distApart,
	sf::Color colour, int slant) {
	// create an array of 3 vertices that define a triangle primitive
	sf::VertexArray* triangle = new sf::VertexArray(sf::TriangleFan, numPoints);

	// define the position of the triangle's points
	(*triangle)[0].position = pos;
	(*triangle)[0].color = colour;

	float x = pos.x - distApart;
	float y = pos.y;

	// define the color of the triangle's points
	for (int i = 1; i < numPoints; i++) {
		if ((pos.x - distApart) <= x) {
			x = x + (distApart / numPoints);
		}
		else {
			x = x - (distApart / numPoints);
		}

		if ((pos.y - distApart) <= y) {
			y = y + (distApart / numPoints);
		}
		else {
			y = y - (distApart / numPoints);
		}

		(*triangle)[i].position = sf::Vector2f(x,y);
		//TODO: make the points "slant" by slant factor
		(*triangle)[i].color = colour;
	}

	return triangle;

}

void Renderer::changeFanColour(int numPoints, sf::Color colour, sf::VertexArray* fan) {
	for (int i = 0; i < numPoints; i++) {
		(*fan)[i].color = colour;
	}
}

void Renderer::drawBasicScene(sf::Drawable* e) {
	window->clear(sf::Color::Black);
	if (e == NULL) return;
	window->draw(*e);
	window->display();
}

void Renderer::drawScene() {
	window->clear(sf::Color::Black);

	for (int i = 0; i < MAX_ELEMS; i++) {
		sf::Drawable* temp = rm->getSceneElem(i);
		if (temp == NULL) continue;

		//draw em
		window->draw(*temp);
	}
}

void Renderer::drawHud() {
	//draw the overlay if necessary
	/*if (overlayActive) {
	int i = 0;
	sf::RectangleShape* line = gridOver->getNextX(i);
	while (line != NULL) {
	window->draw(*line);
	i++;
	line = gridOver->getNextX(i);
	}

	i = 0;
	line = gridOver->getNextY(i);
	while (line != NULL) {
	window->draw(*line);
	i++;
	line = gridOver->getNextY(i);
	}
	}*/

	//draw the hud over the top of everything else
	for (int i = 0; i < MAX_ELEMS; i++) {
		sf::Drawable* temp = rm->getHudElem(i);
		if (temp == NULL) continue;

		window->draw(*temp);
	}

	window->display();
}