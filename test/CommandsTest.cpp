#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GameManager.h"

struct CommandsTest : testing::Test {
    GameManager testGameManager{};
    std::string testUserName = "testUserName19238021";
    std::string testUserPassword = "testUserPassword";
    std::string commandNotCorrectSyntaxString =
        "Wrong command syntax. Please enter \"help\" to see the syntax.\n";
    std::string commandNotFoundString =
        "Command not found. Please enter \"help\" to see the syntax.\n";
    std::string commandUserNotOnlineString =
        "User is not online.\n";
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

class MockGameManager : public GameManager {
public:
    MOCK_METHOD2(extractCommands, std::string(const std::string& connectionID, std::string fullCommand));
};

TEST_F(CommandsTest, SayCommandWorks) {
    MockGameManager mockGameManager;
    testGameManager.extractCommands(
        testUserName,
        "create-account " + testUserName + " " + testUserPassword
    );
    testGameManager.extractCommands(
        testUserName,
        "login " + testUserName + " " + testUserPassword
    );
    EXPECT_CALL(mockGameManager, extractCommands(testUserName, testUserName));
    // TODO: instead of checking if extractCommands is called, try to go deeper
    testGameManager.extractCommands(
        testUserName, testUserName
    );


}


/*
TEST_F(CommandsTest, CommandsSuccessfullyRecognized) {
    for (int i = 0; i < listOfCommands.size(); i++) {
        EXPECT_NE(commandNotFoundString,
            testGameManager.extractCommands(testUserName, listOfCommands[i]));
    }
}

TEST_F(CommandsTest, SayCommand) {
    MockGameManager mockGameManager;

    std::vector<std::string> testList = {
        "create-account " + testUserName + " " + testUserPassword,
        "login " + testUserName + " " + testUserPassword,
        "say: test",
        " sAy : ssdw     a  test "
    };

    EXPECT_CALL(mockGameManager, extractCommands(const std::string& connectionID, std::string fullCommand))
        .Times(4)
        .WillOnce(Re)

    testGameManager.extractCommands(
        testUserName,
        "create-account " + testUserName + " " + testUserPassword
    );
    testGameManager.extractCommands(
        testUserName,
        "login " + testUserName + " " + testUserPassword
    );

    EXPECT_EQ(commandUserNotOnlineString,  
        testGameManager.extractCommands(testUserName, "say: test"));
    EXPECT_EQ(commandUserNotOnlineString,
        testGameManager.extractCommands(testUserName, " sAy : ssdw     a  test "));
}
*/
// testGameManager.extractCommands(testUserName, "create-account " + testUserName + " " + testUserPassword);
// testGameManager.extractCommands(testUserName, "login " + testUserName + " " + testUserPassword);
