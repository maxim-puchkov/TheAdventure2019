//
//  CollectionTests.cpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.CollectionTests
//
//  Created by mpuchkov on 2019-03-22. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include <stdio.h>


#include "gtest/gtest.h"
#include "gmock/gmock.h"




#include "Collection.h"
namespace objects {

using Keywords = KeywordSet;
using S = std::string;
using P = std::pair<S, S>;
using VS = std::vector<S>;
using VP = std::vector<P>;

/// ItemBuilderTests Fixture
class CollectionTests : public testing::Test {
protected:
    
    bool initialized = false;
    
    void SetUp() override {
        // Initial set up before each test...
        initialized = true;
        
        // Create 2 extra actions vectors (vectors of pairs of strings)
        S f  = "first",  s = "second";
        P p1 = P(f, s), p2 = P(s, f);
        VP vp1{p1, p2, p1, p2};
        VP vp2{p2, p1, p2, p1};
        extras_1 = vp1;
        extras_2 = vp2;
        
        
        // Create a test collection with containing item and capacity
        Keywords keywords({"treasury", "chest"});
        Description description("Collection is an item with a storage capacity");
        Item container(0, keywords, description, extras_1);
        unsigned int capacity = 30;
        empty_collection = Collection(container, capacity);
        
        
        // Create a test item
        Keywords item_keys({"test item key 1", "test item key 2"});
        Description item_desc("Item to add/remove from collections");
        Extras item_ex = extras_1;
        test_item = Item(0, item_keys, item_desc, item_ex);
    }
    
    void TearDown() override {
        // Test ends...
    }
    

    
    
    
    /* * *         Variables        * * */
    Extras extras_1;
    Extras extras_2;
    
    Collection empty_collection;
    Item test_item;
    
};









/* Object Fixture Tests */

// Testing test fixture set up
TEST_F(CollectionTests, FixtureInitialization) {
    EXPECT_TRUE(initialized);
}


// Testing item default instantiation
TEST_F(CollectionTests, Instantiation) {
    
    // Identifier
    Identifier id = 0;
    
    // Keywords
    string keyword1 = "Item";
    string keyword2 = "Second keyword";
    KeywordSet keywords({keyword1, keyword2});
    
    // Item description
    Description description("Item tests");
    
    // Extra actions
    Extras extras = extras_1;
    
    // Collection col(id, keywords, description, extras);
    
    
    // EXPECT_EQ(id, col.id());
    // EXPECT_EQ(keywords, col.keywords);
    // EXPECT_EQ(extras, col.actions());
    
}


/// Testing collection size
TEST_F(CollectionTests, Size) {
    Collection col = empty_collection;
    EXPECT_EQ(0, col.size());
}


/// Testing collection adding
TEST_F(CollectionTests, Add) {
    Collection col = empty_collection;
    for (int items_1_to_10 = 1; items_1_to_10 <= 10; items_1_to_10++) {
        col.add(test_item);
        EXPECT_EQ(items_1_to_10, col.size());
    }
}


/// Testing collection adding
TEST_F(CollectionTests, Remove) {
    Collection col = empty_collection;
    col.add(test_item);
    
    // col.remove(test_item);
    //
}

} /* namespace objects */
