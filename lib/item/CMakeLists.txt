#
#   Item CMakeLists
#

cmake_minimum_required(VERSION 3.12)
project(${item} VERSION 1.0)


add_library(${PROJECT_NAME}
    src/Item.cpp
    src/ItemBuilder.cpp
    src/ItemSearchKey.cpp
    src/Keywords.cpp
    src/Description.cpp
    src/Actions.cpp
    src/ItemAttributes.cpp
    src/controllers/ICData.cpp
    src/controllers/ItemController.cpp
)


target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:src/controllers>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/controllers>
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
        ${user-interface}
        ${builder}
        ${print}
)


install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION LIB
    LIBRARY DESTINATION lib
    FRAMEWORK DESTINATION lib
)
