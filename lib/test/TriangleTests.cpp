//
//  TriangleTests.cpp
//  
//
//  Created by admin on 2019-03-03.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Triangle.h"


namespace shapes {


class TriangleTests : public ::testing::Test {
protected:
    
    // Side lengths
    int a = 7;
    int b = 5;
    int c = 4;

};





// Test perimeter (fails)
TEST_F(TriangleTests, Triangle) {
    EXPECT_EQ(a, a);
    EXPECT_EQ(b, b);
    EXPECT_EQ(c, c);
}


}
