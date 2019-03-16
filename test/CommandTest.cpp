#include "gtest/gtest.h"
#include "gmock/gmock.h"

struct CommandTest : testing::Test {
    bool isValid = true;
    std::vector<std::string> testVector;
    std::string commandToPut;
};

