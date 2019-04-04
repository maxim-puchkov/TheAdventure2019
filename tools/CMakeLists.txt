
# Set to ON to build chatserver quickly 
#   'cmake -DBUILD_LITE=YES ../adventure2019/'

if(NOT BUILD_LITE)
    add_subdirectory(chatserver)
else()
    add_subdirectory(liteserver)
endif()


add_subdirectory(chatclient)
