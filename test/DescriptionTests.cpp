//
//  DescriptionTests.cpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.DescriptionTests
//
//  Created by mpuchkov on 2019-03-24. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//


#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Description.h"

namespace objects {


/// ItemBuilderTests Fixture
class DescriptionTests : public testing::Test {
    protected:
    
    bool initialized = false;
    
    void SetUp() override {
        // Initial set up before each test...
        initialized = true;
    }
    
    void TearDown() override {
        // Test ends...
    }
    
    
    
    
    
    /* * *         Variables        * * */
    
};









/* Inventory Fixture Tests */

// Testing test fixture set up
TEST_F(DescriptionTests, FixtureInitialization) {
    EXPECT_TRUE(initialized);
}


// Testing lines partitioning
TEST_F(DescriptionTests, Partition) {
    
    Text source = "break break break break";
    unsigned short width = 5;
    
    
    Description desc(source, width);
    
}


} /* namespace objects */
