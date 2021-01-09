# CMakeList.txt : CMake project for Squirrel-Engine, include source and define
# project specific logic here.
#
project(Squirrel-Game)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Squirrel-Game/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Squirrel-Game/Release)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Add source to this project's executable.
add_executable (Squirrel-Game "Squirrel-Game.cpp" "Squirrel-Game.h")
target_link_libraries (Squirrel-Game Squirrel-Engine)
# TODO: Add tests and install targets if needed.
