#include <iostream>

#include "trie.h"

#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

TEST_CASE("Test1", "[trie]") {
    Trie trie;
    trie.insert("arrow", 1);
    trie.insert("mercedes", 2);
    trie.insert("crash", 3);
    trie.insert("car", 4);
    trie.insert("hello", 5);
    trie.insert("parking", 6);
    trie.insert("brothers", 7);

    REQUIRE(trie.tree_height() == 8);
    REQUIRE(trie.search("car") == 1);
    REQUIRE(trie.search("parking") == 1);
    REQUIRE(trie.search("sisters") == 0);
    REQUIRE(trie.search("") == 0);

    Node* node;
    node = trie.search_node("parking");
    REQUIRE(node->_value() == 6);

    REQUIRE_THROWS(node = trie.search_node("park_king"));
}

TEST_CASE("Test2", "[trie]") {
    Trie trie;
    trie.insert("parking", 1);
    trie.insert("arrow", 2);
    trie.insert("brothers", 3);
    trie.insert("hello", 4);
    trie.insert("car", 5);
    trie.insert("mercedes", 6);
    trie.insert("crash", 7);

    REQUIRE(trie.tree_height() == 8);
    REQUIRE(trie.search("car") == 1);
    REQUIRE(trie.search("parking") == 1);
    REQUIRE(trie.search("sisters") == 0);
    REQUIRE(trie.search("") == 0);

    Node* node;
    node = trie.search_node("parking");
    REQUIRE(node->_value() == 1);

    REQUIRE_THROWS(node = trie.search_node("park_king"));
}
