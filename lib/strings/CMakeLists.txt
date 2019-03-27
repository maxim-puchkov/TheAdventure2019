add_library(${libstrings}
  src/Internationalization.cpp
)

target_include_directories(${libstrings}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libstrings}
  PUBLIC
    ${libparsers}
)

set_target_properties(${libstrings}
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS ${libstrings}
    ARCHIVE DESTINATION lib
)

