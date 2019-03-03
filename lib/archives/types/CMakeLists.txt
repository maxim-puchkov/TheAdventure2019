add_library(${libtypes}
    src/Environment.cpp
    src/TokenizedString.cpp
)

target_include_directories(${libtypes}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(${libtypes}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libtypes}
    ARCHIVE DESTINATION lib
)
