
# CMakeList.txt : CMake project for Squirrel-Engine, include source and define
# project specific logic here.
#
project(Squirrel-Game)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Squirrel-Game/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Squirrel-Game/Release)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(SOURCES "${SRC_DIR}/Squirrel-Game.cpp" "${SRC_DIR}/FatihActor.cpp""${SRC_DIR}/FatihActor.h" "${SRC_DIR}/Squirrel-Game.h")

# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
target_link_libraries (Squirrel-Game Squirrel-Engine)
# TODO: Add tests and install targets if needed.