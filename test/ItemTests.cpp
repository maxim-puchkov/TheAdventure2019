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


namespace items {


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
        
//        string actionKey = "action";
//        string actionDesc = "A description";
//        action = {{actionKey, actionDesc}};
    }
    
    void TearDown() override {
        // Test ends...
    }
    

    
    
    
    /* * *         Variables        * * */
    bool initialized;
    // Extras extras_1;
    // Extras extras_2;
    
//    vector<std::pair<string, string>> action;
    
};









///* Object Fixture Tests */
//
//// Testing test fixture set up
//TEST_F(ItemTests, FixtureInitialization) {
//    EXPECT_TRUE(initialized);
//}
//
//
//// Testing item default instantiation
//TEST_F(ItemTests, Instantiation) {
//    
//    // Identifier
//    Identifier id = 0;
//    
//    // Keywords
//    string keyword1 = "Item";
//    string keyword2 = "Second keyword";
//    Keywords keywords({keyword1, keyword2});
//    
//    // Item description
//    Description description("Item tests");
//    
//    // Extra actions
//    Actions actions(action);
//    
//    Item item = Item(keywords, description, actions);
//    
//    
//    EXPECT_EQ(id, item.id());
//    EXPECT_EQ(keywords, item.keywords);
//    // EXPECT_EQ(actions, item.actions());
//    
//}


} /* namespace items */
