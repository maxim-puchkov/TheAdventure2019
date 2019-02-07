add_executable(cmd
    cmd.cpp
)

set_target_properties(cmd
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    PREFIX ""
)

target_link_libraries(cmd
    ${libcommands}
    ${libusers}
)

install(TARGETS cmd
    RUNTIME DESTINATION bin
)

