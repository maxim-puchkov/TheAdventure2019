/////////////////////////////////////////////////////////////////////////////
//                        PlayerControlledCharacter
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef PlayerControlledCharacter_h
#define PlayerControlledCharacter_h

#include "Character.h"

/**
 *  @class PlayerControlledCharacter
 *
 *  @brief Base class for characters controlled only by users.
 *
 *  Derived from Character.
 *  Handles specific actions a player controlled character may
 *  do when playing: communicate, interact with objects, move, etc...
 */
class PlayerControlledCharacter : public Character {
public:
        
    virtual ~PlayerControlledCharacter();
    
    // Communicate with users
    virtual void say(const std::string &str);                     // say str
    virtual void yell(const std::string &str);                    // yell str
    virtual void tell(const std::string &str, Character *recv);   // tell str recv
    
    
    // Interact with Examinable objects (items, players, exits)
    //      virtual void look(const Examinable &obj);
    
    
    // Take an Interactable item from a Containable object
    //      virtual void get(const Containable &container, const Interactable &item);
    
    
    // Attack NonPlayerControlledCharacter
    //      virtual void attack(const NonPlayerControlledCharacter &c);
    
    // ...
    
};

#endif /* PlayerControlledCharacter_h */
