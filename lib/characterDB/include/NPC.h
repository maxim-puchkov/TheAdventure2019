/////////////////////////////////////////////////////////////////////////////
//                        NPC
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef NonPlayerControlledCharacter_h
#define NonPlayerControlledCharacter_h

#include <vector>
#include "Character.h"

/**
 *  @class NPC
 *
 *  @brief Base class for characters controlled only by computer.
 *
 *  Derived from Character.
 *  Handles specific actions a non-player controlled character may
 *  do: attack, talk, ...
 */
class NPC : public Character {
public:
    NPC();
    void debug();
    virtual ~NPC();
    
    // Attack a PlayerControlledCharacter
    //      virtual void attack(const PlayerControlledCharacter &c);
    
    // ...
private:
    int id;
    std::vector<std::string> keywords;
    std::string shortdesc;
    std::vector<std::string> longdesc;
    std::vector<std::string> description;
};

#endif /* NonPlayerControlledCharacter_h */
