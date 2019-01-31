set(LIB_NAME "types")

add_library(LIB_NAME
    src/Environment.cpp
    src/TokenizedString.cpp
)

target_include_directories(LIB_NAME
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(LIB_NAME
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS LIB_NAME
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION lib
)

