#ifndef AREAGEN_H
#define AREAGEN_H

#include "JsonParser.h"
#include "Area.h"

#include <unordered_map>
#include <string>
#include <iostream> 
#include <fstream>
#include "CharacterManager.h"
#include "ItemController.h"
#include "Item.h"
#include "print.h"

using charactermanager::CharacterManager;

class AreaGenerator {

  private:
    JsonParser jsonParser;
    //Store the roomsMap[roomID] -> pair<AreaName, RoomName>
    std::unordered_map<int,std::pair<std::string,std::string>> roomsMap;
    Internationalization stringManager{};


    void generateRooms(json rooms, Area& area);
    void generateNPC(json allNPC, Area& area, CharacterManager& characterManager);
    void generateObjects(json rooms, Area& area, const items::ItemController<uint64_t>&,json resets);

    void generateExitsTo(Area& area);
    void reset_Area(json resetValues, Area& area, CharacterManager& characterManager);

  public:
    Area getArea(std::string filepath, CharacterManager&, const items::ItemController<uint64_t>&);
    Area generateExits(Area area);

};
#endif
