
# CMakeList.txt : CMake project for Squirrel-Engine, include source and define
# project specific logic here.
#
project(Squirrel-Game)


set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(VENDOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Squirrel-Engine/include/vendor")
include_directories( ${INC_DIR} ${VENDOR_DIR} )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Squirrel-Game/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Squirrel-Game/Release)
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG})
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

FILE(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp" "${INC_DIR}/*.cpp")
FILE(GLOB_RECURSE INCLUDES "${INC_DIR}/*.h" )
# Add source to this project's executable.
add_executable (Squirrel-Game ${SOURCES} ${INCLUDES})
if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)
# TODO: Add tests and install targets if needed.

target_include_directories(${PROJECT_NAME} PRIVATE "${SRC_DIR}")
target_link_libraries (Squirrel-Game Squirrel-Engine)
