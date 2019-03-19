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
        
        void SetUp() {
            itc = ItemConstructor();
        }
        
        void TearDown() { }
        
        
        /* * *         Variables        * * */
        
        ItemConstructor itc;
        
        
        vector<string> firsr_keys{"First Item", "Will have ID = 1"};
        
        
        string second_key1 = "1. Key .1",
               second_key2 = "2. Two .2",
               second_err  = "not a keyword";
        vector<string> second_keys{second_key1, second_key2};

        
        string no_desc = "no description";
    };
    

    TEST_F(ItemConstructorTests, itemCreated) {
        
        // Create an item
        itc.setKeywords(firsr_keys);
        itc.setDescription(no_desc);
        Item item = itc.create();
        
        EXPECT_EQ(1, item.getID());
        
    }
    
    
    TEST_F(ItemConstructorTests, evaluateAllKeywords) {
        
        // Create a second item
        itc.setKeywords(second_keys);
        itc.setDescription(no_desc);
        Item item = itc.create();
        
        EXPECT_EQ(true, item.hasKeyword(second_key1));
        EXPECT_EQ(true, item.hasKeyword(second_key2));
        EXPECT_EQ(false, item.hasKeyword(second_err));
        
        
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
