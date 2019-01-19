#include <string>
#include <vector>
//#include <algorithm> //std::any_of
#include <utility> //std::move (objects)
#include "../include/Exit.h"
#include "../include/Room.h"


// Returns -1 if move is not valid.
// Otherwise, removes character from charactersInRoom and returns ID of new room.
int Room::move(Character * character, short direction){
	if(roomExits.size() <= 0) return -1;
	for (auto exit : roomExits){
		if(exit.getCardinalDirection() == direction){
			removeCharacter(character);
			return exit.getTargetRoomID();
		}
	}
	/* Fancier implementation
	if( std::any_of( roomExits.begin(), roomExits.end(),
	 	[](auto exit) { return exit.getDirection == direction } ) ){
	 	removeCharacter(character);
	 	return exit.getTargetID();
	}
	 */

	return -1;
}

bool Room::createExit(std::string exitName, std::string exitDescription,
						short cardinalDirection, int targetRoomID) {

	Exit newExit(exitName, exitDescription, cardinalDirection, targetRoomID);
	try{
		roomExits.push_back( std::move(newExit) );
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
	for (auto * listCharacter : charactersInRoom){
		if(character == listCharacter){
			charactersInRoom.erase(charactersInRoom.begin() + i);
			return true;
		}
		i++;
	}
	return false;
}