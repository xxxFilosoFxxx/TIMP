#include <iostream>
#include "cstdio"
#include "ctime"

#include "queue.h"

#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

TEST_CASE("Test1", "[queue]")
{
    Queue<int> pQueue;
    pQueue.push(5);
    pQueue.push(10);
    pQueue.push(15);
    REQUIRE(pQueue.size() == 3 );
}

TEST_CASE("Test2", "[queue]")
{
    Queue<int> pQueue;
    REQUIRE_THROWS(pQueue.pop());
}

TEST_CASE("Test3", "[queue]")
{
    Queue<int> pQueue;
    REQUIRE(pQueue.size() == 0);
}

TEST_CASE("Test4", "[queue]")
{
    Queue<int> pQueue;
    pQueue.push(10);
    pQueue.push(15);
    pQueue.push(1000);
    pQueue.push(-30);
    pQueue.clear();
    REQUIRE(pQueue.size() == 0);
}

TEST_CASE("Test5", "[queue]")
{
    Queue<int> pQueue;
    pQueue.push(10);
    pQueue.push(20);
    pQueue.pop();
    REQUIRE(pQueue.size() == 1);
}

TEST_CASE("Test6", "[queue]")
{
    Queue<int> pQueue;
    pQueue.push(10);
    pQueue.push(20);
    REQUIRE(pQueue.pop() == 10);
}

TEST_CASE("Test7", "[queue]")
{
    srand(time(NULL));
    Queue<int> pQueue;
    pQueue.push(rand()%1000);
    pQueue.push(rand()%1000);
    pQueue.push(rand()%1000);
    pQueue.clear();
    pQueue.push(rand()%1000);
    pQueue.push(rand()%1000);
    pQueue.clear();
    pQueue.push(rand()%1000);
    REQUIRE(pQueue.size() == 1);
}

TEST_CASE("Test8", "[queue]")
{
    Queue<double> pQueue;
    pQueue.push(rand()%1000);
    pQueue.push(rand()%1000);
    pQueue.push(rand()%1000);
    pQueue.pop();
    pQueue.pop();
    pQueue.push(rand()%1000);
    pQueue.clear();
    pQueue.push(15.5);
    pQueue.push(1000.15);
    pQueue.push(rand()%1000);
    pQueue.pop();
    REQUIRE(pQueue.pop() == 1000.15);
}

TEST_CASE("Test9", "[queue]")
{
    Queue<std::string> pQueue;
    pQueue.push("Hello ");
    pQueue.push("World?");
    pQueue.pop();
    REQUIRE(pQueue.pop() == "World?");
}


