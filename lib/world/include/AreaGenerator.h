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
    
  public:
    Area getArea(std::string filepath);

};
#endif
