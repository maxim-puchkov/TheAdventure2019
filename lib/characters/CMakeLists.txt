add_library(${libcharacters}
    src/Character.cpp
    src/NPC.cpp
    src/Avatar.cpp
    src/AvatarManager.cpp
    src/Attributes.cpp
    src/Inventory.cpp
)

target_include_directories(${libcharacters}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libcharacters}
    ${libworld}
    ${libobjects}
)

set_target_properties(${libcharacters}
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS ${libcharacters}
  ARCHIVE DESTINATION lib
)
