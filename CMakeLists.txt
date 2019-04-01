#
#   Root CMakeLists.txt
#   Updated: 2019-04-01
#


# CMakeLists configuration

cmake_minimum_required(VERSION 3.12)
project(adventure2019 VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(BUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)





# Package name and version

set(PACKAGE_NAME ImmersiveWorlds)
set(PACKAGE_VERSION 1.0)
set(PACKAGE_STRING "${PACKAGE_NAME} ${PACKAGE_VERSION}")
set(PACKAGE_BUGREPORT "wsumner@sfu.ca")





# Declare new libraries here (in alphabetical order)

set(authentication "authentication")
set(builder "builder")
set(characters "characters")
set(combat "combat")
set(commands "commands")
set(environment "environment")
set(exceptions "exceptions")
set(game "game")
set(item "item")
set(minigame "minigame")
set(network "network")
set(object "object")
set(print "print")
set(parsers "parsers")
set(time "time")
set(traits "traits")
set(user-interface "user-interface")
set(users "users")
set(world "world")





#       set(libcharactersdb "charactersDB")   # Deleted. Files moved to characters
#       set(libuserdb "userdb")               # Deleted. Files moved to user





# Complier flags

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fno-rtti")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -fsanitize=address,undefined -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra  -Wstrict-aliasing -pedantic -Werror -Wunreachable-code -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option")





# Set and link output directories for executables and libraries

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}")





# Add subdirectory for libraries, executables, and tests

add_subdirectory(lib)
add_subdirectory(tools)
# add_subdirectory(test)
