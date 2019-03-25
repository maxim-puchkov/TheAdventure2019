//
//  ObjectTests.cpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.ObjectTests
//
//  Created by mpuchkov on 2019-03-21. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Item.h"
namespace objects {


using S = std::string;
using P = std::pair<S, S>;
using VS = std::vector<S>;
using VP = std::vector<P>;

/// ItemBuilderTests Fixture
class ItemTests : public testing::Test {
protected:
    
    void SetUp() override {
        // Initial set up before each test...
        initialized = true;
        
        S f  = "first",  s = "second";
        P p1 = P(f, s), p2 = P(s, f);
        VP vp1{p1, p2, p1, p2};
        VP vp2{p2, p1, p2, p1};
        
        extras_1 = vp1;
        extras_2 = vp2;
    }
    
    void TearDown() override {
        // Test ends...
    }
    

    
    
    
    /* * *         Variables        * * */
    bool initialized;
    Extras extras_1;
    Extras extras_2;
    
};









/* Object Fixture Tests */

// Testing test fixture set up
TEST_F(ItemTests, FixtureInitialization) {
    EXPECT_TRUE(initialized);
}


// Testing item default instantiation
TEST_F(ItemTests, Instantiation) {
    
    // Identifier
    Identifier id = 0;
    
    // Keywords
    string keyword1 = "Item";
    string keyword2 = "Second keyword";
    KeywordSet keywords({keyword1, keyword2});
    
    // Item description
    Description description("Item tests");
    
    // Extra actions
    Actions actions(extras_1);
    
    Item item = Item(id, keywords, description, actions);
    
    
    EXPECT_EQ(id, item.id());
    EXPECT_EQ(keywords, item.keywords);
    // EXPECT_EQ(actions, item.actions());
    
}


} /* namespace objects */
