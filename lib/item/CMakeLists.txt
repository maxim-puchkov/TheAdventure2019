#
#   Item, ItemBuilder, and ItemProperty CMakeLists
#

cmake_minimum_required(VERSION 3.12)
project(${item} VERSION 1.1)





add_library(${PROJECT_NAME}-data STATIC
#include/items.hpp
    src/Keywords.cpp
    src/Description.cpp
    src/Actions.cpp
    src/ItemAttributes.cpp
    src/Item.cpp
)


target_include_directories(${PROJECT_NAME}-data
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)


set_target_properties(${PROJECT_NAME}-data
    PROPERTIES
        COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
)


target_link_libraries(${PROJECT_NAME}-data
    PUBLIC
        ${authentication}
        ${object}
        ${user-interface}
        ${builder}
        ${properties}
)


install(TARGETS ${PROJECT_NAME}-data
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    FRAMEWORK DESTINATION lib
)






add_library(${PROJECT_NAME}-builder
    src/ItemBuilder.cpp
    src/ItemBuilderConfiguration.cpp
)


target_include_directories(${PROJECT_NAME}-builder
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)


set_target_properties(${PROJECT_NAME}-builder
    PROPERTIES
        COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
)


target_link_libraries(${PROJECT_NAME}-builder
    PUBLIC
        ${authentication}
        ${object}
        ${user-interface}
        ${builder}
        ${PROJECT_NAME}-data
)


install(TARGETS ${PROJECT_NAME}-builder
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    FRAMEWORK DESTINATION lib
)












add_library(${PROJECT_NAME}
    src/ItemSearchKey.cpp
    src/controller/ICData.cpp
    src/controller/ItemController.cpp
)


target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:src/controller>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/controller>
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
        ${authentication}
        ${object}
        ${builder}
        ${PROJECT_NAME}-data
        ${PROJECT_NAME}-builder
)


install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    FRAMEWORK DESTINATION lib
)
