add_library(${libaccounts}
  src/AccountManager.cpp
        ../time/include/TimeStamp.h)

target_include_directories(${libaccounts}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(${libaccounts}
  PUBLIC
    ${libusers}
    ${libparsers}
  PRIVATE
    ${Boost_LIBRARIES}
)

set_target_properties(${libaccounts}
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS ${libaccounts}
    ARCHIVE DESTINATION lib
)

