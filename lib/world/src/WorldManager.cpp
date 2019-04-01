#include <stdexcept>
#include <iostream>
#include "WorldManager.h"

using internationalization::Internationalization;

void WorldManager::generateWorld() {
    Area a(stringManager.getString(
        Internationalization::STRING_CODE::STARTING_AREA),
        stringManager.getString(Internationalization::STRING_CODE::STARTING_AREA_WELCOME_MESSAGE)
    );
    Area b(
        stringManager.getString(Internationalization::STRING_CODE::SECRET_AREA), 
        stringManager.getString(Internationalization::STRING_CODE::SECRET_AREA_WELCOME_MESSAGE)
    );

    Room r1(
        stringManager.getString(Internationalization::STRING_CODE::ROOM_UPPER_CASE) + "1",
        stringManager.getString(Internationalization::STRING_CODE::THIS_DARK_ROOM_CONTAINS_NUMBER) + " 1"
    );
    r1.createExit(
        stringManager.getString(Internationalization::STRING_CODE::GATE),
        stringManager.getString(Internationalization::STRING_CODE::GOES_TO_ROOM) + " 2",
        stringManager.getString(Internationalization::STRING_CODE::EAST), 
        0, 
        1
    );
    r1.createExit(
        stringManager.getString(Internationalization::STRING_CODE::SOUTH_GATE), 
        stringManager.getString(Internationalization::STRING_CODE::GOES_TO_ROOM) + " 3", 
        stringManager.getString(Internationalization::STRING_CODE::SOUTH), 
        0, 
        2
    );
    a.addRoom(r1);
    Room r2(
        stringManager.getString(Internationalization::STRING_CODE::ROOM_UPPER_CASE) + "2", 
        stringManager.getString(Internationalization::STRING_CODE::THIS_DARK_ROOM_CONTAINS_NUMBER) + " 2"
    );
    r2.createExit(
        stringManager.getString(Internationalization::STRING_CODE::WEST_GATE), 
        stringManager.getString(Internationalization::STRING_CODE::GOES_TO_ROOM) + " 1", 
        stringManager.getString(Internationalization::STRING_CODE::WEST), 
        0, 
        0
    );
    r2.createExit(
        stringManager.getString(Internationalization::STRING_CODE::SOUTH_GATE), 
        stringManager.getString(Internationalization::STRING_CODE::GOES_TO_ROOM) + " 4", 
        stringManager.getString(Internationalization::STRING_CODE::SOUTH), 
        0, 
        3
    );
    a.addRoom(r2);
    Room r3(
        stringManager.getString(Internationalization::STRING_CODE::ROOM_UPPER_CASE) + "3", 
        stringManager.getString(Internationalization::STRING_CODE::THIS_DARK_ROOM_CONTAINS_NUMBER) + " 3"
    );
    r3.createExit(
        stringManager.getString(Internationalization::STRING_CODE::EAST_GATE), 
        stringManager.getString(Internationalization::STRING_CODE::GOES_TO_ROOM) + " 4", 
        stringManager.getString(Internationalization::STRING_CODE::EAST),
        0, 
        3
    );
    r3.createExit(
        stringManager.getString(Internationalization::STRING_CODE::WEST_GATE), 
        stringManager.getString(Internationalization::STRING_CODE::GOES_TO_ROOM) + " 6", 
        stringManager.getString(Internationalization::STRING_CODE::WEST), 
        0, 
        5
    );
    r3.createExit(
        stringManager.getString(Internationalization::STRING_CODE::HIDDEN_PASSAGE), 
        stringManager.getString(Internationalization::STRING_CODE::GOES_TO_ROOM) + " 1", 
        stringManager.getString(Internationalization::STRING_CODE::SOUTH), 
        0, 
        0
    );
    a.addRoom(r3);
    Room r4(
        stringManager.getString(Internationalization::STRING_CODE::ROOM_UPPER_CASE) + "4", 
        stringManager.getString(Internationalization::STRING_CODE::THIS_DARK_ROOM_CONTAINS_NUMBER) + " 4"
    );
    r4.createExit(
        stringManager.getString(Internationalization::STRING_CODE::EAST_GATE), 
        stringManager.getString(Internationalization::STRING_CODE::GOES_TO_ROOM) + " 5", 
        stringManager.getString(Internationalization::STRING_CODE::EAST), 
        0, 
        4
    );
    r4.createExit(
        stringManager.getString(Internationalization::STRING_CODE::NORTH_GATE), 
        stringManager.getString(Internationalization::STRING_CODE::GOES_TO_ROOM) + " 2", 
        stringManager.getString(Internationalization::STRING_CODE::NORTH), 
        0, 
        1
    );
    a.addRoom(r4);
    Room r5(
        stringManager.getString(Internationalization::STRING_CODE::ROOM_UPPER_CASE) + "5", 
        stringManager.getString(Internationalization::STRING_CODE::THIS_DARK_ROOM_CONTAINS_NUMBER) + " 5"
    );
    r5.createExit(
        stringManager.getString(Internationalization::STRING_CODE::EAST_GATE), 
        stringManager.getString(Internationalization::STRING_CODE::GOES_OUT_OF_BOUNDS), 
        stringManager.getString(Internationalization::STRING_CODE::EAST), 
        0, 
        10
    );
    r5.createExit(
        stringManager.getString(Internationalization::STRING_CODE::WEST_GATE), 
        stringManager.getString(Internationalization::STRING_CODE::GOES_TO_ROOM) + " 4",
        stringManager.getString(Internationalization::STRING_CODE::WEST), 
        0, 
        3
    );
    a.addRoom(r5);
    Room r6(
        stringManager.getString(Internationalization::STRING_CODE::ROOM_UPPER_CASE) + "6", 
        stringManager.getString(Internationalization::STRING_CODE::THIS_DARK_ROOM_CONTAINS_NUMBER) + " 6"
    );
    r6.createExit(
        stringManager.getString(Internationalization::STRING_CODE::WEST_GATE), 
        stringManager.getString(Internationalization::STRING_CODE::GOES_TO_AREA) + " 2", 
        stringManager.getString(Internationalization::STRING_CODE::WEST), 
        1, 
        0
    );
    a.addRoom(r6);

    Room r7(
        stringManager.getString(Internationalization::STRING_CODE::ROOM_UPPER_CASE) + "6", 
        stringManager.getString(Internationalization::STRING_CODE::THIS_SECRET_ROOM_CONTAINS_NUMBER) + " 1"
    );
    r7.createExit(
        stringManager.getString(Internationalization::STRING_CODE::WEST_GATE), 
        stringManager.getString(Internationalization::STRING_CODE::GOES_TO_AREA) + " 1", 
        stringManager.getString(Internationalization::STRING_CODE::WEST), 
        0, 
        0
    );
    b.addRoom(r7);

    areas.push_back(a);
    areas.push_back(b);

}

Room& WorldManager::findRoomByLocation(LocationCoordinates location) {
    if (areas.empty() || location.area < 0 || (unsigned int)location.area >= areas.size())
        throw std::domain_error(
            stringManager.getString(Internationalization::STRING_CODE::AREA) +
            stringManager.getString(Internationalization::STRING_CODE::OUT_OF_BOUND)
        );

    auto& areaOfInterest = areas.at((unsigned long)location.area);

    if (areaOfInterest.size() < 1 || location.room < 0 || (unsigned int)location.room >= areaOfInterest.size())
        throw std::domain_error(
            stringManager.getString(Internationalization::STRING_CODE::ROOM) +
            stringManager.getString(Internationalization::STRING_CODE::OUT_OF_BOUND)
        );

    return areaOfInterest.getRoom((unsigned int)location.room);
}

bool WorldManager::kick(const std::string& characterName, LocationCoordinates location) {
    try {
        auto& currentRoom = findRoomByLocation(location);
        return currentRoom.removeCharacter(characterName);
    } catch(const std::domain_error& e) {
        return false;
    }
}

bool WorldManager::spawn(const std::string& characterName, LocationCoordinates location) {
    try {
        auto& spawnRoom = findRoomByLocation(location);
        spawnRoom.addCharacter(characterName);
    } catch(const std::domain_error& e){
        return false;
    }
    return true;
}

const std::vector<std::string>& WorldManager::getUserNamesInRoom (LocationCoordinates location) {
    auto& room = findRoomByLocation(location);
    return room.getUserNames();
}

const std::vector<std::string> WorldManager::getUserNamesInRange (LocationCoordinates location, unsigned int range) {

    try {
        auto &roomOfInterest = findRoomByLocation(location);
        auto &exitsInRoom = roomOfInterest.getExits();
        if(range <= 0 || exitsInRoom.empty()) { return roomOfInterest.getUserNames(); }

        auto nameList = std::vector<std::string>{};
        const auto& roomNames = roomOfInterest.getUserNames();
        nameList.reserve(nameList.size() + roomNames.size());
        nameList.insert(nameList.end(), roomNames.begin(), roomNames.end());

        for (const auto &exit : exitsInRoom) {
            const auto& nextNameList = getUserNamesInRange(exit.getTargetLocation(), range - 1);
            nameList.reserve(nameList.size() + nextNameList.size());
            nameList.insert(nameList.end(), nextNameList.begin(), nextNameList.end());
        }

        return nameList;

    } catch(const std::domain_error& e){
        return std::vector<std::string>{};
    }
}

LocationCoordinates WorldManager::move(const std::string& characterName, LocationCoordinates location, const std::string& direction) {
    try{
        auto& roomOfInterest = findRoomByLocation(location);
        LocationCoordinates newLocation = roomOfInterest.findExitLocation(direction);

        auto& newRoom = findRoomByLocation(newLocation);

        roomOfInterest.removeCharacter(characterName);
        newRoom.addCharacter(characterName);
        
        return newLocation;
    } catch(const std::domain_error& e){
        return location;
    }
}

std::string WorldManager::listExits(LocationCoordinates location) {
    try {
        auto& currentRoom = findRoomByLocation(location);
        std::string result = currentRoom.listExits();
        return result;
    } catch(const std::domain_error& e){
        return stringManager.getString(Internationalization::STRING_CODE::NO_EXITS_FOUND);
    }
}


std::string WorldManager::look(LocationCoordinates location) {
    try {
        auto& roomOfInterest = findRoomByLocation(location);
        return roomOfInterest.getDescription();
    } catch (const std::domain_error &e) {
        return stringManager.getString(Internationalization::STRING_CODE::YOU_ARE_LOST);
    }
}

std::string WorldManager::look(LocationCoordinates location, std::string objName) {
    try {
        auto& roomOfInterest = findRoomByLocation(location);
        return roomOfInterest.lookForExitName(objName);
    } catch(const std::domain_error& e){
        return stringManager.getString(Internationalization::STRING_CODE::YOU_ARE_LOST);
    }
}
