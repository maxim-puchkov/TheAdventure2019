add_library(commands
 	src/CommandProcessor.cpp
	src/TokenizedString.cpp
	src/Environment.txx
)

target_include_directories(commands
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(commands
	world
)

set_target_properties(commands
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS commands
  ARCHIVE DESTINATION lib
)
