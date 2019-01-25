add_library(world
        src/Exit.cpp
        src/Room.cpp
        src/WorldManager.cpp
        include/LocationCoordinates.h src/Area.cpp include/Area.h)

target_include_directories(world
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        )


set_target_properties(world
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

