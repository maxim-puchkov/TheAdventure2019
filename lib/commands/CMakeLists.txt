#
#   Commands CMakeLists
#


cmake_minimum_required(VERSION 3.12)
project(${commands} VERSION 1.0)

if(NOT BUILD_ALL_TARGETS)

    add_library(${PROJECT_NAME}
        # Always included commands
        src/Command.cpp
        src/CommandHelp.cpp
        src/CommandLogin.cpp        # use 'login abc abc' or any existing account

        # Testing items
        src/CommandTake.cpp
    )

else()

    add_library(${PROJECT_NAME}
        src/Command.cpp
        src/CommandLogin.cpp
        src/CommandCreate.cpp
        src/CommandLogout.cpp
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
        src/CommandTake.cpp
        src/CommandPut.cpp
        src/CommandDrop.cpp
        src/CommandUse.cpp
        src/CommandEquip.cpp
#       src/CommandUnequip.cpp
        src/CommandMinigame.cpp
        src/CommandCombat.cpp
        src/CommandAttack.cpp
        src/CommandFlee.cpp
        src/CommandCast.cpp
        src/CommandCreateItem.cpp
        src/CommandDeleteRoom.cpp
    )

endif()


target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIR}
)


target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${combat}
        ${characters}
        ${world}
        ${users}
        ${print}
    PRIVATE
        ${Boost_LIBRARIES}
)



set_target_properties(${PROJECT_NAME}
    PROPERTIES
        COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
)


install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)
