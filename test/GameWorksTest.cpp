#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GameManager.h"
#include "CharacterManager.h"

TEST(GameWorksTest, UserCanDoStuff) {
    std::string testUserName = "testUserName";
    std::string testUserPassword="testUserPassword";

    testGameManager.extractCommands(testUserName, "create-account " + testUserName + " " + testUserPassword);
    testGameManager.extractCommands(testUserName, "login " + testUserName + " " + testUserPassword);
    EXPECT_NE(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "say: this should not crash"));
    EXPECT_NE(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "yell: this should not crash either"));
    testGameManager.extractCommands(testUserName, "logout");
}