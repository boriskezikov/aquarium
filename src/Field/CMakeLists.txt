cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)

set(Field_source
        Field.cpp
        Field.h
        )
add_library(Field ${Field_source})

target_link_libraries(Field Creature)
target_include_directories(Field PRIVATE ../Creature)

target_link_libraries(Field Fishes)
target_include_directories(Field PRIVATE ../Fishes)

target_link_libraries(Field Plankton)
target_include_directories(Field PRIVATE ../Plankton)