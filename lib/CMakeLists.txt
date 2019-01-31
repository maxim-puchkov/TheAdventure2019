set(libcommands "commands")
set(libtypes "types")

add_subdirectory(${libcommands})
add_subdirectory(${libtypes})

add_subdirectory(accountmanager)
add_subdirectory(gamelogic)
add_subdirectory(networking)
add_subdirectory(usermanager)
