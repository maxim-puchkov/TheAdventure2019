add_library(commands
    src/Parser.cpp
    src/Command.cpp
)

target_include_directories(commands
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(commands
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

target_link_libraries(commands
    ${libtypes}
)


install(TARGETS commands
  ARCHIVE DESTINATION lib
)
