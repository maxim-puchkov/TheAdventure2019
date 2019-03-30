add_library(${libBuilder} SHARED
    src/Builder.cpp
)

target_include_directories(${libBuilder}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libBuilder}
    ${libObject}
)

set_target_properties(${libBuilder}
    PROPERTIES
    COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libBuilder}
    LIBRARY DESTINATION lib
)
