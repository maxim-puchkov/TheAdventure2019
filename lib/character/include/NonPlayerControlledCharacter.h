/////////////////////////////////////////////////////////////////////////////
//                        NonPlayerControlledCharacter
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef NonPlayerControlledCharacter_h
#define NonPlayerControlledCharacter_h

#include "Character.h"

/**
 *  @class NonPlayerControlledCharacter
 *
 *  @brief Base class for characters controlled only by computer.
 *
 *  Derived from Character.
 *  Handles specific actions a non-player controlled character may
 *  do: attack, talk, ...
 */
class NonPlayerControlledCharacter : public Character {
public:
    
    virtual ~NonPlayerControlledCharacter();
    
    // Attack a PlayerControlledCharacter
    //      virtual void attack(const PlayerControlledCharacter &c);
    
    // ...
    
};

#endif /* NonPlayerControlledCharacter_h */
