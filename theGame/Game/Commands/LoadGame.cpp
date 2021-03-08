//
// Created by vikto on 27.11.2020.
//

#include "LoadGame.h"

LoadGame::~LoadGame() {

}

void LoadGame::execute() {
    SaveAndLoad saveAndLoad(game_);
    saveAndLoad.load();
}
