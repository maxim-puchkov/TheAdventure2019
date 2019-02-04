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



using std::string;

const string DEF_CHAR_NAME = "Character";
const int DEF_CHAR_HEALTH = 100;
const int DEF_CHAR_DAMAGE = 10;

#include "LocationCoordinates.h"      /* Should belong to character's library if needed */
//struct Location {                   /* ~> Location */
//    unsigned int area;
//    unsigned int room;
//};


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
    
    virtual void createCharacter(string &&name);
    
    
    
    
    
    /* Get character's properties */
    
    virtual std::string getName() const;
    
    Attributes getAttributes() const;
    
    Attributes getBaseAttributes() const;
    
    Inventory getInventory() const;
    
    Equipment getEquipment() const;
    
    unsigned int getCurrentAreaId() const;
    
    unsigned int getCurrentRoomId() const;
    
    LocationCoordinates getCurrentLocation();
    
    
    
    
    
    /* Set */
    
    void setCurrentArea(unsigned int areaId);
    
    void setCurrentRoom(unsigned int roomId);
    
    void setCurrentLocation(LocationCoordinates newLocation);
    
    
    
    /* Check character's state */
    
    virtual bool isInCombat();
    
    virtual bool isAlive();
    
    
    
    
    
    /* Custom members */
    
    virtual bool operator==(const Character &other);
    
    virtual bool operator!=(const Character &other);
    
protected:
    
    string name;
    
    Attributes baseAttr;
    
    Attributes currentAttr;
    
    Equipment equipment;
    
    Inventory inventory;

    LocationCoordinates currentLocation; // !
    
    unsigned int areaId;
    
    unsigned int roomId;
    
};

#endif /* Character_h */
