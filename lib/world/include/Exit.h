//
// Created by jordan on 17/01/19.
//

#ifndef WEBSOCKETNETWORKING_EXIT_H
#define WEBSOCKETNETWORKING_EXIT_H

#include <string>
#include <algorithm>
#include "LocationCoordinates.h"

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
         const std::string& cardinalDirection, int areaID, int roomID);


    static Exit::CardinalDirection getCardinalDirection(const std::string& direction);
    //getters
    const std::string &getExitName() const;
    const std::string &getExitDescription() const;
    CardinalDirection getCardinalDirection() const;
    LocationCoordinates getTargetLocation() const;


    //Setters
    void setExitName(const std::string &exitName);
    void setExitDescription(const std::string &exitDescription);
    void setCardinalDirection(CardinalDirection direction);
    void setTargetLocation(int area, int room);
    void setTargetLocation(LocationCoordinates newLocation);

private:
    std::string exitName;
    std::string exitDescription;
    CardinalDirection exitDirection;
    LocationCoordinates targetLocation;
};


#endif //WEBSOCKETNETWORKING_EXIT_H
