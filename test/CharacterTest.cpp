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

TEST(CharacterTests, CharacterAliveOnCreate) {
    std::string username = "tester";
    Character testCharacter;
    testCharacter.createCharacter(username);

    EXPECT_TRUE(testCharacter.isAlive());
}

TEST(CharacterTests, CharacterDies) {
    std::string username = "tester";
    Character testCharacter;
    testCharacter.createCharacter(username);

    testCharacter.doDamageToCharacter((testCharacter.getAttributes()).getHealth() + 1);
    EXPECT_FALSE(testCharacter.isAlive());
}
