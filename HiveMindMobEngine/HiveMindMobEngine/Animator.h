#pragma once
#include <ctime>
#include "RendererConfig.h"

//max animations happening concurrently
const int MAX_ANIMATORS = 8;
//max frames for a single animation
const int MAX_FRAMES = 12;

//holds all information associated with animation
struct Animator {
	int id; //stores index in the animations array
	int currentFrame = 0; //default at first frame
						  //keep track of time the frame started
						  //needed to know when to change frames
	clock_t startTime;
	double time = 0; //elapsed time
	double timeThreshold = 1.0; //seconds each frame lasts
	sf::Sprite* target; //the sprite the animation is being carried out on
						//each frame of animation pre-loaded as a texture
	sf::Texture* frames[MAX_FRAMES] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
	//autoplay? if false animate on trigger
	bool play = false;
};
