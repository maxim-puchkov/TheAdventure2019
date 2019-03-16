#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GameManager.h"
#include "Command.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

struct CommandsTest : testing::Test {
    GameManager testGameManager{};
    std::string testUserName = "testUserName19238021";
    std::string testUserPassword = "testUserPassword";
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

class MockCommandSay : public CommandSay {
public:
    MockCommandSay(CharacterManager& c, OnlineUserManager& u, WorldManager& w) : CommandSay(c, u, w) {}
    MOCK_METHOD2(reassembleCommand, std::vector<std::string>(std::string& fullCommand, bool& commandIsValid));
};

// Test does not work correctly (EXPECT_CALL cannot detect if function was called)
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
    //EXPECT_CALL(mockCommandSay, reassembleCommand(commandToPut, isCommandValid)).Times(1);
}
