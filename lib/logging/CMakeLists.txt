add_library(${liblogging}
  src/Logger.cpp
)

SET(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS system log)

add_definitions(-DBOOST_LOG_DYN_LINK)

target_include_directories(${liblogging}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(${liblogging}
  ${Boost_LIBRARIES}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_LOG_LIBRARY}
)

set_target_properties(${liblogging}
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS ${liblogging}
    ARCHIVE DESTINATION lib
)

