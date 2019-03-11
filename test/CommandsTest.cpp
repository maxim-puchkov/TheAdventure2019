#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GameManager.h"

TEST(CommandsTest, SayCommandFound) {
    std::string fakeUser = "fakeuser";
    std::string commandNotFoundString = "Command not found\n";
    std::string testCommand1 = "say: test";
    std::string testCommand2 = "      sAy     :    ssdw     a  test ";
    std::string testCommand3 = "fail test";
    GameManager testObject{};
    EXPECT_NE(commandNotFoundString, testObject.extractCommands(fakeUser, testCommand1));
    EXPECT_NE(commandNotFoundString, testObject.extractCommands(fakeUser, testCommand2));
    EXPECT_EQ(commandNotFoundString, testObject.extractCommands(fakeUser, testCommand3));
}