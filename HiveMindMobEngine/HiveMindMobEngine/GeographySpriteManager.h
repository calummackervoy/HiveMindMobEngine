#pragma once
#include "SpriteManager.h"

//Author: Calum Mackervoy
//Purpose: Manages sprites for geographical items, buildings etc

class GeographySpriteManager : SpriteManager {
public:
    //overrides
    void override setPosition(sf::Vector2f pos);
private:

};