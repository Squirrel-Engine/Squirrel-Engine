# CMakeList.txt : CMake project for Squirrel-Engine, include source and define
# project specific logic here.
#
project(Squirrel-Game)

set(CMAKE_BUILD_TYPE Debug)
# Add source to this project's executable.
add_executable (Squirrel-Game "Squirrel-Game.cpp" "Squirrel-Game.h")
target_link_libraries (Squirrel-Game Squirrel-Engine)
# TODO: Add tests and install targets if needed.
