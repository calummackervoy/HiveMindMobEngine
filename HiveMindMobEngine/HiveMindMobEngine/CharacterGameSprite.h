#pragma once
#include "GameSprite.h"
#include "Emotion.h"

//Author: Calum Mackervoy
//Purpose: Expansion of GameSprite for characters- e.g. manages clothing & animation

//defines the different animations available to a character
enum CharacterAnimations : uint8_t {
	WALK,
	JOG,
	RUN
};

class CharacterGameSprite : public GameSprite {
public:
	CharacterGameSprite(sf::Texture* tex, suint z = 0, sf::Vector2f worldPos = sf::Vector2f(0.0f, 0.0f));
	~CharacterGameSprite();

	//Overriden to maintain consistensy of character graphic's clothes etc
	void setWorldPosition(float x, float y) override;
	void setWorldPosition(const sf::Vector2f &position) override;

	inline Emotion getExpression() { return expression; };
	inline void setExpression(Emotion val) { expression = val; };

protected:
	//TODO: clothing etc
	Emotion expression;
};