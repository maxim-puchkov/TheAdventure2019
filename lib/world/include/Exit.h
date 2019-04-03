//
// Created by jordan on 17/01/19.
//

#ifndef WEBSOCKETNETWORKING_EXIT_H
#define WEBSOCKETNETWORKING_EXIT_H

#include <string>
#include <algorithm>
#include "LocationCoordinates.h"
#include <unordered_map>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>
using  namespace boost::bimaps;

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


    static Exit::CardinalDirection getCardinalDirection(const std::string &direction) ;
    //getters
    const std::string &getExitName() const;
    const std::string &getExitDescription() const;
    CardinalDirection getCardinalDirection() const;
    LocationCoordinates getTargetLocation() const;
    const std::string &CardinalToString() const;
    std::string getExitTargetLocation();


    //Setters
    void setExitName(const std::string &exitName);
    void setExitDescription(const std::string &exitDescription);
    void setCardinalDirection(CardinalDirection direction);
    void setTargetLocation(std::string area, int room);
    void setTargetLocation(LocationCoordinates newLocation);
    void setExitTargetLocation(const std::string & name);


    typedef bimap <
            unordered_set_of<Exit::CardinalDirection>,
            unordered_set_of<std::string>
    > bimapType;

    static bimapType const enumStringMap;


private:
    std::string exitTargetLocation;
    std::string exitName;
    std::string exitDescription;
    CardinalDirection exitDirection;
    LocationCoordinates targetLocation;

};






#endif //WEBSOCKETNETWORKING_EXIT_H
