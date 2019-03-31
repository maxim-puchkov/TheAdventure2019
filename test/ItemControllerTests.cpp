//
//  ItemControllerTests.cpp
//  adventure2019: adventure2019
//  com.maximpuchkov.Faworki.adventure2019.ItemControllerTests
//
//  Created by mpuchkov on 2019-03-29. macOS 10.13, Xcode 10.1.
//  Copyright © 2019 Maxim Puchkov. All rights reserved.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ItemController.h"
#include "Authenticator.h"


namespace items {
    
using ContainerSearchKey = uint8_t;


/// ItemControllerTests Fixture
class ItemControllerTests: public testing::Test {
protected:
    
    bool initialized = false;
    
    void SetUp() override {
        // Initial set up before each test...
        initialized = true;
        
        // Set input values
        input_keys = {"Keyword 1", "Keyword 2"};
        input_desc = "ItemController tests...";
        input_acts = {
            {"open", "you opened something!"},
            {"close", "you closed something!"}
        };
        
        // Convert to object data
        keys = Keywords(input_keys);
        desc = Description(input_desc);
        acts = Actions(input_acts);
        
        // Set defaults values
        def_desc = DEF_DESC;
        def_acts = DEF_ACTS;
        
    }
    
    void TearDown() override {
        // Test ends...
    }
    
    
    
    
    
    /* * *         Functions        * * */
    
    string f_action_1() { return "Action will be mapped to a functor, one day."; }
    
    
    
    
    
    /* * *         Variables        * * */
    
    /// Pre-existing authenticator
    const Authenticator<ItemIdentifier> test_authenticator = Authenticator<ItemIdentifier>(0);
    
    /// Fixture controller
    const ItemController<ContainerSearchKey> test_controller{test_authenticator};
    
    /// Default placement
    const ContainerSearchKey test_container = 0;
    
    
    
    
    
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
    
    
    
    
    
    
    
    
    
/* ItemController Fixture Tests */

// Testing test fixture set up
TEST_F(ItemControllerTests, FixtureInitialization) {
    EXPECT_TRUE(initialized);
}


// Testing item controller default instantiation
TEST_F(ItemControllerTests, Instantiation) {
    ItemController<ContainerSearchKey> controller = ItemController<ContainerSearchKey>();
    EXPECT_EQ(0, controller.itemsCreated());
}


// Testing item controller instantiation with an existing authenticator
TEST_F(ItemControllerTests, InstantiationAuth) {
    
    // Authenticator with id = 123
    ItemIdentifier initial_value = 123;
    Authenticator<ItemIdentifier> auth(initial_value);
    ItemController<ContainerSearchKey> controller(auth);
    EXPECT_EQ(0, controller.itemsCreated());
    
}


// Testing creating an item with keywords, description, and actions
TEST_F(ItemControllerTests, Create) {
    
    // Create an item
    test_controller.builder.setKeywords(input_keys);
    test_controller.builder.setDescription(input_desc);
    test_controller.builder.setActions(input_acts);
    auto id = test_controller.create(test_container);
    
    EXPECT_EQ(1, test_controller.itemsCreated());
    
//    EXPECT_EQ(1, item.id);
//    EXPECT_EQ(keys, item.keywords);
//    EXPECT_EQ(desc, item.description);
//    EXPECT_EQ(acts, item.actions);
//    EXPECT_TRUE(item.isInteractable());
    
}


// Testing creating an item with keywords, description, and NO actions
TEST_F(ItemControllerTests, CreateNoActs) {
    
    // Create an item without actions
    test_controller.builder.setKeywords(input_keys);
    test_controller.builder.setDescription(input_desc);
    auto id = test_controller.create(test_container);
    
    EXPECT_EQ(1, test_controller.itemsCreated());
    
//    EXPECT_EQ(1, item.id);
//    EXPECT_EQ(keys, item.keywords);
//    EXPECT_EQ(desc, item.description);
//    EXPECT_EQ(def_acts, item.actions);
//    EXPECT_FALSE(item.isInteractable());
    
}


// Testing creating an item with keywords, NO description, and NO actions
TEST_F(ItemControllerTests, CreateNoDescActs) {
    
    // Create an item without description and actions
    test_controller.builder.setKeywords(input_keys);
    auto id = test_controller.create(test_container);
    
    EXPECT_EQ(1, test_controller.itemsCreated());
    
//    EXPECT_EQ(1, item.id);
//    EXPECT_EQ(keys, item.keywords);
//    EXPECT_EQ(def_desc, item.description);
//    EXPECT_EQ(def_acts, item.actions);
//    EXPECT_FALSE(item.isInteractable());
}


// Testing creating an item with NO parameters (input error)
TEST_F(ItemControllerTests, CreateEmpty) {
    bool caught;
    auto count = test_controller.itemsCreated();
    
    // Try to create an invalid item
    try {
        auto id = test_controller.create(test_container);
        caught = false;
    } catch (std::exception &e) {
        caught = true;
    }
    
    EXPECT_EQ(count, test_controller.itemsCreated());
    EXPECT_TRUE(caught);
}


// Testing items created count
TEST_F(ItemControllerTests, ItemsCreated) {
    int count = 10;
    
    for (int i = 0; i < count; i++) {
        test_controller.builder.setItemProperties(keys, desc, acts);
        auto id = test_controller.create(test_container);
        EXPECT_EQ(i, test_controller.itemsCreated());
    }
    
    EXPECT_EQ(count, test_controller.itemsCreated());
}


// Testing exists function
TEST_F(ItemControllerTests, ExistsItemIdentifier) {
    
    ItemIdentifier id = 1;
    EXPECT_FALSE(test_controller.exists(id));
    
    test_controller.builder.setItemProperties(keys, desc, acts);
    auto id = test_controller.create(test_container);
    EXPECT_TRUE(test_controller.exists(id));
    
}


// Testing exists function
TEST_F(ItemControllerTests, ExistsKeywords) {
    
    EXPECT_FALSE(test_controller.exists(test_container, keys));
    
    test_controller.builder.setItemProperties(keys, desc, acts);
    auto id = test_controller.create(test_container);
    EXPECT_TRUE(test_controller.exists(test_container, keys));
    
}


// Testing lookup function
TEST_F(ItemControllerTests, Lookup) {
    
    test_controller.builder.setItemProperties(keys, desc, acts);
    auto id = test_controller.create(test_container);
    auto search_key = test_controller.lookup(test_container, id);
    
    EXPECT_EQ(id, search_key.id);
    EXPECT_EQ(desc, search_key.desc);
    
    // EXPECT_EQ(item, test_controller.lookup(item.id));
    // EXPECT_EQ(item, test_controller.lookup(item.keywords));
    
}
    
    
// Testing authenticity of created objects when using local authenticator
TEST_F(ItemControllerTests, Authenticity) {
    
    int count = 10;
    
    for (int i = 0; i < count; i++) {
        test_controller.builder.setItemProperties(keys, desc, acts);
        auto id = test_controller.create(test_container);
        EXPECT_EQ(i, id);
    }
    
}
    
    
//  Testing authenticity of created objects when using global authenticator
TEST_F(ItemControllerTests, AuthenticityGlobal) {
    
    const auto size = 5;
    ItemIdentifier ids[size] = {0, 1, 100, 10000000, 999999999999999999};
    
    for (auto id : ids) {
        Authenticator<ItemIdentifier> auth(id);
        ItemController<ContainerSearchKey> controller(auth);
        
        // Create an item
        controller.builder.setKeywords(input_keys);
        controller.create(test_container);
    }
    
}


} /* namespace items */

