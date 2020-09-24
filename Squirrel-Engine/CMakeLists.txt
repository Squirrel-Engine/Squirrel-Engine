# CMakeList.txt : CMake project for Squirrel-Engine, include source and define
# project specific logic here.
#
project("Squirrel-Engine")
cmake_minimum_required (VERSION 3.8)
include_directories(${YOUR_DIRECTORY} CMAKE_SOURCE_DIR/Squirrel-Engine/include)
FILE(GLOB_RECURSE SOURCES "src/*.cpp")
FILE(GLOB_RECURSE INCLUDES "include/*.h")
set(CMAKE_BUILD_TYPE Debug)

add_library(Squirrel-Engine STATIC ${SOURCES} ${INCLUDES} src/Utilities/StringUtilities.cpp)

add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
target_link_libraries(Squirrel-Engine PRIVATE glfw)
# TODO: Add tests and install targets if needed.
