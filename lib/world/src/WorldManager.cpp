#include <stdexcept>
#include <iostream>
#include "WorldManager.h"
#include "AreaGenerator.h"

WorldManager::WorldManager() {}

Room& WorldManager::findRoomByLocation(LocationCoordinates location) {
    if (areas.empty() || location.area == ""){
        throw std::domain_error("Area out of bounds");
    }
    // auto& areaOfInterest = areas.at((unsigned long)location.area);
    auto search = areas.find(location.area);
    if (search != areas.end()) {
        return search->second.getRoom(location.room);
    }else{
        throw std::domain_error("Room out of bounds");
    }
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
    Room room{name, "Admin generated"};
    int roomID = areas[location.area].getNextRoomID();
    room.setRoomID(roomID);
    areas[location.area].addRoom(room);
    areas[location.area].setNextRoomID(roomID);

    auto& currentRoom = findRoomByLocation(location);
    currentRoom.createExit("-1", "to Admin Generated Room", direction, location.area, roomID);
    auto& exitList = currentRoom.getExits();
    for(auto& ext : exitList) {
        if(ext.getExitName() == "-1"){
            std::string exitName = "exit to, Area: " + location.area;
            exitName += " Room: " + name;
            ext.setExitTargetLocation(exitName);
            break;
        }
    }
}

int WorldManager::getRoomToSpawnUser() {
    //need to change this to dynamic
    auto search = areas.find("Mirkwood");

    if(search != areas.end()) {
        return search->second.getFirstRoomID();
    }else{
        return -1;
    }
}

std::string WorldManager::worldDetail(LocationCoordinates location) {
    std::string worldDetail = "The world made of: \n";
    for(auto& area : areas) {
        worldDetail += "Area: ";
        worldDetail += area.second.getName();
        worldDetail += "\n";
        worldDetail += "Rooms:\n";
        auto roomNameIDsList = area.second.getRoomNameIDListAdmin();
        for(auto& room : roomNameIDsList){
            worldDetail += room;
            worldDetail += "\n";
        }
    }
    return worldDetail;
}
void WorldManager::addArea(Area area){
    areas.insert(std::make_pair(area.getName(), area));
}

void WorldManager::printRoomsInArea(Area area) {
    for(auto& p: area.getRoomList()){
        std::cout << p.first << " => " << p.second.getName() << ": ";
        std::cout << p.second.getDescription() << "\n";
        std::cout <<"\n";

        for(auto ext: p.second.getExits()){
            std::cout << "EXIT NAME: " + ext.getExitName() << " \n";
        }
    }
}

Area& WorldManager::getAreaByLocation(LocationCoordinates location){
    auto search = areas.find(location.area);
    if(search != areas.end()){
        return search->second;
    }
    return nullArea;
}