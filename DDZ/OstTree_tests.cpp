#include <iostream>
#include "ctime"

#include "OstTree.h"
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE("Test1", "DDZ_Tests") {
    Graph g;
    g.add_node(1,2,10);
    g.add_node(3,1,20);
    g.add_node(3,4,30);
    g.add_node(1,4,10);
    g.add_node(2,3,15);
    g.add_node(2,2,5);
    g.add_node(5,4,40);
    g.add_node(3,5,60);

    g.KruskalPoisk();
    REQUIRE(g.sum == 75);
    REQUIRE(g.result[0].first == 1);
    REQUIRE(g.result[0].second == 2);
    REQUIRE(g.result[1].first == 1);
    REQUIRE(g.result[1].second == 4);
    REQUIRE(g.result[2].first == 2);
    REQUIRE(g.result[2].second == 3);
    REQUIRE(g.result[3].first == 5);
    REQUIRE(g.result[3].second == 4);
}


