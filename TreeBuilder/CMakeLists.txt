set(_target "TreeBuilder")

#################################################
# List of project files
#################################################

set(_src
    Node.cpp
    XMLBuilder.cpp
    XMLManager.cpp

    XMLBuilder.h
    Node.h
    Types.h
    XMLManager.h
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -fstrict-aliasing -pedantic-errors -pedantic -Wno-deprecated-declarations -Wno-unused-variable")
find_package(Qt5 COMPONENTS Core REQUIRED)
add_library(${_target} STATIC ${_src} )
add_link_options("-shared")
target_link_libraries(${_target}
   PRIVATE
   Qt5::Core
)



