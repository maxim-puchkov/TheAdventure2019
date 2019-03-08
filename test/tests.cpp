#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Attributes.h"


TEST(AttributesTest, pipelinetest) {
    EXPECT_TRUE(true);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}