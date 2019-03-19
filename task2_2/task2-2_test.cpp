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
    Heap<int>* heap = new Heap<int>(10,20);
    Node<int> *node = new Node<int>(heap, 5, 5);

    heap->Max_Heap_Insert(node, 7,7);
 //   heap->Max_Heap_Insert(heap, 30,31);
 //   heap->Max_Heap_Insert(heap, 15,32);
 //   heap->Max_Heap_Insert(heap, 3,7);




   // heap->Max_Heap_Insert(heap, 3, 30);
   // heap->Max_Heap_Insert(heap, 10, 50);
   // heap->Max_Heap_Insert(heap, 6, 7);
    REQUIRE(heap->max_key() == 10);

}

TEST_CASE("Test2", "task2-2_Tests") {
/*    Heap<int>* heap = new Heap<int>(10,20);
    Node<int>* node = new Node<int>();
    heap->Max_Heap_Insert(node, 30,31);
    heap->Max_Heap_Insert(node, 30,32);
    heap->Max_Heap_Insert(node, 30,33);
    heap->Max_Heap_Insert(node, 30,34);

    REQUIRE(heap->max_key() == 30);
*/
}