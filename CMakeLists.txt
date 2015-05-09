cmake_minimum_required (VERSION 2.6)
project (gcode_to_descartes)

# 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -std=c++11")

add_library(gcode_parse src/gcode_lexer.cpp
                        src/gcode_iohelpers.cpp)

include_directories(include/gcode_to_descartes)

add_executable(gcode_test src/main.cpp)
target_link_libraries(gcode_test gcode_parse)