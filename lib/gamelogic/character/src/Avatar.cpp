/////////////////////////////////////////////////////////////////////////////
//                                  Avatar
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Avatar.h"

Avatar::Avatar() {
    this->init();
    
    // Ask for valid input
    this->name = "ask for input";
    this->appearance = this->createCustomAppearance();
}

Avatar::Avatar(const std::string &name) {
    this->init();
    this->name = name;
    this->appearance = this->createCustomAppearance();
}

Avatar::Avatar(const std::string &name, const Custom::Appearance &appearance) {
    this->init();
    this->name = name;
    this->appearance = appearance;
}

Avatar::~Avatar() { }

void Avatar::init() {
    this->name = DEF_AVATAR_NAME;
    this->baseAttr = Attributes(DEF_AVATAR_HEALTH, DEF_AVATAR_DAMAGE);
    this->inventory = Inventory();
    this->equipment = Equipment();
}

Custom::Appearance Avatar::createCustomAppearance() {
    Custom::Appearance appr;
    int input = 0;
    
    // Ask for valid input
    appr.setSex((Custom::Sex)input);
    
    // Ask for valid input [old, young]
    appr.setAge((Custom::Age)input);
    
    // Ask for valid input
    appr.setSkill((Custom::Skill)input);
    
    return appr;
}
