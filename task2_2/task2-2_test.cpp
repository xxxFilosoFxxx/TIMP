//Тесты для задания ПЗ-2, Для файла task2-2.h (в котором содержится реализация Кучи).

#include <iostream>
#include "cstdio"
#include "ctime"

#include "task2-2.h"

#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

TEST_CASE("Test1", "task2-2_Tests") {
    Heap* heap = new Heap(10);
    heap->Max_Heap_Insert(5);
    heap->Max_Heap_Insert(12);
    heap->Max_Heap_Insert(7);
    heap->Max_Heap_Insert(15);

    heap->Max_Heap_Insert(16);
    heap->Max_Heap_Insert(17);
    heap->Max_Heap_Insert(18);
    heap->Max_Heap_Insert(19);
    heap->Max_Heap_Insert(8);
    heap->Max_Heap_Insert(2);
    REQUIRE(heap->max_key() == 19);

    heap->Heap_Extract_Max();
    heap->Heap_Extract_Max();
    REQUIRE(heap->max_key() == 17);
}

TEST_CASE("Test2", "task2-2_Tests") {
    Heap* heap = new Heap(10);
    heap->Max_Heap_Insert(8);
    REQUIRE(heap->Heap_Extract_Max() == 10);
    REQUIRE(heap->Heap_Extract_Max() == 8);
    REQUIRE_THROWS(heap->Heap_Extract_Max());
    REQUIRE_THROWS(heap->Heap_Change_key(heap->root, 0));
}

TEST_CASE("Test3", "task2-2_Tests")
{
    Heap* heap = new Heap(10);
    heap->Max_Heap_Insert(5);
    heap->Max_Heap_Insert(12);
    heap->Max_Heap_Insert(2);
    heap->Heap_Change_key(heap->root->left->left, 20);
    REQUIRE(heap->Heap_Extract_Max() == 20);
    for (int i = 0; i < 3; i++)
        heap->Heap_Extract_Max();
    heap->Max_Heap_Insert(12);
    heap->Heap_Extract_Max();
    REQUIRE_THROWS( heap->Heap_Extract_Max());

}
