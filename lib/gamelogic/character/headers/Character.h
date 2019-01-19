/////////////////////////////////////////////////////////////////////////////
//                              Character
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Character_h
#define Character_h

#include <string>
#include "Inventory.h"
#include "Attributes.h"
#include "Equipment.h"

class Character {
public:
    
    virtual ~Character() { }
    
    // Communicate
    virtual void say();
    virtual void yell();
    virtual void tell();
    
    
    // Items
    virtual void drop(InteractiveObject *obj);
    virtual void wear(InteractiveObject *obj);
    // ...


	virtual void look();
	virtual void examine();

    
    // Other
    virtual std::string getUsername();
    virtual bool isHostile();
    virtual Attributes getAttributes();
    virtual Inventory getInventory();
    // virtual Room *getCurrentRoom();

    //QUICK HACK TO GET WORLDMANAGER.cpp running
    int getRoomID(){
        return roomID;
    }
    void setRoomID(int newroomID){
        roomID = newroomID;
    }


protected:
    std::string username;
    Attributes *baseAttributes;
    Inventory *inventory;
    Equipment *equipment;
    int roomID;
    
};

#endif /* Character_h */
