add_library(${libcharacters}
     src/Character.cpp
     src/Attributes.cpp
     src/CharacterManager.cpp
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
    ${libcharacterdb}
    ${libminigame}
    ${libcombat}
)

set_target_properties(${libcharacters}
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS ${libcharacters}
  ARCHIVE DESTINATION lib
)
