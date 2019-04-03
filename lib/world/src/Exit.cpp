#include <iostream>
#include "Exit.h"
#include <boost/assign.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/assign/list_inserter.hpp>
#include <map>//delete??
#include <unordered_map>//delete??

using namespace std;
using namespace boost; // bring 'insert()' into scope

const Exit::bimapType Exit::enumStringMap = assign::list_of<bimapType::relation>
        (NONE,"none"  )
        (NORTH,"north")
        (NORTHEAST,"northeast")
        (EAST,"east")
        (SOUTHEAST,"southeast")
        (SOUTH,"south")
        (SOUTHWEST,"southwest")
        (WEST,"west")
        (NORTHWEST,"northwest");

    //Constructors
    Exit::Exit(const string& exitName, const string& exitDescription, const std::string& cardinalDirection, std::string areaID, int roomID)
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
        auto search = enumStringMap.left.find(result);
        if( search == enumStringMap.left.end()){
            const std::string ans = " exit not found ";
            return std::move(ans);
        }
        return search->second;

    }

    ///////////FIGURE HOW TO MAKE THIS WORK WITH BIMAP, We shouldn't need to use if-elseif.
    Exit::CardinalDirection Exit::getCardinalDirection(const std::string &direction) {

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

       return Exit::NONE;
    }


    const string &Exit::getExitName() const {return exitName;}
    const string &Exit::getExitDescription() const {return exitDescription;}
    Exit::CardinalDirection Exit::getCardinalDirection() const {return exitDirection;}
    LocationCoordinates Exit::getTargetLocation() const {return targetLocation;}

    //Setters
    void Exit::setExitName(const string &exitName) { Exit::exitName = exitName; }
    void Exit::setExitDescription(const string &exitDescription) { Exit::exitDescription = exitDescription; }
    void Exit::setCardinalDirection(Exit::CardinalDirection cardinalDirection) { exitDirection = cardinalDirection; }
    void Exit::setTargetLocation(std::string areaID, int roomID) {
        LocationCoordinates exitLocation;
        exitLocation.area = areaID;
        exitLocation.room = roomID;
        this->targetLocation = exitLocation;
    }
    void Exit::setTargetLocation(LocationCoordinates newLocation) {
        this->targetLocation = newLocation;
    }

    void Exit::setExitTargetLocation(const std::string & name) {
        this->exitTargetLocation = name;
    }

    std::string Exit::getExitTargetLocation() {
        return exitTargetLocation;
    }


