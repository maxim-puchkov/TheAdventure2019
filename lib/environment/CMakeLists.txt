add_library(${libenvironment} SHARED
    src/Environment.cpp
)

target_include_directories(${libenvironment}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(${libenvironment}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libenvironment}
    LIBRARY DESTINATION lib
)
