add_library(accountmanager
  src/User.cpp
  src/AccountManager.cpp
)

target_include_directories(accountmanager
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(accountmanager
  PRIVATE
    ${Boost_LIBRARIES}
)

set_target_properties(accountmanager
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS accountmanager
  ARCHIVE DESTINATION lib
)

