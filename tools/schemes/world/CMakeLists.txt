add_executable(sworld
  world.cpp
)

set_target_properties(sworld
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
                      PREFIX ""
)

target_link_libraries(sworld
    ${libworld}
    ${CMAKE_THREAD_LIBS_INIT}
)

install(TARGETS sworld
  RUNTIME DESTINATION bin OPTIONAL
)
