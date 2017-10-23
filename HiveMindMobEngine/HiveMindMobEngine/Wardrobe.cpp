#include "Wardrobe.h"

Wardrobe::Wardrobe(Renderer* r, FileHandler* file, std::string hatsLocation, std::string clothingLocation) {
    this->r = r;
	this->file = file;
	hats = new HatClothing*[MAX_CLOTHING];
	clothes = new HatClothing*[MAX_CLOTHING];
	
	//initialise both to null
	for (int i = 0; i < MAX_CLOTHING; i++) {
		hats[i] = NULL;
		clothes[i] = NULL;
	}

    readWardrobe(true, hatsLocation);
	readWardrobe(false, clothingLocation);
}

Wardrobe::~Wardrobe() {
    delete[] hats;
    delete[] clothes;
}

HatClothingPair Wardrobe::getRandom(bool hat, CharacterClass charClass,
    ClothingStyle style) {
        //make a pool of all the items which match this description
        suint hatPool[MAX_CLOTHING];
        suint clothingPool[MAX_CLOTHING];
        suint hatCount = 0;
        suint clothingCount = 0;

        for(int i = 0; i < MAX_CLOTHING; i++) {
            if(hat) {
                if(hats[i] != NULL &&
					hats[i]->charClass == charClass &&
					hats[i]->style == style) {
                       hatPool[hatCount] = i;
                       hatCount++;
                }
            }
            if(clothes[i] != NULL &&
				clothes[i]->charClass == charClass &&
                    clothes[i]->style == style) {
                       clothingPool[clothingCount] = i;
                       clothingCount++;
            }
        }

		//check for empty hat/clothing
		if (hat && hatCount == 0) return {};
		if (clothingCount == 0) return {};

        //randomly choose a pair from the pools
        //recycling count as the selected from now
        if(hat) {
            hatCount = randInt(0, hatCount);
        }
        clothingCount = randInt(0, clothingCount);

        //construct Elements out of these and send
        HatClothingPair res;
        if(hat) res.hat = convertToElement(hats[hatCount]);
        res.clothing = convertToElement(clothes[clothingCount]);
        return res;
}

Element* Wardrobe::convertToElement(HatClothing* hc) {
    Element* e = new Element;
    e->model = new sf::Sprite();
    e->texture = r->getTexture(hc->textureLocation);
    ((sf::Sprite*)e->model)->setTexture(*e->texture);

    return e;
}

void Wardrobe::readWardrobe(bool hats, std::string configLocation) {
	file->openStream(configLocation);

	//obtain how many hats/clothes there are to read (& bounds check)
	int count = std::min(file->getNextInt(), (int)MAX_CLOTHING);

	std::string textureLocation = "";
	suint id = 0; //TODO: this is as-yet unused
	CharacterClass charClass = MALE_AVERAGE;
	ClothingStyle style = CLOTHING_EVERYDAY;

	for (int i = 0; i < count; i++) {
		//start building a new HatClothing object for the item
		HatClothing* hc = new HatClothing;

		//read in the details
		hc->textureLocation = file->getNextWord();
		//TODO: hc->charClass = (CharacterClass)file->getNextInt();
		//TODO: hc->style = (ClothingStyle)file->getNextInt();

		if (hats) this->hats[i] = hc;
		else clothes[i] = hc;
	}

	file->closeStream();
}