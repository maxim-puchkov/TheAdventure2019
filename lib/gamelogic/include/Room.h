#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
//#include <algorithm> //std::any_of
#include <utility> //std::move (objects)
#include "Exit.h"
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
		Room();
		Room(std::string rName, std::string rDescription);
		int move(Character* character, short direction);
		bool createExit();
		bool addCharacter(Character* character);
		bool removeCharacter(Character* character);
		//getters
		std::string getName() const;
		std::string getDescription() const;
		//setters
		void setName(std::string newName);
		void setDescription(std::string newDescription);
};

#endif
