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
            auto creatExit = roomObj.createExit(
                (stringManager.getString(Internationalization::STRING_CODE::EXIT_TO) + ":" + std::to_string(index)), 
                exitDesc, 
                jsonParser.removeQuotes(tmpExit["dir"].dump()), 
                area.getName(), 
                tmpExit["to"]
            );
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
        
        std::vector<std::string> extra_keywords = jsonParser.json2Vector(object["extra"][0]);
        std::string extra_desc = jsonParser.json2string(object["extra"][1]);
        
        vector<items::Action> vec{items::Action(
            stringManager.getString(Internationalization::STRING_CODE::READ), 
            stringManager.getString(Internationalization::STRING_CODE::ITEMS_NOW_WORKING)
        )};

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
            std::string exitTo = 
                stringManager.getString(Internationalization::STRING_CODE::EXIT_TO) + 
                ": " + 
                nextRoom.getName();
            ext.setExitTargetLocation(exitTo);
        }
    }
}

Area AreaGenerator::generateExits(Area area){
    for(auto& room :area.getRoomList()){
        for(auto& ext: room.second.getExits()){

            auto exitID = ext.getTargetLocation().room;
            ext.getTargetLocation().area = roomsMap[exitID].first;
            std::string exitName = 
                stringManager.getString(Internationalization::STRING_CODE::EXIT_TO) + 
                ", " + 
                stringManager.getString(Internationalization::STRING_CODE::AREA) + 
                ": " + 
                roomsMap[exitID].first + 
                " " + 
                stringManager.getString(Internationalization::STRING_CODE::ROOM) + 
                ": " + 
                roomsMap[exitID].second; 
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
        if(val["action"] == stringManager.getString(Internationalization::STRING_CODE::NPC)){
            area.addNPCtoRooms(characterManager.getNPCshortDesc(val["id"]), val["room"]);
        }
        
    }
}

