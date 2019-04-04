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
    
    bool initialized;
    
    void SetUp() override {
        // Initial set up before each test...
        initialized = true;
        
        // Set test identifier
        test_id = 1;
        
        // Set input values
        input_keys = {"Keyword 1", "Keyword 2"};
        input_desc = "ItemController tests...";
        input_acts = {
            {"open", "you opened something!"},
            {"close", "you closed something!"}
        };
        
        // Item will convert raw data to object data
        keys = Keywords(input_keys);
        desc = Description(input_desc);
        acts = Actions(input_acts);
        
        // Defaults values if nothing is set
        def_desc = DEF_DESC;
        def_acts = DEF_ACTS;
    }
    
    void TearDown() override {
        // Test ends...
    }
    
    
    
    /* * *         Variables        * * */
    
    /// Fixture builder
    ItemBuilder test_builder;
    
    /// Identifier assigned to all test items (will be generated by controller)
    ItemIdentifier test_id;
    
    
    
    // Raw variables that could be read from file or entered by characters
    vector<string> input_keys;
    string input_desc;
    vector<pair<string, string>> input_acts;
    
    
    // ItemBuilder converts raw variables to easy-to-use
    // self-managing classes. These can be converted back via
    // .toString() and/or .toVector()
    Keywords keys;
    Description desc;
    Actions acts;
    
    
    // Keywords are required; Description and Actions are optional.
    // If value is not specified when creating an object,
    // builder will assign default values.
    Description def_desc;
    Actions def_acts;
    
};









/* Fixture Tests */

// Testing fixture initialization
TEST_F(ItemBuilderTests, TestInitialization) {
    EXPECT_TRUE(initialized);
}


// Testing building a complete item with keywords, description, and actions
TEST_F(ItemBuilderTests, Build) {
    
    // Create an item
    test_builder.setKeywords(input_keys);
    test_builder.setDescription(input_desc);
    test_builder.setActions(input_acts);
    Item item = test_builder.build(test_id);
    
    EXPECT_EQ(test_id, item.id);
    EXPECT_EQ(keys, item.keywords);
    EXPECT_EQ(desc, item.description);
    EXPECT_EQ(acts, item.actions);
    EXPECT_TRUE(item.isInteractable());

}
    
    
// Testing building an item with keywords, description, and NO actions
TEST_F(ItemBuilderTests, BuildItemWithoutActions) {
    
    // Create an item without actions
    test_builder.setKeywords(input_keys);
    test_builder.setDescription(input_desc);
    Item item = test_builder.build(test_id);
    
    EXPECT_EQ(1, item.id);
    EXPECT_EQ(keys, item.keywords);
    EXPECT_EQ(desc, item.description);
    EXPECT_EQ(def_acts, item.actions);
    EXPECT_FALSE(item.isInteractable());
    
}


// Testing building an item with keywords, NO description, and NO actions
TEST_F(ItemBuilderTests, BuildItemWithoutDescriptionAndActions) {
    
    // Build an item without description and actions
    test_builder.setKeywords(input_keys);
    Item item = test_builder.build(test_id);

    EXPECT_EQ(1, item.id);
    EXPECT_EQ(keys, item.keywords);
    EXPECT_EQ(def_desc, item.description);
    EXPECT_EQ(def_acts, item.actions);
    EXPECT_FALSE(item.isInteractable());
    
}


// Testing building and resetting builder
TEST_F(ItemBuilderTests, BuildReset) {
    
    // Create an item
    test_builder.setKeywords(input_keys);
    test_builder.setDescription(input_desc);
    test_builder.setActions(input_acts);
    Item item = test_builder.build(test_id);
    
    // And another one
    auto test_id_2 = test_id + 1;
    Item item_2 = test_builder.build(test_id_2);
    
    EXPECT_EQ(test_id, item.id);
    EXPECT_EQ(test_id_2, item_2.id);
    
    EXPECT_EQ(EMPTY_KEYS, item_2.keywords);
    EXPECT_EQ(DEF_DESC, item_2.description);
    EXPECT_EQ(DEF_ACTS, item_2.actions);
    
    EXPECT_NE(item, item_2);
    
}


// Testing matching item keywords 
TEST_F(ItemBuilderTests, KeywordMatching) {

    // Create an item
    test_builder.setKeywords(input_keys);
    test_builder.setDescription(input_desc);
    Item item = test_builder.build(test_id);

    EXPECT_TRUE(item.keywords.contains(input_keys[0]));
    EXPECT_TRUE(item.keywords.contains(input_keys[1]));
    EXPECT_FALSE(item.keywords.contains("Not a keyword"));

}


} /* namespace items */
