/////////////////////////////////////////////////////////////////////////////
//                                  Avatar
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "Avatar.h"
#include <iostream>

/*
Avatar::Avatar() {
    this->createCharacter("< Test_Avatar >");
    this->createOnFirstLogin();
}
*/


Avatar::Avatar(string &&name) {
    this->createCharacter(std::move(name));
    this->createOnFirstLogin();
    
    // std::cout << "Debug: Character with name " + this->getName() + " created! -> (c string&) \n";
}


Avatar::Avatar(string &&name, Custom::Appearance &&appearance) {
    this->createCharacter(std::move(name));
    this->appearance = appearance;
    
    
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
