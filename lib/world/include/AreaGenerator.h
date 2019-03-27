#ifndef AREAGEN_H
#define AREAGEN_H

#include "JsonParser.h"
#include "Area.h"

#include <unordered_map>
#include <string>
#include <iostream> 
#include <fstream>
#include "CharacterManager.h"

using charactermanager::CharacterManager;

class AreaGenerator {

  private:
    JsonParser jsonParser;
    CharacterManager characterManager;

    void generateRooms(json rooms, Area& area);
    void generateNPC(json allNPC, Area& area, CharacterManager& characterManager);
    void generateObjects(json rooms, Area& area);

  public:
    Area getArea(std::string filepath, CharacterManager&);
};
#endif
