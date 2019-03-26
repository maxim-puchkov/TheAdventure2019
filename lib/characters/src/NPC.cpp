/////////////////////////////////////////////////////////////////////////////
//                        NPC
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "NPC.h"
#include <iostream>

NPC::~NPC() { }

NPC::NPC() : Character("Test NPC") {
    this->id = 8800;
    this->keywords = {"sylvan","elf","scout"};
    this->shortdesc = "a sylvan elf scout";
    this->longdesc = {"A Sylvan Elf scout is offended at your intrusion!"};
    this->description = {"The Sylvan Elves are a good people, but centuries of subjection to the",
        "violences and prejudices of other races have made them wary and very",
        "hostile toward outsiders. However, if you're tough enough, perhaps he'll",
        "back down. As natives of Mirkwood, they are virtually imposssible to see",
        "if they don't want to be seen."};
}

void NPC::debug(){
    std::cout << "NPC Name: " << this->getName() << "\n";
    std::cout << "keywords: \n";
    for (auto element: keywords) {
        std::cout << element << "\n";
    }
}
