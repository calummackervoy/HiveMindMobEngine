#pragma once
#include "Renderer.h"
#include "ResourceManager.h"
#include "Typedef.h"
#include "Terrain.h"
#include "CharacterGameSprite.h"
#include "Logger.h"

const suint TILE_SIZE = 64;
const suint MAX_TILE_OCCUPANTS = 4;

enum SpriteType {
	SPRITETYPE_OCCUPANT,
	SPRITETYPE_DECOR,
	SPRITETYPE_INTERACTABLE
};

class Tile
{
public:
	Tile(ResourceManager* rm, Terrain ter= FLAT_GROUND, TerrainGraphic floorTex = FLOOR_GRASS);
	~Tile();

	//function for drawing a tile(rendering)
	void draw(sf::RenderWindow* win);
	void clear(bool deleteContents);

	//insert/remove a sprite pointer in local pointage & get the resource manager to manage
	inline bool insertSprite(ResourceManager* rm, GameSprite* s, SpriteType type) {
		switch (type) {
		case SPRITETYPE_OCCUPANT:
			for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
				if (occupants[i] == NULL) {
					rm->addSprite(s);
					occupants[i] = (CharacterGameSprite*)s;

					//set the position to the bottom-centre of this tile
					tieSpriteToBottom(occupants[i]);
					return true;
				}
			}
			return false;
		case SPRITETYPE_DECOR:
			for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
				if (decor[i] == NULL) {
					rm->addSprite(s);
					decor[i] = s;

					//set the position to match the position of this tile
					tieSpriteToBottom(decor[i]);
					return true;
				}
			}
			return false;
		case SPRITETYPE_INTERACTABLE:
			for (int i = 0; i < MAX_TILE_OCCUPANTS; i++) {
				if (interactables[i] == NULL) {
					rm->addSprite(s);
					interactables[i] = s;

					//set the position to match the position of this tile
					tieSpriteToBottom(interactables[i]);
					return true;
				}
			}
			return false;
		}
	};
	//function for removing sprite
	inline void removeSprite(ResourceManager* rm, suint i, SpriteType type, bool deleteSprite) {
		switch (type) {
		case SPRITETYPE_OCCUPANT:
			//bounds checking
			if (i < 0 || i >= MAX_TILE_OCCUPANTS) return;
			//delete the sprite from the game if necessary
			if (deleteSprite) {
				rm->removeSprite(occupants[i]->getIndex());
			}
			occupants[i] = NULL;
			break;
		case SPRITETYPE_DECOR:
			//bounds checking
			if (i < 0 || i >= MAX_TILE_OCCUPANTS) return;
			//delete the sprite from the game if necessary
			if (deleteSprite) {
				rm->removeSprite(decor[i]->getIndex());
			}
			decor[i] = NULL;
			break;
		case SPRITETYPE_INTERACTABLE:
			//bounds checking
			if (i < 0 || i >= MAX_TILE_OCCUPANTS) return;
			//delete the sprite from the game if necessary
			if (deleteSprite) {
				rm->removeSprite(interactables[i]->getIndex());
			}
			interactables[i] = NULL;
			break;
		}
	};

	//getters
	inline sf::Vector2f getWorldPos() { return worldpos; };
	inline GameSprite* getOccupantAt(int i) {
		if (i < 0 || i > MAX_TILE_OCCUPANTS) {
			Logger::logError("Tile", "getSpriteAt out of bounds");
			return NULL;
		}
		return occupants[i];
	};
	inline GameSprite* getDecorAt(int i) {
		if (i < 0 || i > MAX_TILE_OCCUPANTS) {
			Logger::logError("Tile", "getSpriteAt out of bounds");
			return NULL;
		}
		return decor[i];
	};
	inline GameSprite* getInteractableAt(int i) {
		if (i < 0 || i > MAX_TILE_OCCUPANTS) {
			Logger::logError("Tile", "getSpriteAt out of bounds");
			return NULL;
		}
		return interactables[i];
	};
	//inline bool hasRoof() { if(roof == NULL) return true; else return false; };
	inline Tile* getRoof() { return roof; };
	inline Terrain getTerrain() { return terrain; };
	inline TerrainGraphic getFloorTex() { return floorTex; };
	//setters
	inline void setWorldPos(sf::Vector2f val) { worldpos = val; };
	inline void setRoof(Tile* val) { delete roof; roof = val; };
	inline void setTerrain(Terrain val) { terrain = val; };
	inline void setFloorTex(TerrainGraphic val) { floorTex = val; };

protected:
	//position in the world
	sf::Vector2f worldpos;
	ResourceManager* rm;
	//list of decoration sprites/objects on the tile
	GameSprite* decor[MAX_TILE_OCCUPANTS];
	//list of interactive/item sprites/objects on the tile
	GameSprite* interactables[MAX_TILE_OCCUPANTS];
	//list of sprites inside of it
	CharacterGameSprite* occupants[MAX_TILE_OCCUPANTS];
	//if tile has a walkable roof
	Tile* roof;
	//terrain info
	Terrain terrain;
	TerrainGraphic floorTex;

	//auxillary function to set the position of a sprite to the bottom of the tile
	void tieSpriteToBottom(GameSprite* s);
};