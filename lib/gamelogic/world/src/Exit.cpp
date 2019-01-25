#include "Exit.h"

using namespace std;


    //Constructors
    Exit::Exit(const string &exitName, const string &exitDescription, short cardinalDirection, int areaID, int roomID)
        : exitName(exitName), exitDescription(exitDescription), cardinalDirection(cardinalDirection)
        {
            setTargetLocation(areaID, roomID);
        }


    //Getters
    const string &Exit::getExitName() const {return exitName;}
    const string &Exit::getExitDescription() const {return exitDescription;}
    short Exit::getCardinalDirection() const {return cardinalDirection;}
    LocationCoordinates Exit::getTargetLocation() const {return targetLocation;}

    //Setters
    void Exit::setExitName(const string &exitName) { Exit::exitName = exitName; }
    void Exit::setExitDescription(const string &exitDescription) { Exit::exitDescription = exitDescription; }
    void Exit::setCardinalDirection(short cardinalDirection) { Exit::cardinalDirection = cardinalDirection; }
    void Exit::setTargetLocation(int areaID, int roomID) {
        LocationCoordinates exitLocation;
        exitLocation.area = areaID;
        exitLocation.room = roomID;
        this->targetLocation = exitLocation;
    }
    void Exit::setTargetLocation(LocationCoordinates newLocation) {
        this->targetLocation = newLocation;
    }


