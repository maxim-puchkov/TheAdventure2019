#include "AreaGenerator.h"

Area AreaGenerator::getArea(std::string filePath){
    json jsonArea;
    jsonArea = jsonParser.processJSON("../adventure2019/data/mirkwood.json");

    Area area{};
    area.setName(jsonArea["AREA"]["name"]);

    auto rooms = jsonArea["ROOMS"];
    auto allNPC = jsonArea["NPCS"];
    auto objects = jsonArea["OBJECTS"];

    generateRooms(rooms, area);
    generateNPC(allNPC);
    generateObjects(objects, area);

    return Area{};
}

void AreaGenerator::generateRooms(json rooms, Area& area){
    for (auto room: rooms) {

        Room roomObj{};
        std::string roomDesc = jsonParser.json2string(room["desc"]);
        roomObj.setRoomID(room["id"]);
        roomObj.setName(room["name"]);
        roomObj.setDescription(roomDesc);

        int count = 0;
        for(auto tmpExit : room["doors"]){

            std::string exitDesc = jsonParser.json2string(tmpExit["desc"]);
            auto creatExit = roomObj.createExit(("exit " + std::to_string(count)), exitDesc, jsonParser.removeQuotes(tmpExit["dir"].dump()), 0, 0);
            count++;
        }
        area.addRoom(roomObj);
    }

    // For Testing 
    // auto areaRooms = area.getRooms();
    // for(auto room: areaRooms){

    //     auto exits = room.getExits();
    //     std::cout<< room.getName() << "\n";
    //     std::cout<< room.getDescription() << "\n";

    //     for(auto tmpExit : exits){
    //         std::cout<< tmpExit.getExitName() << "\n";
    //         std::cout<< tmpExit.getExitDescription() << "\n";
    //     }

    // }
}

void AreaGenerator::generateNPC(json allNPC){

    for(auto NPC: allNPC){

        std::cout << NPC["id"] << "\n";
        std::vector<std::string> keywords = jsonParser.json2Vector(NPC["keywords"]);
        std::string shortDesc = NPC["shortdesc"];
        std::string longDesc = jsonParser.json2string(NPC["longdesc"]);
        std::string description = jsonParser.json2string(NPC["description"]);

        // For Testing
        // for(auto word : keywords){
        //     std::cout << word + "\n";
        // }
        // std::cout << shortDesc << "\n";
        // std::cout << longDesc << "\n";
        // std::cout << description << "\n";
    }
}

void AreaGenerator::generateObjects(json objects, Area& area){
    
    for(auto object : objects){

        std::cout << object["id"] << "\n";
        std::vector<std::string> keywords = jsonParser.json2Vector(object["keywords"]);
        std::string shortDesc = object["shortdesc"];
        std::string longDesc = jsonParser.json2string(object["longdesc"]);
        
        std::vector<std::string> extra_keywords = jsonParser.json2Vector(object["extra"][0]);
        std::string extra_desc = jsonParser.json2string(object["extra"][1]);

        // For Testing
        // for(auto word : keywords){
        //     std::cout << word + "\n";
        // }
        // std::cout << shortDesc << "\n";
        // std::cout << longDesc << "\n";

        // for(auto word : extra_keywords){
        //     std::cout << word + "\n";
        // }
        // std::cout << extra_desc << "\n";

    }
}