#
#   World CMakeLists
#


cmake_minimum_required(VERSION 3.12)
project(${world} VERSION 1.0)


add_library(${PROJECT_NAME}
    src/Exit.cpp
    src/Room.cpp
    src/WorldManager.cpp
    src/Area.cpp
    src/AreaGenerator.cpp
)


target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${location}
        ${libusers}
        ${characters}
        ${parsers}
        ${item}
        ${print}
        ${libstrings}
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
