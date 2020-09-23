cmake_minimum_required (VERSION 3.8)
set(This Tests)

FILE(GLOB_RECURSE Sources
    "ExampleTests.cpp"
    "StringUtilities_test.cpp"

)
SET(CMAKE_EXE_LINKER_FLAGS  "/FORCE")
add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
)

add_test(
    NAME ${This}
    COMMAND ${This}
)