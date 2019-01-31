add_executable(cmd
    cmd.cpp
)

set_target_properties(cmd
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    PREFIX ""
)

find_package(Threads REQUIRED)

target_link_libraries(cmd
    commands
)

install(TARGETS cmd
    RUNTIME DESTINATION cmd/bin
)

