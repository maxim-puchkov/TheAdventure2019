add_library(${libcommands}
    src/CommandParser.cpp
    src/Functor.cpp
    include/Command.h
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
    ${libaccounts}
    ${libusers}
    ${libworld}
    ${libtypes}
)


install(TARGETS ${libcommands}
  ARCHIVE DESTINATION lib
)
