
add_subdirectory(character)
add_subdirectory(commands)
add_subdirectory(world)

add_library(gamelogic
  src/GameManager.cpp
)

target_include_directories(gamelogic
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(gamelogic
  PRIVATE
    world
    accountmanager
    ${Boost_LIBRARIES}
)

set_target_properties(gamelogic
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS gamelogic
  ARCHIVE DESTINATION lib
)

