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

TEST_F(CommandsTest, CommandNotCorrectSyntax) {
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "say yes :"));
}

TEST_F(CommandsTest, CommandsSuccessfullyRecognized) {
    for (int i = 0; i < listOfCommands.size(); i++) {
        EXPECT_NE(commandNotFoundString, testGameManager.extractCommands(testUserName, listOfCommands[i]));
    }
}

TEST_F(CommandsTest, SayCommand) {
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "say: test"));
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "      sAy     :    ssdw     a  test "));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "SAY: testSAY:"));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "say: say:"));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "say: tell:"));
}

TEST_F(CommandsTest, TellCommand) {
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "tell auserasd : test"));
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "      tElL     userstest:    car     a  test "));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "TELL    usesadr: testTELL:"));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "tell   a: tell:"));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "tell: yell:"));
}

TEST_F(CommandsTest, YellCommand) {
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "yell: test"));
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(testUserName, "      yElL     :    ssdw     a  test "));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "YELL: testYELL:"));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "yell: yell:"));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "yell: tell:"));
}

TEST_F(CommandsTest, UserCanDoStuff) {
    testGameManager.extractCommands(testUserName, "create-account " + testUserName + " " + testUserPassword);
    testGameManager.extractCommands(testUserName, "login " + testUserName + " " + testUserPassword);
    EXPECT_NE(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "say: this should not crash"));
    EXPECT_NE(commandNotCorrectSyntaxString, testGameManager.extractCommands(testUserName, "yell: this should not crash either"));
    testGameManager.extractCommands(testUserName, "logout");
}
