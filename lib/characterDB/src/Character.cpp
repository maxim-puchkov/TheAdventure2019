/////////////////////////////////////////////////////////////////////////////
//                              Character
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Character.h"

Character::Character(const std::string &name) {
    createCharacter(name);

    // debug::prefix("Character");
    // debug::print("Created character \"", name, "\"");
}

Character::~Character() {
    // debug::print("Destroyed character \"", name, "\"");
}


void Character::createCharacter(const std::string &name) {
    this->name = DEF_CHAR_NAME;
    this->baseAttr = Attributes(DEF_CHAR_HEALTH, DEF_CHAR_DAMAGE);
    this->equipment = Equipment();
    //need to fix this
    this->currentLocation = LocationCoordinates{"test",0};

    // Creating a character
    this->name = name;
    this->shortdesc = "";
    this->longdesc = "";
    this->description = "";
}

std::string Character::getName() const {
    return this->name;
}

Attributes Character::getAttributes() const {
    return this->currentAttr + this->equipment.attributeBonus();
}

Attributes Character::getBaseAttributes() const {
    return this->baseAttr;
}

Equipment Character::getEquipment() const {
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

void Character::damageCharacter(int amount) {
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

void Character::setMode(const std::string& modeName){
    if(modeName == "user"){
        this->mode = &userControl;
    }else if(modeName == "aggro"){
        this->mode = &aggroNPC;
    }else if(modeName == "pacifist"){
        this->mode = &pacifistNPC;
    }
}

bool Character::isConfused() const{
    return this->confused;
}
bool Character::isSwapped() const{
    return this->swapped;
}
bool Character::isDecoy() const{
    return this->decoy;
}

void Character::setConfused(const bool status) {
    this->confused = status;
}
void Character::setSwapped(const bool status) {
    this->swapped = status;
}
void Character::setDecoy(const bool status) {
    this->decoy = status;
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

std::string Character::getCombatReply(){
    return this->mode->getCombatReply();
}

std::string Character::getAttackReply(){
    return this->mode->getAttackReply();
}

void Character::characterTakeDamage(const int &damage) {
    currentAttr.setHealth(currentAttr.getHealth() - damage);
}
