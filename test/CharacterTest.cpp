#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Character.h"

TEST(CharacterTests, CreatingCharacter) {
    std::string username = "tester";
    Character testCharacter;
    testCharacter.createCharacter(username);
    
    EXPECT_EQ(username, testCharacter.getName());
}

TEST(CharacterTests, GetBaseAttributes) {
    std::string username = "tester";
    Character testCharacter;
    testCharacter.createCharacter(username);

    Attributes testAttributes;

    EXPECT_EQ(testAttributes.getHealth(), (testCharacter.getBaseAttributes()).getHealth());
}

TEST(CharacterTests, CharacterAliveOrDeadDependingOnHealth) {
    std::string username = "tester";
    Character testCharacter;
    testCharacter.createCharacter(username);

    // Check if created character is created alive
    EXPECT_GT(0, (testCharacter.getAttributes()).getHealth());
    EXPECT_TRUE(testCharacter.isAlive());

    // WIP: add part that deals damage and kills character then checks if isAlive = false
}
