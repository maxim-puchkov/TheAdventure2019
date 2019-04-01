#include "Exit.h"

using namespace std;


    //Constructors
    Exit::Exit(const string& exitName, const string& exitDescription, const std::string& cardinalDirection, int areaID, int roomID)
        : exitName(exitName), exitDescription(exitDescription)
        {
            exitDirection = getCardinalDirection(cardinalDirection);
            setTargetLocation(areaID, roomID);
        }


    /**
     * Returns the cardinal direction of a room as a string for viewing, displaying for the user to view
     */
    const string& Exit::CardinalToString() const {
        CardinalDirection result = this->exitDirection;
        auto search = directionMap.find(result);

        if(search != directionMap.end()){
            return search->second;
        }

        return stringManager.getString(Internationalization::STRING_CODE::DIRECTION_NOT_FOUND);

    }

    //REARRANGE THIS TO TAKE ADVANTAGE OF MAP "directionMap"
    //Getters
    Exit::CardinalDirection Exit::getCardinalDirection(const std::string& direction) {
        std::string input = direction;
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);

        if(input == "north"){
            return Exit::CardinalDirection::NORTH;
        } else if(input == "northeast"){
            return Exit::CardinalDirection::NORTHEAST;
        } else if(input == "east"){
            return Exit::CardinalDirection::EAST;
        } else if(input == "southeast"){
            return Exit::CardinalDirection::SOUTHEAST;
        } else if(input == "south"){
            return Exit::CardinalDirection::SOUTH;
        } else if(input == "southwest"){
            return Exit::CardinalDirection::SOUTHWEST;
        } else if(input == "west"){
            return Exit::CardinalDirection::WEST;
        } else if(input == "northwest"){
            return Exit::CardinalDirection::NORTHWEST;
        }

        return Exit::CardinalDirection::NONE;
    }

    //A map that is used to convert ENUM's into strings for viewing
    const std::unordered_map<Exit::CardinalDirection, std::string> Exit::directionMap = {
            {NONE,"none"},
            {NORTH,"north"},
            {NORTHEAST,"northeast"},
            {EAST,"east"},
            {SOUTHEAST,"southeast"},
            {SOUTH,"south"},
            {SOUTHWEST,"southwest"},
            {WEST,"west"},
            {NORTHWEST,"northwest"}
    };


    const string &Exit::getExitName() const {return exitName;}
    const string &Exit::getExitDescription() const {return exitDescription;}
    Exit::CardinalDirection Exit::getCardinalDirection() const {return exitDirection;}
    LocationCoordinates Exit::getTargetLocation() const {return targetLocation;}

    //Setters
    void Exit::setExitName(const string &exitName) { Exit::exitName = exitName; }
    void Exit::setExitDescription(const string &exitDescription) { Exit::exitDescription = exitDescription; }
    void Exit::setCardinalDirection(Exit::CardinalDirection cardinalDirection) { exitDirection = cardinalDirection; }
    void Exit::setTargetLocation(int areaID, int roomID) {
        LocationCoordinates exitLocation;
        exitLocation.area = areaID;
        exitLocation.room = roomID;
        this->targetLocation = exitLocation;
    }
    void Exit::setTargetLocation(LocationCoordinates newLocation) {
        this->targetLocation = newLocation;
    }



