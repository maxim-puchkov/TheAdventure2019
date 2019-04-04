add_executable(liteserver
    liteserver.cpp
)


set_target_properties(liteserver
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
                      PREFIX ""
)


find_package(Threads REQUIRED)


target_link_libraries(liteserver
    ${network}
    ${CMAKE_THREAD_LIBS_INIT}
    ${world}
)


install(TARGETS liteserver
    RUNTIME DESTINATION bin
)
