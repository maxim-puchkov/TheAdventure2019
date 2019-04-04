//
//  HailstoneTests.cpp
//  
//
//  Created by admin on 2019-03-04.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Hailstone.h"



namespace sequence {



class HailstoneTests : public ::testing::Test {
protected:
    
    // Number computed during next while iteration
    uint64_t computeNext(uint64_t number) {
        return (number % 2 == 0) ?
            (number / 2) : (3 * number + 1);
    }
    
};





// Test n == 0
TEST_F(HailstoneTests, NotTriangle) {
    int number = 0;
    EXPECT_EQ(0, number);
}



}
