#include <stdexcept>
#include "WorldManager.h"

WorldManager::WorldManager() {}

void WorldManager::generateWorld() {
    Area a("Starting Area", "Welcome to adventure.");

    //temporary hard coded rooms
    for(int i = 0; i < 10; i++){
        std::string roomName = "Room number " + std::to_string(i+1);
        std::string roomDescription = "This dark room contains only the number " + std::to_string(i+1);
        int exit1TargetID = i+1;
        int exit2TargetID = i+2;

        Room r(roomName, roomDescription);
        r.createExit("Exit 1", "The first exit. Looks shady.", Exit::CardinalDirection::NORTH, 0, exit1TargetID);
        r.createExit("Exit 2", "The second exit. Looks way better than exit 1.", Exit::CardinalDirection::SOUTH, 0, exit2TargetID);

        a.addRoom(r);
    }
    areas.push_back(a);
}

Room WorldManager::findRoomByLocation(LocationCoordinates location) const{
    if (location.area < 0 || (unsigned int)location.area >= areas.size())
        throw std::domain_error("Area out of bounds");

    Area areaOfInterest = areas.at((unsigned long)location.area);
    if (location.room < 0 || (unsigned int)location.room >= areaOfInterest.size())
        throw std::domain_error("Room out of bounds");

    return areaOfInterest.getRoom((unsigned int)location.room);
}

bool WorldManager::kick(Character* character){
    LocationCoordinates charLocation = character->getCurrentLocation();
    Room currentRoom;
    try{
        currentRoom = findRoomByLocation(charLocation);
    } catch(const std::domain_error& e){
        return false;
    }

    return currentRoom.removeCharacter(character);
}

bool WorldManager::spawn(Character* character, LocationCoordinates location){
    Room spawnRoom;
    try{
        spawnRoom = findRoomByLocation(location);
    } catch(const std::domain_error& e){
        return false;
    }

    spawnRoom.addCharacter(character);
    character->setCurrentLocation(location);
    return true;
}

std::string WorldManager::say (Character* character, std::string message) const{
     return "You said the thing.";
}

LocationCoordinates WorldManager::move(Character * character, Exit::CardinalDirection direction) const {
    LocationCoordinates currentLocation = character->getCurrentLocation();
    Room roomOfInterest;
    try{
        roomOfInterest = findRoomByLocation(currentLocation);
    } catch(const std::domain_error& e){
        return currentLocation;
    }

    LocationCoordinates newLocation = roomOfInterest.findExitLocation(direction);

    Room newRoom;
    try{
        newRoom = findRoomByLocation(newLocation);
    } catch(const std::domain_error& e){
        return currentLocation;
    }

    roomOfInterest.removeCharacter(character);
    character->setCurrentLocation(newLocation);
    newRoom.addCharacter(character);
    return newLocation;
}

std::string WorldManager::look(Character* character) const {
    LocationCoordinates location = character->getCurrentLocation();
    Room roomOfInterest;
    try{
        roomOfInterest = findRoomByLocation(location);
    } catch(const std::domain_error& e){
        return "You've become terribly lost...";
    }

    return roomOfInterest.getDescription();
}

std::string WorldManager::look(Character* character, std::string objName) const{
    LocationCoordinates location = character->getCurrentLocation();
    Room roomOfInterest;
    try{
        roomOfInterest = findRoomByLocation(location);
    } catch(const std::domain_error& e){
        return "You've become terribly lost...";
    }

    return roomOfInterest.lookForName(objName);
}
