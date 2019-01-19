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
    
    // virtual void look(const Examinable &obj);
    
    // ...
    
private:

protected:
    
};

#endif /* PlayerControlledCharacter_h */
