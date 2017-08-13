#pragma once
#include "Typedef.h"
#include "RendererConfig.h"
#include "Logger.h"

//Author: Calum Mackervoy
//Purpose: Base class for all SpriteManagers in the game
//SpriteManagers will manage the displaying/layering of sprites & optimisations

class SpriteManager {
public:
	SpriteManager(sf::Sprite* model = NULL, sf::Texture* tex = NULL);
	~SpriteManager();

	inline void setIndex(int index) {
		if (index < 0 || index > MAX_ELEMS) {
			Logger::logError("SpriteManager", "Index out of bounds!");
		}
		element->index = index;
	}

	inline void setTexture(sf::Texture* tex) {
		delete element->texture;
		element->texture = tex;
	};

	//TODO: move depth management to renderer?
	inline suint getDepth() { return depth; };
	inline void setDepth(suint val) { depth = val; };

	inline suint getOpaque() { return opaque; };
	inline void setOpaque(suint val) { opaque = val; };

private:
	Element* element;
	suint opaque;
	suint depth; //higher is further forward
};