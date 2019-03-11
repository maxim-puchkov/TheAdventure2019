#include "AreaGenerator.h"

Area AreaGenerator::getArea(std::string filePath){
    json jsonArea;
    jsonArea = jsonParser.processJSON("../adventure2019/data/mirkwood.json");

    Area area{};
    area.setName(jsonArea["AREA"]["name"]);

    auto rooms = jsonArea["ROOMS"];
    generateRooms(rooms, area);


    return Area{};
}

std::string AreaGenerator::removeQuotes( std::string str){
    return str.substr(1, str.size() - 2);
}

std::string AreaGenerator::json2string(json j){
    std::string retStr;
    for(auto elm : j){
        retStr += (elm.dump() + "\n");
    }
    return retStr;
}

void AreaGenerator::generateRooms(json rooms, Area& area){
    for (auto room: rooms) {

        Room roomObj{};
        std::string roomDesc = json2string(room["desc"]);
        roomObj.setRoomID(room["id"]);
        roomObj.setName(room["name"]);
        roomObj.setDescription(roomDesc);

        int count = 0;
        for(auto tmpExit : room["doors"]){

            std::string exitDesc = json2string(tmpExit["desc"]);
            auto creatExit = roomObj.createExit(("exit " + std::to_string(count)), exitDesc, removeQuotes(tmpExit["dir"].dump()), 0, 0);
            count++;
        }
        area.addRoom(roomObj);
    }

    // For Testing 
    auto areaRooms = area.getRooms();
    for(auto room: areaRooms){

        auto exits = room.getExits();
        std::cout<< room.getName() << "\n";
        // std::cout<< room.getDescription() << "\n";

        for(auto tmpExit : exits){
            std::cout<< tmpExit.getExitName() << "\n";
            std::cout<< tmpExit.getExitDescription() << "\n";
        }

    }
}