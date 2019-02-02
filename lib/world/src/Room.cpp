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


bool Room::addCharacter(const std::string &character){
	try{
		charactersInRoom.push_back(character);
	} catch(const std::bad_alloc& e){
		return false;
	}
	return true;
}

/**
 *Removes username from Room. Note that it removes duplicates (but we shouldn't have duplicates)
 * @param userName - UserNmae you want to remove
 * @return true if the username is removed, false if not found
 */
bool Room::removeCharacter(const std::string &userName){
	auto iter = std::remove(charactersInRoom.begin(),charactersInRoom.end(),userName);
	charactersInRoom.erase(iter,charactersInRoom.end());
	return ( !( charactersInRoom.end() == iter ) ); //If iter==char.end() then userName wasn't found in list
}

std::string Room::lookForName(const std::string &objName) const{
	std::string result;
	auto iter = std::find_if(charactersInRoom.begin(),charactersInRoom.end(),objName);

	if(iter != charactersInRoom.end()){
		result = "A stranger stands before you with the name " + (*iter)  ;
		return result;
	}
	return "You couldn't find anything called " + objName;
}

std::string Room::lookRoomName(const std::string &objName) const {
	std::string result;
	auto roomExit = std::find_if(exitsInRoom.begin(), exitsInRoom.end(),
								 [&](const auto& i) {return objName == i.getExitName();} );

	if(roomExit != exitsInRoom.end()){
		result = (*roomExit).getExitDescription();
		return result;
	}
	return "You couldn't find anything called " + objName;
}




