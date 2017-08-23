#pragma once
#include "SpriteManager.h"
#include "AnimationManager.h"
#include "Emotion.h"

//Author: Calum Mackervoy
//Purpose: Sprite-management for character sprites

//TODO: speech animation/indication
//TODO: animation management

//defines the different animations available to a character
enum CharacterAnimations : uint8_t {
    WALK,
    JOG,
    RUN
};

class CharacterSpriteManager : SpriteManager {
public:
    CharacterSpriteManager(sf::Sprite* model = NULL, sf::Texture* tex = NULL, managerType type = MANAGER_CHARACTER,
		suint opaque = 100, suint depth = 0);
    ~CharacterSpriteManager();

    //TODO: method to assign random clothing based on params

    //overrides
    //TODO: must move all clothing etc along in correct positions
    void override setPosition(sf::Vector2f pos);

    inline Emotion getExpression() {return expression;};
    inline Element* getHat() {return hat;};
    inline Element* getClothing() {return clothing;};

    inline void setExpression(Emotion val) {expression = val;};
    inline void setHat(Element* hat) {this->hat = hat;};
    inline void setClothing(Element* clothing) {this->clothing = clothing;};

protected:
    AnimationManager* am;
    Element* hat;
    Element* clothing;
    Emotion expression;
};