cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

set(Creature_source
        Creature.cpp
        Creature.h
        Cell.cpp
        Cell.h
        )
add_library(Creature ${Creature_source})

target_link_libraries(Creature Field)
target_include_directories(Creature PRIVATE ../Field)