
add_subdirectory(character)
add_subdirectory(world)

add_library(gamelogic
  world/src/WorldManager.cpp
  world/src/Room.cpp
  world/include/WorldManager.h
  world/include/Room.h
  world/include/Exit.h)

target_include_directories(gamelogic
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/world
)

install(TARGETS gamelogic
  ARCHIVE DESTINATION lib
)

