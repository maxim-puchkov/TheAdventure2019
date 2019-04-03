add_subdirectory(lib)


add_executable(runAllTests
    TriangleTests.cpp
    HailstoneTests.cpp
    AwardsTests.cpp

# Character
#	  AttributesTest.cpp

# Minigame
    testChessBoard.cpp

# Item Data Classes
#     KeywordsTests.cpp
#     DescriptionTests.cpp

# Item Use Classess
#    InventoryTests.cpp
#    ItemBuilderTests.cpp
#    ItemControllerTests.cpp
)


target_link_libraries(runAllTests
    gmock
    gtest
    gtest_main

    simpleLibrary
    ${minigame}
#    ${characters}

#    ${authentication}
#    ${builder}
#    ${object}
#    ${item}
#    ${print}
)


set_target_properties(runAllTests
    PROPERTIES
        LINK_FLAGS "${CXX_COVERAGE_FLAGS}"
)


add_test(NAME AllTests COMMAND runAllTests)
