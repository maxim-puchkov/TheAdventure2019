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

using ContainerSearchKey = uint64_t;


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

    /// Default container id (i.e. a room, avatar, or NPC with id = 0)
    ContainerSearchKey test_container_id = 0;

    /// Authenticator that will start at id = 1
    // Authenticator<ItemIdentifier> test_authenticator = Authenticator<ItemIdentifier>(0);
    
    Authenticator<ItemIdentifier> test_authenticator{};

    /// Fixture controller
    // ItemController<ContainerSearchKey> test_controller{test_authenticator};
    ItemController<ContainerSearchKey> test_controller{};




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

/*
// Testing test fixture set up
TEST_F(ItemControllerTests, FixtureInitialization) {
    EXPECT_TRUE(initialized);
}


// Testing item controller default instantiation
TEST_F(ItemControllerTests, Instantiation) {
    // ItemController with id = 0
    ItemController<ContainerSearchKey> controller = ItemController<ContainerSearchKey>();
    EXPECT_EQ(0, controller.itemsCreated());
}


// Testing item controller instantiation with an existing authenticator
TEST_F(ItemControllerTests, InstantiationAuth) {

    // ItemController with id = 123
    ItemIdentifier initial_value = 123;
    Authenticator<ItemIdentifier> auth(initial_value);
    ItemController<ContainerSearchKey> controller(auth);
    EXPECT_EQ(0, controller.itemsCreated());

}


// Testing creating an valid item with keywords, description, and actions
TEST_F(ItemControllerTests, Create) {

    // Item is prepared by using .builder of the controller
    test_controller.builder.setKeywords(input_keys);
    test_controller.builder.setDescription(input_desc);
    test_controller.builder.setActions(input_acts);

    // Create function will generate unique item in a container.
    // Container can be a Character (== same as Inventory), a Room,
    // or anything else.
    // ALL used containers must be unique (cannot simply store a character with id = 123 and room with id = 123, yet)

    // If test_container_id = 0, then an item will be owned by
    // anything that has id = 0
    ItemIdentifier id = test_controller.create(test_container_id);

    // Creating a valid item returns its id. First id = 1
    EXPECT_EQ(1, test_controller.itemsCreated());

}


// Testing creating an invalid item with NO parameters (input error)
TEST_F(ItemControllerTests, CreateEmpty) {

    // Keywords are required to create an item
    // Description and Actions are optional
    auto count = test_controller.itemsCreated();
    ItemIdentifier id = test_controller.create(test_container_id);

    // Trying to create an invalid item returns controller's id
    EXPECT_EQ(id, test_controller.id);
    EXPECT_EQ(count, test_controller.itemsCreated());

}


// Testing creating an item with keywords, description, and NO actions
TEST_F(ItemControllerTests, CreateNoActs) {

    // Create an item without actions
    test_controller.builder.setKeywords(input_keys);
    test_controller.builder.setDescription(input_desc);
    ItemIdentifier id = test_controller.create(test_container_id);

    EXPECT_EQ(1, test_controller.itemsCreated());

}


// Testing creating an item with keywords, NO description, and NO actions
TEST_F(ItemControllerTests, CreateNoDescActs) {

    // Create an item without description and actions
    test_controller.builder.setKeywords(input_keys);
    ItemIdentifier id = test_controller.create(test_container_id);

    EXPECT_EQ(1, test_controller.itemsCreated());

}



// Testing items created count
TEST_F(ItemControllerTests, ItemsCreated) {
    int count = 10;

    for (int i = 1; i <= count; i++) {
        test_controller.builder.setItemProperties(keys, desc, acts);
        ItemIdentifier id = test_controller.create(test_container_id);
        EXPECT_EQ(i, test_controller.itemsCreated());
    }

    EXPECT_EQ(count, test_controller.itemsCreated());
}


// Testing exists function
TEST_F(ItemControllerTests, ExistsItemIdentifier) {

    // Checking if id = 1 exists before creating
    ItemIdentifier test_id = 1;
    EXPECT_FALSE(test_controller.exists(test_container_id, test_id));

    // Checking if id = 1 exists after creating
    test_controller.builder.setItemProperties(keys, desc, acts);
    ItemIdentifier id = test_controller.create(test_container_id);
    EXPECT_TRUE(test_controller.exists(test_container_id, test_id));

}


// Testing exists function
TEST_F(ItemControllerTests, ExistsKeywords) {

    // Checking if keywords exist before creating
    EXPECT_FALSE(test_controller.exists(test_container_id, keys));

    // Checking if keywords exist after creating
    test_controller.builder.setItemProperties(keys, desc, acts);
    ItemIdentifier id = test_controller.create(test_container_id);
    EXPECT_TRUE(test_controller.exists(test_container_id, keys));

}


// Testing lookup function
TEST_F(ItemControllerTests, Lookup) {

    // Identifier can be used to find {id, keywords} pair
    test_controller.builder.setItemProperties(keys, desc, acts);
    ItemIdentifier id = test_controller.create(test_container_id);
    auto search_key = test_controller.lookup(test_container_id, id);

    EXPECT_EQ(id, search_key.id);
    EXPECT_EQ(keys, search_key.keywords);

}


// Testing authenticity of created objects when using local authenticator
TEST_F(ItemControllerTests, Authenticity) {

    int count = 10;

    // Identifier is never duplicated or reused
    for (int i = 1; i <= count; i++) {
        test_controller.builder.setItemProperties(keys, desc, acts);
        ItemIdentifier id = test_controller.create(test_container_id);
        EXPECT_EQ(i, id);
    }

}


//  Testing authenticity of created objects when using global authenticator
TEST_F(ItemControllerTests, AuthenticityGlobal) {

    const auto size = 5;
    ItemIdentifier ids[size] = {0, 1, 100, 10000000, 999999999999999999};

    for (ItemIdentifier id : ids) {
        Authenticator<ItemIdentifier> auth(id);
        ItemController<ContainerSearchKey> controller(auth);

        // Create an item
        controller.builder.setKeywords(input_keys);
        controller.create(test_container_id);
    }

}


// Testing searching for a keyword if there is more than one match
TEST_F(ItemControllerTests, Search) {

    const auto same_keyword = "Same Keyword";

    // Create first item
    test_controller.builder.setKeywords({same_keyword, "Different Keyword"});
    auto id_1 = test_controller.create(test_container_id);

    // Create second item where one keyword is the same
    test_controller.builder.setKeywords({same_keyword, "Keyword Different"});
    auto id_2 = test_controller.create(test_container_id);

    // Search for the same keyword in one container
    auto ids = test_controller.search(test_container_id, same_keyword);

    // Both identifiers will be returned
    EXPECT_EQ(2, ids.size());


//        EXPECT_EQ(id_1, ids[0]);
//        EXPECT_EQ(id_2, ids[1]);

}

*/

} /* namespace items */
