#include "Game.h"

Game::Game(Engine* e, GameConfig config) {
    this->e = e;
    mode = MENU;
    world = new World(config.worldParams);
}

Game::~Game() {
    delete world;
}

void Game::run() {
    while(true) {
        //input response
        EngineResponse r = e->run();

        switch(r.responseCode) {

        }
    }
}