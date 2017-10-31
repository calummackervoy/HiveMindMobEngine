/*#pragma once
#include <algorithm>
#include "Renderer.h"
#include "FileHandler.h"
#include "Clothing.h"
#include "rand.h"

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
    Wardrobe(Renderer* r, FileHandler* file, std::string hatsLocation, std::string clothingLocation);
    ~Wardrobe();

    //select a random hat/clothing from params
    HatClothingPair getRandom(bool hat = true, CharacterClass charClass = MALE_AVERAGE,
        ClothingStyle style = CLOTHING_EVERYDAY);

	inline Element* getHatAt(int i) {
		if (i < 0 || i > MAX_CLOTHING) return NULL;
		return convertToElement(hats[i]);
	}

	inline Element* getClothingAt(int i) {
		if (i < 0 || i > MAX_CLOTHING) return NULL;
		return convertToElement(clothes[i]);
	}

private:
    Renderer* r;
	FileHandler* file;
    HatClothing** hats;
    HatClothing** clothes;

    //turn a HatClothing struct into an Element
    Element* convertToElement(HatClothing* hc);

	//method for reading in a Wardrobe config file
	void readWardrobe(bool hats, std::string configLocation);
};*/