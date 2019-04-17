cmake_minimum_required(VERSION 3.13)
project(TIMP)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_task2-1 task2_1/task2-1.h task2_1/task2-1_test.cpp)
add_executable(test_task2-2 task2_2/task2-2.h task2_2/task2-2_test.cpp )
add_executable(task_2-2_main task2_2/task2-2.h task2_2/task2-2_main.cpp)
add_executable(test_task2_3 task2_3/task2-3.h task2_3/task2-3.cpp task2_3/tests.cpp)
add_executable(task_2-3_main task2_3/task2-3.h task2_3/task2-3.cpp task2_3/main.cpp)
add_executable(ddz_main DDZ/OstTree.h DDZ/OstTree_realize.cpp DDZ/OstTree_main.cpp)
add_executable(ddz_test DDZ/OstTree.h DDZ/OstTree_realize.cpp DDZ/OstTree_tests.cpp)