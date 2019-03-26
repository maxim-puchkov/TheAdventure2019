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


/*!
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
    std::string getName();
    Attributes getAttributes();
    Attributes getBaseAttributes();
    Inventory getInventory();
    Equipment getEquipment();
    LocationCoordinates getCurrentLocation() const;

    std::string getShortdesc() const;
    std::string getLongdesc() const;
    std::string getDescription() const;
    bool getIsDoneFirstTimeSetup() const;
    
    // Set
    void setCurrentLocation(LocationCoordinates newLocation);
    void damageCharacter(int amount);
    void setShortdesc(const std::string& shortdesc);
    void setLongdesc(const std::string& longdesc);
    void setDescription(const std::string& description);
    void setFirstTimeSetup(const bool value);
    
    // States ...
    bool isInCombat();
    bool isAlive();
    
    // Compare characters' usernames
    bool operator==(const Character &other);
    bool operator!=(const Character &other);

    // Combat WIP
    void characterTakeDamage(const int &damage);
    
private:
    std::string name;
    Attributes baseAttr;
    Attributes currentAttr;
    Equipment equipment;
    Inventory inventory;
    LocationCoordinates currentLocation;
    
    //basic stuff to allow user edit
    std::string shortdesc;
    std::string longdesc;
    std::string description;

    //first time set up flag
    bool isDoneFirstTimeSetup = false;

    void createCharacter(const std::string &name);
};

#endif /* Character_h */
