add_executable(demo
  demo.cpp
)

set_target_properties(demo
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
                      PREFIX ""
)

find_package(Threads REQUIRED)

target_link_libraries(demo
    ${libcommands}
    ${libaccounts}
    ${libusers}
    ${libnetwork}
    ${libworld}
    ${libgame}
    ${libcharacters}
    ${CMAKE_THREAD_LIBS_INIT}
)

install(TARGETS demo
  RUNTIME DESTINATION bin OPTIONAL
)
