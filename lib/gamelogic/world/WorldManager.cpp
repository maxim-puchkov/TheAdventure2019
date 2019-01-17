#include <string>
#include "Room.h"
#include "Character.h"

class WorldManager {
	
	private:
		Room[10] worldRooms;

	public:
		WorldManager();
		unsigned int move(Character* character, short direction) const;
		std::string look(unsigned int roomID) const;

};

worldManager(){
	for(int i = 0; i < 10; i++){
		Room r;
		worldRooms[i] = r;
	}
	//generate rooms
}

int WorldManager::move(Character* character, short direction){
		return 0;
}

std::string WorldManager::look(unsigned int roomID){
		return "The room is dark, cold and empty.";
}