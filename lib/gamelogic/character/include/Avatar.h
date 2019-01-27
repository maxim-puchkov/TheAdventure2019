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

const int DEF_AVATAR_HEALTH = 100;
const int DEF_AVATAR_DAMAGE = 10;
const string DEF_AVATAR_NAME = "NO";


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
    
    // Create new avatar and set up Character name and Avatar Appearance
    Avatar();
    
    // Create avatar with existing appearance
    //Avatar(const Custom::Appearance &appearance);
    
    string getName();
    
    virtual ~Avatar();
    
private:
    
    void init();
    
    void createOnFirstLogin();
    
    // Avatar's Appearance will change its in-game looks and stats
    Custom::Appearance createCustomAppearance();
    
protected:
    
    Custom::Appearance appearance;
    
};

#endif /* Avatar_h */
