#include "AreaGenerator.h"

Area AreaGenerator::getArea(std::string filePath, CharacterManager& characterManager, const items::ItemController<uint64_t>& worldItems){
    json jsonArea;
    jsonArea = jsonParser.processJSON(filePath);

    Area area{};
    area.setName(jsonArea["AREA"]["name"]);

    auto rooms = jsonArea["ROOMS"];
    auto allNPC = jsonArea["NPCS"];
    auto objects = jsonArea["OBJECTS"];
    auto resets = jsonArea["RESETS"];

    generateRooms(rooms, area);
    generateNPC(allNPC, area, characterManager);
    generateObjects(objects, area, worldItems,resets);
    reset_Area(resets,area,characterManager);

    // For Testing 
    // auto areaRooms = area.getRoomList();
    // for(auto elm: areaRooms){
    //     auto room = elm.second;

    //     auto exits = room.getExits();
    //     auto NPCs = room.getNPCs();
    //     if(room.getName() == "A Guard Post"){

    //         std::cout<< "\n *** ROOM " +room.getName()+ " *** \n ";
    //         std::cout<< room.getDescription() << "\n";
            
    //         std::cout<< "\n *** EXITS *** \n ";
    //         for(auto tmpExit : exits){
    //             std::cout<< tmpExit.getExitName() << "\n";
    //             std::cout<< tmpExit.getExitDescription() << "\n";
    //         }
    //         std::cout<< "\n *** ALL NPCS *** \n ";
    //         for(auto NPC_name : NPCs){
    //             std::cout<< NPC_name << "\n";
    //         }
            
    //     }

    // }
    return area;
}

void AreaGenerator::generateRooms(json rooms, Area& area){
    int count = 0;
    int lastRoomID = 0;
    for (auto room: rooms) {

        Room roomObj{room["id"]};
        std::string roomDesc = jsonParser.json2string(room["desc"]);
        roomObj.setRoomID(room["id"]);
        roomObj.setName(room["name"]);
        roomObj.setDescription(roomDesc);
        
        // roomsMap[roomID] -> pair<AreaName, RoomName>
        roomsMap.insert(std::pair(roomObj.getRoomID(), std::pair(area.getName(), roomObj.getName())));

        if(count == 0) {
            area.setFirstRoomInArea(room["id"]);
            count ++;
        }
        
        for(auto tmpExit : room["doors"]){
            std::string exitDesc = jsonParser.json2string(tmpExit["desc"]);
        }

        for(auto keyword: room["extended_descriptions"][0]["keywords"]){
            roomObj.addExtendedKeyword(keyword);
        }
        roomObj.setExtended_desc(jsonParser.json2string(room["extended_descriptions"][0]["desc"]));
        
        area.addRoom(roomObj);
        lastRoomID = room["id"];
    }
    area.setNextRoomID(lastRoomID);
}

void AreaGenerator::generateNPC(json allNPC, Area& area, CharacterManager& characterManager){

    //vector of room ids
    auto roomIds = area.getRoomIdList();
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
        characterNPC.setID(NPC["id"]);
        characterNPC.setFirstTimeSetup(true);
       
        characterManager.addNPC(characterNPC);
    }
}

void AreaGenerator::generateObjects(json objects, Area& area, const items::ItemController<uint64_t>& worldItems,json resetValues){
    
    for(auto object : objects){

        //std::cout << object["id"] << "\n";
        std::vector<std::string> keywords = jsonParser.json2Vector(object["keywords"]);
        std::string shortDesc = object["shortdesc"];
        std::string longDesc = jsonParser.json2string(object["longdesc"]);
        
        std::string extra_keywords = jsonParser.json2string(object["extra"][0]);
        std::string extra_desc = jsonParser.json2string(object["extra"][1]);
        
        vector<items::Action> vec{items::Action(extra_keywords, extra_desc)};

        worldItems.builder.setItemProperties(items::Keywords(keywords), items::Description(longDesc), items::Actions(vec));

        for( auto val : resetValues){
            // std::cout << val.dump() << "\n";
            if(val["action"] == "object" && val["id"] == object["id"]){
                worldItems.create(val["room"], val["id"]);
                std::cout << val["room"] << " "<< val["id"];
                std::cout << " ITEM MADE \n";
            }
        }
        // world.items.print_contentsOf(val["room"]);
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

void AreaGenerator::reset_Area(json resetValues, Area& area, CharacterManager& characterManager){

    for( auto val : resetValues){
        // std::cout << val.dump() << "\n";
        if(val["action"] == "npc"){
            area.addNPCtoRooms(characterManager.getNPCshortDesc(val["id"]), val["room"]);
        }
        
    }
}

