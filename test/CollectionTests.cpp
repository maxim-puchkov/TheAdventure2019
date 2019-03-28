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


namespace items {


/// ItemBuilderTests Fixture
class CollectionTests : public testing::Test {
protected:
    
    bool initialized = false;
    
    void SetUp() override {
        // Initial set up before each test...
        initialized = true;
        
        
        // Create an action
        string actionKey = "action";
        string actionDesc = "A description";
        vector<pair<string, string>> action{{actionKey, actionDesc}};
        actions_1 = Actions(action);
        
        
        
        
        // Create a test collection with containing item and capacity
        Keywords keywords({"treasury", "chest"});
        Description description("Collection is an item with a storage capacity");
        Item container(0, keywords, description, actions_1);
        unsigned int capacity = 30;
        empty_collection = Collection(container, capacity);
        
        
        
        
        // Create a test item
        Keywords item_keys({"test item key 1", "test item key 2"});
        Description item_desc("Item to add/remove from collections");
        test_item = Item(0, item_keys, item_desc, actions_1);
        
        
        
        // Create test collection
        collection10 = Collection(container, 10);
        Description vec10_desc("10 different items");
        for (unsigned int count = 0; count < 10; count++) {
            Keywords k({"vec10 item #" + std::to_string(count)});
            Item item = Item(count, keywords, vec10_desc, actions_1);
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
    
    Actions actions_1;
    
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
    Keywords keywords({keyword1, keyword2});
    
    // Item description
    Description description("Item tests");
    
    // Extra actions
    Actions actions = actions_1;
    
    // Collection col(id, keywords, description, actions);
    
    
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
    for (int count = 0; count < vec10_items.size(); count++) {
        col.insert(vec10_items[count]);
        EXPECT_EQ(count + 1, col.size());
    }
}


/// Testing collection erase
TEST_F(CollectionTests, Erase) {
    Collection col = collection10;
    EXPECT_EQ(10, col.size());
    for (int count = vec10_items.size(); count > 0; count--) {
        col.erase(vec10_items[count - 1]);
        EXPECT_EQ(count - 1, col.size());
    }
}


} /* namespace objects */
