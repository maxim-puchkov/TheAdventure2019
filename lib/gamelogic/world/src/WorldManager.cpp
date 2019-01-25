#include "WorldManager.h"

WorldManager::WorldManager() {}

void WorldManager::generateWorld() {
    Area a("Starting Area", "Welcome to adventure.");

    //temporary hard coded rooms
    for(int i = 0; i < 10; i++){
        std::string roomName = "Room number " + std::to_string(i+1);
        std::string roomDescription = "This dark room contains only the number " + std::to_string(i+1);
        int exit1TargetID = /*std::rand() % */(i+1); //rand ID from 0 to i
        int exit2TargetID = /*std::rand() % */(i+2); //rand ID from 0 to i

        Room r(roomName, roomDescription);
        r.createExit("Exit 1", "The first exit. Looks shady.", 0, 0, exit1TargetID);
        r.createExit("Exit 2", "The second exit. Looks way better than exit 1.", 2, 0, exit2TargetID);

        a.addRoom(r);
    }
    areas.push_back(a);
}

LocationCoordinates WorldManager::move(Character * character, short direction) const {
    LocationCoordinates currentLocation = character->getCurrentLocation();

    Room roomOfInterest = areas.at((unsigned long)currentLocation.area).getRoom(currentLocation.room);
    LocationCoordinates newLocation = roomOfInterest.findExitLocation(direction);

    if(newLocation.area < 0 || newLocation.room < 0) return currentLocation; //move failed

    roomOfInterest.removeCharacter(character);
    character->setCurrentLocation(newLocation);
    areas.at((unsigned long)newLocation.area).getRoom(newLocation.room).addCharacter(character);
    return newLocation;
}

std::string WorldManager::look(LocationCoordinates location) const {
    if(location.area < 0 || (unsigned int)location.area > areas.size()) return "room not found";
    Area areaOfInterest = areas.at((unsigned int)location.area);
    if(location.room < 0 || (unsigned int)location.room > areaOfInterest.size()) return "room not found";
    std::string result = areaOfInterest.getRoom(location.room).getDescription();
    return result;
}
