add_library(character
 	src/Character.cpp
	src/Avatar.cpp
	src/PlayerControlledCharacter.cpp
	src/NonPlayerControlledCharacter.cpp
	src/Attributes.cpp
)

target_include_directories(character
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(character
	world
)

set_target_properties(character
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS character
  ARCHIVE DESTINATION lib
)

