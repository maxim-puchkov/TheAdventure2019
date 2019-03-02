/////////////////////////////////////////////////////////////////////////////
//                              Character
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Character_h
#define Character_h


#include <string>
#include <utility>


#include "Attributes.h"
#include "Inventory.h"
#include "Equipment.h"
#include "LocationCoordinates.h"      /* Should belong to character's
                                         library if needed */

using std::string;


const string DEF_CHAR_NAME = "New Character";
const int DEF_CHAR_HEALTH = 100;
const int DEF_CHAR_DAMAGE = 10;


/**
 *  @class Character
 *
 *  @brief Base class for characters controlled by users or NPC.
 *
 *  Handles character's attributes, inventory, and equipment.
 */
class Character {
public:
    
    Character(const string &name);
    
    virtual ~Character();
    
    
    
    
    
    
    
    /* Get character's properties */
    
    virtual std::string getName() const;
    
    Inventory getInventory() const;
    
    Equipment getEquipment() const;
    
    unsigned int getCurrentAreaId() const;
    
    unsigned int getCurrentRoomId() const;
    
    
    
    
    
    /* Set */
    
    void setCurrentArea(unsigned int areaId);
    
    void setCurrentRoom(unsigned int roomId);
    
    
    
    
    
    /* Check character's state */
    
    virtual bool isInCombat();
    
    virtual bool isAlive();
    
    
    
    
    
    /* Custom members */
    
    virtual bool operator==(const Character &other);
    
    virtual bool operator!=(const Character &other);
    
    
    
    
    
    /* Deprecated */
    
    void createCharacter(string &&name); /* undefined */
    
    LocationCoordinates getCurrentLocation() const;
    
    void setCurrentLocation(LocationCoordinates newLocation);
    
    LocationCoordinates currentLocation;
    
    Attributes getAttributes() const;
    
    Attributes getBaseAttributes() const;
    
    Attributes baseAttr;
    
    Attributes currentAttr;
    
    
    
    
    
    /* Protected */
    
protected:
    
    string name;
    
    Equipment equipment;
    
    Inventory inventory = Inventory();
    
    unsigned int areaId;
    
    unsigned int roomId;
    
private:
    
};

#endif /* Character_h */
