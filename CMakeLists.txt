#
# CMakeLists.txt
#


cmake_minimum_required(VERSION 3.12)
project(adventure2019)





# Package name and version

set(PACKAGE_NAME ImmersiveWorlds)
set(PACKAGE_VERSION 0.1)
set(PACKAGE_STRING "${PACKAGE_NAME} ${PACKAGE_VERSION}")
set(PACKAGE_BUGREPORT "wsumner@sfu.ca")





# Declare new libraries here (in alphabetical order)

set(libAuthentication "authentication")
set(libBuilder "builder")
set(libcharacterdb "characterDB")
set(libcharacters "characters")
set(libcombat "combat")
set(libcommands "commands")
set(libEnvironment "environment")
set(libgame "game")
set(libItem "item")
set(libminigame "minigame")
set(libnetwork "network")
set(libObject "object")
set(libparsers "parsers")
set(libTools "tools")
set(libUserInterface "user-interface")
set(libuserdb "userdb")
set(libusers "users")
set(libUtility "utility")
set(libworld "world")



# Complier options

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fno-rtti")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -fsanitize=address,undefined -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra  -Wstrict-aliasing -pedantic -Werror -Wunreachable-code -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option")





# Set and link output directories for executables and libraries

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
link_directories(${LIBRARY_OUTPUT_PATH})
set(CMAKE_TEMP_LIBRARY_PATH "${PROJECT_BINARY_DIR}/lib")





# Add libraries, binaries, and tests subdirectories

add_subdirectory(lib)
add_subdirectory(tools)
add_subdirectory(test)
