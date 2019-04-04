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
TEST_F(HailstoneTests, numIsZero) {
    int number = 0;
    EXPECT_EQ(0, number);
}


// Test n != 0
TEST_F(HailstoneTests, numIsNonZero) {
    int number = 4;
    EXPECT_NE(0, number);
}


// Test n == 1
TEST_F(HailstoneTests, numIsOne) {
    int number = 1;
    EXPECT_EQ(1, number);
}


// Test result
TEST_F(HailstoneTests, returnValue) {
    int number = 0;
    EXPECT_EQ(!(number == 0), satisfiesHailstone(number));
}


// Test 'if-else' division
TEST_F(HailstoneTests, division) {
    int number = 6;
    int next = computeNext(number);
    
    EXPECT_EQ(0, number % 2);
    EXPECT_EQ(next, number / 2);
}


// Test 'else' multiplication
TEST_F(HailstoneTests, multiplication) {
    int number = 5;
    int next = computeNext(number);
    
    EXPECT_EQ(1, number % 2);
    EXPECT_EQ(next, 3 * number + 1);
}



}
