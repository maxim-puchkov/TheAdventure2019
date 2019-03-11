/////////////////////////////////////////////////////////////////////////////
//                              Character
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Character_h
#define Character_h

#include <string>
#include <utility> //std::move
#include "Attributes.h"
#include "Inventory.h"
#include "Equipment.h"
#include "LocationCoordinates.h"

const std::string DEF_CHAR_NAME = "DEF_CHAR_NAME";
const int DEF_CHAR_HEALTH = 100;
const int DEF_CHAR_DAMAGE = 10;


/**
 *  @class Character
 *
 *  @brief class for both characters controlled by users and NPC via action control modes.
 *
 *  Handles character's attributes, inventory, and equipment.
 */
class Character {
public:
    
    Character(const std::string &name);
    
    //TODO: create control mode interface for combat
    
    // Get
    virtual std::string getName();
    Attributes getAttributes();
    Attributes getBaseAttributes();
    Inventory getInventory();
    Equipment getEquipment();
    LocationCoordinates getCurrentLocation() const;
    
    // Set
    void setCurrentLocation(LocationCoordinates newLocation);
    
    
    // States ...
    bool isInCombat();
    bool isAlive();
    
    
    // Compare characters' usernames
    bool operator==(const Character &other);
    bool operator!=(const Character &other);
    
protected:
    void createCharacter(const std::string &name);
    std::string name;
    Attributes baseAttr;
    Attributes currentAttr;
    Equipment equipment;
    Inventory inventory;
    LocationCoordinates currentLocation;
    
};

#endif /* Character_h */
