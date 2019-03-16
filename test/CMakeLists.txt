add_subdirectory(lib)

add_executable(runAllTests
  # Add all new test files to the list here.
  # Place each file name on a separate line.
  tests.cpp
  Dummy.cpp # This file is a placeholder and tests nothing.
  testChessBoard.cpp

)

target_link_libraries(runAllTests
  ${libminigame}
  gmock
  gtest
  gtest_main
  
)

set_target_properties(runAllTests
  PROPERTIES
  LINK_FLAGS "${CXX_COVERAGE_FLAGS}"
)

add_test(NAME AllTests COMMAND runAllTests)

