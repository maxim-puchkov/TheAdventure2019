
add_library(simpleLibrary
  src/Triangle.cpp
  src/Hailstone.cpp
  src/Awards.cpp
)

target_include_directories(simpleLibrary
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

set_target_properties(simpleLibrary
  PROPERTIES
  COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})

