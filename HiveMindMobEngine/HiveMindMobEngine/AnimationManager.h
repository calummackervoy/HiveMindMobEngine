#include "Animator.h"
#include "Typedef.h"
#include "ResourceManager.h"

//Author: Calum Mackervoy
//Purpose: Manages a suite of animators and calls the correct one of certain triggers

const suint MAX_ANIMATIONS_MANAGER = 16;

class AnimationManager {
public:
    AnimationManager(ResourceManager* rm, sint capacity = 8);
    ~AnimationManager();

    //accessing/adding/removing animators from animation's storage
	inline Animator* getAnimator(uint i) {
		//bounds checking
		if (i > MAX_ANIMATIONS_MANAGER) throw std::exception("Index out of bounds");
		return animations[i];
	};
	int addAnimator(Animator &resource);
	//void removeAnimator(uint id);

    inline int getActive() {return active;};
    inline void setActive(int val);

protected:
    Animator** animations;
    ResourceManager* rm;
    sint active;
    sint capacity;
};