//
//  ItemConstructorTests.cpp
//  
//
//  Created by admin on 2019-03-16.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ItemConstructor.h"
#include "Item.h"



namespace objects {

    
    
    
    /// ItemConstructorTests fixture
    class ItemConstructorTests : public testing::Test {
    protected:
        
        void SetUp() override {
            items = ItemConstructor();
        }
        
        void TearDown() override { }
        
        
        /* * *         Variables        * * */
        
        ItemConstructor constructor;
        
        
    };
    
    
    
    
    Test_F(ItemConstructorTests, Construction) {
        
        // Variable input
        vector<string> keys{"sword", "rare"};
        string description = "item will retain this input";
        // ...
        
        // Create a rare sword
        constuctor.setKeywords(keys);
        constructor.setDescription(description);
        Item sword = constructor.create();
        
        EXPECT_NE(0, item.id());
        //EXPECT_EQ(keys, item.keywords);
        EXPECT_EQ(keys[0], item.first());
        
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
        string key1 = "1. A keyword",
        string key2 = "2. Also a keyword,
        vector<string> keys{second_key1, second_key2};
        err  = "Not a keyword";
        string description = "Testing items";
        
        // Create an item
        constructor.setKeywords(keys);
        constructor.setDescription(description);
        Item item = constructor.create();
        
        //
        EXPECT_EQ(true, item.hasKeyword(key1));
        EXPECT_EQ(true, item.hasKeyword(key2));
        EXPECT_EQ(false, item.hasKeyword(err));
        
        
    }
    
    
    
    
    

///* Server Stub */
//class ServerStub : public Server {
//public:
//
//    // Get next name
//    std::string getNext() override {
//        return names.at(++index);
//    }
//
//    // Add a new name to the list
//    void add(const string &name) {
//        names.push_back(name);
//    }
//
//private:
//
//    int index = -1;
//    std::vector<std::string> names;
//
//};
//
//
//
//
//
///* AwardCeremonyActions Mock */
//class GameManagerMock : public AwardCeremonyActions {
//public:
//
//    MOCK_METHOD0(playAnthem, void());
//
//    MOCK_METHOD0(turnOffTheLightsAndGoHome, void());
//
//    MOCK_METHOD1(awardBronze, void(string recipient));
//
//    MOCK_METHOD1(awardSilver, void(string recipient));
//
//    MOCK_METHOD1(awardGold, void(string recipient));
//
//};

//
//
///* AwardsTests Fixture */
//class ObjectsTests : public ::testing::Test {
//protected:
//
//    // Set up: add three names to the list
//    void SetUp() override {
//
//        vector<string> keywords{key1, key2, key3};
//
//    }
//
//
//    void TearDown() override { }
//
//
//
//    string key1 = "Key";
//    string key2 = "Word";
//    string key3 = "Testers";
//
//
//    ItemConstructor itc;
//
//
//};


//
//TEST_F(ObjectsTests, ItemConstructorWorks) {
//    ItemConstructor itc = ;
//
//    Item firstImage = itc.
//}

    
    
    
//// Test correctness of performance
//TEST_F(AwardsTests, performAwardCeremony) {
//    // Read three names from the list
//    string name1 = list.getNext();
//    string name2 = list.getNext();
//    string name3 = list.getNext();
//
//    // Expected ceremony actions
//    EXPECT_CALL(ceremony, playAnthem())
//        .Times(1);
//    EXPECT_CALL(ceremony, awardBronze(name1))
//        .Times(1);
//    EXPECT_CALL(ceremony, awardSilver(name2))
//        .Times(1);
//    EXPECT_CALL(ceremony, awardGold(name3))
//        .Times(1);
//    EXPECT_CALL(ceremony, turnOffTheLightsAndGoHome())
//        .Times(1);
//
//    // Actual actions
//    ceremony.playAnthem();
//    ceremony.awardBronze(name1);
//    ceremony.awardSilver(name2);
//    ceremony.awardGold(name3);
//    ceremony.turnOffTheLightsAndGoHome();
//}



}