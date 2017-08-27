#pragma once
#include <SFML\Graphics.hpp>
#include <ctime>
#include "ResourceManager.h"

//Author: Calum Mackervoy
//Purpose: Manages animation

class Animation {
public:
	Animation(ResourceManager* rm);
	~Animation();

	//loops through animations & increments frames at correct moments
	void play();

private:
	ResourceManager* rm;

	//function to progress an animator to its next frame
	void nextFrame(Animator* a);
};
