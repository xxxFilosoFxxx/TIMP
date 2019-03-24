//
// Created by Roman on 03.03.2019.
//

#include <iostream>
#include "cstdio"
#include "ctime"

#include "task2-2.h"

#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

TEST_CASE("Test1", "task2-2_Tests") {
    Heap* heap = new Heap(10);
    heap->Max_Heap_Insert(heap->root, 5);
    heap->Max_Heap_Insert(heap->root, 12);
    heap->Max_Heap_Insert(heap->root->left, 7);
    heap->Max_Heap_Insert(heap->root->left, 15);

    heap->Max_Heap_Insert(heap->root->right, 16);
    heap->Max_Heap_Insert(heap->root->right, 17);
    heap->Max_Heap_Insert(heap->root->left->left, 18);
    heap->Max_Heap_Insert(heap->root->left->left, 19);

    REQUIRE(heap->max_key() == 19);
   // REQUIRE(heap->Heap_Extract_Max() == 19);
    heap->Heap_Extract_Max();
    REQUIRE(heap->max_key() == 18);


}

//TEST_CASE("Test2", "task2-2_Tests") {
/*

}*/