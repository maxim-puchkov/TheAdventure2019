add_library(${libobjects}
	src/Object.cpp
	src/KeywordSet.cpp
	src/Collection.cpp
	src/Description.cpp
	src/Collection.cpp
)

target_include_directories(${libobjects}
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${libobjects}
	${libbuilder}
	${libauthentication}
)

set_target_properties(${libobjects}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)

install(TARGETS ${libobjects}
    ARCHIVE DESTINATION lib
)
