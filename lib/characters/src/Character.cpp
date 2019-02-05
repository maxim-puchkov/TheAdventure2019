/////////////////////////////////////////////////////////////////////////////
//                              Character
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////


#include "Character.h"


Character::Character(string &&name) {
    this->name = DEF_CHAR_NAME;
    this->baseAttr = Attributes(DEF_CHAR_HEALTH, DEF_CHAR_DAMAGE);
    this->inventory = Inventory();
    this->equipment = Equipment();
    
    // Creating a character
    this->name = name;
}


Character::~Character() { }




/* Getters */

std::string Character::getName() const {
    return this->name;
}


Attributes Character::getAttributes() const {
    return this->currentAttr + this->equipment.attributeBonus();
}


Attributes Character::getBaseAttributes() const {
    return this->baseAttr;
}


Inventory Character::getInventory() const {
    return this->inventory;
}


Equipment Character::getEquipment() const {
    return this->equipment;
}





/* Location */

// Use separate setters instead
unsigned int Character::getCurrentAreaId() const {
    return this->areaId;
}


unsigned int Character::getCurrentRoomId() const {
    return this->roomId;
}


LocationCoordinates Character::getCurrentLocation() {
    return this->currentLocation;
    // return {this->areaId, this->roomId};
}







/* Setters */

// Now set separately
void Character::setCurrentLocation(LocationCoordinates newLocation) {
    this->currentLocation = newLocation;
}


void Character::setCurrentArea(unsigned int areaId) {
    this->areaId = areaId;
}


void Character::setCurrentRoom(unsigned int roomId) {
    this->roomId = roomId;
}





/* States */

bool Character::isInCombat() {
    return false;
}


bool Character::isAlive() {
    Attributes attr = this->getAttributes();
    return attr.getHealth() <= 0;
}





/* Custom */

bool Character::operator==(const Character &other) {
    return this->name.compare(other.name) == 0;
}


bool Character::operator!=(const Character &other) {
    return this->name.compare(other.name) != 0;
}
