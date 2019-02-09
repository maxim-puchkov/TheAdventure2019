#include <iostream>
#include "Exit.h"
#include <boost/assign.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/assign/list_inserter.hpp>


using namespace std;
using namespace boost; // bring 'insert()' into scope

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
        Exit::bimapType::left_const_iterator search = enumStringMap.left.find(result);

        if( search == enumStringMap.left.end()){
            const std::string ans = " exit not found ";
            return std::move(ans);
        }
        return search->second;
    }

    //REARRANGE THIS TO TAKE ADVANTAGE OF MAP "directionMap"
    //Getters
    Exit::CardinalDirection Exit::getCardinalDirection(const std::string& direction) {
        std::string input = direction;
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);

        //map stores enum on the left and string on the right
       auto iter = enumStringMap.right.find(direction);
        if(iter == enumStringMap.right.end()){
            return Exit::CardinalDirection::NONE;
        }

        return iter->second;

    }


    const Exit::bimapType Exit::enumStringMap = assign::list_of<bimapType::relation>
            (NONE,"none")
            (NORTH,"north")
            (NORTHEAST,"northeast")
            (EAST,"east")
            (SOUTHEAST,"southeast")
            (SOUTH,"south")
            (SOUTHWEST,"southwest")
            (WEST,"west")
            (NORTHWEST,"northwest");




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



