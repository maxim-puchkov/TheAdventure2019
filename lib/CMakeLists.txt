#
#   lib CMakeLists
#




# Add subdirectories in alphabetical order

# Protocols
add_subdirectory(${builder})
add_subdirectory(${object})


# Debugging
add_subdirectory(${print})


# Libraries
add_subdirectory(${authentication})
add_subdirectory(${characters})
add_subdirectory(${config})
add_subdirectory(${combat})
add_subdirectory(${commands})
add_subdirectory(${environment})
add_subdirectory(${game})
add_subdirectory(${item})
add_subdirectory(${minigame})
add_subdirectory(${network})
add_subdirectory(${parsers})
add_subdirectory(${properties})
add_subdirectory(${time})
add_subdirectory(${user-interface})
add_subdirectory(${users})
add_subdirectory(${world})





# Added (coverage tests)
# add_subdirectory(simple)


# Moved
#   add_subdirectory(${libuserdb})
#   add_subdirectory(characterDB)
#   add_subdirectory(test)


# Excluded
#   add_subdirectory(${exceptions})
