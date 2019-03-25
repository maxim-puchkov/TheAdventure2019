add_library(${libobject} SHARED
	src/Object.cpp
	src/Keywords.cpp
	src/Description.cpp
    src/Actions.cpp
)

target_include_directories(${libobject}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libobject}
	${libauthentication}
    ${libenvironment}
    ${libdebugtools}
)

set_target_properties(${libobject}
    PROPERTIES
    COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libobject}
    LIBRARY DESTINATION lib
)
