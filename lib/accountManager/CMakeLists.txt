add_library(usermanager
  src/User.cpp
  src/AccountManager.cpp
)

target_include_directories(usermanager
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(usermanager
  PRIVATE
    ${Boost_LIBRARIES}
)

set_target_properties(usermanager
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS usermanager
  ARCHIVE DESTINATION lib
)

