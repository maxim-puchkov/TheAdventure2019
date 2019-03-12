add_library(${libcharacterdb}
  src/UserDB.cpp
)

target_include_directories(${libcharacterdb}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(${libcharacterdb}
  PUBLIC
    ${libusers}
    ${libparsers}
    ${libparsers}
    ${libcharacters}
  PRIVATE
    ${Boost_LIBRARIES}
)

set_target_properties(${libcharacterdb}
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS ${libcharacterdb}
    ARCHIVE DESTINATION lib
)

