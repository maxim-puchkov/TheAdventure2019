#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GameManager.h"
#include "Command.h"
#include <boost/algorithm/string.hpp>

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

struct CommandsTest : testing::Test {
    GameManager testGameManager{};
    std::string testUserName = "testUserName19238021";
    std::string testUserPassword = "testUserPassword";
    //std::string testUserName = "a";
    //std::string testUserPassword = "s";
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
    OnlineUserManager u;
    CharacterManager c;
    WorldManager w;
    bool isValid = true;
    std::vector<std::string> testVector;
    std::string commandToPut;
};

class MockCommandSay : public CommandSay{
public:
    MockCommandSay(CharacterManager& c, OnlineUserManager& u, WorldManager& w) : CommandSay(c, u, w) {}
    MOCK_METHOD2(reassembleCommand, std::vector<std::string>(std::string& fullCommand, bool& commandIsValid));
    MOCK_METHOD2(executePromptReply, std::string(const std::string& connectionID, const std::vector<std::string>& fullCommand));
    MOCK_METHOD2(executeInHeartbeat, void(const std::string& username, const std::vector<std::string>& fullCommand));
};

// TODO: Test does not work correctly. EXPECT_CALL cannot detect if function was called
/*
TEST_F(CommandsTest, SayCommandWorks) {
    OnlineUserManager u;
    CharacterManager c;
    WorldManager w;
    MockCommandSay mockCommandSay(c, u, w);
    std::string commandToPut = "say: hello";
    bool isCommandValid = true;
    testGameManager.extractCommands(
        testUserName,
        "create-account " + testUserName + " " + testUserPassword
    );
    testGameManager.extractCommands(
        testUserName,
        "login " + testUserName + " " + testUserPassword
    );
    EXPECT_CALL(mockCommandSay, reassembleCommand(commandToPut, isCommandValid)).Times(0);
    testGameManager.extractCommands(testUserName, commandToPut);
}
*/
/*
TEST_F(CommandsTest, AttackCommandSplitsCorrectly) {
    CommandSay testCommand(c, u, w);
    commandToPut = "attack";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);

    EXPECT_EQ("attack", testVector.at(0));
}
*/
TEST_F(CommandsTest, SayCommandSplitsCorrectly) {
    CommandSay testCommand(c, u, w);
    commandToPut = "say: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));
}

TEST_F(CommandsTest, SayCommandSplitsCorrectlyWithDifferentSpaces) {
    CommandSay testCommand(c, u, w);
    commandToPut = "say           :                     hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));

    commandToPut = "say:hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));
}

TEST_F(CommandsTest, SayCommandSplitsCorrectlyNotCaseSensitive) {
    CommandSay testCommand(c, u, w);
    commandToPut = "SAy: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));

    commandToPut = "sAY: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));

    commandToPut = "SAY: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));
}

TEST_F(CommandsTest, TellCommandSplitsCorrectly) {
    CommandSay testCommand(c, u, w);
    commandToPut = "tell user: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    // TODO: LOOK AT THIS 
    // EXPECT_EQ("hello", testVector.at(2));
}

TEST_F(CommandsTest, TellCommandSplitsCorrectlyWithDifferentSpaces) {
    CommandSay testCommand(c, u, w);
    commandToPut = "tell       user    :                     hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));

    commandToPut = "tell user:hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
}

TEST_F(CommandsTest, TellCommandSplitsCorrectlyNotCaseSensitive) {
    CommandSay testCommand(c, u, w);
    commandToPut = "TEll user: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));

    commandToPut = "tELL user: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));

    commandToPut = "TELL USER: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
}

/*
TEST_F(CommandsTest, CastCommandSplitsCorrectly) {
    CommandSay testCommand(c, u, w);
    commandToPut = "cast ligma";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);

    EXPECT_EQ("cast", testVector.at(0));
    EXPECT_EQ("ligma", testVector.at(1));
}

TEST_F(CommandsTest, CreateAvatarCommandSplitsCorrectly) {
    CommandSay testCommand(c, u, w);
    commandToPut = "create-avatar user";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);

    EXPECT_EQ("create-avatar", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
}
*/
TEST_F(CommandsTest, YellCommandSplitsCorrectly) {
    CommandSay testCommand(c, u, w);
    commandToPut = "yell: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);

    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));
}

TEST_F(CommandsTest, YellCommandSplitsCorrectlyWithDifferentSpaces) {
    CommandSay testCommand(c, u, w);
    commandToPut = "yell           :                     hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));

    commandToPut = "yell:hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));
}

TEST_F(CommandsTest, YellCommandSplitsCorrectlyNotCaseSensitive) {
    CommandSay testCommand(c, u, w);
    commandToPut = "Yell: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));

    commandToPut = "yELL: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));

    commandToPut = "YELL: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));
}

/*
TEST_F(CommandsTest, HelpCommandSplitsCorrectly) {
    CommandSay testCommand(c, u, w);
    commandToPut = "help";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);

    EXPECT_EQ("help", testVector.at(0));
}
*/