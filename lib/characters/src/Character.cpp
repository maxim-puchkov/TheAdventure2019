/////////////////////////////////////////////////////////////////////////////
//                              Character
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Character.h"

Character::Character(const std::string &name) {
    createCharacter(name);
    
    debug::prefix("Character");
    debug::print("Created character \"", name, "\"");
}

Character::~Character() {
    debug::print("Destroyed character \"", name, "\"");
}

void Character::createCharacter(const std::string &name) {
    this->name = DEF_CHAR_NAME;
    this->baseAttr = Attributes(DEF_CHAR_HEALTH, DEF_CHAR_DAMAGE);
    // this->inventory = Inventory();
    this->equipment = Equipment();
    this->currentLocation = LocationCoordinates{0,0};
    
    // Creating a character
    this->name = name;
    this->shortdesc = "";
    this->longdesc = "";
    this->description = "";
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

//Inventory Character::getInventory() {
//    return this->inventory;
//}

Equipment Character::getEquipment() {
    return this->equipment;
}

std::string Character::getShortdesc() const {
    return this->shortdesc;
}

std::string Character::getLongdesc() const {
    return this->longdesc;
}

std::string Character::getDescription() const {
    return this->description;
}

LocationCoordinates Character::getCurrentLocation() const {
    return this->currentLocation;
}

bool Character::getIsDoneFirstTimeSetup() const {
    return this->isDoneFirstTimeSetup;
}

void Character::setFirstTimeSetup(const bool value) {
    isDoneFirstTimeSetup = value;
}

void Character::setCurrentLocation(LocationCoordinates newLocation){
    this->currentLocation = newLocation;
}

void Character::damageCharacter(int amount){
    Attributes damage{-amount, 0};
    this->currentAttr = this->currentAttr + damage;
}

void Character::setShortdesc(const std::string& shortdesc) {
    this->shortdesc = shortdesc;
}

void Character::setLongdesc(const std::string& longdesc) {
    this->longdesc = longdesc;
}

void Character::setDescription(const std::string& description) {
    this->description = description;
}


bool Character::isInCombat() {
    return false;
}

bool Character::isAlive() {
    Attributes attr = this->getAttributes();
    return attr.getHealth() > 0;
}

bool Character::operator==(const Character &other) {
    return this->name.compare(other.name) == 0;
}

bool Character::operator!=(const Character &other) {
    return this->name.compare(other.name) != 0;
}

void Character::characterTakeDamage(const int &damage) {
    currentAttr.setHealth(currentAttr.getHealth() - damage);
}
