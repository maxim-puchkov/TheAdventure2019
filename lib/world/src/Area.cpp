//
// Created by jordan on 24/01/19.
//

#include "Area.h"

/**
 * Returns a room at a particular index from an area
 */
Room Area::getRoom(unsigned int index) const {
    if(index >= rooms.size()){
        //return some invalid room
    }
    return rooms.at(index);
}

void Area::addRoom(Room room){
    rooms.push_back(room);
}

unsigned int Area::size() const{
    return rooms.size();
}

const std::string &Area::getName() const {
    return name;
}

void Area::setName(const std::string &name) {
    Area::name = name;
}

const std::string &Area::getDescription() const {
    return description;
}

void Area::setDescription(const std::string &description) {
    Area::description = description;
}
