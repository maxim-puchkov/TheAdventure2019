add_library(Character
 	src/Character.cpp
	src/Avatar.cpp
	src/PlayerControlledCharacter.cpp
	src/NonPlayerControlledCharacter.cpp
	src/Attributes.cpp
)

target_include_directories(Character
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(Character
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS Character
  ARCHIVE DESTINATION lib
)

