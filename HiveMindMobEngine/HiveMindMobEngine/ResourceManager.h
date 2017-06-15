#pragma once
#include "RendererConfig.h"

class ResourceManager {
public:
	ResourceManager();
	~ResourceManager();

	inline Element* getSceneElem(int i) {
		//bounds checking
		if (i < 0 || i > MAX_ELEMS) throw std::exception("Index out of bounds");
		return scene[i];
	};
	inline int addSceneElem(Element* e);
	inline void removeSceneElem(int i);

	inline Element* getHudElem(int i) {
		//bounds checking
		if (i < 0 || i > MAX_ELEMS) throw std::exception("Index out of bounds");
		return hud[i];
	}
	inline int addHudElem(Element* e);
	inline void removeHudElem(int i);

	void clearScene();

private:
	//renderer's array of scene entities
	Element** scene;
	//renderer's array of HUD entities (the overlay)
	Element** hud;
};