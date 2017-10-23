#pragma once
#include "Typedef.h"

//Author: Calum Mackervoy
//Purpose: Define clothing-related structs to be used in FileHandler & Wardrobe

//enum to represent the different sizes & shapes of sprite
//NOTE: clothing only applies to one of these classes
enum CharacterClass : uint8_t {
    MALE_AVERAGE,
    FEMALE_AVERAGE
};

//enum to represent different styles of clothing
enum ClothingStyle : uint8_t {
    CLOTHING_EVERYDAY,
    CLOTHING_UNDERWEAR,
    CLOTHING_WORKPLACE,
    CLOTHING_FORMAL,
    CLOTHING_MILITARY,
    CLOTHING_MILITARY_FORMAL,
    CLOTHING_POLICE,
    CLOTHING_MILITIA
};

struct HatClothing {
    std::string textureLocation = "";
    suint id = 0; //TODO: this is as-yet unused
    CharacterClass charClass = MALE_AVERAGE;
    ClothingStyle style = CLOTHING_EVERYDAY;
};