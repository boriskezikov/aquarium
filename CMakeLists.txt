cmake_minimum_required(VERSION 3.13)
project(aquarium_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)
include_directories(src/Creature)
include_directories(src/Field)
include_directories(src/Fishes)
include_directories(src/Plankton)

add_executable(aquarium_master
        src/Creature/Cell.cpp
        src/Creature/Cell.h
        src/Creature/Creature.cpp
        src/Creature/Creature.h
        src/Field/Field.cpp
        src/Field/Field.h
        src/Fishes/Predators.cpp
        src/Fishes/Predators.h
        src/Fishes/Goats.cpp
        src/Fishes/Goats.h
        src/Plankton/Plankton.cpp
        src/Plankton/Plankton.h
        src/CMakeLists.txt
        CMakeLists.txt
        main.cpp)
