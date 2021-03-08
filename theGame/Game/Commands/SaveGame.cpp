//
// Created by vikto on 27.11.2020.
//

#include "SaveGame.h"

SaveGame::~SaveGame() {

}

void SaveGame::execute() {
    SaveAndLoad saveAndLoad(game_);
    saveAndLoad.save();
}
