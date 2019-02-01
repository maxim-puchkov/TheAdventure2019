add_executable(susers
  users.cpp
)

set_target_properties(susers
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
                      PREFIX ""
)

target_link_libraries(susers
    ${libusers}
    ${CMAKE_THREAD_LIBS_INIT}
)

install(TARGETS susers
  RUNTIME DESTINATION bin OPTIONAL
)
