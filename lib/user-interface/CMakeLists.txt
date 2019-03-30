add_library(${libUserInterface} SHARED
    src/UIText.cpp
    src/UITextPartition.cpp
)

target_include_directories(${libUserInterface}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(${libUserInterface}
    PROPERTIES
    COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libUserInterface}
    LIBRARY DESTINATION lib
)