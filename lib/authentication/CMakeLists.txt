add_library(${libauth}
	src/UUID.cpp
)

target_include_directories(${libauth}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libauth}

)

set_target_properties(${libauth}
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS ${libauth}
    ARCHIVE DESTINATION lib
)

