add_library(${libuserdb}
  src/UserDB.cpp
)

target_include_directories(${libuserdb}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(${libuserdb}
  PUBLIC
    ${libusers}
    ${libparsers}
  PRIVATE
    ${Boost_LIBRARIES}
)

set_target_properties(${libuserdb}
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS ${libuserdb}
    ARCHIVE DESTINATION lib
)

