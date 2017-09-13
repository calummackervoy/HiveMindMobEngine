#include "GridOverlay.h"

GridOverlay::GridOverlay() {
	//setup the grid
	int count = 0;
	for (int i = 0; ((i+1) * TILE_SIZE) < WIN_WIDTH; i++) {
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
	for (int i = 0; ((i + 1) * TILE_SIZE) < WIN_HEIGHT; i++) {
		drawLine(false, i);
		count++;
	}
	//flag last one as NULL
	if (count < MAX_HEIGHT) {
		yLines[count] = NULL;
		//std::cout << "yLines endpoint = " << count << std::endl;
	}
	else Logger::logError("GridOverlay", "yLines could not flag last as NULL", "count", count);
}

GridOverlay::~GridOverlay() {

}

//which access is the increment over?
void GridOverlay::drawLine(bool xAxis, int index) {
	//draw the rectangle
	sf::RectangleShape* line;
	if (xAxis) line = new sf::RectangleShape(sf::Vector2f(WIN_HEIGHT, 3));
	else line = new sf::RectangleShape(sf::Vector2f(WIN_WIDTH, 3));

	//rotate
	if(xAxis) line->rotate(-70);
	else line->rotate(70);

	//change position based on increment
	if(xAxis) line->setPosition(sf::Vector2f((TILE_SIZE * (index+1)),0.0f));
	else line->setPosition(sf::Vector2f(0.0f, (TILE_SIZE * (index + 1))));

	//change colour
	sf::Color colour = colours[COLOUR_BLUE_GREY];
	colour.a = 60;
	line->setFillColor(colour);

	//add it to the array of lines
	if (xAxis) xLines[index] = line;
	else yLines[index] = line;
}