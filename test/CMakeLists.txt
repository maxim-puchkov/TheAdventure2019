add_subdirectory(lib)

add_executable(runAllTests
  # Add all new test files to the list here.
  # Place each file name on a separate line.
  TestRunner.cpp # Contains main that will run tests
  
)

target_link_libraries(runAllTests
  gmock
  gtest
  gtest_main
  characters
  commands
  game
  network
  types
  users
  world
  parsers
  userdb
    ${libauthentication}
    ${libbuilder} ${libobject}
    ${libitem}
)

set_target_properties(runAllTests
  PROPERTIES
  LINK_FLAGS "${CXX_COVERAGE_FLAGS}"
)

add_test(NAME AllTests COMMAND runAllTests)
