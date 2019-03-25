add_library(${libauthentication} SHARED
	src/Authentication.cpp
    src/Identity.cpp
)

target_include_directories(${libauthentication}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libauthentication}
	${libenvironment}
)

set_target_properties(${libauthentication}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libauthentication}
    LIBRARY DESTINATION lib
)
