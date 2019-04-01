cmake_minimum_required(VERSION 3.12)


project(${item})


add_library(${PROJECT_NAME} SHARED
    src/Item.cpp
    src/ItemBuilder.cpp
    src/Collection.cpp
    src/Inventory.cpp
    src/ItemSearchKey.cpp
    src/ItemController.cpp
    src/ICMemory.cpp
    src/Keywords.cpp
    src/Description.cpp
    src/Actions.cpp
)


target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)


set_target_properties(${PROJECT_NAME}
    PROPERTIES
        COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
)


target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${object}
        ${user-interface}
    PRIVATE
        ${authentication}

        ${builder}
        ${print}

        ${exceptions}
)


install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
