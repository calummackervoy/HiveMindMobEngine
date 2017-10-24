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

	//function to draw a character & it's clothing attachments
	void draw(sf::RenderWindow* win);

	//clothing getters and setters TODO: make inline?
	GameSprite* getHat() { return hat; };
	GameSprite* getTop() { return top; };
	GameSprite* getBottom() { return bottom; };
	void setClothing(GameSprite* hat, GameSprite* top, GameSprite* bottom) {
		this->hat = hat;
		this->top = top;
		this->bottom = bottom;
	};
	void setHat(GameSprite* val) { hat = val; };
	void setTop(GameSprite* val) { top = val; };
	void setBottom(GameSprite* val) { bottom = val; };

	inline Emotion getExpression() { return expression; };
	inline void setExpression(Emotion val) { expression = val; };

protected:
	//clothing sprites
	GameSprite* hat;
	GameSprite* top;
	GameSprite* bottom;

	Emotion expression;
};