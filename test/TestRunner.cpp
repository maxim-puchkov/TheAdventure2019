#include "gtest/gtest.h"
#include "gmock/gmock.h"
//#include "AttributesTest.cpp"
//#include "CharacterTest.cpp"
//#include "CommandSplittingTest.cpp"
//#include "CommandValidTest.cpp"
#include "testChessBoard.cpp"


//#include "KeywordsTests.cpp"
//#include "DescriptionTests.cpp"
//#include "ItemTests.cpp"
//#include "CollectionTests.cpp"
//#include "ItemBuilderTests.cpp"
//#include "InventoryTests.cpp"


//#include "ItemControllerTests.cpp"


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
