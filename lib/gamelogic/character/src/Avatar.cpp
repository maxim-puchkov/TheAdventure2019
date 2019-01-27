/////////////////////////////////////////////////////////////////////////////
//                                  Avatar
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Avatar.h"
#include <iostream>

Avatar::Avatar() {
    this->init();
    this->createOnFirstLogin();
}

/*
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
 */

Avatar::~Avatar() { }

void Avatar::init() {
    this->createCharacter("< Test_Avatar >");
    
    std::cout << "Character with name " + this->getName() + " created!\n";
}

void Avatar::createOnFirstLogin() {
    this->appearance = this->createCustomAppearance();
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
