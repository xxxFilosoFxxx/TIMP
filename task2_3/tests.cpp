#include <iostream>
#include "task2-3.h"

#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

TEST_CASE("Test1", "task2-3_Tests") {
    Trie trie;
    trie.insert("arrow", 1);
    trie.insert("merss", 2);
    trie.insert("krash", 3);
    trie.insert("avto", 4);
    trie.insert("privet", 5);
    trie.insert("parking", 6);
    trie.insert("brothers",7);
    REQUIRE(trie.tree_height() == 8);
    REQUIRE(trie.search("avto") == 1);
    REQUIRE(trie.search("parking") == 1);
    REQUIRE(trie.search("systers") == 0);
    REQUIRE(trie.search("") == 0);
    Node* node;
    node = trie.search_node("parking");
    REQUIRE(node->_value() == 6);
    node = trie.search_node("park");
    REQUIRE(node->_value() == 0);
    REQUIRE_THROWS(node = trie.search_node("park_king"));
}

TEST_CASE("Test2", "task2-3_Tests") {
    Trie trie;
    trie.insert("parking", 1);
    trie.insert("arrow", 2);
    trie.insert("brothers", 3);
    trie.insert("privet", 4);
    trie.insert("avto", 5);
    trie.insert("merss", 6);
    trie.insert("krash",7);
    REQUIRE(trie.tree_height() == 8);
    REQUIRE(trie.search("avto") == 1);
    REQUIRE(trie.search("parking") == 1);
    REQUIRE(trie.search("systers") == 0);
    REQUIRE(trie.search("") == 0);
    Node* node;
    node = trie.search_node("parking");
    REQUIRE(node->_value() == 1);
    node = trie.search_node("park");
    REQUIRE(node->_value() == 0);
    REQUIRE_THROWS(node = trie.search_node("park_king"));
}