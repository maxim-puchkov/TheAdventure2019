#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GameManager.h"

struct CommandsTest : testing::Test {
    GameManager testGameManager{};
    std::string testUserName = "testUserName";
    std::string testUserPassword = "testUserPassword";
    std::string commandNotCorrectSyntaxString = "Wrong command syntax. Please enter \"help\" to see the syntax.\n";
    std::string commandNotFoundString = "Command not found. Please enter \"help\" to see the syntax.\n";
    std::string commandUserNotOnlineString = "User is not online.\n";
    std::vector<std::string> listOfCommands {
                                        "login",
                                        "logout",
                                        "create-account",
                                        "help",
                                        "say",
                                        "tell",
                                        "yell",
                                        "look",
                                        "examine",
                                        "move",
                                        "create-avatar",
                                        "edit-avatar",
                                        "create-room",
                                        "edit-room",
                                        "use",
                                        "equip",
                                        "pickup",
                                        "drop",
                                        "put",
                                        "minigame",
                                        "combat",
                                        "attack",
                                        "flee",
                                        "cast"
                                        };
};

TEST_F(CommandsTest, CommandsSuccessfullyRecognized) {
    for (int i = 0; i < listOfCommands.size(); i++) {
        EXPECT_NE(commandNotFoundString, testGameManager.extractCommands(testUserName, listOfCommands[i]));
    }
}

TEST_F(CommandsTest, SayCommand) {
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "say: test"));
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "      sAy     :    ssdw     a  test "));
}

TEST_F(CommandsTest, TellCommand) {
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "tell auserasd : test"));
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "      tElL     userstest:    car     a  test "));
}

TEST_F(CommandsTest, YellCommand) {
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "yell: test"));
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "      yElL     :    ssdw     a  test "));
}

TEST_F(CommandsTest, UserCanDoStuff) {
    testGameManager.extractCommands(testUserName, "create-account " + testUserName + " " + testUserPassword);
    testGameManager.extractCommands(testUserName, "login " + testUserName + " " + testUserPassword);
    EXPECT_NE(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "say: this should not crash"));
    EXPECT_NE(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "yell: this should not crash either"));
    EXPECT_NE(commandNotFoundString, testGameManager.extractCommands(testUserName, "say: this command should work"));
    EXPECT_NE(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "say: this command should work"));
    testGameManager.extractCommands(testUserName, "logout");
}

TEST_F(CommandsTest, CommandNotCorrectSyntaxLoggedIn) {
    testGameManager.extractCommands(testUserName, "create-account " + testUserName + " " + testUserPassword);
    testGameManager.extractCommands(testUserName, "login " + testUserName + " " + testUserPassword);
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "say   s s : ss"));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "tell   s s : ss"));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "yell   s s : ss"));
}
