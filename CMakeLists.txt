cmake_minimum_required(VERSION 3.16)

set(_target "PDV")

#################################################
# List of project files
################################################

set(_src
    main.cpp
    qml.qrc
)
include(build/conanbuildinfo.cmake)
conan_basic_setup()
find_package(Boost 1.74.0 EXACT REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -fstrict-aliasing -pedantic-errors -pedantic -Wno-deprecated-declarations -Wno-unused-variable")
add_compile_options("-lstdc++")
find_package(Qt5 COMPONENTS Core Quick REQUIRED)
add_subdirectory(TreeBuilder)

add_executable(${_target} ${_src})
target_compile_definitions(PDV
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${_target}
   PRIVATE
   Qt5::Core
   Qt5::Quick
   TreeBuilder
)
