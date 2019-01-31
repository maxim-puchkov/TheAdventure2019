add_library(${libgame}
	src/GameManager.cpp
)

target_include_directories(${libgame}
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${Boost_INCLUDE_DIR}
)

target_link_libraries(${libgame}
    ${libaccounts}
    ${libcharacters}
    ${libworld}
    ${libusers}
    ${Boost_LIBRARIES}
)

set_target_properties(${libgame}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libgame}
  ARCHIVE DESTINATION lib
)

