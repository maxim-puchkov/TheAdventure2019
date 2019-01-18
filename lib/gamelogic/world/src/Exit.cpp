#include <string>
#include "../include/Exit.h"

using namespace std;


    //Getters
    const string &Exit::getExitName() const {return exitName;}
    const string &Exit::getExitDescription() const {return exitDescription;}
    short Exit::getCardinalDirection() const {return cardinalDirection;}
    unsigned int Exit::getTargetRoomID() const {return targetRoomID;}

    //Setters
    void Exit::setExitName(const string &exitName) { Exit::exitName = exitName; }
    void Exit::setExitDescription(const string &exitDescription) { Exit::exitDescription = exitDescription; }
    void Exit::setCardinalDirection(short cardinalDirection) { Exit::cardinalDirection = cardinalDirection; }
    void Exit::setTargetRoomID(unsigned int targetRoomID) { Exit::targetRoomID = targetRoomID; }




