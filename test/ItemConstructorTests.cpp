//
//  ItemConstructorTests.cpp
//  
//
//  Created by admin on 2019-03-16.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ItemConstructor.h"



namespace objects {


/// ItemConstructorTests Fixture
class ItemConstructorTests : public testing::Test {
protected:
    
    void SetUp() override {
        
        // Initial set up before each test...
        constructor = ItemConstructor();
        
    }
    
    void TearDown() override {
        
        // Test ends...
        
    }
    
    
    
    /* * *         Variables        * * */
    
    ItemConstructor constructor;
    
};









/* Fixture Tests */
    
TEST_F(ItemConstructorTests, Construction) {
    
    // Variable input
    vector<string> keys{"sword", "rare"};
    string description = "item will retain this input";
    // ...
    
    // Create a rare sword
    KeywordSet keywords(keys);
    constructor.setKeywords(keywords);
    // constructor.setDescription(description);
    Item sword = constructor.create();
    
    
    EXPECT_TRUE(sword.id() > 0);
    EXPECT_TRUE(keywords == sword.keywords);
    
   // EXPECT_EQ(keys[0], sword.keywords.first());
    
}


TEST_F(ItemConstructorTests, Authention) {
    
    // Item's keywords and description
    vector<string> keys{"Unique item", "First item's id ID = 1"};
    string description = "1";
    
    // Create first item
    constructor.setKeywords(keys);
    constructor.setDescription(description);
    Item item = constructor.create();
    
    EXPECT_EQ(1, item.id());
    
}


TEST_F(ItemConstructorTests, KeywordMatching) {
    
    // Variable input
    vector<string> keys{"1. A keyword", "2. Also a keyword"};
    string description = "Testing keywords";
    
    // Create an item
    constructor.setKeywords(keys);
    constructor.setDescription(description);
    Item item = constructor.create();
    
    
    //
    EXPECT_TRUE(item.hasKeyword(keys[0]));
    EXPECT_TRUE(item.hasKeyword(keys[1]));
    EXPECT_FALSE(item.hasKeyword("Not a keyword"));
    
}

/*
TEST_F(ItemConstructorTests, KeywordType) {
 
    string skey = "string key";
    char *ckey = "char* key";
    string description = "Testing item types";

 
    // Create an item
    constructor.setKeywords(keys);
    constructor.setDescription(description);
    Item item = constructor.create();
 
 
    EXPECT_EQ(true, item.hasKeyword(skey));
    EXPECT_EQ(true, item.hasKeyword(ckey));
 
}

*/
    

}
