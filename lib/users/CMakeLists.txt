add_library(${libusers}
    src/User.cpp
    src/OnlineUserManager.cpp
)

target_include_directories(${libusers}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(${libusers}
    PUBLIC
        ${libaccounts}
        ${libcharacters}
	${libparsers}
	${libuserdb}
	${libstrings}
    PRIVATE
        ${Boost_LIBRARIES}
)

set_target_properties(${libusers}
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS ${libusers}
  ARCHIVE DESTINATION lib
)

