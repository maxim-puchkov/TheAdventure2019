#
#   lib CMakeLists
#



# Add subdirectories in alphabetical order

add_subdirectory(${location})
add_subdirectory(${authentication})
add_subdirectory(${builder})
add_subdirectory(${characters})
add_subdirectory(${config})
add_subdirectory(${combat})
add_subdirectory(${commands})
add_subdirectory(${environment})
add_subdirectory(${game})
add_subdirectory(${item})
add_subdirectory(${minigame})
add_subdirectory(${network})
add_subdirectory(${object})
add_subdirectory(${parsers})
add_subdirectory(${print})
add_subdirectory(${time})
add_subdirectory(${traits})
add_subdirectory(${user-interface})
add_subdirectory(${users})
add_subdirectory(${world})




# Added
add_subdirectory(simple)
add_subdirectory(test)



# Moved
#   add_subdirectory(${libuserdb})
#   add_subdirectory(characterDB)


# Excluded
#   add_subdirectory(${exceptions})
