#include <stdexcept>
#include <iostream>
#include "WorldManager.h"

WorldManager::WorldManager() {}

void WorldManager::generateWorld() {
    Area a("Starting Area", "Welcome to adventure.");
    Area b("Secret area", "Welcome to die.");

    Room r1("Room1", "This dark room contains only the number 1");
    r1.createExit("gate", "goes to room 2", "east", 0, 1);
    r1.createExit("South Gate", "goes to room 3", "south", 0, 2);
    a.addRoom(r1);
    Room r2("Room2", "This dark room contains only the number 2");
    r2.createExit("West Gate", "goes to room 1", "west", 0, 0);
    r2.createExit("South Gate", "goes to room 4", "south", 0, 3);
    a.addRoom(r2);
    Room r3("Room3", "This dark room contains only the number 3");
    r3.createExit("East Gate", "goes to room 4", "east", 0, 3);
    r3.createExit("West Gate", "goes to room 6", "west", 0, 5);
    r3.createExit("South Hidden Passage", "goes to room 1", "south", 0, 0);
    a.addRoom(r3);
    Room r4("Room4", "This dark room contains only the number 4");
    r4.createExit("East Gate", "goes to room 5", "east", 0, 4);
    r4.createExit("North Gate", "goes to room 2", "north", 0, 1);
    a.addRoom(r4);
    Room r5("Room5", "This dark room contains only the number 5");
    r5.createExit("East Gate", "goes out of bounds", "east", 0, 10);
    r5.createExit("West Gate", "goes to room 4", "west", 0, 3);
    a.addRoom(r5);
    Room r6("Room6", "This dark room contains only the number 6");
    r6.createExit("West Gate", "goes to area 2", "west", 1, 0);
    a.addRoom(r6);

    Room r7("Room6", "This secret room contains only the number 1");
    r7.createExit("West Gate", "goes to area 1", "west", 0, 0);
    b.addRoom(r7);

    areas.push_back(a);
    areas.push_back(b);

}

Room& WorldManager::findRoomByLocation(LocationCoordinates location) {
    if (areas.empty() || location.area < 0 || (unsigned int)location.area >= areas.size())
        throw std::domain_error("Area out of bounds");

    auto& areaOfInterest = areas.at((unsigned long)location.area);

    if (areaOfInterest.size() < 1 || location.room < 0 || (unsigned int)location.room >= areaOfInterest.size())
        throw std::domain_error("Room out of bounds");

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

void WorldManager::createRoom() {
    Room room{"G1", "Admin Generated"};
    room.createExit("G1 exit", "Testing", "north", 0, 6);
    areas[0].addRoom(room);
    std::cout << "ROOM is CREATE\n";
}

void WorldManager::createArea() {
    Area c("Admin Area", "Generating World");
    areas.push_back(c);
    currentArea = areas.size() - 1;
}
