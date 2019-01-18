
add_library(gamelogic
  world/WorldManager.cpp
  world/Room.cpp
        include/WorldManager.h include/Room.h include/Exit.h)

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

