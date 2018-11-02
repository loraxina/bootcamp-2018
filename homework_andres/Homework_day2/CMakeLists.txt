cmake_minimum_required (VERSION 2.6)
project (Vector)

include_directories(public)

add_executable(Vector_app private/main.cpp private/position.cpp private/unit_vector.cpp)
