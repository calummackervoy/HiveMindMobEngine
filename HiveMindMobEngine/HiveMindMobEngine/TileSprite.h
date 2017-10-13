#pragma once
#include <SFML\Graphics.hpp>

class TileSprite : public sf::Sprite
{
public:
	TileSprite(bool useLighting = true, sf::Vector2f worldPos = sf::Vector2f(0.0f,0.0f), int z = 0);
	~TileSprite();

	void setWorldPosition(float x, float y);
	void setWorldPosition(const sf::Vector2f &position);
	sf::Vector2f getWorldPosition() const;

	void setWorldZ(int z);
	int getWorldZ() { return z; }

	void setUseLighting(bool use) { lighting = use; }
	bool getUseLighting() { return lighting; }
	
protected:
	sf::Vector2f worldpos;
	int z;
	bool lighting;

	//functions for converting between world space co-ords and view space co-ords
	// ScreenX = 2*WorldX - 2*WorldY
	// ScreenY = WorldX + WorldY
	inline sf::Vector2f worldToScreen(sf::Vector2f v) {
		return sf::Vector2f(2.0f*v.x - 2.0f*v.y, v.x + v.y);
	}

	// WorldX = (ScreenX + 2*ScreenY)/4
	// WorldY = (2*ScreenY - ScreenX)/4
	inline sf::Vector2f screenToWorld(sf::Vector2f v) {
		return sf::Vector2f((v.x + 2.0f*v.y) / 4.0f, (2.0f*v.y - v.x) / 4.0f);
	}
};