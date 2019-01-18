#include <string>
#include <cstdlib> //std::rand
#include "WorldManager.h"
#include "../../character/headers/Character.h"



WorldManager::WorldManager() {
	//temporary hard coded rooms
	for(int i = 0; i < 10; i++){
		std::string roomName = "Room number " + std::to_string(i+1);
		std::string roomDescription = "This dark room contains only the number " + std::to_string(i+1);
		int exit1TargetID = std::rand() % (i+1); //rand ID from 0 to i
		int exit2TargetID = std::rand() % (i+1); //rand ID from 0 to i

		Room r(roomName, roomDescription);
		r.createExit("Exit 1", "The first exit. Looks shady.", 0, exit1TargetID);
		r.createExit("Exit 2", "The second exit. Looks way better than exit 1.", 0, exit2TargetID);
		worldRooms[i] = r;
	}

}

int WorldManager::move(Character * character, short direction) {
	int currentRoomID = character->getRoomID();
	int newRoomID = worldRooms[currentRoomID].move(character, direction);
	if( newRoomID < 0) return -1; //if move failed, return -1

	character->setRoomID(newRoomID);
	bool result = worldRooms[newRoomID].addCharacter(character); //add character to new room in world

	if(result == false) return -1;

}

std::string WorldManager::look(unsigned int roomID) const {
		return worldRooms[roomID].getDescription();
}