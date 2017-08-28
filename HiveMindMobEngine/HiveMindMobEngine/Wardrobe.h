#pragma once
#include "Renderer.h"
#include "FileHandler.h"
#include "Clothing.h"
#include "Rand.h"

//Author: Calum Mackervoy
//Purpose: Manages clothing ranges & fetches em for other classes

const suint MAX_CLOTHING = 8;

//TODO: switch with std::pair?
struct HatClothingPair {
    Element* hat = NULL;
    Element* clothing = NULL;
};

class Wardrobe {
public:
    Wardrobe(Renderer* r, string hatsLocation, string clothingLocation);
    ~Wardrobe();

    //select a random hat/clothing from params
    HatClothingPair getRandom(bool hat = true, CharacterClass charClass = MALE_AVERAGE,
        ClothingStyle style = CLOTHING_EVERYDAY);

private:
    Renderer* r;
    HatClothing* hats[MAX_CLOTHING];
    HatClothing* clothes[MAX_CLOTHING];

    //turn a HatClothing struct into an Element
    Element* convertToElement(HatClothing &hc);
};