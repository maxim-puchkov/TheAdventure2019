add_library(${libcommands}
    src/Parser.cpp
    src/Command.cpp
    src/CommandLogin.cpp
    src/CommandLogout.cpp
    src/CommandCreate.cpp
    src/CommandHelp.cpp
    src/CommandSay.cpp
    src/CommandTell.cpp
    src/CommandYell.cpp
    src/CommandLook.cpp
    src/CommandExamine.cpp
    src/CommandMove.cpp
    src/CommandCreateAva.cpp
    src/CommandEditAva.cpp
    src/CommandCreateRoom.cpp
    src/CommandEditRoom.cpp
    src/CommandUse.cpp
    src/CommandEquip.cpp
    src/CommandPickup.cpp
    src/CommandDrop.cpp
    src/CommandPut.cpp
    src/CommandMinigame.cpp
    src/CommandCombat.cpp
    src/CommandAttack.cpp
    src/CommandFlee.cpp
    src/CommandCast.cpp
)

target_include_directories(${libcommands}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

set_target_properties(${libcommands}
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

target_link_libraries(${libcommands}
    ${libtypes}
    ${libaccounts}
    ${libcharacters}
    ${libworld}
    ${libusers}
    ${libcharacter}
    ${Boost_LIBRARIES}
    ${libusers}
)


install(TARGETS ${libcommands}
  ARCHIVE DESTINATION lib
)
