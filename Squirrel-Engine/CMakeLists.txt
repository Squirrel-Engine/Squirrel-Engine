# CMakeList.txt : CMake project for Squirrel-Engine, include source and define
# project specific logic here.
#
project("Squirrel-Engine")

include_directories(${YOUR_DIRECTORY} CMAKE_SOURCE_DIR/Squirrel-Engine/include)


FILE(GLOB_RECURSE SOURCES "src/Squirrel/*.cpp")
FILE(GLOB_RECURSE INCLUDES "include/*.h")

add_library(Squirrel-Engine STATIC ${SOURCES} ${INCLUDES})


# TODO: Add tests and install targets if needed.
