#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GameManager.h"

GameManager testGameManager{};
std::string fakeUser = "fakeUser";
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

TEST(CommandsTest, CommandNotCorrectSyntax) {
    std::string testCommand1 = "say yes :";
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(fakeUser, testCommand1));
}

TEST(CommandsTest, CommandsSuccessfullyRecognized) {
    for (int i = 0; i < listOfCommands.size(); i++) {
        EXPECT_NE(commandNotFoundString, testGameManager.extractCommands(fakeUser, listOfCommands[i]));
    }
}

TEST(CommandsTest, SayCommand) {
    std::string testCommand1 = "say: test";
    std::string testCommand2 = "      sAy     :    ssdw     a  test ";
    std::string testCommand3 = "SAY: testSAY:";
    std::string testCommand4 = "say: say:";
    std::string testCommand5 = "say: tell:";
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(fakeUser, testCommand1));
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(fakeUser, testCommand2));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(fakeUser, testCommand3));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(fakeUser, testCommand4));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(fakeUser, testCommand5));
}

TEST(CommandsTest, TellCommand) {
    std::string testCommand1 = "tell asdadw : test";
    std::string testCommand2 = "      tElL     userstest:    car     a  test ";
    std::string testCommand3 = "TELL  user : testTELL:";
    std::string testCommand4 = "tell   a : tell:";
    std::string testCommand5 = "tell: say:";
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(fakeUser, testCommand1));
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(fakeUser, testCommand2));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(fakeUser, testCommand3));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(fakeUser, testCommand4));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(fakeUser, testCommand5));
}

TEST(CommandsTest, YellCommand) {
    std::string testCommand1 = "yell: test";
    std::string testCommand2 = "      yELl     :    ssdw     a  test ";
    std::string testCommand3 = "YELL: testYELL:";
    std::string testCommand4 = "yell: yell:";
    std::string testCommand5 = "yell: tell:";
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(fakeUser, testCommand1));
    EXPECT_EQ(commandUserNotOnlineString, testGameManager.extractCommands(fakeUser, testCommand2));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(fakeUser, testCommand3));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(fakeUser, testCommand4));
    EXPECT_EQ(commandNotCorrectSyntaxString, testGameManager.extractCommands(fakeUser, testCommand5));
}