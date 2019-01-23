
add_subdirectory(character)
add_subdirectory(world)

add_library(gamelogic
  GameManager.cpp
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
  PUBLIC
        world
  PRIVATE
    ${Boost_LIBRARIES}
)




install(TARGETS gamelogic
  ARCHIVE DESTINATION lib
)

