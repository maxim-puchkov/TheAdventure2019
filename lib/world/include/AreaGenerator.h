#ifndef AREAGEN_H
#define AREAGEN_H

#include "JsonParser.h"
#include "Area.h"

#include <unordered_map>
#include <string>
#include <iostream> 
#include <fstream>


class AreaGenerator {

  private:
    JsonParser jsonParser;

    void generateRooms(json rooms, Area& area);
    void generateNPC(json allNPC, Area& area);
    void generateObjects(json rooms, Area& area);

  public:
    Area getArea(std::string filepath);

};
#endif
