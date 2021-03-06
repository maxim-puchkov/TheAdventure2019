/////////////////////////////////////////////////////////////////////////////
//                                  Avatar
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Avatar.h"


Avatar::Avatar(const string &name) : Character(name) {
    // this->createCharacter(std::move(name));
    // this->createOnFirstLogin();
}


Avatar::~Avatar() { }


void Avatar::createOnFirstLogin() {
    this->appearance = this->createCustomAppearance();
}


Custom::Appearance Avatar::createCustomAppearance() {
    Custom::Appearance appr;
    int input = 0;
    
    // Ask for valid input [male, female] local input
    appr.setSex((Custom::Sex)input);
    
    // Ask for valid input [old, young] local input
    appr.setAge((Custom::Age)input);
    
    // Ask for valid input [,] local input
    appr.setSkill((Custom::Skill)input);
    
    return appr;
}
