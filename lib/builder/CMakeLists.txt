add_library(${libbuilder}
    src/ItemBuilder.cpp
)

target_include_directories(${libbuilder}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libbuilder}
    ${libobjects}
)

set_target_properties(${libbuilder}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libbuilder}
    ARCHIVE DESTINATION lib
)
