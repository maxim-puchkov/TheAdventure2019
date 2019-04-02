add_subdirectory(lib)

add_executable(runAllTests
    testChessBoard.cpp
    HailstoneTests.cpp
    AwardsTests.cpp
#	AttributesTest.cpp
	KeywordsTests.cpp
#DescriptionTests.cpp
#InventoryTests.cpp
ItemBuilderTests.cpp
ItemControllerTests.cpp

)

target_link_libraries(runAllTests
  gmock
  gtest
  gtest_main

  simpleLibrary
  minigame
  
  characters

  authentication
  object
  ${item}
  print
  builder
 
)

set_target_properties(runAllTests
  PROPERTIES
  LINK_FLAGS "${CXX_COVERAGE_FLAGS}"
)

add_test(NAME AllTests COMMAND runAllTests)

