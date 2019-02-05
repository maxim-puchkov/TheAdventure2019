add_library(${libscripts}
    src/ScriptParser.cpp
)

target_include_directories(${libscripts}
PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(${libscripts}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

target_link_libraries(${libscripts}
    ${libtypes}
)


install(TARGETS ${libscripts}
    ARCHIVE DESTINATION lib
)

