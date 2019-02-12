#include <stdexcept>
#include <iostream>
#include "WorldManager.h"

WorldManager::WorldManager() {}

void WorldManager::generateWorld() {
    Area a("Starting Area", "Welcome to adventure.");
    Area b("Secret area", "Welcome to die.");

    Room r1("Room1", "This dark room contains only the number 1");
    r1.createExit("East Gate", "goes to room 2", "east", 0, 1);
    r1.createExit("South Slide", "goes to room 3. ONE WAY EXIT.", "south", 0, 2);
    a.addRoom(r1);
    Room r2("Room2", "This dark room contains only the number 2");
    r2.createExit("West Gate", "goes to room 1", "west", 0, 0);
    r2.createExit("South Gate", "goes to room 4", "south", 0, 3);
    a.addRoom(r2);
    Room r3("Room3", "This dark room contains only the number 3");
    r3.createExit("East Slide", "goes to room 4. ONE WAY EXIT.", "east", 0, 3);
    r3.createExit("West Gate", "goes to room 6", "west", 0, 5);
    r3.createExit("South Hidden Passage", "goes to room 1. ONE WAY EXIT.", "south", 0, 0);
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
    r6.createExit("East Gate", "goes to room 3", "east", 0, 2);
    r6.createExit("West Bungie Drop", "goes to area 2. ONE WAY EXIT.", "west", 1, 0);
    a.addRoom(r6);

    Room r7("Room6", "This secret room contains only the number 1");
    r7.createExit("West Rickety Door", "goes to area 1. ONE WAY EXIT.", "west", 0, 0);
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

bool WorldManager::kick(Character& character){
    LocationCoordinates charLocation = character.getCurrentLocation();

    try{
        auto& currentRoom = findRoomByLocation(charLocation);
        if (currentRoom.removeCharacter(character.getName())){
            character.setCurrentLocation(LocationCoordinates{-1,-1});
            return true;
        }
        return false;

    } catch(const std::domain_error& e){

        return false;
    }
}

bool WorldManager::spawn(Character& character, LocationCoordinates location){
    try{
        auto& spawnRoom = findRoomByLocation(location);
        spawnRoom.addCharacter(character.getName());
        character.setCurrentLocation(location);
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

LocationCoordinates WorldManager::move(Character& character, const std::string& direction) {
    LocationCoordinates currentLocation = character.getCurrentLocation();
    try{
        auto& roomOfInterest = findRoomByLocation(currentLocation);
        LocationCoordinates newLocation = roomOfInterest.findExitLocation(direction);

        auto& newRoom = findRoomByLocation(newLocation);

        roomOfInterest.removeCharacter(character.getName());
        character.setCurrentLocation(newLocation);
        newRoom.addCharacter(character.getName());

        return newLocation;
    } catch(const std::domain_error& e){
        return currentLocation;
    }
}

std::string WorldManager::listExits(const Character& character) {
    LocationCoordinates currentLocation = character.getCurrentLocation();
    try{

        auto& currentRoom = findRoomByLocation(currentLocation);
        std::string result = currentRoom.listExits();

        return result;
    } catch(const std::domain_error& e){
        return "No exits found! uh oh!";
    }
}

std::string WorldManager::listPeople(const Character& character) {
    LocationCoordinates currentLocation = character.getCurrentLocation();
    try{

        auto& currentRoom = findRoomByLocation(currentLocation);
        auto& peopleList = currentRoom.getUserNames();
        std::string result = "People in room: \n";
        for(auto& charName: peopleList){
            result += "- " + charName + "\n";
        }

        return result;
    } catch(const std::domain_error& e){
        return "No one else in the room.";
    }
}


std::string WorldManager::look(Character& character) {
    LocationCoordinates location = character.getCurrentLocation();

    try {
        auto& roomOfInterest = findRoomByLocation(location);

        return roomOfInterest.getDescription();
    } catch (const std::domain_error &e) {
        return "You've become terribly lost...";
    }
}

std::string WorldManager::look(Character& character, std::string objName) {
    LocationCoordinates location = character.getCurrentLocation();

    try{
        auto& roomOfInterest = findRoomByLocation(location);

        return roomOfInterest.lookForExitName(objName);
    } catch(const std::domain_error& e){
        return "You've become terribly lost...";
    }
}
