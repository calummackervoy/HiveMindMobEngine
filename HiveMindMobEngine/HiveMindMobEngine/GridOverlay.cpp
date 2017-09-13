#include "GridOverlay.h"

GridOverlay::GridOverlay() {
	//setup the grid
	int count = 0;
	for (int i = 0; (i * TILE_SIZE) < WIN_WIDTH; i++) {
		drawLine(true, i);
		count++;
	}
	//flag last one as NULL
	if (count < MAX_WIDTH) {
		xLines[count] = NULL;
		//std::cout << "xLines endpoint = " << count << std::endl;
	}
	else Logger::logError("GridOverlay", "xLines could not flag last as NULL","count",count);

	//repeat process for y lines
	count = 0;
	for (int i = 0; ((i * 0.5) * TILE_SIZE) < WIN_HEIGHT; i = i + 2) {
		drawLine(false, i);
		count++;
	}
	//flag last one as NULL
	if (count < MAX_HEIGHT) {
		yLines[count] = NULL;
		//std::cout << "yLines endpoint = " << count << std::endl;
	}
	else Logger::logError("GridOverlay", "yLines could not flag last as NULL", "count", count); //TODO: handle?
}

GridOverlay::~GridOverlay() {

}

//which access is the increment over?
void GridOverlay::drawLine(bool xAxis, int index) {
	//second line with 160 degree rotation incremeneted along x axis
	//draw the rectangle
	sf::RectangleShape* linea;
	sf::RectangleShape* lineb = NULL; //second line for the other direction (on y axis)
	if (xAxis) linea = new sf::RectangleShape(sf::Vector2f(5000, 3));
	else {
		linea = new sf::RectangleShape(sf::Vector2f(5000, 3));
		lineb = new sf::RectangleShape(sf::Vector2f(5000, 3));
	}

	//rotate
	if(xAxis) linea->rotate(160);
	else {
		linea->rotate(20);
		lineb->rotate(20);
	}

	//change position based on increment
	if(xAxis) linea->setPosition(sf::Vector2f(((TILE_SIZE * 5) * index), 0.0f)); //extra movement to counter weird error
	else {
		linea->setPosition(sf::Vector2f(0.0f, (TILE_SIZE * index)));
		lineb->setPosition(sf::Vector2f(0.0f, -(TILE_SIZE * index)));
	}

	//change colour
	sf::Color colour = colours[COLOUR_BLUE_GREY];
	colour.a = 60;
	linea->setFillColor(colour);
	if (!xAxis) lineb->setFillColor(colour);

	//add it to the array of lines
	if (xAxis) xLines[index] = linea;
	else {
		yLines[index] = linea;
		yLines[index + 1] = lineb;
	}
}