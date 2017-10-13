#pragma once
#include <SFML\Graphics.hpp>

class TileSprite : public sf::Sprite
{
public:
	TileSprite();
	TileSprite(const sf::Image &image, const sf::Vector2f &position = sf::Vector2f(0, 0),
		const sf::Vector2f &scale = sf::Vector2f(1, 1), float rotation = 0.f, const sf::Color &color = sf::Color(255, 255, 255, 255));
	~TileSprite();

	void SetWorldPosition(float x, float y);
	void SetWorldPosition(const sf::Vector2f &position);
	sf::Vector2f GetWorldPosition() const;

	void SetWorldZ(float z);
	float GetWorldZ() { return m_z; }

	void setUseLighting(bool use) { m_uselighting = use; }
	bool getUseLighting() { return m_uselighting; }

protected:
	sf::Vector2f m_worldpos;
	float m_z;
	bool m_uselighting;
};