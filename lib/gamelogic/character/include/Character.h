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

/**
 *  @class Character
 *
 *  @brief Base class for characters controlled by users or NPC.
 *
 *  Handles character's attributes, inventory, and equipment.
 */
class Character {
public:
    
    virtual ~Character();
    
    // Get
    std::string getName();
    Attributes getAttributes();
    Attributes getBaseAttributes();
    Inventory getInventory();
    Equipment getEquipment();
    LocationCoordinates getCurrentLocation();
    void setCurrentLocation(LocationCoordinates newLocation);
    void setCurrentLocation(int areaID, int roomID);
    
    
    // States ...
    virtual bool isInCombat();
    virtual bool isAlive();
    
    
    // Compare characters' usernames
    virtual bool operator==(const Character &other);
    virtual bool operator!=(const Character &other);
    
protected:
    
    std::string name;
    
    Attributes baseAttr;
    
    Attributes currentAttr;
    
    Equipment equipment;
    
    Inventory inventory;

    LocationCoordinates currentLocation;
    
};

#endif /* Character_h */
