cmake_minimum_required(VERSION 3.12)


project(${environment})


add_library(${PROJECT_NAME} SHARED
    include/${PROJECT_NAME}.h
    src/${PROJECT_NAME}.cpp
)


target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/traits/>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)


target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${traits}
)


install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib)
