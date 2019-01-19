/////////////////////////////////////////////////////////////////////////////
//                        PlayerControlledCharacter
//
// This file is distributed under the MIT License. See the LICENSE file
// for details.
/////////////////////////////////////////////////////////////////////////////

#include "PlayerControlledCharacter.h"

PlayerControlledCharacter::~PlayerControlledCharacter() { }

void PlayerControlledCharacter::say(const std::string &str) {
    // Character *sender = this;
    // Room *room = this->currentRoom;
    
    // Send to all PlayerControlledCharacters in the room
}

void PlayerControlledCharacter::yell(const std::string &str) {
    // Character *sender = this;
    // Room *room = this->currentRoom;
    
    // Send to all PlayerControlledCharacters in the room and connected rooms
}

void PlayerControlledCharacter::tell(const std::string &str, Character *recv) {
    // Character *sender = this;
    // Room *room = this->currentRoom;
    
    // Send to recv
}
