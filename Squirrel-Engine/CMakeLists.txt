# CMakeList.txt : CMake project for Squirrel-Engine, include source and define
# project specific logic here.
#
project(Squirrel-Engine)

cmake_minimum_required (VERSION 3.8)
#find_package(OpenGL REQUIRED)


set(CMAKE_BUILD_TYPE Debug)
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

#Add the given directories to those the compiler uses to search for include files.
include_directories(${SQUIRREL_ENGINE} ./)
include_directories(${YOUR_DIRECTORY} CMAKE_SOURCE_DIR/Squirrel-Engine/include)

FILE(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.cpp")
FILE(GLOB_RECURSE INCLUDES "include/*.h")

add_library(Squirrel-Engine STATIC ${SOURCES} ${INCLUDES})

# GLFW
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

#GLAD
set(GLAD_DIR "${LIB_DIR}/glad")
add_subdirectory("${GLAD_DIR}")
target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")

# TODO: Add tests and install targets if needed.