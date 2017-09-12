#pragma once
#include "Typedef.h"
#include "RendererConfig.h"
#include "Logger.h"

//Author: Calum Mackervoy
//Purpose: Base class for all SpriteManagers in the game
//SpriteManagers will manage the displaying/layering of sprites & optimisations

//enum for referencing different types of sprite manager
enum managerType : uint8_t {
	MANAGER_BASE,
	MANAGER_CHARACTER,
	MANAGER_GEOGRAPHY
};

class SpriteManager {
public:
	SpriteManager(sf::Sprite* model = NULL, sf::Texture* tex = NULL, managerType type = MANAGER_BASE,
		suint opaque = 100, suint depth = 0);
	~SpriteManager();

	//functions to be overriden by sprite managers
	virtual void setPosition(sf::Vector2f pos) = 0;

	inline void setIndex(int index) {
		if (index < 0 || index > MAX_ELEMS) {
			Logger::logError("SpriteManager", "Index out of bounds!");
		}
		element->index = index;
	}
	inline sint getIndex() { return element->index; };

	inline void setTexture(sf::Texture* tex) {
		delete element->texture;
		element->texture = tex;
	};

	inline suint getDepth() { return depth; };
	inline void setDepth(suint val) { depth = val; };

	inline suint getOpaque() { return opaque; };
	inline void setOpaque(suint val) { opaque = val; };

	inline managerType getType() { return type; };

protected:
	Element* element;
	suint opaque;
	suint depth; //higher is further forward
	managerType type;
};