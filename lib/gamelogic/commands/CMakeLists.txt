add_library(ServerCommands
 	src/ServerCommands.cpp
)

target_include_directories(ServerCommands
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(ServerCommands
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS ServerCommands
  ARCHIVE DESTINATION lib
)

