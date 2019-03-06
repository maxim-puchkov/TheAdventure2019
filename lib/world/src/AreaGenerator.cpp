#include "AreaGenerator.h"

Area AreaGenerator::getArea(std::string filePath){
    json area;
    area = jsonParser.processJSON("mirkwood.json");
    std::cout << area["AREA"] ;
    std::cout << "BITCH\n\n\n" ;


    for (json::iterator it = area.begin(); it != area.end(); ++it) {
    std::cout << it.key() << "\n";
    }
    return Area{};
}
