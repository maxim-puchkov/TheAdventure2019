add_library(userdb
  src/UserDB.cpp
)

target_include_directories(userdb
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(userdb
  PUBLIC
    ${libusers}
    ${libparsers}
  PRIVATE
    ${Boost_LIBRARIES}
)

set_target_properties(userdb
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS userdb
    ARCHIVE DESTINATION lib
)

