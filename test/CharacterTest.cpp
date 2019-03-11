#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Character.h"

TEST(CharacterTest, CreatingCharacter) {
    std::string username = "tester";
    Character testCharacter;
    testCharacter.createCharacter(username);
    
    EXPECT_EQ(username, testCharacter.getName());
}

TEST(CharacterTest, GetBaseAttributes) {
    std::string username = "tester";
    Character testCharacter;
    testCharacter.createCharacter(username);

    Attributes testAttributes;

    EXPECT_EQ(testAttributes.getHealth(), (testCharacter.getBaseAttributes()).getHealth());
}

TEST(CharacterTest, CharacterAliveOnCreate) {
    std::string username = "tester";
    Character testCharacter;
    testCharacter.createCharacter(username);

    EXPECT_TRUE(testCharacter.isAlive());
}

TEST(CharacterTest, CharacterDies) {
   std::string username = "tester";
   Character testCharacter;
   testCharacter.createCharacter(username);

   int damageToDo = testCharacter.getAttributes().getHealth() + 1;
   testCharacter.characterTakeDamage(damageToDo);

   EXPECT_FALSE(testCharacter.isAlive());
}
