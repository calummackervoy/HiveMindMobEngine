#pragma once
#include "Typedef.h"
#include "RendererConfig.h"

class GameSprite : public sf::Sprite
{
public:
	GameSprite(sf::Texture* tex, suint z = 0, sf::Vector2f worldPos = sf::Vector2f(0.0f, 0.0f));
	~GameSprite();

	void setWorldPosition(float x, float y);
	void setWorldPosition(const sf::Vector2f &position);
	inline sf::Vector2f getWorldPosition() const { return worldpos; };

	void setWorldZ(int z);
	int getWorldZ() { return z; };

	inline void setIndex(suint i) { id = i; };
	inline suint getIndex() { return id; };

protected:
	sf::Vector2f worldpos;
	suint z;
	suint id; //tracking index in ResourceManager
};