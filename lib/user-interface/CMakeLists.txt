add_library(${libuser-interface}
    src/UIColorTerminal.cpp
)

target_include_directories(${libuser-interface}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(${libuser-interface}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libuser-interface}
    ARCHIVE DESTINATION lib
)

