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
    std::string removeQuotes(std::string str);
    std::string json2string(json j);

    
  public:
    Area getArea(std::string filepath);

};
#endif
