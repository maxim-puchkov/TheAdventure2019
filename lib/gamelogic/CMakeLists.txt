
add_subdirectory(character)
add_subdirectory(world)

add_library(gamelogic
  GameManager.cpp
  world/src/WorldManager.cpp
  world/src/Room.cpp
  world/src/Exit.cpp
  GameManager.h
  world/include/WorldManager.h
  world/include/Room.h
  world/include/Exit.h 
)

target_include_directories(gamelogic
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/world
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(gamelogic
  PRIVATE
    ${Boost_LIBRARIES}
)

install(TARGETS gamelogic
  ARCHIVE DESTINATION lib
)

