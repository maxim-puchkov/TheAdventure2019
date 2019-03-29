//
// Created by jordan on 17/01/19.
//

#ifndef WEBSOCKETNETWORKING_EXIT_H
#define WEBSOCKETNETWORKING_EXIT_H

#include <string>
#include <algorithm>
#include "LocationCoordinates.h"
#include <unordered_map>



class Exit{

public:
    enum CardinalDirection{
        NONE,
        NORTH,
        NORTHEAST,
        EAST,
        SOUTHEAST,
        SOUTH,
        SOUTHWEST,
        WEST,
        NORTHWEST
    };


    Exit(const std::string& exitName, const std::string& exitDescription,
         const std::string& cardinalDirection, std::string areaID, int roomID);


    static Exit::CardinalDirection getCardinalDirection(const std::string& direction);
    //getters
    const std::string &getExitName() const;
    const std::string &getExitDescription() const;
    CardinalDirection getCardinalDirection() const;
    LocationCoordinates getTargetLocation() const;
    const std::string &CardinalToString() const;


    //Setters
    void setExitName(const std::string &exitName);
    void setExitDescription(const std::string &exitDescription);
    void setCardinalDirection(CardinalDirection direction);
    void setTargetLocation(std::string area, int room);
    void setTargetLocation(LocationCoordinates newLocation);

private:
    std::string exitName;
    std::string exitDescription;
    CardinalDirection exitDirection;
    LocationCoordinates targetLocation;

    //A map that is used to convert CardinalDirection's (enum) into a string for viewing, initialized in cpp
    static std::unordered_map<CardinalDirection, std::string> const directionMap;
};




#endif //WEBSOCKETNETWORKING_EXIT_H
