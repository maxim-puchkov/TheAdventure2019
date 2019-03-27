#include <stdexcept>
#include <iostream>
#include "WorldManager.h"
#include "AreaGenerator.h"

WorldManager::WorldManager() {}


void WorldManager::printRoomsInArea(Area area) {
    for(auto& p: area.getRoomList()){
        std::cout << p.first << " => " << p.second.getName() << ": ";
        std::cout << p.second.getDescription() << "\n";
        std::cout <<"\n";
    }
}

void WorldManager::generateWorld() {

    // *** AREA GENERATION TEST CODE ***
    AreaGenerator areaGen;
    std::string filePath = "mirkwood.json";
    auto newArea = areaGen.getArea(filePath);
    printRoomsInArea(newArea);
    areas.push_back(newArea);

}

Room& WorldManager::findRoomByLocation(LocationCoordinates location) {
    if (areas.empty() || location.area < 0 || (unsigned int)location.area >= areas.size()){
        throw std::domain_error("Area out of bounds");
    }

    auto& areaOfInterest = areas.at((unsigned long)location.area);
    std::cout << location.room << "\n";
    // if (areaOfInterest.size() < 1 || location.room < 0 || (unsigned int)location.room >= areaOfInterest.size())
    if (areaOfInterest.size() < 1 || location.room < 0) {
        throw std::domain_error("Room out of bounds");
    }

    // return areaOfInterest.getRoom((unsigned int)location.room);
    return areaOfInterest.getRoom(location.room);
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
        return "No exits found! uh oh!";
    }
}


std::string WorldManager::look(LocationCoordinates location) {
    try {
        auto& roomOfInterest = findRoomByLocation(location);
        return roomOfInterest.getDescription();
    } catch (const std::domain_error &e) {
        return "You've become terribly lost...";
    }
}

std::string WorldManager::look(LocationCoordinates location, std::string objName) {
    try {
        auto& roomOfInterest = findRoomByLocation(location);
        return roomOfInterest.lookForExitName(objName);
    } catch(const std::domain_error& e){
        return "You've become terribly lost...";
    }
}

void WorldManager::createRoom(const LocationCoordinates & location, const std::string& direction, const std::string& name) {
    Room room{name, "Admind generated"};
    int roomID = areas[location.area].getNextRoomID();
    room.setRoomID(roomID);
    areas[location.area].addRoom(room);

    std::string exitName = direction; 
    exitName = exitName + " Gate";
    auto& currentRoom = findRoomByLocation(location);
    currentRoom.createExit(exitName, "to Admin Generated Room", direction, location.area, roomID);
    std::cout << areas.size() << "ROOM is CREATE\n";
}

void WorldManager::createArea() {
    Area c("Admin Area", "Generating World");
    areas.push_back(c);
}

int WorldManager::getRoomToSpawnUser() {
    return areas[0].getFirstRoomID();
}
