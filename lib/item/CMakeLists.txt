add_library(${libItem} SHARED
    src/Item.cpp
    src/ItemBuilder.cpp
    src/Collection.cpp
    src/Inventory.cpp
    src/ItemSearchKey.cpp
    src/ItemController.cpp
)

target_include_directories(${libItem}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libItem}
    ${libAuthentication}
    ${libenvironment}
    ${libBuilder}
    ${libObject}
    ${libTools}
)

set_target_properties(${libItem}
    PROPERTIES
    COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libItem}
    LIBRARY DESTINATION lib
)
