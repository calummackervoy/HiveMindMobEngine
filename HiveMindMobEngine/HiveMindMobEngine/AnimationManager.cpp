#include "AnimationManager.h"

AnimationManager::AnimationManager(ResourceManager* rm, sint capacity) {
    this->rm = rm;
    this->capacity = capacity;
    active = -1;

    animations = new Animator*[capacity];
    for(int i = 0; i < capacity; i++) {
        animations[i] = NULL;
    }
}

AnimationManager::~AnimationManager() {
    delete[] animations;
}

int AnimationManager::addAnimator(Animator &resource) {
    //find an empty slot for the animator
	for (int i = 0; i < capacity; i++) {
		if (animations[i] == NULL) {
			//put it in this slot and store the location
			animations[i] = new Animator(resource);
			resource->id = i;
			return i;
		}
	}
	return -1;
}

void AnimationManager::setActive(int val) {
    //bounds checking
    if(val > capacity) return;
    
    //remove the current active animator from RM (if there is one)
    if(active > 0) {
        rm->removeAnimator(animations[active]->id);
    }

    //set a new active
    active = val;

    //if appropriate add animator to RM
    if(active > 0) {
        animations[active]->startTime = clock();
        rm->addAnimator(animations[active]);
    }
    else {
        //TODO: reset model to standing?
    }
}