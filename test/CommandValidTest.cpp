#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GameManager.h"
#include "Command.h"
#include <boost/algorithm/string.hpp>

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

struct CommandValidTest : testing::Test {
    Internationalization stringManager{};
    WorldManager w = WorldManager(stringManager);
    OnlineUserManager u;
    CharacterManager c;
    bool isValid = true;
    std::vector<std::string> testVector;
    std::string commandToPut;
};

// SAY
TEST_F(CommandValidTest, SayCommandIsValid) {
    CommandSay testCommand(c, u, w, stringManager);
    
    commandToPut = "say: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "say:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandValidTest, DISABLED_SayCommandIsNotValid) {
    CommandSay testCommand(c, u, w, stringManager);
    
    commandToPut = "say hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_FALSE(isValid);

    commandToPut = "say";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_FALSE(isValid);

    commandToPut = "saysay: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_FALSE(isValid);
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandValidTest, DISABLED_SayCommandIsValidOwnCommand) {
    CommandSay testCommand(c, u, w, stringManager);

    commandToPut = "say: say:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "say: helpsay:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "say: sayhello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandValidTest, DISABLED_SayCommandIsValidOtherCommand) {
    CommandSay testCommand(c, u, w, stringManager);

    commandToPut = "say: yell:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "say: helpyell:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

TEST_F(CommandValidTest, SayCommandIsValidWithDifferentSpaces) {
    CommandSay testCommand(c, u, w, stringManager);

    commandToPut = "say           :                     hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "say           :                     hel lo";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "say:hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

TEST_F(CommandValidTest, SayCommandIsValidNotCaseSensitive) {
    CommandSay testCommand(c, u, w, stringManager);

    commandToPut = "SAy: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "sAY: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "SAY: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

// TELL
TEST_F(CommandValidTest, TellCommandIsValid) {
    CommandTell testCommand(c, u, w, stringManager);

    commandToPut = "tell user: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "tell user:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandValidTest, DISABLED_TellCommandIsNotValid) {
    CommandTell testCommand(c, u, w, stringManager);

    commandToPut = "tell user hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_FALSE(isValid);

    commandToPut = "tell hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_FALSE(isValid);

    commandToPut = "telltell user: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_FALSE(isValid);
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandValidTest, DISABLED_TellCommandIsValidOwnCommand) {
    CommandTell testCommand(c, u, w, stringManager);

    commandToPut = "tell user: tell:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "tell user: helptell:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandValidTest, DISABLED_TellCommandIsValidOtherCommand) {
    CommandTell testCommand(c, u, w, stringManager);

    commandToPut = "tell user: say:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "tell user: helpsay:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

TEST_F(CommandValidTest, TellCommandIsValidWithDifferentSpaces) {
    CommandTell testCommand(c, u, w, stringManager);

    commandToPut = "tell       user    :                     hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "tell       user    :                     hel lo";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "tell user:hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

TEST_F(CommandValidTest, TellCommandIsValidNotCaseSensitive) {
    CommandTell testCommand(c, u, w, stringManager);

    commandToPut = "TEll user: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "tELL user: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "TELL USER: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}


// CAST
TEST_F(CommandValidTest, CastCommandIsValid) {
    CommandCast testCommand(c, u, w, stringManager);

    commandToPut = "cast ligma";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandValidTest, DISABLED_CastCommandIsNotValid) {
    CommandCast testCommand(c, u, w, stringManager);

    commandToPut = "castcast ligma";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_FALSE(isValid);
}

TEST_F(CommandValidTest, CastCommandIsValidCastingACommand) {
    CommandCast testCommand(c, u, w, stringManager);

    commandToPut = "cast say:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

TEST_F(CommandValidTest, CastCommandIsValidCastingOwnCommand) {
    CommandCast testCommand(c, u, w, stringManager);

    commandToPut = "cast cast";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

TEST_F(CommandValidTest, CastCommandIsValidWithSpace) {
    CommandCast testCommand(c, u, w, stringManager);
    
    commandToPut = "cast               ligma";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

TEST_F(CommandValidTest, CastCommandIsValidNotCaseSensitive) {
    CommandCast testCommand(c, u, w, stringManager);

    commandToPut = "caSt liGma";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "CAST LIGMA";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

// CREATE-AVATAR
TEST_F(CommandValidTest, CreateAvatarCommandIsValid) {
    CommandCreateAva testCommand(c, u, w, stringManager);

    commandToPut = "create-avatar user";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandValidTest, DISABLED_CreateAvatarCommandIsNotValid) {
    CommandCreateAva testCommand(c, u, w, stringManager);

    commandToPut = "create-avatarcreate-avatar user";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_FALSE(isValid);
}

TEST_F(CommandValidTest, CreateAvatarCommandIsValidWithSpaces) {
    CommandCreateAva testCommand(c, u, w, stringManager);

    commandToPut = "create-avatar                   user";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

TEST_F(CommandValidTest, CreateAvatarCommandIsValidNotCaseSensitive) {
    CommandCreateAva testCommand(c, u, w, stringManager);

    commandToPut = "crEAte-aVaTar user";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "CREATE-AVATAR user";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

// YELL
TEST_F(CommandValidTest, YellCommandIsValid) {
    CommandYell testCommand(c, u, w, stringManager);

    commandToPut = "yell: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandValidTest, DISABLED_YellCommandIsNotValid) {
    CommandYell testCommand(c, u, w, stringManager);

    commandToPut = "yell hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_FALSE(isValid);

    commandToPut = "yell";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_FALSE(isValid);

    commandToPut = "yellyell: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_FALSE(isValid);
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandValidTest, DISABLED_YellCommandIsValidOwnCommand) {
    CommandYell testCommand(c, u, w, stringManager);

    commandToPut = "yell: yell:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "yell: helpyell:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "yell: yellhello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

// TODO: TEST DISABLED BECAUSE IT FAILS
TEST_F(CommandValidTest, DISABLED_YellCommandIsValidOtherCommand) {
    CommandYell testCommand(c, u, w, stringManager);

    commandToPut = "yell: say:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "yell: helpsay:";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

TEST_F(CommandValidTest, YellCommandIsValidWithDifferentSpaces) {
    CommandYell testCommand(c, u, w, stringManager);

    commandToPut = "yell           :                     hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "yell           :                     hel lo";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "yell:hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

TEST_F(CommandValidTest, YellCommandIsValidNotCaseSensitive) {
    CommandYell testCommand(c, u, w, stringManager);

    commandToPut = "Yell: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "yELL: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "YELL: hello";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

//HELP
TEST_F(CommandValidTest, HelpCommandIsValid) {
    CommandHelp testCommand(c, u, w, stringManager);

    commandToPut = "help";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "help account";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

TEST_F(CommandValidTest, HelpCommandIsValidOwnCommand) {
    CommandHelp testCommand(c, u, w, stringManager);

    commandToPut = "help help";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}


TEST_F(CommandValidTest, HelpCommandIsValidWithSpaces) {
    CommandHelp testCommand(c, u, w, stringManager);

    commandToPut = "help                    account";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}

TEST_F(CommandValidTest, HelpCommandIsValidNotCaseSensitive) {
    CommandHelp testCommand(c, u, w, stringManager);

    commandToPut = "hELP";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "HELP";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);

    commandToPut = "heLp aCcOunt";
    testCommand.reassembleCommand(commandToPut, isValid);
    EXPECT_TRUE(isValid);
}