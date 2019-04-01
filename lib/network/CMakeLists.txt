#
#   Network CMakeLists
#


cmake_minimum_required(VERSION 3.12)
project(${network} VERSION 1.0)


add_library(${PROJECT_NAME} STATIC
    src/Server.cpp
    src/Client.cpp
)


find_package(Boost 1.68 COMPONENTS system REQUIRED)


target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIR}
)


target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${Boost_LIBRARIES}
)


set_target_properties(${PROJECT_NAME}
    PROPERTIES LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)


install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
)
