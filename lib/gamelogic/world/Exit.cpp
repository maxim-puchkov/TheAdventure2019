#include "Exit.h"

Exit::Exit(std::string exName, std::string exDescription, short cDirection, int targetID)
	: exitName{exName},
	  exitDescription{exDescription},
	  cardinalDirection{cDirection},
	  targetRoomID{targetID}
{}
Exit::Exit()
	: exitName{"NO_EXIT_NAME"},
	  exitDescription{"NO_EXIT_DESCRIPTION"},
	  cardinalDirection{0},
	  targetRoomID{0}
{}
//getters
std::string Exit::getName() const { return exitName; }
std::string Exit::getDescription() const { return exitDescription; }
short Exit::getDirection() const { return cardinalDirection; }
unsigned int Exit::getTargetID() const { return targetRoomID; }
//setters
void Exit::setName(std::string newName) { exitName = newName; }
void Exit::setDescription(std::string newDescription) { exitDescription = newDescription; }
void Exit::setDirection(short newDirection) { cardinalDirection = newDirection; }
void Exit::setTargetID(int newTargetID) { targetRoomID = newTargetID; }


