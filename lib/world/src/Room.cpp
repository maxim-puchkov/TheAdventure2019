#include "Room.h"


LocationCoordinates Room::findExitLocation(const std::string& direction) const {
	auto checkDirection = Exit::getCardinalDirection(direction);


	auto iterator = std::find_if(exitsInRoom.begin(), exitsInRoom.end(),
			[&] (const Exit& e) { return e.getCardinalDirection() == checkDirection; } );

	LocationCoordinates result{-1,-1}; //returns invalid location if exit doesn't exist

	if(iterator != exitsInRoom.end()){
		auto index = std::distance(exitsInRoom.begin(), iterator);
		result = exitsInRoom.at(index).getTargetLocation();
	}

	return result;
}


bool Room::createExit(const std::string& exitName, const std::string& exitDescription,
					  const std::string& cardinalDirection, int areaID, int roomID) {

	Exit newExit(exitName, exitDescription, cardinalDirection, areaID, roomID);
	try{
		exitsInRoom.push_back( std::move(newExit) );
	} catch(const std::bad_alloc& e){
		return false;
	}
	return true;
}


bool Room::addCharacter(const std::string &userName){
	try{
		charactersInRoom.push_back(userName);
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

	auto iter = std::find(charactersInRoom.begin(),charactersInRoom.end(), objName);
	if(iter != charactersInRoom.end()){
		return "A stranger stands before you with the name " + (*iter)  ;
	}
	return "You couldn't find anything called " + objName;
}

std::string Room::lookForExitName(const std::string &objName) const {

	auto roomExit = std::find_if(exitsInRoom.begin(), exitsInRoom.end(),
								 [&](const auto& i) {return objName == i.getExitName();} );

	if(roomExit != exitsInRoom.end()){
		return (*roomExit).getExitDescription();
	}
	return "You couldn't find anything called " + objName;
}


/**
 * Check's and see's all the possible exits in a room, then returns a string with all possible exits
 * @return A string with all the exits listed out
 */
std::string Room::listExits() const {

	std::string result = "Exits are: \n";
	for(Exit iter: exitsInRoom){
		result += "- " + iter.getExitName() + ", " + iter.CardinalToString() + "\n";
	}

	return result;
}




