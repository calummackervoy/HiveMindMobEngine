#pragma once
#include "Typedef.h"
#include "RendererConfig.h"

//Author: Calum Mackervoy
//Purpose: Expanding SFML's sprite class for use in the game

//enum for referencing different types of GameSprite
enum GameSpriteType : uint8_t {
	GAMESPRITE_BASE,
	GAMESPRITE_CHARACTER
};

class GameSprite : public sf::Sprite
{
public:
	GameSprite(sf::Texture* tex, suint z = 0, sf::Vector2f worldPos = sf::Vector2f(0.0f, 0.0f),
		GameSpriteType type = GAMESPRITE_BASE);
	~GameSprite();

	virtual void setWorldPosition(float x, float y);
	virtual void setWorldPosition(const sf::Vector2f &position);
	inline sf::Vector2f getWorldPosition() const { return worldpos; };

	void setWorldZ(int z);
	int getWorldZ() { return z; };

	inline void setIndex(suint i) { id = i; };
	inline suint getIndex() { return id; };

	inline GameSpriteType getType() { return type; };

protected:
	sf::Vector2f worldpos;
	suint z;
	suint id; //tracking index in ResourceManager
	GameSpriteType type;
};