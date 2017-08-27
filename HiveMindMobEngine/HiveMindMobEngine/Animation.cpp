#include "Animation.h"

Animation::Animation(ResourceManager* rm) {
	this->rm = rm;
}

Animation::~Animation() {

}

void Animation::nextFrame(Animator* a) {
	if (a == NULL || a->target == NULL) throw std::exception("NULL pointer");
	//increment the current frame and wraparound if need be
	a->currentFrame++;
	if (a->frames[a->currentFrame] == NULL 
		|| a->currentFrame >= MAX_FRAMES) a->currentFrame = 0;

	//change the texture on the sprite to match the new frame
	a->target->setTexture(*(a->frames[a->currentFrame]));
}

void Animation::play() {
	//auto-play the next frames of animators set to do this
	for (int i = 0; i < MAX_ANIMATORS; i++) {
		Animator* a = rm->getAnimator(i);
		if (a == NULL) continue;
		if (a->play == true) {
			//figure out time since last clock cycle and add to accumulation
			double elapsed = double(clock() - a->startTime) / CLOCKS_PER_SEC;
			a->time = elapsed;

			//change frame after a certain number of loops
			if (a->time >= a->timeThreshold) {
				a->startTime = clock();
				nextFrame(a);
			}
		}
	}
}
