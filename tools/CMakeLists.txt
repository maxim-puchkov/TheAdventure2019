
# Choose to build all targets including all commands and game
#
#  Default option to build quickly is chosen by default
#       'cmake -DBUILD_ALL_TARGETS=NO ../adventure2019'
#
#  Choose this option to include all game commands and force 23 additional builds of all code:
#       'cmake -DBUILD_ALL_TARGETS=NO ../adventure2019'

if(NOT BUILD_ALL_TARGETS)
    add_subdirectory(liteserver)
else()
    add_compile_definitions(BUILD_ALL_TARGETS)
    add_subdirectory(chatserver)
endif()


add_subdirectory(chatclient)

