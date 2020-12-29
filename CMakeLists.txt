# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
# enable C and C++ language
project (Squirrel)

cmake_minimum_required (VERSION 3.8)

enable_testing()

# Include sub-projects.
add_subdirectory(googletest)
add_subdirectory (Squirrel-Engine)
add_subdirectory (Squirrel-Game)
add_subdirectory (Squirrel-Launcher)
add_subdirectory(test)




