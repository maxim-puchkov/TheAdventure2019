#
#   Root CMakeLists.txt
#   Updated: 2019-04-03
#


# CMakeLists configuration

cmake_minimum_required(VERSION 3.12)
project(adventure2019 VERSION 1.0)

# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(BUILD_SHARED_LIBS ON)





# Package name and version

set(PACKAGE_NAME ImmersiveWorlds)
set(PACKAGE_VERSION 1.0)
set(PACKAGE_STRING "${PACKAGE_NAME} ${PACKAGE_VERSION}")
set(PACKAGE_BUGREPORT "wsumner@sfu.ca")





# Build type

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)





# Choose to build all targets including all commands and game

#  Default option to build quickly is chosen by default
#       'cmake -DBUILD_ALL_TARGETS=NO ../adventure2019/'
#
#  Choose this option to include all game commands and force 23 additional builds of all code:
#       'cmake -DBUILD_ALL_TARGETS=YES ../adventure2019/'

if(BUILD_ALL_TARGETS)
    add_compile_definitions(BUILD_ALL_TARGETS)
endif()





# Find dependencies

find_package(Boost 1.68 COMPONENTS system REQUIRED)





# Declare new libraries here (in alphabetical order)

set(location "location")
set(authentication "authentication")
set(builder "builder")
set(characters "characterDB")
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
set(users "userdb")
set(world "world")





#       set(libcharacters "characters")   # Deleted. Files moved to characterDB
#       set(libuserdb "userdb")               # Deleted. Files moved to user





# Statement coverage
# NOTE: Coverage only works/makes sense with debug builds

if(ENABLE_COVERAGE)

    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang")
        set(CXX_COVERAGE_FLAGS "-fprofile-instr-generate -fcoverage-mapping")
        message("-- Enabling coverage instrumentation with: ${CXX_COVERAGE_FLAGS}")
    else()
        message(FATAL_ERROR "-- Coverage generation is only supported for clang")
    endif()

endif()





# Complier flags including additional warnings

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fno-rtti")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -fsanitize=undefined -fno-omit-frame-pointer")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra  -Wstrict-aliasing -pedantic #-Wunreachable-code -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 #-Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow #-Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros #-Wno-parentheses -fdiagnostics-show-option")
#char_filePath




# Set and link output directories for executables and libraries

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}")





# Add subdirectory for libraries and executables

add_subdirectory(lib)
add_subdirectory(tools)
# add_subdirectory(test)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})