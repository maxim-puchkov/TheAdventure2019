/////////////////////////////////////////////////////////////////////////////
//                              Character
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Character.h"

Character::~Character() { }

void Character::createCharacter(const std::string &name) {
    this->name = DEF_CHAR_NAME;
    this->baseAttr = Attributes(DEF_CHAR_HEALTH, DEF_CHAR_DAMAGE);
    this->inventory = Inventory();
    this->equipment = Equipment();
    this->currentLocation = LocationCoordinates{0,0};
    
    // Creating a character
    this->name = name;
}

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

LocationCoordinates Character::getCurrentLocation() const {
    return this->currentLocation;
}

void Character::setCurrentLocation(LocationCoordinates newLocation){
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
