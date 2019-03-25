add_library(${libbuilder} SHARED
    src/Builder.cpp
)

target_include_directories(${libbuilder}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libbuilder}
    ${libobject}
)

set_target_properties(${libbuilder}
    PROPERTIES
    COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libbuilder}
    LIBRARY DESTINATION lib
)
