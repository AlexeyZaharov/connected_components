cmake_minimum_required(VERSION 3.15)
project(untitled1)

include_directories(include/ sources/)
set(CMAKE_CXX_STANDARD 17)
set(SOURCES sources/graph.cpp)

add_executable(untitled1 main.cpp ${SOURCES})