add_library(${libcommands}
    src/Parser.cpp
    src/CommandLogin.cpp
)

target_include_directories(${libcommands}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
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
