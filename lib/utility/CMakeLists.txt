add_library(${libUtility} SHARED
    src/Utility.cpp
)

target_include_directories(${libUtility}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(${libUtility}
    PROPERTIES
    COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libUtility}
    LIBRARY DESTINATION lib
)
