#include "Room.h"


// Returns -1 if move is not valid.
// Otherwise, removes character from charactersInRoom and returns ID of new room.
/*int Room::move(user::User * character, short direction){
	if(roomExits.size() <= 0) return -1;
	for (auto exit : roomExits){
		if(exit.getCardinalDirection() == direction){
			removeCharacter(character);
			return exit.getTargetRoomID();
		}
	}
	*//* Fancier implementation
	if( std::any_of( roomExits.begin(), roomExits.end(),
	 	[](auto exit) { return exit.getDirection == direction } ) ){
	 	removeCharacter(character);
	 	return exit.getTargetID();
	}
	 *//*

	return -1;
}*/

LocationCoordinates Room::findExitLocation(Exit::CardinalDirection exitDirection) const {
	for (auto roomExit : exitsInRoom){
		if(roomExit.getCardinalDirection() == exitDirection){
			return roomExit.getTargetLocation();
		}
	}
	LocationCoordinates invalidLocation;
	invalidLocation.area = -1;
	invalidLocation.room = -1;
	return invalidLocation; //no exit found with that direction
}

bool Room::createExit(std::string exitName, std::string exitDescription,
						Exit::CardinalDirection cardinalDirection, int areaID, int roomID) {

	Exit newExit(exitName, exitDescription, cardinalDirection, areaID, roomID);
	try{
		exitsInRoom.push_back( std::move(newExit) );
	} catch(const std::bad_alloc& e){
		return false;
	}
	return true;
}

bool Room::addCharacter(Character * character){
	try{
		charactersInRoom.push_back(character);
	} catch(const std::bad_alloc& e){
		return false;
	}
	return true;
}

bool Room::removeCharacter(Character * character){
	int i = 0;
	for (auto * roomCharacter : charactersInRoom){
		if(character == roomCharacter){
			charactersInRoom.erase(charactersInRoom.begin() + i);
			return true;
		}
		i++;
	}
	return false;
}

std::string Room::lookForName(std::string objName) const{
	std::string result;
	for(auto * roomCharacter : charactersInRoom){
		if(roomCharacter->getName() == objName){
			result = "A stranger stands before you with the name ";
			result.append(roomCharacter->getName());
			return result;
		}
	}
	for(Exit roomExit : exitsInRoom){
		if(roomExit.getExitName() == objName){
			result = roomExit.getExitDescription();
			return result;
		}
	}
	result = "You couldn't find anything called ";
	result.append(objName);
	return result;
}