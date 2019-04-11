cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

set(Plankton_source
        Plankton.cpp
        Plankton.h
        )
add_library(Plankton ${Plankton_source})

target_link_libraries(Plankton Creature)
target_include_directories(Plankton PRIVATE ../Creature)

target_link_libraries(Plankton Field)
target_include_directories(Plankton PRIVATE ../Field)