add_library(${libminigame}
        src/Board.cpp
        src/MoveValidator.cpp
        src/Piece.cpp
        src/MiniGameLobby.cpp include/MiniGameLobby.h src/MiniGameMatch.cpp include/MiniGameMatch.h)




target_include_directories(minigame
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # this line here fixes the include/include issues
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${Boost_INCLUDE_DIR}
        )

target_link_libraries(minigame
        ${Boost_LIBRARIES}
        )

set_target_properties(minigame
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        )

install(TARGETS minigame
        ARCHIVE DESTINATION lib
        )

add_subdirectory(test)
