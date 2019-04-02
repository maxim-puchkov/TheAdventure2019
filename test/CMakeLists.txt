#
#   GoogleTest CMakeLists
#


add_subdirectory(lib)


add_executable(runAllTests
    # Add all new test files to the list here.
    # Place each file name on a separate line.
#    TestRunner.cpp
#   testChessBoard.cpp
    ItemBuilderTests.cpp
)


target_link_libraries(runAllTests
    gmock
    gmock_main
    gtest
    gtest_main

#    ${network}

#    ${game}
#    ${minigame}
#    ${commands}

#    ${users}
#    ${characters}

#    ${authentication}
#    ${world}

#    ${parsers}
    ${builder}

    ${object}
    ${item}
)


set_target_properties(runAllTests
    PROPERTIES
        LINK_FLAGS "${CXX_COVERAGE_FLAGS}"
)


add_test(NAME AllTests COMMAND runAllTests)
