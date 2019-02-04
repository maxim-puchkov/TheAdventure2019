/////////////////////////////////////////////////////////////////////////////
//                                  Avatar
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Avatar_h
#define Avatar_h

#include "PlayerControlledCharacter.h"
#include "Appearance.h"

using std::string;



/**
 *  @class Avatar
 *
 *  @brief Character that can be controlled and customized.
 *
 *  Derived from PlayerControlledCharacter.
 *  Handles character creation and customization.
 */
class Avatar : public PlayerControlledCharacter {
public:
    
    // Not allowed. Created with a name of its user.
    // Avatar();
    
    // Create new avatar and set up its appearance
    Avatar(const string &name) = delete;
    Avatar(string &&name);
    
    // Load avatar with existing appearance
    Avatar(const string &name, const Custom::Appearance &appearance) = delete;
    Avatar(string &&name, Custom::Appearance &&appearance);
    
    virtual ~Avatar();
    
private:
    
    void init();
    
    void createOnFirstLogin();
    
    // Avatar's Appearance will change its in-game looks and stats
    Custom::Appearance createCustomAppearance();

    string name;
    
    Custom::Appearance appearance;
    
};

#endif /* Avatar_h */
