cmake_minimum_required(VERSION 3.13)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(queue queue/queue.h queue/queue.test.cpp)
add_executable(heap heap/heap.h heap/heap.test.cpp)
add_executable(trie_test trie/trie.h trie/trie.cpp trie/trie.test.cpp)
add_executable(trie trie/trie.h trie/trie.cpp trie/main.cpp)
add_executable(mst_tree_test mst_tree/mst_tree.h mst_tree/mst_tree.cpp mst_tree/mst_tree.test.cpp)
add_executable(mst_tree mst_tree/mst_tree.h mst_tree/mst_tree.cpp mst_tree/main.cpp)
