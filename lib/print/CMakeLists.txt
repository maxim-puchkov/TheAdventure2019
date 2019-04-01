project(${dev})


add_library(${PROJECT_NAME} INTERFACE)


target_include_directories(${PROJECT_NAME}
    INTERFACE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)


install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/" DESTINATION lib)

# install(DIRECTORY include DESTINATION bin)


#install(TARGETS ${PROJECT_NAME} PUBLIC_HEADER DESTINATION lib)


#install(
#    DIRECTORY include/${PROJECT_NAME}
#    DESTINATION include/${PROJECT_NAME}
#)
