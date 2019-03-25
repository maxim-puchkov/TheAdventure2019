add_library(${libitem} SHARED
    src/Item.cpp
    src/ItemBuilder.cpp
    src/Collection.cpp
)

target_include_directories(${libitem}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libitem}
    ${libbuilder}
    ${libobject}
    ${libdebugtools}
)

set_target_properties(${libitem}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libitem}
    LIBRARY DESTINATION lib
)