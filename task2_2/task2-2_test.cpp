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

    heap->Max_Heap_Insert(heap->root->right, 1);
   // heap->Max_Heapify(heap->root->right);
  //  heap->Max_Heapify(heap->root->left);
    heap->Build_Max_Heap(heap->root->right->left);


    REQUIRE(heap->max_key() == 12);


}

//TEST_CASE("Test2", "task2-2_Tests") {
/*    Heap<int>* heap = new Heap<int>(10,20);
    Node<int>* node = new Node<int>();
    heap->Max_Heap_Insert(node, 30,31);
    heap->Max_Heap_Insert(node, 30,32);
    heap->Max_Heap_Insert(node, 30,33);
    heap->Max_Heap_Insert(node, 30,34);

    REQUIRE(heap->max_key() == 30);

}*/