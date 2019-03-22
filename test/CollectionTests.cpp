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
        
        collection10 = Collection(container, 10);
        Description vec10_desc("10 different items");
        for (unsigned int count = 0; count < 10; count++) {
            Keywords k({"vec10 item #" + std::to_string(count)});
            Item item = Item(count, keywords, vec10_desc, extras_1);
            vec10_items.push_back(item);
            collection10.insert(item);
        }
        
        
    }
    
    void TearDown() override {
        // Test ends...
    }
    

    
    
    
    /* * *         Variables        * * */
    Collection empty_collection;    // no items
    Collection collection10;        // 10 items
    
    Item test_item;
    
    Extras extras_1;
    Extras extras_2;
    vector<Item> vec10_items;
    
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


/// Testing collection insert
TEST_F(CollectionTests, Insert) {
    Collection col = empty_collection;
    EXPECT_EQ(0, col.size());
    for (int count = 1; count <= vec10_items.size(); count++) {
        col.insert(vec10_items[count - 1]);
        EXPECT_EQ(count, col.size());
    }
}


///// Testing collection erase
//TEST_F(CollectionTests, Erase) {
//    Collection col = collection10;
//    // EXPECT_EQ(10, col.size());
//    for (int count = vec10_items.size() + 1; count > 1; count--) {
//        col.erase(vec10_items[count - 1]);
//        EXPECT_EQ(count, col.size());
//    }
//}


} /* namespace objects */
