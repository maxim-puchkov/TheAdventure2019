add_library(${libtime}
  include/TimeStamp.h
)

target_include_directories(${libparsers}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(${libtime}
        ${libminigame}
        )

set_target_properties(${libtime}
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS ${libtime}
    ARCHIVE DESTINATION lib
)

