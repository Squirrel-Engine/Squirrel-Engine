# CMakeList.txt : CMake project for Squirrel-Engine, include source and define
# project specific logic here.
#
project(Squirrel-Engine)

cmake_minimum_required (VERSION 3.8)
find_package(OpenGL REQUIRED)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(RES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/res")

#Add the given directories to those the compiler uses to search for include files.
include_directories( ${INC_DIR} )

FILE(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp" "${INC_DIR}/*.cpp" "${RES_DIR}/shaders/*.shader")
FILE(GLOB_RECURSE INCLUDES "${INC_DIR}/*.h" )

add_library(Squirrel-Engine STATIC ${SOURCES} ${INCLUDES})

# GLFW
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_include_directories(${PROJECT_NAME} PUBLIC "${GLFW_DIR}/include")	
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

#GLAD
set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PUBLIC "${GLAD_DIR}/include")
target_link_libraries(${PROJECT_NAME} "glad" )

#GLM
set(GLM_DIR "${INC_DIR}/vendor/glm")
add_subdirectory("${GLM_DIR}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLM_DIR}/glm")
target_link_libraries(${PROJECT_NAME} glm)

#ASSIMP


# TODO: Add tests and install targets if needed.