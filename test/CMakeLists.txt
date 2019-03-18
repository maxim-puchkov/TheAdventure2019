add_subdirectory(lib)

add_executable(runAllTests
	tests.cpp
)

target_link_libraries(runAllTests
	gmock
	test
	gtest_main
)

set_target_properties(runAllTests
	PROPERTIES
	LINK_FLAGS "${CXX_COVERAGE_FLAGS}"
)

add_test(NAME AllTests COMMAND runAllTests)

