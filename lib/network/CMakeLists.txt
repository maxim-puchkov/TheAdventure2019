add_library(${libnetwork}
  src/Server.cpp
  src/Client.cpp
)

find_package(Boost 1.68 COMPONENTS system REQUIRED)

target_include_directories(${libnetwork}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(${libnetwork}
  PRIVATE
    ${Boost_LIBRARIES}
)

set_target_properties(${libnetwork}
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS ${libnetwork}
  ARCHIVE DESTINATION lib
)

