add_executable(saccs
  accs.cpp
)

set_target_properties(saccs
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
                      PREFIX ""
)

target_link_libraries(saccs
    ${libaccounts}
    ${CMAKE_THREAD_LIBS_INIT}
)

install(TARGETS saccs
  RUNTIME DESTINATION bin OPTIONAL
)
