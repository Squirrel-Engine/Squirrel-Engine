# CMakeList.txt : CMake project for Squirrel-Engine, include source and define
# project specific logic here.
#
project("Squirrel-Engine")

include_directories(${YOUR_DIRECTORY} CMAKE_SOURCE_DIR/Squirrel-Engine/include)
FILE(GLOB_RECURSE SOURCES "src/*.cpp")
FILE(GLOB_RECURSE INCLUDES "include/*.h")


add_library(Squirrel-Engine SHARED ${SOURCES} ${INCLUDES})

add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
target_link_libraries(Squirrel-Engine PRIVATE glfw)
# TODO: Add tests and install targets if needed.
