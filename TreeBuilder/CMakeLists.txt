cmake_minimum_required(VERSION 3.15)

project(TreeBuilder LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -fstrict-aliasing -pedantic-errors -pedantic -Wno-deprecated-declarations -Wno-unused-variable")

find_package(Qt5 COMPONENTS Core REQUIRED)

add_link_options("-shared")
add_executable(TreeBuilder
    Types.h
    Tree.cpp
    Tree.h
    XMLBuilder.cpp
    XMLBuilder.h)

#target_link_libraries(TreeBuilder PRIVATE Qt5::Core)
