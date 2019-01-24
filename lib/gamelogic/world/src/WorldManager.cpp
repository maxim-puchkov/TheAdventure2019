#include "WorldManager.h"

WorldManager::WorldManager() {}

void WorldManager::generateWorld() {
    //temporary hard coded rooms
    for(int i = 0; i < 10; i++){
        std::string roomName = "Room number " + std::to_string(i+1);
        std::string roomDescription = "This dark room contains only the number " + std::to_string(i+1);
        int exit1TargetID = std::rand() % (i+1); //rand ID from 0 to i
        int exit2TargetID = std::rand() % (i+1); //rand ID from 0 to i

        Room r(roomName, roomDescription);
        r.createExit("Exit 1", "The first exit. Looks shady.", 0, 0, exit1TargetID);
        r.createExit("Exit 2", "The second exit. Looks way better than exit 1.", 2, 0, exit2TargetID);
        worldRooms[i] = r;
    }
}

bool WorldManager::move(Character * character, short direction) {
    auto currentLocation = character->getCurrentLocation();

    return true;
    LocationCoordinates newLocation = worldRooms[currentLocation.room].findExitLocation(direction);



    if(newLocation.area < 0 || newLocation.room < 0) return false; //move failed

    if(!worldRooms[currentLocation.room].removeCharacter(character)) return false;
    character->setCurrentLocation(newLocation);
    return worldRooms[newLocation.room].addCharacter(character);
}

std::string WorldManager::look(LocationCoordinates location) const {
        if(location.room < 0) return "room not found\n";
		return worldRooms[location.room].getDescription();
}
