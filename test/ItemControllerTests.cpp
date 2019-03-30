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


namespace items {


/// ItemControllerTests Fixture
class ItemControllerTests: public testing::Test {
protected:
    
    bool initialized = false;
    
    void SetUp() override {
        // Initial set up before each test...
        initialized = true;
        
        // temp
        controller = Itemcontroller(auth);
       // auth(0);
    }
    
    void TearDown() override {
        // Test ends...
    }
    
    
    
    
    
    /* * *         Functions        * * */
    
    string f_action_1() {
        return "Action will be mapped to a functor, one day.";
    }
    
    
    
    
    
    /* * *         Variables        * * */
    
    // Pre-existing authenticator
    Authenticator<Identifier> auth; // authenticator
    
    
    // Raw keywords
    vector<string> input_keys = {"Keyword 1", "Keyword 2"};
    
    // Raw description
    string input_desc = "ItemController tests...";
    
    // Raw actions
    vector<pair<string, string>> input_acts = {
        {"open", "you opened something!"},
        {"close", "you closed something!"}
    };
    
    
    
    // Object's Data classes
    Keywords keys = Keywords(input_keys);
    Description desc = Description(input_desc);
    Actions acts = Actions(input_acts);
    
    
    // vector<pair<string, std::function<void *()>> acts_2;
    
    // !
    ItemController controller;
    
};
    
    
    
    
    
    
    
    
    
/* ItemController Fixture Tests */

// Testing test fixture set up
TEST_F(ItemControllerTests, FixtureInitialization) {
    EXPECT_TRUE(initialized);
}


// Testing item controller default instantiation
TEST_F(ItemControllerTests, Instantiation) {
    // ItemController<Identifier> controller();
    // EXPECT_EQ(0, controller.itemsCreated());
    // EXPECT_FALSE(controller.exists(rand()));
}


// Testing item controller instantiation with an existing authenticator
TEST_F(ItemControllerTests, InstantiationAuth) {
    // ItemController<Identifier> controller(authenticator);
    // EXPECT_EQ(0, controller.itemsCreated());
    // EXPECT_FALSE(controller.exists(rand()));
}


// Testing creating an item with keywords, description, and actions
TEST_F(ItemControllerTests, Create) {
    // ItemController<Identifier> controller(authenticator);
    
    // Create an item
    controller.builder.setKeywords(input_keys);
    controller.builder.setDescription(input_desc);
    controller.builder.setActions(input_acts);
    Item item = controller.create();
    
    EXPECT_EQ(1, item.id);
    EXPECT_EQ(keys, item.keywords);
    EXPECT_EQ(desc, item.description);
    // EXPECT_TRUE(item.isInteractable());
    EXPECT_EQ(acts, item.actions);
}


// Testing creating an item with keywords, description, and NO actions
TEST_F(ItemControllerTests, DISABLED_CreateNoActs) {
    // ItemController<Identifier> controller(authenticator);
    
    // Create an item
    controller.builder.setKeywords(input_keys);
    controller.builder.setDescription(input_desc);
    Item item = controller.create(); // segf
    
    EXPECT_EQ(1, item.id);
    EXPECT_EQ(keys, item.keywords);
    EXPECT_EQ(desc, item.description);
    // EXPECT_FALSE(item.isInteractable());
}


// Testing creating an item with keywords, NO description, and NO actions
TEST_F(ItemControllerTests, DISABLED_CreateNoDescActs) {
    // ItemController<Identifier> controller(authenticator);
    
    // Create an item; description will use default value
    controller.builder.setKeywords(input_keys);
    Item item = controller.create(); // segf
    
    EXPECT_EQ(1, item.id);
    EXPECT_EQ(keys, item.keywords);
    // EXPECT_EQ(Description::NONE, item.description);
    // EXPECT_FALSE(item.isInteractable());
}


// Testing creating an item with NO parameters (input error)
TEST_F(ItemControllerTests, DISABLED_CreateEmpty) {
    // ItemController<Identifier> controller(authenticator);
    
    bool caught;
    // auto count = controller.itemsCreated();
    
    // Try to create an invalid item
    try {
        Item item = controller.create(); // segf
        caught = false;
    } catch (std::exception &e) {
        caught = true;
    }
    
    // EXPECT_EQ(count, controller.itemsCreated());
    EXPECT_TRUE(caught);
}


// Testing items created count
TEST_F(ItemControllerTests, ItemsCreated) {
    // ItemController<Identifier> controller(authenticator);
    int count = 10;
    
    for (int i = 0; i < count; i++) {
        controller.builder.setItemProperties(keys, desc, acts);
        controller.create();
    }
    
    // EXPECT_EQ(count, controller.itemsCreate());
}


// Testing exists function
TEST_F(ItemControllerTests, ExistsIdentifier) {
    // ItemController<Identifier> controller(authenticator);

    Identifier id = 1;
    EXPECT_FALSE(controller.exists(id));
    
    controller.builder.setItemProperties(keys, desc, acts);
    controller.create();
    EXPECT_TRUE(controller.exists(id));
}


// Testing exists function
TEST_F(ItemControllerTests, ExistsKeywords) {
    // ItemController<Identifier> controller(authenticator);
    // EXPECT_FALSE(controller.exists(keys));
    
    controller.builder.setItemProperties(keys, desc, acts);
    controller.create();
    // EXPECT_TRUE(controller.exists(keys));
}


// Testing lookup function
TEST_F(ItemControllerTests, Lookup) {
    // ItemController<Identifier> controller(authenticator);
    
    controller.builder.setItemProperties(keys, desc, acts);
    Item item = controller.create();
    
    // EXPECT_EQ(item, controller.lookup(item.id));
    // EXPECT_EQ(item, controller.lookup(item.keywords));
}


} /* namespace items */

