#include "Wardrobe.h"

Wardrobe::Wardrobe(Renderer* r, string hatsLocation, string clothingLocation) {
    this->r = r;
    hats = FileHandler::readWardrobe(hatsLocation);
    clothes = FileHandler::readWardrobe(clothingLocation);
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
                if(hats[i]->charClass == charClass &&
                    hats[i]->style == style) {
                        hatPool[hatCount] = i;
                        hatCount++;
                }
            }
            if(clothes[i]->charClass == charClass &&
                    clothes[i]->style == style) {
                        clothingPool[clothingCount] = i;
                        clothingCount++;
            }
        }

        //randomly choose a pair from the pools
        //recycling count as the selected from now
        if(hat) {
            hatCount = Rand::randInt(0, hatCount);
        }
        clothingCount = Rand::randInt(0, clothingCount);

        //construct Elements out of these and send
        HatClothingPair res;
        if(hat) res.hat = convertToElement(hats[hatCount]);
        res.clothing = convertToElement(clothes[clothingCount]);
        return res;
}

Element* Wardrobe::convertToElement(HatClothing &hc) {
    Element* e = new Element;
    e->model = new sf::Sprite();
    e->texture = r->getTexture(hc.textureLocation);
    e->model->setTexture(*e->texture);

    return e;
}