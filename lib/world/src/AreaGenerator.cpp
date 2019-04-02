#include "AreaGenerator.h"

Area AreaGenerator::getArea(std::string filePath, CharacterManager& characterManager){
    json jsonArea;
    jsonArea = jsonParser.processJSON(filePath);

    Area area{};
    area.setName(jsonArea["AREA"]["name"]);

    auto rooms = jsonArea["ROOMS"];
    auto allNPC = jsonArea["NPCS"];
    auto objects = jsonArea["OBJECTS"];

    generateRooms(rooms, area);
    generateNPC(allNPC, area, characterManager);
    generateObjects(objects, area);

    // For Testing 
    // auto areaRooms = area.getRoomList();
    // for(auto elm: areaRooms){
    //     auto room = elm.second;

    //     auto exits = room.getExits();
    //     auto NPCs = room.getNPCs();

    //     std::cout<< "\n *** ROOM " +room.getName()+ " *** \n ";
    //     std::cout<< room.getDescription() << "\n";
        
    //     std::cout<< "\n *** EXITS *** \n ";
    //     for(auto tmpExit : exits){
    //         std::cout<< tmpExit.getExitName() << "\n";
    //         std::cout<< tmpExit.getExitDescription() << "\n";
    //     }
    //     std::cout<< "\n *** ALL NPCS *** \n ";
    //     for(auto NPC_name : NPCs){
    //         std::cout<< NPC_name << "\n";
    //     }

    // }
    return area;
}

void AreaGenerator::generateRooms(json rooms, Area& area){
    int count = 0;
    int lastRoomID = 0;
    for (auto room: rooms) {

        Room roomObj{};
        std::string roomDesc = jsonParser.json2string(room["desc"]);
        roomObj.setRoomID(room["id"]);
        roomObj.setName(room["name"]);
        roomObj.setDescription(roomDesc);
        
        
        // roomsMap[roomID] -> pair<AreaName, RoomName>
        roomsMap.insert(std::pair(roomObj.getRoomID(), std::pair(area.getName(), roomObj.getName())));

        //keep track the first room to spawn character
        //idk how to access the element using index LOL

        if(count == 0) {
            area.setFirstRoomInArea(room["id"]);
            count ++;
        }
        
        int index = 0;
        for(auto tmpExit : room["doors"]){

            std::string exitDesc = jsonParser.json2string(tmpExit["desc"]);
            auto creatExit = roomObj.createExit(("exit to:" + std::to_string(index)), exitDesc, jsonParser.removeQuotes(tmpExit["dir"].dump()), area.getName(), tmpExit["to"]);
            index++;
        }
        area.addRoom(roomObj);
        lastRoomID = room["id"];
    }
    // generateExitsTo(area);
    area.setNextRoomID(lastRoomID);
    // Updating the Exit Names to the corresponding room they lead to
}

void AreaGenerator::generateNPC(json allNPC, Area& area, CharacterManager& characterManager){

    //vector of room ids
    auto roomIds = area.getRoomIdList();
    int index = 0;
    for(auto NPC: allNPC){
        //std::cout << NPC["id"] << "\n";
        std::vector<std::string> keywords = jsonParser.json2Vector(NPC["keywords"]);
        std::string shortDesc = NPC["shortdesc"];
        std::string longDesc = jsonParser.json2string(NPC["longdesc"]);
        std::string description = jsonParser.json2string(NPC["description"]);
        
        Character characterNPC{shortDesc};
        characterNPC.setShortdesc(shortDesc);
        characterNPC.setLongdesc(longDesc);
        characterNPC.setDescription(description);
       
        characterManager.addNPC(characterNPC);

        // need to check for out of bound
        if(area.addNPCtoRooms(shortDesc, roomIds[index])){
            index++;
        } else{
            index = 0;
        }
    }
}

void AreaGenerator::generateObjects(json objects, Area& area){
    
    for(auto object : objects){

        //std::cout << object["id"] << "\n";
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

void AreaGenerator::generateExitsTo(Area& area){
    for (auto& room : area.getRoomList()){
        for(auto& ext : room.second.getExits()) {
            auto exitLocation = ext.getTargetLocation();
            auto nextRoom = area.getRoom(exitLocation.room);
            std::string exitTo = "exit to: " + nextRoom.getName();
            ext.setExitTargetLocation(exitTo);
        }
    }
}

Area AreaGenerator::generateExits(Area area){
    for(auto& room :area.getRoomList()){
        for(auto& ext: room.second.getExits()){

            auto exitID = ext.getTargetLocation().room;
            ext.getTargetLocation().area = roomsMap[exitID].first;
            std::string exitName = "exit to, Area: " + roomsMap[exitID].first + " Room: " + roomsMap[exitID].second; 
            // area.updateRoomExits(exitID,exitName);
            ext.setExitTargetLocation(exitName);
            ext.setExitName(exitName);
            // std::cout<<exitName << " \n";
        }
    }
    return area;
}
