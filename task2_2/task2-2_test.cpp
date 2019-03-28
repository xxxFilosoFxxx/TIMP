//Тесты для задания ПЗ-2, для файла task2-2.h и task2-2.cpp (в которых содержится реализация Кучи).

#include <iostream>
#include "cstdio"
#include "ctime"

#include "task2-2.h"

#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

TEST_CASE("Test1", "task2-2_Tests") {
    Heap<int>* heap = new Heap<int>(10, 0);
    heap->Max_Heap_Insert(5, 0);
    heap->Max_Heap_Insert(12, 0);
    heap->Max_Heap_Insert(7, 0);
    heap->Max_Heap_Insert(15, 0);

    heap->Max_Heap_Insert(16, 0);
    heap->Max_Heap_Insert(17, 5);
    heap->Max_Heap_Insert(18, 0);
    heap->Max_Heap_Insert(19, 1);
    heap->Max_Heap_Insert(8, 0);
    heap->Max_Heap_Insert(2, 0);
    REQUIRE(heap->max_key() == 19);
    REQUIRE(heap->max_value() == 1);

    heap->Heap_Extract_Max();
    heap->Heap_Extract_Max();
    REQUIRE(heap->max_key() == 17);
    REQUIRE(heap->max_value() == 5);
}

TEST_CASE("Test2", "task2-2_Tests") {
    Heap<int>* heap = new Heap<int>(10, 1);
    heap->Max_Heap_Insert(8, 2);
    heap->Max_Heap_Insert(7, 3);
    heap->Max_Heap_Insert(6, 4);
    REQUIRE(heap->max_value() == 1);
    REQUIRE(heap->Heap_Extract_Max() == 10);
    REQUIRE(heap->max_value() == 2);
    REQUIRE(heap->Heap_Extract_Max() == 8);
    REQUIRE(heap->max_value() == 3);
    REQUIRE(heap->Heap_Extract_Max() == 7);
    REQUIRE(heap->max_value() == 4);
    REQUIRE(heap->Heap_Extract_Max() == 6);
    REQUIRE_THROWS(heap->max_value());
    REQUIRE_THROWS(heap->Heap_Extract_Max());
    REQUIRE_THROWS(heap->Heap_Change_key(heap->root, 0));
}

TEST_CASE("Test3", "task2-2_Tests")
{
    Heap<int>* heap = new Heap<int>(10, 0);
    heap->Max_Heap_Insert(5, 0);
    heap->Max_Heap_Insert(12, 0);
    heap->Max_Heap_Insert(2, 0);
    heap->Heap_Change_key(heap->root->left->left, 20);
    REQUIRE(heap->Heap_Extract_Max() == 20);
    for (int i = 0; i < 3; i++)
        heap->Heap_Extract_Max();
    heap->Max_Heap_Insert(12, 0);
    heap->Heap_Extract_Max();
    REQUIRE_THROWS( heap->Heap_Extract_Max());
}

TEST_CASE("Test4", "task2-2_Tests") {
    Heap<char>* heap = new Heap<char>(10, '0');
    heap->Max_Heap_Insert(5, '0');
    heap->Max_Heap_Insert(12, '0');
    heap->Max_Heap_Insert(7, '0');
    heap->Max_Heap_Insert(15, '0');

    heap->Max_Heap_Insert(16, '0');
    heap->Max_Heap_Insert(17, '5');
    heap->Max_Heap_Insert(18, '0');
    heap->Max_Heap_Insert(19, '1');
    heap->Max_Heap_Insert(8, '0');
    heap->Max_Heap_Insert(2, '0');
    REQUIRE(heap->max_key() == 19);
    REQUIRE(heap->max_value() == '1');

    heap->Heap_Extract_Max();
    heap->Heap_Extract_Max();
    REQUIRE(heap->max_key() == 17);
    REQUIRE(heap->max_value() == '5');
}


