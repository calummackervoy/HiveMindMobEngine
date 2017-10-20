#pragma once
/*#include "Typedef.h"
#include "RendererConfig.h"
#include "Colour.h"
#include "Logger.h"

class GridOverlay {
public:
	GridOverlay();
	~GridOverlay();

	inline sf::RectangleShape* getNextX(int i) {
		if (i > MAX_WIDTH || xLines[i] == NULL) return NULL;
		else return xLines[i];
	}

	inline sf::RectangleShape* getNextY(int i) {
		if (i > MAX_WIDTH || yLines[i] == NULL) return NULL;
		else return yLines[i];
	}

protected:
	//array of lines
	sf::RectangleShape* xLines[MAX_WIDTH];
	sf::RectangleShape* yLines[MAX_HEIGHT];

	//method for drawing a line
	void drawLine(bool xAxis, int index);
};*/