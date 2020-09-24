cmake_minimum_required (VERSION 3.8)
set(This Tests)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

FILE(GLOB_RECURSE SOURCES "*.cpp")
SET(CMAKE_EXE_LINKER_FLAGS  "/FORCE")
add_executable(${This} ${SOURCES})
target_link_libraries(${This} PUBLIC
    gtest
    gtest_main
    Squirrel-Engine
)

add_test(
    NAME ${This}
    COMMAND ${This}
)