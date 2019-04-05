#
#   Game CMakeLists
#


cmake_minimum_required(VERSION 3.12)
project(${game} VERSION 1.0)


add_library(${PROJECT_NAME}
    src/GameManager.cpp
)


target_include_directories(${game}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIR}
)


target_link_libraries(${game}
    PUBLIC
        ${characters}
        ${world}
        ${users}
        ${minigame}
        ${commands}
        ${parsers}
    PRIVATE
        ${Boost_LIBRARIES}
)


set_target_properties(${PROJECT_NAME}
    PROPERTIES
        COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
)


install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
