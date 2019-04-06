#include "Exit.h"
// #include <boost/algorithm/string.hpp>
// #include <boost/bimap/bimap.hpp>
// #include <boost/bimap/unordered_set_of.hpp>
// using  namespace boost::bimaps;

using namespace std;


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
    const string Exit::CardinalToString() const {
        const CardinalDirection &result = this->exitDirection;
        auto search = directionMap.find(result);
        if(search != directionMap.end()){
            return search->second;
        }

        return (stringManager.getString(Internationalization::STRING_CODE::DIRECTION_NOT_FOUND), "\n");

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
        } else if(input == "up"){
            return Exit::CardinalDirection::UP;
        } else if(input == "down"){
            return Exit::CardinalDirection::DOWN;
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
            {NORTHWEST,"northwest"},
            {UP,"up"},
            {DOWN,"down"}
    };

    /*
    Exit::CardinalDirection Exit::getCardinalDirection(const std::string& direction) {
        std::string input = direction;
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);

        if(input == stringManager.getString(Internationalization::STRING_CODE::NORTH)){
            return Exit::CardinalDirection::NORTH;
        } else if(input == stringManager.getString(Internationalization::STRING_CODE::NORTHEAST)){
            return Exit::CardinalDirection::NORTHEAST;
        } else if(input == stringManager.getString(Internationalization::STRING_CODE::EAST)){
            return Exit::CardinalDirection::EAST;
        } else if(input == stringManager.getString(Internationalization::STRING_CODE::SOUTHEAST)){
            return Exit::CardinalDirection::SOUTHEAST;
        } else if(input == stringManager.getString(Internationalization::STRING_CODE::SOUTH)){
            return Exit::CardinalDirection::SOUTH;
        } else if(input == stringManager.getString(Internationalization::STRING_CODE::SOUTHWEST)){
            return Exit::CardinalDirection::SOUTHWEST;
        } else if(input == stringManager.getString(Internationalization::STRING_CODE::WEST)){
            return Exit::CardinalDirection::WEST;
        } else if(input == stringManager.getString(Internationalization::STRING_CODE::NORTHWEST)){
            return Exit::CardinalDirection::NORTHWEST;
        } else if(input == "up"){
            return Exit::CardinalDirection::UP;
        } else if(input == "down"){
            return Exit::CardinalDirection::DOWN;
        }

        return Exit::CardinalDirection::NONE;
    }

    //A map that is used to convert ENUM's into strings for viewing
    const std::unordered_map<Exit::CardinalDirection, std::string> Exit::directionMap = {
            {NONE,stringManager.getString(Internationalization::STRING_CODE::NONE)},
            {NORTH,stringManager.getString(Internationalization::STRING_CODE::NORTH)},
            {NORTHEAST,stringManager.getString(Internationalization::STRING_CODE::NORTHEAST)},
            {EAST,stringManager.getString(Internationalization::STRING_CODE::EAST)},
            {SOUTHEAST,stringManager.getString(Internationalization::STRING_CODE::SOUTHEAST)},
            {SOUTH,stringManager.getString(Internationalization::STRING_CODE::SOUTH)},
            {SOUTHWEST,stringManager.getString(Internationalization::STRING_CODE::SOUTHWEST)},
            {WEST,stringManager.getString(Internationalization::STRING_CODE::WEST)},
            {NORTHWEST,stringManager.getString(Internationalization::STRING_CODE::NORTHWEST)},
            {UP,"up"},
            {DOWN,"down"}
    };
    */

    const string &Exit::getExitName() const {return exitName;}

    const string Exit::getLowerCaseExitName() const {
        std::string result = exitName;
        // boost::algorithm::to_lower(result);
        return std::move(result);

    }

    const string Exit::getExitDescription() const {
        if (exitDescription.empty()) {
            return stringManager.getString(Internationalization::STRING_CODE::THIS_EXIT_HAS_NO_DESC);
        }
        return exitDescription;
    }

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
