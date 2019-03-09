#include "AreaGenerator.h"

Area AreaGenerator::getArea(std::string filePath){
    json jsonArea;
    jsonArea = jsonParser.processJSON("../adventure2019/data/mirkwood.json");

    Area area{};
    area.setName(jsonArea["AREA"]["name"]);

    auto rooms = jsonArea["ROOMS"];
    for (auto room: rooms) {

        Room roomObj{};
        std::string roomDesc;
        roomObj.setRoomID(room["id"]);
        roomObj.setName(room["name"]);
        for(auto line : room["desc"]){
            roomDesc += (line.dump() + "\n");
        }
        roomObj.setDescription(roomDesc);
        area.addRoom(roomObj);

        // TODO doors / exits
    }
    auto areaRooms = area.getRooms();
    for(auto room: areaRooms){
        std::cout<<room.getName() << "\n";
        std::cout<<room.getDescription() << "\n\n";
    }

    return Area{};
}
