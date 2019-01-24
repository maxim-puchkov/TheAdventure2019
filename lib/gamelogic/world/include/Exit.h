//
// Created by jordan on 17/01/19.
//

#ifndef WEBSOCKETNETWORKING_EXIT_H
#define WEBSOCKETNETWORKING_EXIT_H

#include "LocationCoordinates.h"

class Exit{

private:
    std::string exitName;
    std::string exitDescription;
    short cardinalDirection;
    LocationCoordinates targetLocation;

public:
    Exit(const std::string &exitName, const std::string &exitDescription, short cardinalDirection,
         int areaID, int roomID);


    //getters
    const std::string &getExitName() const;
    const std::string &getExitDescription() const;
    short getCardinalDirection() const;
    LocationCoordinates getTargetLocation() const;


    //Setters
    void setExitName(const std::string &exitName);
    void setExitDescription(const std::string &exitDescription);
    void setCardinalDirection(short cardinalDirection);
    void setTargetLocation(int area, int room);
    void setTargetLocation(LocationCoordinates newLocation);
};


#endif //WEBSOCKETNETWORKING_EXIT_H
