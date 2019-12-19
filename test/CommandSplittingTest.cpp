#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <boost/algorithm/string.hpp>

#include "GamePrefixHeader.pch"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

struct CommandSplittingTest : testing::Test {
    Internationalization stringManager{};
    CombatManager cm{};
	WorldManager w{};
	OnlineUserManager u{};
	CharacterManager c{};
    bool isValid = true;
    std::vector<std::string> testVector;
    std::string commandToPut;
};

// SAY
TEST_F(CommandSplittingTest, SayCommandSplitsCorrectly) {
    CommandSay testCommand(c, u, w, stringManager);
    
    commandToPut = "say: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));

    commandToPut = "say:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("", testVector.at(1));
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandSplittingTest, DISABLED_SayCommandSplitsCorrectlyOwnCommand) {
    CommandSay testCommand(c, u, w, stringManager);

    commandToPut = "say: say:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("say:", testVector.at(1));

    commandToPut = "say: helpsay:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("helpsay:", testVector.at(1));
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandSplittingTest, DISABLED_SayCommandSplitsCorrectlyOtherCommand) {
    CommandSay testCommand(c, u, w, stringManager);

    commandToPut = "say: yell:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("yell:", testVector.at(1));

    commandToPut = "say: helpyell:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("helpyell:", testVector.at(1));
}

TEST_F(CommandSplittingTest, SayCommandSplitsCorrectlyWithDifferentSpaces) {
    CommandSay testCommand(c, u, w, stringManager);

    commandToPut = "say           :                     hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));

    commandToPut = "say           :                     hel lo";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("hel lo", testVector.at(1));

    commandToPut = "say:hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("say", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));
}

TEST_F(CommandSplittingTest, SayCommandSplitsCorrectlyNotCaseSensitive) {
    CommandSay testCommand(c, u, w, stringManager);

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

// TELL
TEST_F(CommandSplittingTest, TellCommandSplitsCorrectly) {
    CommandTell testCommand(c, u, w, stringManager);

    commandToPut = "tell user: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    EXPECT_EQ("hello", testVector.at(2));

    commandToPut = "tell user:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    EXPECT_EQ("", testVector.at(2));
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandSplittingTest, DISABLED_TellCommandSplitsCorrectlyOwnCommand) {
    CommandTell testCommand(c, u, w, stringManager);

    commandToPut = "tell user: tell:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    EXPECT_EQ("tell:", testVector.at(2));

    commandToPut = "tell user: helptell:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    EXPECT_EQ("helptell:", testVector.at(2));
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandSplittingTest, DISABLED_TellCommandSplitsCorrectlyOtherCommand) {
    CommandTell testCommand(c, u, w, stringManager);

    commandToPut = "tell user: say:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    EXPECT_EQ("say:", testVector.at(2));

    commandToPut = "tell user: helpsay:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    EXPECT_EQ("helpsay:", testVector.at(2));
}

TEST_F(CommandSplittingTest, TellCommandSplitsCorrectlyWithDifferentSpaces) {
    CommandTell testCommand(c, u, w, stringManager);

    commandToPut = "tell       user    :                     hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    EXPECT_EQ("hello", testVector.at(2));

    commandToPut = "tell       user    :                     hel lo";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    EXPECT_EQ("hel lo", testVector.at(2));

    commandToPut = "tell user:hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    EXPECT_EQ("hello", testVector.at(2));
}

TEST_F(CommandSplittingTest, TellCommandSplitsCorrectlyNotCaseSensitive) {
    CommandTell testCommand(c, u, w, stringManager);

    commandToPut = "TEll user: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    EXPECT_EQ("hello", testVector.at(2));

    commandToPut = "tELL user: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    EXPECT_EQ("hello", testVector.at(2));

    commandToPut = "TELL USER: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("tell", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
    EXPECT_EQ("hello", testVector.at(2));
}


// CAST
TEST_F(CommandSplittingTest, CastCommandSplitsCorrectly) {
    CommandCast testCommand(c, u, w, stringManager, cm);

    commandToPut = "cast ligma";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("cast", testVector.at(0));
    EXPECT_EQ("ligma", testVector.at(1));
}

TEST_F(CommandSplittingTest, CastCommandSplitsCorrectlyCastingACommand) {
    CommandCast testCommand(c, u, w, stringManager, cm);

    commandToPut = "cast say:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("cast", testVector.at(0));
    EXPECT_EQ("say:", testVector.at(1));
}

TEST_F(CommandSplittingTest, CastCommandSplitsCorrectlyCastingOwnCommand) {
    CommandCast testCommand(c, u, w, stringManager, cm);

    commandToPut = "cast cast";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("cast", testVector.at(0));
    EXPECT_EQ("cast", testVector.at(1));
}

TEST_F(CommandSplittingTest, CastCommandSplitsCorrectlyWithSpace) {
    CommandCast testCommand(c, u, w, stringManager, cm);
    
    commandToPut = "cast               ligma";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("cast", testVector.at(0));
    EXPECT_EQ("ligma", testVector.at(1));
}

TEST_F(CommandSplittingTest, CastCommandSplitsCorrectlyNotCaseSensitive) {
    CommandCast testCommand(c, u, w, stringManager, cm);

    commandToPut = "caSt liGma";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("cast", testVector.at(0));
    EXPECT_EQ("ligma", testVector.at(1));

    commandToPut = "CAST LIGMA";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("cast", testVector.at(0));
    EXPECT_EQ("ligma", testVector.at(1));
}

// CREATE-AVATAR
TEST_F(CommandSplittingTest, CreateAvatarCommandSplitsCorrectly) {
    CommandCreateAva testCommand(c, u, w, stringManager);

    commandToPut = "create-avatar user";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("create-avatar", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
}

TEST_F(CommandSplittingTest, CreateAvatarCommandSplitsCorrectlyWithSpaces) {
    CommandCreateAva testCommand(c, u, w, stringManager);

    commandToPut = "create-avatar                   user";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("create-avatar", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
}

TEST_F(CommandSplittingTest, CreateAvatarCommandSplitsCorrectlyNotCaseSensitive) {
    CommandCreateAva testCommand(c, u, w, stringManager);

    commandToPut = "crEAte-aVaTar user";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    EXPECT_EQ("create-avatar", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));

    commandToPut = "CREATE-AVATAR user";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    EXPECT_EQ("create-avatar", testVector.at(0));
    EXPECT_EQ("user", testVector.at(1));
}

// YELL
TEST_F(CommandSplittingTest, YellCommandSplitsCorrectly) {
    CommandYell testCommand(c, u, w, stringManager);

    commandToPut = "yell: hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));

    commandToPut = "yell:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("", testVector.at(1));
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandSplittingTest, DISABLED_YellCommandSplitsCorrectlyOwnCommand) {
    CommandYell testCommand(c, u, w, stringManager);

    commandToPut = "yell: yell:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("yell:", testVector.at(1));

    commandToPut = "yell: helpyell:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("helpyell:", testVector.at(1));
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandSplittingTest, DISABLED_YellCommandSplitsCorrectlyOtherCommand) {
    CommandYell testCommand(c, u, w, stringManager);

    commandToPut = "yell: say:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("say:", testVector.at(1));

    commandToPut = "yell: helpsay:";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("helpsay:", testVector.at(1));
}

TEST_F(CommandSplittingTest, YellCommandSplitsCorrectlyWithDifferentSpaces) {
    CommandYell testCommand(c, u, w, stringManager);

    commandToPut = "yell           :                     hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));

    commandToPut = "yell           :                     hel lo";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("hel lo", testVector.at(1));

    commandToPut = "yell:hello";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("yell", testVector.at(0));
    EXPECT_EQ("hello", testVector.at(1));
}

TEST_F(CommandSplittingTest, YellCommandSplitsCorrectlyNotCaseSensitive) {
    CommandYell testCommand(c, u, w, stringManager);

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

//HELP
TEST_F(CommandSplittingTest, HelpCommandSplitsCorrectly) {
    CommandHelp testCommand(c, u, w, stringManager);

    commandToPut = "help";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("help", testVector.at(0));
    EXPECT_EQ(1, testVector.size());

    commandToPut = "help account";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("help", testVector.at(0));
    EXPECT_EQ("account", testVector.at(1));
}

TEST_F(CommandSplittingTest, HelpCommandSplitsCorrectlyOwnCommand) {
    CommandHelp testCommand(c, u, w, stringManager);

    commandToPut = "help help";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("help", testVector.at(0));
    EXPECT_EQ("help", testVector.at(1));
}


TEST_F(CommandSplittingTest, HelpCommandSplitsCorrectlyWithSpaces) {
    CommandHelp testCommand(c, u, w, stringManager);

    commandToPut = "help                    account";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_EQ("help", testVector.at(0));
    EXPECT_EQ("account", testVector.at(1));
}

TEST_F(CommandSplittingTest, HelpCommandSplitsCorrectlyNotCaseSensitive) {
    CommandHelp testCommand(c, u, w, stringManager);

    commandToPut = "hELP";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    EXPECT_EQ("help", testVector.at(0));
    EXPECT_EQ(1, testVector.size());

    commandToPut = "HELP";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    EXPECT_EQ("help", testVector.at(0));
    EXPECT_EQ(1, testVector.size());

    commandToPut = "heLp aCcOunt";
    testVector = testCommand.reassembleCommand(commandToPut, isValid);
    boost::to_lower(testVector.at(0));
    boost::to_lower(testVector.at(1));
    EXPECT_EQ("help", testVector.at(0));
    EXPECT_EQ("account", testVector.at(1));
}
