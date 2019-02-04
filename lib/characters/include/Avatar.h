/////////////////////////////////////////////////////////////////////////////
//                                  Avatar
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#ifndef Avatar_h
#define Avatar_h


#include "Character.h"
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
class Avatar : public Character {
public:
        
    // Create new avatar and set up its appearance
    Avatar(string &&name);
    
    void loadAppearance(const Custom::Appearance &appearance);
    
    virtual ~Avatar();
    
private:
    
    Avatar() = delete;
    
    Avatar(const string &name) = delete;
    
    void init();
    
    void createOnFirstLogin();
    
    Custom::Appearance createCustomAppearance();
    
    
    
    
    
    
    
    /* Fields */
    
    Custom::Appearance appearance;
    
};

#endif /* Avatar_h */
