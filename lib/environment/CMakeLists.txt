add_library(${libEnvironment} SHARED
    src/Environment.cpp
)

target_include_directories(${libEnvironment}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libEnvironment}
    PUBLIC
        ${libUtility}
)


set_target_properties(${libEnvironment}
    PROPERTIES
    COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libEnvironment}
    LIBRARY DESTINATION lib
)
