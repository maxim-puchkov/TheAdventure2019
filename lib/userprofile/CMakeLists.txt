add_library(userprofile
  src/User.cpp
)

target_include_directories(userprofile
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(userprofile
  PRIVATE
    ${Boost_LIBRARIES}
)

set_target_properties(userprofile
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS userprofile
  ARCHIVE DESTINATION lib
)

