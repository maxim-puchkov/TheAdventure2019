#include <string>
#include <vector>
//#include <algorithm> //std::any_of
#include <utility> //std::move (objects)
#include "../include/Exit.h"
#include "Character.h"
#include "Item.h"

class Room {

	private:
		std::string roomName;
		std::string roomDescription;
		std::vector<Character*> charactersInRoom;
		//std::vector<Item> itemsInRoom;
		std::vector<Exit> roomExits;

	public:
		Room()
			: roomName{"NO_ROOM_NAME"},
			roomDescription{"NO_ROOM_DESCRIPTION"}
		{}
		Room(std::string rName, std::string rDescription)
			: roomName{rName},
			roomDescription{rDescription}
		{}
		int move(Character* character, short direction);
		bool createExit();
		bool addCharacter(Character* character);
		bool removeCharacter(Character* character);
		//getters
		std:string getName() const { return roomName; }
		std:string getDescription() const { return roomDescription; }
		//setters
		void setName(std::string newName) { roomName = newName; }
		void setDescription(std::string newDescription) { roomDescription = newDescription; }
};

// Returns -1 if move is not valid.
// Otherwise, removes character from charactersInRoom and returns ID of new room.
int Room::move(*Character character, short direction){
	if(roomExits.size() <= 0) return -1;
	for (auto exit : roomExits){
		if(exit.getDirection == direction){
			removeCharacter(character);
			return exit.getTargetID();
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

bool Room::addCharacter(*Character character){
	try{
		charactersInRoom.push_back(character);
	} catch(const std::bad_alloc& e){
		return false;
	}
	return true;
}

bool Room::removeCharacter(*Character character){
	int i = 0;
	for (auto *listCharacter : charactersInRoom){
		if(character == listCharacter){
			charactersInRoom.erase(charactersInRoom.begin() + i);
			return true;
		}
		i++;
	}
	return false;
}