#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "AttributesTest.cpp"
#include "CharacterTest.cpp"
#include "CommandsTest.cpp"
#include "GameWorksTest.cpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}