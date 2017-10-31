#include "ResourceManager.h"

ResourceManager::ResourceManager() {
	loadFonts();
	loadTerrain();

	//initialise renderer's shiznaz to NULL to indicate free space
	scene = new sf::Drawable*[MAX_ELEMS];
	hud = new sf::Drawable*[MAX_ELEMS];
	for (int i = 0; i < MAX_ELEMS; i++) {
		scene[i] = NULL;
		hud[i] = NULL;
	}

	//init animators to NULL
	animations = new Animator*[MAX_ANIMATORS];
	for (int i = 0; i < MAX_ANIMATORS; i++) {
		animations[i] = NULL;
	}
	sprites = new GameSprite*[MAX_ELEMS];
	for (int i = 0; i < MAX_ELEMS; i++) {
		sprites[i] = NULL;
	}
}

ResourceManager::~ResourceManager() {
	delete[] scene;
	delete[] hud;
	delete[] animations;
	delete[] sprites;

	for (int i = 0; i < NUM_FONTS; i++) {
		delete fonts[i];
	}
	for (int i = 0; i < MAX_ACTIVE_TERRAINS; i++) {
		delete terrain[i];
	}
}

void ResourceManager::clearAll() {
	clearScene();
	clearHud();
	clearSprites();
}

void ResourceManager::clearScene() {
	for (int i = 0; i < MAX_ELEMS; i++) {
		delete scene[i];
		scene[i] = NULL;
	}
}

void ResourceManager::clearHud() {
	for (int i = 0; i < MAX_ELEMS; i++) {
		delete hud[i];
		hud[i] = NULL;
	}
}

void ResourceManager::clearSprites() {
	for (int i = 0; i < MAX_ELEMS; i++) {
		delete sprites[i];
		sprites[i] = NULL;
	}
}

int ResourceManager::addAudioSource(string fileLocation) {
	for (int i = 0; i < MAX_SOURCES; i++) {
		if (sources[i]->getId() == -1) {
			sources[i]->loadFromFile(i, fileLocation);
		}
		return i;
	}
	return -1;
}

void ResourceManager::removeAudioSource(int id) {
	if (id >= MAX_SOURCES || id < 0) {
		throw std::out_of_range("out of bounds for sources array");
	}
	sources[id]->clear();
}

void ResourceManager::loadFonts() {
	sf::Font* font = new sf::Font;
	//TODO: read in from config file
	if (!font->loadFromFile("../../assets/fonts/Abel-Regular.ttf")) {
		std::cout << "ERROR reading in fonts type!" << std::endl;
	}

	fonts[FONT_ABEL_REGULAR] = font;
}

//TODO: read this all from config
void ResourceManager::loadTerrain() {
	terrain[FLOOR_CARPET] = new sf::Texture();
	terrain[FLOOR_CARPET]->loadFromFile("../../assets/sprites/geography/carpet.png");
	terrain[FLOOR_CONCRETE] = new sf::Texture();
	terrain[FLOOR_CONCRETE]->loadFromFile("../../assets/sprites/geography/concrete.png");
	terrain[FLOOR_DIRT] = new sf::Texture();
	terrain[FLOOR_DIRT]->loadFromFile("../../assets/sprites/geography/dirt.png");
	terrain[FLOOR_FRESHWATER] = new sf::Texture();
	terrain[FLOOR_FRESHWATER]->loadFromFile("../../assets/sprites/geography/freshwater.png");
	terrain[FLOOR_GRASS] = new sf::Texture();
	terrain[FLOOR_GRASS]->loadFromFile("../../assets/sprites/geography/grass.png");
	terrain[FLOOR_ROOFING_FLAT] = new sf::Texture();
	terrain[FLOOR_ROOFING_FLAT]->loadFromFile("../../assets/sprites/geography/roofing_flat.png");
	terrain[FLOOR_ROOFING_PRECARIOUS] = new sf::Texture();
	terrain[FLOOR_ROOFING_PRECARIOUS]->loadFromFile("../../assets/sprites/geography/roofing_precarious.png");
	terrain[FLOOR_SALTWATER] = new sf::Texture();
	terrain[FLOOR_SALTWATER]->loadFromFile("../../assets/sprites/geography/saltwater.png");
	terrain[FLOOR_SAND] = new sf::Texture();
	terrain[FLOOR_SAND]->loadFromFile("../../assets/sprites/geography/sand.png");
	terrain[FLOOR_WOOD] = new sf::Texture();
	terrain[FLOOR_WOOD]->loadFromFile("../../assets/sprites/geography/wood.png");
}

int ResourceManager::addAnimator(Animator* resource) {
	//find an empty slot for the animator
	for (int i = 0; i < MAX_ANIMATORS; i++) {
		if (animations[i] == NULL) {
			//put it in this slot and store the location
			animations[i] = resource;
			resource->id = i;
			resource->startTime = clock();
			return i;
		}
	}
	return -1;
}

void ResourceManager::removeAnimator(uint id) {
	//bounds checking
	if(id >= MAX_ANIMATORS) return;
	
	//NOTE: AnimationManager will delete the animators
	animations[id] = NULL;
}