cmake_minimum_required(VERSION 3.13)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(queue queue/queue.h queue/queue.test.cpp)
add_executable(heap heap/heap.h heap/heap.test.cpp)

