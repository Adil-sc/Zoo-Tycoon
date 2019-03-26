cmake_minimum_required(VERSION 3.12)
project(Project2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project2 main.cpp Animal.cpp Animal.h Zoo.cpp Zoo.h Tiger.cpp Tiger.h Penguin.cpp Penguin.h Turtle.cpp Turtle.h inputValidation.h inputValidation.cpp)