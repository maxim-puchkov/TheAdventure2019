#
#   Time CMakeLists
#

cmake_minimum_required(VERSION 3.12)
project(${time} VERSION 1.0)


add_library(${PROJECT_NAME} SHARED
    include/TimeStamp.h
)


target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)


target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${libminigame}
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
