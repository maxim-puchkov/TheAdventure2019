add_library(data
    src/Environment.cpp
    src/TokenizedString.cpp
)

target_include_directories(data
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(data
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS data
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION lib
)

