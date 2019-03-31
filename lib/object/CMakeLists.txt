add_library(${libObject} SHARED
	src/Object.cpp
    src/ObjectData.cpp
	src/Keywords.cpp
	src/Description.cpp
    src/Actions.cpp
)

target_include_directories(${libObject}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libObject}
    PUBLIC
        ${libTools}
        ${libUserInterface}
        ${libEnvironment}
)

set_target_properties(${libObject}
    PROPERTIES
    COMPILE_FLAGS "${CXX_COVERAGE_FLAGS}"
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libObject}
    LIBRARY DESTINATION lib
)
