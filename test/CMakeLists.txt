




add_subdirectory(lib)

add_executable(runAllTests
	tests.cpp
	ItemConstructorTests.cpp
)

target_link_libraries(runAllTests
	gmock
	test
	gtest_main
	

	
	ItemConstructorTests.cpp
)

set_target_properties(runAllTests
	PROPERTIES
	LINK_FLAGS "${CXX_COVERAGE_FLAGS}"
)

add_test(NAME AllTests COMMAND runAllTests)

