//
//  ItemBuilderTests.cpp
//  
//
//  Created by admin on 2019-03-16.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ItemBuilder.h"


namespace items {


/// ItemBuilderTests Fixture
class ItemBuilderTests : public testing::Test {
protected:
    
    void SetUp() override {
        // Initial set up before each test...
        constructor = ItemBuilder();
        initialized = true;
    }
    
    void TearDown() override {
        // Test ends...
    }
    
    
    
    /* * *         Variables        * * */
    
    ItemBuilder constructor;
    bool initialized;
    
};









/* Fixture Tests */

// Testing fixture initialization
TEST_F(ItemBuilderTests, TestInitialization) {
    EXPECT_TRUE(initialized);
}


// Testing objing construction
TEST_F(ItemBuilderTests, Build) {

    // Variable input
    Identifier id = 1;
    vector<string> keys{"sword", "rare"};
    Text description = "Testing Construction";
    vector<pair<string, string>> actions{{"action", "examining action"}};

    
    // Create a rare sword with one action
    constructor.setKeywords(keys);
    constructor.setDescription(description);
    constructor.setActions(actions);
    Item sword = constructor.build(id);

    
    // Test main object properties
    EXPECT_EQ(id, sword.id);
    EXPECT_EQ(Keywords(keys), sword.keywords);
    EXPECT_EQ(Description(description), sword.description);
    EXPECT_EQ(Actions(actions), sword.actions);

}


//TEST_F(ItemBuilderTests, Authentication) {
//
//    // Item's keywords and description
//    vector<string> keys{"Unique item", "First item's id ID = 1"};
//    string description = "1";
//
//    // Create first item
//    constructor.setKeywords(keys);
//    constructor.setDescription(description);
//    Item item = constructor.build();
//
//    EXPECT_EQ(1, item.id());
//
//}


//TEST_F(ItemBuilderTests, KeywordMatching) {
//
//    // Variable input
//    vector<string> keys{"1. A keyword", "2. Also a keyword"};
//    string description = "Testing keywords";
//
//    // Create an item
//    constructor.setKeywords(keys);
//    constructor.setDescription(description);
//     Item item = constructor.build();
//
//
//     EXPECT_TRUE(item.keywords.contains(keys[0]));
//     EXPECT_TRUE(item.keywords.contains(keys[1]));
//     EXPECT_FALSE(item.keywords.contains("Not a keyword"));
//
//}

/*
TEST_F(ItemBuilderTests, KeywordType) {
 
    string skey = "string key";
    char *ckey = "char* key";
    string description = "Testing item types";

 
    // Create an item
    constructor.setKeywords(keys);
    constructor.setDescription(description);
    Item item = constructor.build();
 
 
    EXPECT_EQ(true, item.keywords.contains(skey));
    EXPECT_EQ(true, item.keywords.contains(ckey));
 
}

*/
    

} /* namespace items */
