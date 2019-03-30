add_library(${libauthentication} SHARED
	src/Authenticator.cpp
)

target_include_directories(${libauthentication}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libauthentication}
    ${libtools}
	${libenvironment}
)

set_target_properties(${libauthentication}
    PROPERTIES
    COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libauthentication}
    LIBRARY DESTINATION lib
)
