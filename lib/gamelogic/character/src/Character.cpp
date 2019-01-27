/////////////////////////////////////////////////////////////////////////////
//                              Character
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Character.h"

Character::~Character() { }

std::string Character::getName() {
    return this->name;
}

Attributes Character::getAttributes() {
    return this->currentAttr + this->equipment.attributeBonus();
}

Attributes Character::getBaseAttributes() {
    return this->baseAttr;
}

Inventory Character::getInventory() {
    return this->inventory;
}

Equipment Character::getEquipment() {
    return this->equipment;
}

LocationCoordinates Character::getCurrentLocation() {
    return this->currentLocation;
}

void Character::setCurrentLocation(LocationCoordinates newLocation){
    this->currentLocation = newLocation;
}

void Character::setCurrentLocation(int areaID, int roomID){
    LocationCoordinates newLocation;
    newLocation.area = areaID;
    newLocation.room = roomID;
    this->currentLocation = newLocation;
}

bool Character::isInCombat() {
    return false;
}

bool Character::isAlive() {
    Attributes attr = this->getAttributes();
    return attr.getHealth() <= 0;
}

bool Character::operator==(const Character &other) {
    return this->name.compare(other.name) == 0;
}

bool Character::operator!=(const Character &other) {
    return this->name.compare(other.name) != 0;
}
