cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

set(Fishes_source
        Predators.cpp
        Predators.h
        Goats.cpp
        Goats.h
        )
add_library(Fishes ${Fishes_source})

target_link_libraries(Fishes Creature)
target_include_directories(Fishes PRIVATE ../Creature)

target_link_libraries(Fishes Field)
target_include_directories(Fishes PRIVATE ../Field)

#target_link_libraries(Fishes Carnivores)
#target_link_libraries(Fishes Herbivores)

#target_include_directories(Fishes PRIVATE ../Carnivores)
#target_include_directories(Fishes PRIVATE ../Herbivores)
