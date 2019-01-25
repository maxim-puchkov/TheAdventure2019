//
// Created by jordan on 24/01/19.
//

#include "Area.h"

/**
 * Returns a room at a particular index from an area
 */
Room Area::getRoom(int index) {
    if(index < 0){
        //return error?
    }
    if(index >= rooms.size()){
        //return some invalid room
    }
    return rooms.at(index);
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
