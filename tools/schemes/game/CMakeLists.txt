add_executable(sgame
  gm.cpp
)

set_target_properties(sgame
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
                      PREFIX ""
)

find_package(Threads REQUIRED)

target_link_libraries(sgame
    -${libgame}
    -${CMAKE_THREAD_LIBS_INIT}
)

install(TARGETS sgame
  RUNTIME DESTINATION bin OPTIONAL
)
