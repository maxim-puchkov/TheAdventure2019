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

Room WorldManager::findRoomByLocation(LocationCoordinates location) const{
    if (areas.empty() || location.area < 0 || (unsigned int)location.area >= areas.size())
        throw std::domain_error("Area out of bounds");
    Area areaOfInterest = areas.at((unsigned long)location.area);
    if (areaOfInterest.size() < 1 || location.room < 0 || (unsigned int)location.room >= areaOfInterest.size())
        throw std::domain_error("Room out of bounds");
    return areaOfInterest.getRoom((unsigned int)location.room);
}

bool WorldManager::kick(Character& character){
    LocationCoordinates charLocation = character.getCurrentLocation();
    Room currentRoom;
    try{
        currentRoom = findRoomByLocation(charLocation);
    } catch(const std::domain_error& e){
        return false;
    }

    return currentRoom.removeCharacter(character.getName());
}

bool WorldManager::spawn(Character& character, LocationCoordinates location){
    Room spawnRoom;
    try{
        spawnRoom = findRoomByLocation(location);
    } catch(const std::domain_error& e){
        return false;
    }

    spawnRoom.addCharacter(character.getName());
    character.setCurrentLocation(location);
    return true;
}

std::string WorldManager::say (Character& character, std::string message) const{
     return "You said the thing.";
}

LocationCoordinates WorldManager::move(Character& character, const std::string& direction) const {
    LocationCoordinates currentLocation = character.getCurrentLocation();
    Room roomOfInterest;
    try{
        roomOfInterest = findRoomByLocation(currentLocation);
    } catch(const std::domain_error& e){
        return currentLocation;
    }

    //find the target location of the exit in the current room with input direction
    LocationCoordinates newLocation = roomOfInterest.findExitLocation(direction);

    Room newRoom;
    try{
        newRoom = findRoomByLocation(newLocation);
    } catch(const std::domain_error& e){
        return currentLocation;
    }

    roomOfInterest.removeCharacter(character.getName());
    
    character.setCurrentLocation(newLocation);
    newRoom.addCharacter(character.getName());
    return newLocation;
}

std::string WorldManager::listExits(const Character& character) const{
    LocationCoordinates currentLocation = character.getCurrentLocation();
    Room currentRoom = findRoomByLocation(currentLocation);
    std::string result = "Exits are:";

    currentLocation = currentRoom.findExitLocation("north");
    if(currentLocation.room >= 0)
        result.append(" North");

    currentLocation = currentRoom.findExitLocation("east");
    if(currentLocation.room >= 0)
        result.append(" East");

    currentLocation = currentRoom.findExitLocation("south");
    if(currentLocation.room >= 0)
        result.append(" South");

    currentLocation = currentRoom.findExitLocation("west");
    if(currentLocation.room >= 0)
        result.append(" West");

    if(result == "Exits are:")
        result.append(" not anywhere to be seen.");

    return result;
}


std::string WorldManager::look(Character& character) const {
    LocationCoordinates location = character.getCurrentLocation();

    Room roomOfInterest;
    try {
        roomOfInterest = findRoomByLocation(location);
    } catch (const std::domain_error &e) {
        return "You've become terribly lost...";
    }

    return roomOfInterest.getDescription();
}

std::string WorldManager::look(Character& character, std::string objName) const{
    LocationCoordinates location = character.getCurrentLocation();
    Room roomOfInterest;
    try{
        roomOfInterest = findRoomByLocation(location);
    } catch(const std::domain_error& e){
        return "You've become terribly lost...";
    }

    return roomOfInterest.lookForExitName(objName);
}
