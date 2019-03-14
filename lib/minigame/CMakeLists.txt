add_library(${libminigame}
        src/Board.cpp
        src/MoveValidator.cpp
        src/Piece.cpp
        src/MiniGameLobby.cpp
        src/MiniGameMatch.cpp)


cmake_minimum_required(VERSION 3.12)
find_package(Boost 1.68 COMPONENTS system REQUIRED)


target_include_directories(${libminigame}
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # this line here fixes the include/include issues
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${Boost_INCLUDE_DIR}
        )

target_link_libraries(${libminigame}
        ${Boost_LIBRARIES}
        ${libtime}
        )

set_target_properties(${libminigame}
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        )

install(TARGETS ${libminigame}
        ARCHIVE DESTINATION lib
        )
