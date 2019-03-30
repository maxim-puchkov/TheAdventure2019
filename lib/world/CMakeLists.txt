add_library(${libworld}
        src/Exit.cpp
        src/Room.cpp
        src/WorldManager.cpp
        src/Area.cpp
)

target_include_directories(${libworld}
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libworld}
    ${libusers}
    ${libcharacters}
    ${libAuthentication}
    ${libItem}
)

set_target_properties(${libworld}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libworld}
    ARCHIVE DESTINATION lib
)
