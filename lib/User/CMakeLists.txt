add_library(User
        src/User.cpp
        )

target_include_directories(User
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

set_target_properties(User
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
)